/* 
Auteurs : Alix Deleule et Mathieu Zeman
Exercice 4.6 [★★★]

Ici, on a un programme qui compare un mot et un fichier,
Le programme va compter le nombre de fois que le mot ce 
situe sur une ligne et donner le résumer ensuite du nombre de
fois par ligne que le mot est présent.
*/

#include "fichier.h"
#include <stdio.h>
#include <string.h>

// Cette fonction a pour but de chercher, compter et afficher le nombre de 
// qu'un mot est trouver dans un ligne
void chercher_phrase(char *buffer, char phrase[30]){
    int Iter_Ligne[100];
    int index_IL = 0;
    int numero_ligne = 0;
    int nb_mot = 0;
    char *p2 = phrase;

    memset(Iter_Ligne, 0, 400);

// Cette boucle viens parcourire la chaîne de caractère qui correspond au fichiers,
// donc tant que l'on arrive pas a la fin du fichier, on continue de boucler
    while (*buffer != '\0') {

        // cette condition sert a vérifier si on arrive on fin de ligne,
        // c'est a dire, si on trouve le caractère de retour a la ligne \n
        if(*buffer == '\n'){
            Iter_Ligne[index_IL] = nb_mot;
            numero_ligne += 1;
            index_IL++;
            nb_mot = 0;
            }

        // Dans cette boucle, on vois si le terme du texte est équivalent
        // au mot rechercher, si c'est le cas, on va boucler sur le mot
        while(*buffer == *p2){
            p2++;
            buffer++;
 
        // On va vérifier si le pointeur du mot arrive a la fin, si il aboutis, 
        // c'est que les mots comparer sont les mêmes, On va donc incrémenter le nombre de mot
        // réinitialiser le pointeur du mot comparer, et revenir en arrière de 1 sur le texte pour
        // pas se décaler de 1.
        if (*p2 == '\0'){ //si on est à la fin de la phrase recherchée 
            nb_mot++;
            p2 = phrase;
            buffer--;
        }
        }

        buffer++;

        }

        // La dernière ligne n'étant pas conclue par un \n puisque c'est part un \0
        // on viens intégrer la dernière ligne au tableau.
        Iter_Ligne[index_IL] = nb_mot;

        // On viens afficher les données récupérer, donc les lignes et les nombres de 
        // mot repérer par ligne.
        for (int i=0; i < 30; i++){ 
            if (Iter_Ligne[i] != 0){
                printf("Ligne %i, %i fois\n",i+1,Iter_Ligne[i]);
            }
        };
        }

int main(int argc, char *argv[]) {
    char * nom_fichier;
    char * phrase;

    // On récupère les variables donner par l'utilisateur lors de l'appel du programme
    nom_fichier = argv[2];
    phrase = argv[1];
    
    // On crée notre string qui contient notre fichier
    char * buffer;
    buffer = lire_fichier(nom_fichier);

    // On compare
    chercher_phrase(buffer,phrase);


 return 0;
}