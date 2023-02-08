/*
Auteurs : Alix Deleule et Mathieu Zeman
Nom du fichier : grand_petit.c

Exercice 3.2 [★]

Objectif:
Ce programme creer un tableau de 100 entiers randoms et trouve ces valeurs min et max.
*/  
#include <stdio.h> // importation d'une librairie standard en C
#include <stdlib.h> // importation d'une librairie pour la fonction rand afin d'obtenir des entiers "aleatoires"

int main() {
    // Creation d'un tableau de 100 entiers randoms
    int tab[100];

    for(int i = 0; i < 100; i++) {//remplir le tableau de int random
        tab[i] = rand();
    }

    int min = tab[0];
    int max = tab[0];

    // Recherche des valeurs min et max du tableau
    for (int i = 0; i < 100; i++){
        if (tab[i] < min){
            min = tab[i];
        } else if (tab[i]>max) {
            max = tab[i];
        }
    }
    
    // Affichage des valeurs min et max du tableau
    printf("min = %i\n",min);
    printf("max = %i\n",max);

    return 0;
}