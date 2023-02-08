/*
Auteurs : Alix Deleule et Mathieu Zeman
Nom du fichier : puissance.c

Exercice 2.1 [★]

Objectif :
Ce programme prend deux entiers a et b et affiche la valeur du nombre a élevé à une puissance b.
*/
#include <stdio.h>

int main() {

    int a = 5; /* Initialisation du nombre qui est a la puissance */
    int b = 7; /* Initialisation de la puissance */
    int res = 1 /* Initialisation de la variable qui stockera le résultat */ ;

    for (int i = 0; i < b; i++) { /* On viens crée une boucle pour multipler le nombre du nombre de fois sa puissance. */
        res = res * a;
    }

    printf("a^b=%i",res);

    return 0;
}