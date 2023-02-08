/* 
Auteurs : Alix Deleule et Mathieu Zeman
*/

/*
 * SPDX-FileCopyrightText: 2021 John Samuel
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "client.h"
#include "bmp.h"

/*
 * Fonction d'envoi et de réception de messages
 * Il faut un argument : l'identifiant de la socket
 */

int envoie_recois_message(int socketfd)
{

  char data[1024];
  // la réinitialisation de l'ensemble des données
  memset(data, 0, sizeof(data));

  // Demandez à l'utilisateur d'entrer un message
  char message[1024];
  printf("Votre message (max 1000 caracteres): ");
  fgets(message, sizeof(message), stdin);
  strcpy(data, "message: ");
  strcat(data, message);

  int write_status = write(socketfd, data, strlen(data));
  if (write_status < 0)
  {
    perror("erreur ecriture");
    exit(EXIT_FAILURE);
  }

  // la réinitialisation de l'ensemble des données
  memset(data, 0, sizeof(data));

  // lire les données de la socket
  int read_status = read(socketfd, data, sizeof(data));
  if (read_status < 0)
  {
    perror("erreur lecture");
    return -1;
  }

  printf("Message recu: %s\n", data);

  return 0;
}

void analyse(char *pathname, char *data, int nb_couleurs)
{
  // compte de couleurs
  couleur_compteur *cc = analyse_bmp_image(pathname);

  int count;
  strcpy(data, "couleurs: ");
  char temp_string[10];
  sprintf(temp_string,"%d,",nb_couleurs);
  if (cc->size < nb_couleurs)
  {
    sprintf(temp_string, "%d,", cc->size);
  }
  strcat(data, temp_string);

  // choisir nb_couleurs couleurs
  for (count = 1; count < nb_couleurs + 1 && cc->size - count > 0; count++)
  {
    if (cc->compte_bit == BITS32)
    {
      sprintf(temp_string, "#%02x%02x%02x,", cc->cc.cc24[cc->size - count].c.rouge, cc->cc.cc32[cc->size - count].c.vert, cc->cc.cc32[cc->size - count].c.bleu);
    }
    if (cc->compte_bit == BITS24)
    {
      sprintf(temp_string, "#%02x%02x%02x,", cc->cc.cc32[cc->size - count].c.rouge, cc->cc.cc32[cc->size - count].c.vert, cc->cc.cc32[cc->size - count].c.bleu);
    }
    strcat(data, temp_string);
  }

  // enlever le dernier virgule
  data[strlen(data) - 1] = '\0';
}

// permet d'envoyer les couleurs via la socket
int envoie_couleurs(int socketfd, char *pathname, int nb_couleurs)
{
  char data[512];
  memset(data, 0, sizeof(data));
  analyse(pathname, data, nb_couleurs);

  int write_status = write(socketfd, data, strlen(data));
  if (write_status < 0)
  {
    perror("erreur ecriture");
    exit(EXIT_FAILURE);
  }

  return 0;
}

// Cette fonction permet de mettre le contenu texte d'un json dans data
// code = numero du json(1,2 ou 3)(ex: json1.json)
int lecture_donnees(int code,char * data){
  if (code >= 1 && code <= 3){// si le json existe
    //ouverture du json
    FILE *f;
    char dir[11];
    sprintf(dir,"json%d.json",code);
    f = fopen(dir,"r");
    memset(data, 0, sizeof(data));
    char chaine[100] = "";
    // ecriture dans data lignes par lignes
    while (fgets(chaine, 100, f)){
      strcat(data,chaine);
    }
    fclose(f);
    printf("%s\n",data);
  } else {
    return (EXIT_FAILURE);
  }
  return 0;
}

// permet de envoyer les donnes dans lea socket au serveur
int envoie_donnees(int socketfd, int code){
  char data[512];
  memset(data, 0, sizeof(data));
  lecture_donnees(code, data);// lecture dans le json n°(code)
  int write_status = write(socketfd, data, strlen(data));
  if (write_status < 0)
  {
    perror("erreur ecriture");
    exit(EXIT_FAILURE);
  }

  return 0;
}

int main(int argc, char **argv)
{
  int socketfd;

  struct sockaddr_in server_addr;

  if (argc < 3)
  {
    printf("usage: ./client chemin_bmp_image nombre_couleurs\n");
    return (EXIT_FAILURE);
  }

  /*
   * Creation d'une socket
   */
  socketfd = socket(AF_INET, SOCK_STREAM, 0);
  if (socketfd < 0)
  {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  // détails du serveur (adresse et port)
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT);
  server_addr.sin_addr.s_addr = INADDR_ANY;

  // demande de connection au serveur
  int connect_status = connect(socketfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
  if (connect_status < 0)
  {
    perror("connection serveur");
    exit(EXIT_FAILURE);
  }
  
  if (argc != 3)
  {
    // envoyer et recevoir un message
    envoie_recois_message(socketfd);
  }
  else
  {
    // envoyer et recevoir les couleurs prédominantes
    // d'une image au format BMP (argv[1])
    int nb_couleurs;
    sscanf(argv[2],"%d",&nb_couleurs);
    // envoie_couleurs(socketfd, argv[1], nb_couleurs);
    envoie_donnees(socketfd,3);
  }

  close(socketfd);
}