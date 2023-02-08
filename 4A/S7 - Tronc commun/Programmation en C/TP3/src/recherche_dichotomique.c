/* 
Auteurs : Alix Deleule et Mathieu Zeman
Nom du fichier : recherche_dichotomique.c

Exercice 3.5 [★★]

Objectif:
Regardez l'article sur la recherche dichotomique:
<https://fr.wikipedia.org/wiki/Recherche_dichotomique>.
Ce programme cree un tableau de 100 entiers et puis cherche(par dichotomie) un entier dans le tableau déjà trie en ordre croissant. 
Si l'entier est présent dans le tableau, affichez le message 'entier présent'.

*/
#include <stdio.h> // importation d'une librairie standard en C
#include <stdlib.h> // importation d'une librairie pour la fonction rand afin d'obtenir des entiers "aleatoires"

// Forward declare des fonctions
int* tabTrier();
void swap(int*,int, int);
void printTab(int*);

int main() {
    
    int* tab = tabTrier(); // Creation du tableau trie
    printTab(tab); // Affichage du tableau
    int entier = 14;
    int indMax = 99;
    int indMin = 0;
    int indMid = (indMax+indMin)/2;
    while (tab[indMid]!=entier && indMid != indMin){ // recherche de l'entier
        printf("%i %i %i\n",indMin,indMid,indMax);
        if (entier < tab[indMid]) {
            indMax = indMid;
        } else {
            indMin = indMid;
        }
        indMid = (indMax+indMin)/2;
    }
    
    if (tab[indMid]==entier) {
        printf("entier présent : %i\n", indMid);
    } else {
        printf("entier non présent\n");
    }
    
    return 0;
}

// Cette fonction echange les valeurs aux indices i et j du tableau 'tabl'
void swap(int tabl[],int i, int j){
    int temp = tabl[i]; //*(tab+i)
    tabl[i] = tabl[j];
    tabl[j] = temp;
}

// Cettte fonction affiche toutes les valeurs d'un tableau de 100 entiers
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

// Cette fonction cree un tableau de 100 entiers et le tri en ordre croissant puis retourne ce tableau.
int* tabTrier(){

    static int tab[100];//Creation du tableau vide

    for(int i = 0; i < 100; i++) {//remplir le tableau de int random entre 0 et 99 inclus
        tab[i] = rand() % 100;
    }

    //Tri du tableau
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 99 - i; j++){
            if (tab[j] > tab[j+1]){
                swap(tab,j,j+1);
            }
        }
    }

    return tab;
}