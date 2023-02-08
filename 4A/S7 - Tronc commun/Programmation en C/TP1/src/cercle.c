/*
Auteurs : Alix Deleule et Mathieu Zeman
Nom du fichier : cercle.c

Exercice 1.2 [★]

Objectif :
Ce programme calcule l'aire et le périmètre d'un cercle
*/
#include <stdio.h> /* importation d'une librairie standard en C */
#include <math.h> /* importation d'une librairie standard pour les opérations mathématique en C */

int main(){

    float rayon = 5; /* Création d'une variable qui est la rayon du cercle */
    float aire = M_PI*rayon*rayon; /* Calcule de l'aire du cercle (M_PI permet d'avoir une valeur de PI précise) */
    float perimetre = 2 * M_PI * rayon; /* Calcule du Perimètre du cercle (M_PI permet d'avoir une valeur de PI précise) */

    printf("\nPour un cercle de rayon : %f cm\n\n",rayon); /* On affiche dans la console nos résultats */
    printf("L'Aire vaut : %f cm^2\n", aire);
    printf("Le Perimetre vaut : %f cm\n\n", perimetre);

    return 0;
}