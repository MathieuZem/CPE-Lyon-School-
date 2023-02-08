/* 
Auteurs : Alix Deleule et Mathieu Zeman
*/
/*
 * SPDX-FileCopyrightText: 2021 John Samuel
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "serveur.h"

void plot(char *data)
{
  int nb_couleurs;
  sscanf(data,"couleurs: %d,",&nb_couleurs);

  // Extraire le compteur et les couleurs RGB
  FILE *p = popen("gnuplot -persist", "w");
  printf("Plot\n");
  int count = 0;
  int n;
  char *saveptr = NULL;
  char *str = data;
  fprintf(p, "set xrange [-15:15]\n");
  fprintf(p, "set yrange [-15:15]\n");
  fprintf(p, "set style fill transparent solid 0.9 noborder\n");
  fprintf(p, "set title 'Top %d colors'\n",nb_couleurs);
  fprintf(p, "plot '-' with circles lc rgbcolor variable\n");
  while (1)
  {
    char *token = strtok_r(str, ",", &saveptr);
    if (token == NULL)
    {
      break;
    }
    str = NULL;
    printf("%d: %s\n", count, token);
    if (count == 1)
    {
      n = atoi(token);
      printf("n = %d\n", n);
    }
    else
    {
      // Le numéro 36, parceque 360° (cercle) / nb_couleurs couleurs = ?
      int angle = 360 / nb_couleurs;
      fprintf(p, "0 0 %d %d %d 0x%s\n", nb_couleurs, (count - 1) * angle, count * angle, token + 1);
    }
    count++;
  }
  fprintf(p, "e\n");
  printf("Plot: FIN\n");
  pclose(p);
}

// renvoie le pointeur de c dans la string(char *) str
char* search(char * str, char c){
  while (*str != '\0'){
    if (*str == c){
      return str;
    }
    str++;
  }
  return str;
}

/* renvoyer un message (*data) au client (client_socket_fd)
 */
int renvoie_message(int client_socket_fd, char *data)
{
  
  int data_size = write(client_socket_fd, (void *)data, strlen(data));

  if (data_size < 0)
  {
    perror("erreur ecriture");
    return (EXIT_FAILURE);
  }
  return (EXIT_SUCCESS);
}

/* accepter la nouvelle connection d'un client et lire les données
 * envoyées par le client. En suite, le serveur envoie un message
 * en retour
 */
int recois_envoie_message(int socketfd)
{
  struct sockaddr_in client_addr;
  char data[1024];

  unsigned int client_addr_len = sizeof(client_addr);

  // nouvelle connection de client
  int client_socket_fd = accept(socketfd, (struct sockaddr *)&client_addr, &client_addr_len);
  if (client_socket_fd < 0)
  {
    perror("accept");
    return (EXIT_FAILURE);
  }

  // la réinitialisation de l'ensemble des données
  memset(data, 0, sizeof(data));

  // lecture de données envoyées par un client
  int data_size = read(client_socket_fd, (void *)data, sizeof(data));

  if (data_size < 0)
  {
    perror("erreur lecture");
    return (EXIT_FAILURE);
  }


  /*
   * extraire le code des données envoyées par le client.
   * Les données envoyées par le client peuvent commencer par le mot "message :" ou un autre mot.
   */
  printf("Message recu:\n%s\n", data);
  char code[10];
  char valeurs[512];
  char* p = data;
  // recuperation des donnees
  while (*p != '\0'){
    if (*p == ':'){
      printf("%s\n",p);
    } else if (*p == '[') {
      printf("%s\n",p);
    }
    p++;
  }
  sscanf(data, "{\n\"code\" : %s\n \"valeur\" : [\"%s\"]\n}", code, valeurs);
  printf("code : %s\nvaleurs : %s\n", code, valeurs);

  // Si le message commence par le mot: 'message:'
  if (strcmp(code, "message:") == 0)
  {
    renvoie_message(client_socket_fd, data);
  }  else  {
    plot(data);
  }

  // fermer le socket
  close(socketfd);
  return (EXIT_SUCCESS);
}

int main()
{

  int socketfd;
  int bind_status;

  struct sockaddr_in server_addr;

  /*
   * Creation d'une socket
   */
  socketfd = socket(AF_INET, SOCK_STREAM, 0);
  if (socketfd < 0)
  {
    perror("Unable to open a socket");
    return -1;
  }

  int option = 1;
  setsockopt(socketfd, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(option));

  // détails du serveur (adresse et port)
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT);
  server_addr.sin_addr.s_addr = INADDR_ANY;

  // Relier l'adresse à la socket
  bind_status = bind(socketfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
  if (bind_status < 0)
  {
    perror("bind");
    return (EXIT_FAILURE);
  }

  // Écouter les messages envoyés par le client
  listen(socketfd, 30);

  // Lire et répondre au client
  recois_envoie_message(socketfd);

  return 0;
}
