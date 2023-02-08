/*
Auteurs : Alix Deleule et Mathieu Zeman
Nom du fichier : tri.c

Exercice 3.3 [★★]

Objectif:
Ce programme creer un tableau de 100 entiers randoms puis le tri en ordre croissant.
*/
#include <stdio.h> // importation d'une librairie standard en C
#include <stdlib.h> // importation d'une librairie pour la fonction rand afin d'obtenir des entiers "aleatoires"


// Forward declaration of functions
void swap(int*,int, int);
int * tabTrier();
void printTab(int*);

int main() {
    tabTrier();
    return 0;
}

// Cette fonction creer un tableau de 100 entiers randoms, puis tri ce tableau dans l'ordre croissant, et enfin retourne ce tableau
int* tabTrier(){
    // Creation d'un tableau de 100 entiers randoms
    int tab[100];

    for(int i = 0; i < 100; i++) {//remplir le tableau de int random
        tab[i] = rand();
    }

    // Affichage du tableau avant tri
    printTab(tab);
    printf("\n");

    // Tri du tableau dans l'ordre croissant
    for (int i = 0; i < 100; i++) { // On parcourt 100 fois le tableau
        for (int j = 0; j < 99 - i; j++){ // On pousse la valeur max jusqu'a 99-i+1
            if (tab[j] > tab[j+1]){
                swap(tab,j,j+1);
            }
        }
    }

    // Affichage du tableau après tri
    printTab(tab);
    return tab;
}

// Cette fonction affiche la tableau "tab"
void printTab(int tab[100]){
    printf("[ ");
    for (int i = 0; i < 100; i++) {
        if (i == 99){
            printf("%i",tab[i]);
        } else {
            printf("%i, ",tab[i]);
        }
    }
    printf("]\n");
}

// Cette fonction echange les valeurs aux indices i et j du tableau "tab"
void swap(int tabl[],int i, int j){
    int temp = tabl[i]; //*(tab+i)
    tabl[i] = tabl[j];
    tabl[j] = temp;
}