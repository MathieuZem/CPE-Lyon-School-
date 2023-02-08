/* 
Auteurs : Alix Deleule et Mathieu Zeman
Exercice 4.2 [★] 

Ce programme contient des fonctions de lecture et ecriture de fichier.

*/
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// Cette fonction permet la lecture d'un fichier et renvoie son contenu
// parametre : le nom du fichier
char* lire_fichier(char *nom_de_fichier){
    int f;
    f = open(nom_de_fichier, O_RDONLY);
    static char contenu[1000];
    //int size;
    //size = 
    read(f,contenu,1000);
    close(f);
    // for(short i = 0; i < size; i++){
    //     printf("%c",contenu[i]);
    // }
    return contenu;
} //int intint

// Cette fonction permet d'ecrire dans un fichier
// parametre: nom_de_fichier et le message a ecrire dans le fichier
void ecrire_dans_fichier(char *nom_de_fichier, char *message){
    int f;
    printf("taille de message : %lu\n", sizeof(message));
    f = open(nom_de_fichier, O_WRONLY);
    write(f, message, strlen(message));
    close(f);
}