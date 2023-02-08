/*
Auteurs : Alix Deleule et Mathieu Zeman
Nom du fichier : opérateurs.c

Exercice 1.5 [★][★]

Objectif :
Ce programme utilise deux variables et effectue un test de tout les opérateurs.
*/
#include <stdio.h>

int main() {

    int a = 16, b = 3; /* Initialisation des variables */

    printf("\na = %d, b = %d\n", a, b);

    printf("\nOpérateur Arithmétique de base :\n");
    printf("Addition : a+b=%i\n", a+b); /* Calcule et Affichage des opérations */
    printf("Soustraction : a-b=%i\n", a-b);
    printf("Multiplication : a*b=%i\n", a*b);
    printf("Division : a/b=%i\n", a/b);
    printf("Modulo : a%%b=%i\n", a%b);

    printf("\nOpérateur Incrémentation/Déecrémentation :\n");
    printf("Incrémentation après affichage : a++=%i\n", a++);
    printf("Incrémentation avant affichage : ++a=%i\n", ++a);
    printf("Décrémentation après affichage : a--=%i\n", a--);
    printf("Décrémentation avant affichage : --a=%i\n", --a);


    printf("\nOpérateur Logique :\n");
    printf("Équivalence : a==b = %i\n", a==b);
    printf("Supérieur : a>b = %i\n", a>b);
    printf("ET Logique : a&b = %i\n", a&&b);
    printf("OU Logique : a|b = %i\n", a||b);
    printf("NON Logique : a&b = %i\n", !a);
    printf("OU EXCLUSIF Logique : a^b = %i\n\n", a^b);

    return 0;
}