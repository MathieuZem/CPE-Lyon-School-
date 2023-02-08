/*
Auteurs : Alix Deleule et Mathieu Zeman
Nom du fichier : sizeof.c

Exercice 3.1 [★]

Objectif:
Ce programme affiche la taille maximale en octet de différents type de variables.

Ce programme affiche:
1.  sizeof (int)        4
2.  sizeof (int *)      8
3.  sizeof (int **)     8
4.  sizeof (char *)     8
5.  sizeof (char **)    8
6.  sizeof (char ***)   8
7.  sizeof (float *)    8
8.  sizeof (float **)   8
9.  sizeof (float ***)  8
*/
#include <stdio.h> // importation d'une librairie standard en C

int main() {
    printf("%ld\n", sizeof (int));
    printf("%ld\n", sizeof (int *));
    printf("%ld\n", sizeof (int **));
    printf("%ld\n", sizeof (char *));
    printf("%ld\n", sizeof (char **));
    printf("%ld\n", sizeof (char ***));
    printf("%ld\n", sizeof (float *));
    printf("%ld\n", sizeof (float **));
    printf("%ld\n", sizeof (float ***));
    
    return 0;
}