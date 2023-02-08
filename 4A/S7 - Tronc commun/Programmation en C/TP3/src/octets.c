/*
Auteurs : Alix Deleule et Mathieu Zeman
Nom du fichier : octets.c

Exercice 3.6 [★★]

Objectif:
Ce programme affiche les octets d'une variable(short, int, long int, float, double et long double).
Utilisez char * et les opérateurs de pointeurs.

*/
#include <stdio.h> // importation d'une librairie standard en C

int main(){
    unsigned char * p;//Création du pointeur

    int i = 0xa47865ff;
    p = &i;
    printf("int : %i\t%x %x %x %x\n",i,*(p+3),*(p+2),*(p+1),*p);

    short s = 235;
    p = &s;
    printf("short : %i\t%x %x %x %x\n",s,*(p+3),*(p+2),*(p+1),*p);

    float f = 0xa47865ff;
    p = &f;
    printf("float : %f\t%x %x %x %x\n",f,*(p+3),*(p+2),*(p+1),*p);

    long int li = 0xa47865ff;
    p = &li;
    printf("long int : %li\t%x %x %x %x\n",li,*(p+3),*(p+2),*(p+1),*p);

    double d = 0xa47865ff;
    p = &d;
    printf("double : %d\t%x %x %x %x\n",d,*(p+3),*(p+2),*(p+1),*p);

    long double ld = 0xa47865ff;
    p = &ld;
    printf("long double : %ld\t%x %x %x %x\n",ld,*(p+3),*(p+2),*(p+1),*p);               

    return 0;
}
