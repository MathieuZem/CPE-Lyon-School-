/*
Auteurs : Alix Deleule et Mathieu Zeman
Nom du fichier : bits.c

Exercice 2.2 [★]

Objectif :
Ce programme vérifie si les 4eme et 20eme bits de gauche d'un nombre sont 1 (en binaire). Si les deux bits sont 1, il affiche 1 sinon 0.
*/
#include <stdio.h>
 int main(){
    int d = 2147483647; /* Initialisation du nombre de test*/
    printf("%d\n",d&0b00010000000000000000000000000000 > 0 && d&0b00000000000000000001000000000000 > 0);// utilisation de masque pour ne garder que le 4e et 20e bits 
    return 0;
 }