/*
Auteurs : Alix Deleule et Mathieu Zeman
Nom du fichier : variables.c

Exercice 1.4 [★★]

Objectif :
Ce programme affecte et affiche les valeurs des variables des différents types de base 
*/
#include <stdio.h>

int main(){
    printf("\nVoici un exemple de variables de chacun des types :\n");

    printf("\nSignée :\n");

    char c = 'a'; //On affecte la valeur a la variable
    printf("char : %c\n",c); //On affiche la valeur

    short s = 32767;
    printf("short : %d\n",s);

    int i = -2147483647;
    printf("int : %i\n",i);

    long int li = 4294967295;
    printf("long int : %li\n",li);

    long long int lli = 9223372036854775807;
    printf("lli : %lli\n",lli);

    float f = 5.7;
    printf("float : %f\n",f);

    double d = 5.58;
    printf("double : %f\n",d);

    long double ld = 8459.254;
    printf("short ld : %Lf\n",ld);


    printf("\nNon Signée :\n");

    unsigned char U_c= 'z';
    printf("unsigned char : %hhu\n",U_c);

    unsigned short U_s= 65535;
    printf("unsigned short : %hu\n",U_s);

    unsigned int U_i= 13;
    printf("unsigned int : %u\n",U_i);

    unsigned long int U_li= 4294967295;
    printf("unsigned long int : %lu\n",U_li);

    unsigned long long int U_lli = 9223372036854775807;
    printf("unsigned long long int : %llu\n\n",U_lli);

    return 0;
}