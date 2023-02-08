/*
Auteurs : Alix Deleule et Mathieu Zeman
Nom du fichier : chercher.c

Exercice 3.4 [★★]

    Objectif: 
    Ce programme cree un tableau de 100 entiers et
    puis cherche un entier dans ce tableau. 
    Si l'entier est présent dans le tableau, affiche le message 'entier présent'.
    Sinon affiche le message 'entier non présent'.


Exercice 3.8 [★★★]

    Objectif:
    Ce programme cree un tableau de 10 phrases (un tableau de tableau de caractères).
    Sans utilisant les fonctions de bibliothèques standards ou externes, 
    cherchez si une phrase est dans le tableau ou pas.
    Si la phrase est présente dans le tableau, affiche le message 'phrase présente'.
    Sinon affiche le message 'phrase non présente'.

*/

#include <stdio.h> // importation d'une librairie standard en C
#include <stdlib.h> // importation d'une librairie pour la fonction rand afin d'obtenir des entiers "aleatoires"

// unsigned int chercher_nombre(int*,int);
// unsigned int chercher_phrase(char*,char*);

/*  Cette cherche l'entier dans le tableau d'entier 'tab'
    Si l'entier est present 1 est retourne sinon 0 */
unsigned int chercher_nombre(int tab[],int entier){
    for(int i = 0; i < 100; i++) {
        if(tab[i]==entier){
            return 1;
        }
    }
    return 0;
}

// Cette fonction compare 2 strings (tableaux de char), si les deux sont egaux 1 est retourne sinon 0
unsigned int compareStr(char * str1, char * str2) {
    while (*str1 == *str2) {
        if (*str1 == '\0' && *str2 == '\0'){
            return 1;
        }
        str1++;
        str2++;
    }
    return 0;
}

/*  Cette cherche la phrase dans le tableau de phrase 'tab_phrase'
    Si la phrase est presente 1 est retourne sinon 0 */
unsigned int chercher_phrase(char tab_phrase[][50],char phrase[]){
    for(int i = 0; i < 10; i++) {
        if(compareStr(tab_phrase[i],phrase)){//si les la phrase a l'indice i est egale a la phrase chercher
            return 1;
        }
    }
    return 0;
}

int main() {
/* exercice 3.4*/
    int tab[100];
    for(int i = 0; i < 100; i++) {//remplir le tableau de int random entre 0 et 99 inclus
        tab[i] = rand() % 100;
    }

    int entier = 1;

    if (chercher_nombre(tab,entier)){
        printf("entier présent\n");
    } else {
        printf("entier non présent\n");
    }

/*exercice 3.8*/
    //Creation du tableau de phrases (10 phrases de 50 char max)
    char tab_phrase[10][50] = {"Test","Si","Ces","Phrases","Existent","Si","Oui","Ou","Non","Voilà"};
    
    char phrase[50] = "Oui";// phrase a chercher

    if (chercher_phrase(tab_phrase,phrase)){
        printf("phrase présente\n");
    } else {
        printf("phrase non présente\n");
    }
    return 0;
}
