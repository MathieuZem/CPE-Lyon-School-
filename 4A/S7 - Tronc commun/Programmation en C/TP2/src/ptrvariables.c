/*
Auteurs : Alix Deleule et Mathieu Zeman
Nom du fichier : ptrvariables.c

Exercice 2.8 [★★]

Objectif:
Ce programme affecte et affiche les valeurs des variables de
différents types de base (char, short, int, long int, long long int,
float, double, long double) en utilisant leurs adresses.

*/
#include <stdio.h> // importation d'une librairie standard en C

int main() {
    unsigned char * p;// Creation du pointeur

    char var_c = 'b';
    p = &var_c;
    printf("char : %c\t%x\n",var_c,*p);


    short var_s = 5;
    p = &var_s;
    printf("short 5 : %d\t%x %x\n",var_s,*(p+1),*p);


    int var_i = 0xa47865ff;
    p = &var_i;
    printf("int 0xa47865ff : %i\t%x %x %x %x\n",var_i,*(p+3),*(p+2),*(p+1),*p);


    long int var_li = 2200220022;
    p = &var_li;
    printf("long int 2200220022 : %li\t%x %x %x %x %x %x %x %x\n",var_li,*(p+7),*(p+6),*(p+5),*(p+4),*(p+3),*(p+2),*(p+1),*p);


    long long int var_lli = 300;
    p = &var_lli;
    printf("lli 300 : %lli\t%x %x %x %x %x %x %x %x\n",var_lli,*(p+7),*(p+6),*(p+5),*(p+4),*(p+3),*(p+2),*(p+1),*p);


    float var_f = 2;
    p = &var_f;
    printf("float : %f\t%x %x %x %x\n",var_f,*(p+3),*(p+2),*(p+1),*p);


    double var_d = 5.58;
    p = &var_d;
    printf("double 5.58 : %f\t%x %x %x %x %x %x %x %x\n",var_d,*(p+7),*(p+6),*(p+5),*(p+4),*(p+3),*(p+2),*(p+1),*p);

    long double var_ld = 8459.254;
    p = &var_ld;
    printf("long double ld 8459.254 : %Lf\n%x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x\n",var_ld,*(p+15),*(p+14),*(p+13),*(p+12),*(p+11),*(p+10),*(p+9),*(p+8),*(p+7),*(p+6),*(p+5),*(p+4),*(p+3),*(p+2),*(p+1),*p);

    return 0;
}
