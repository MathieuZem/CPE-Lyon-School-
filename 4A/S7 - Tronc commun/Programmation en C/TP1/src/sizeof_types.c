/*
Auteurs : Alix Deleule et Mathieu Zeman
Nom du fichier : sizeof_types.c

Exercice 1.3 [★]

Objectif :
Ce programme affiche la taille des différents types de base (en octets)
*/
#include <stdio.h>

int main(){
    printf("\nLes différentes tailles des types de base en octet :\n");

    printf("\nSignée\n");
    printf("sizeof(char) : %ld octet\n",sizeof(char)); /* affiche la taille a l'aide de la fonction sizeof() */
    printf("sizeof(short) : %ld octet\n",sizeof(short));
    printf("sizeof(int) : %ld octet\n",sizeof(int));
    printf("sizeof(long int) : %ld octet\n",sizeof(long int));
    printf("sizeof(long long int) : %ld octet\n",sizeof(long long int));
    printf("sizeof(float) : %ld octet\n",sizeof(float));
    printf("sizeof(double) : %ld octet\n",sizeof(double));
    printf("sizeof(long double) : %ld octet\n",sizeof(long double));

    printf("\nNon-signée\n");
    printf("sizeof(unsigned char) : %ld octet\n",sizeof(unsigned char));
    printf("sizeof(unsigned short) : %ld octet\n",sizeof(unsigned short));
    printf("sizeof(unsigned int) : %ld octet\n",sizeof(unsigned int));
    printf("sizeof(unsigned long int) : %ld octet\n",sizeof(unsigned long int));
    printf("sizeof(unsigned long long int) : %ld octet\n\n",sizeof(unsigned long long int));

    return 0;
}