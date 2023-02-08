/*
Auteurs : Alix Deleule et Mathieu Zeman
Nom du fichier : tableauptr.c

Exercice 2.9 [★★★]

Objectif:
Ce programme cree 2 tableaux différents : int et float. Les valeurs sont aleatoires.
Pour les deux tableaux, si l'indice est divisible par 2, on multiplie la
valeur à cette position par 3. 
On n'utilise pas la notation indicielle pour parcourir les tableaux (par exemple, i [3], i [5] etc.), mais des pointeurs.
*/

#include <stdio.h> // importation d'une librairie standard en C
#include <stdlib.h> // importation d'une librairie pour la fonction rand afin d'obtenir des entiers "aleatoires"

int main(){
    //Creation des 2 tableaux
    int entiers[23];
    float floats[23];
    int* p_i = entiers;
    float* p_f = floats;
    for(int i = 0; i < 23; i++){
        *p_i = rand() % 100;
        *p_f = (float)rand()/(float)(RAND_MAX);
        p_i++;
        p_f++;
    }

    // Affichage des 2 tableaux avant modification
    for(int i = 0; i < 23; i++){
        printf("%i\t%f0\n",entiers[i],floats[i]);
    }

    //Modification des tableaux
    p_i = entiers;
    p_f = floats;
    for(int i = 0; i < 23; i++){
        if (i%2==0){// si l'indice est divisible par 2
            *p_i *= 3;
            *p_f *= 3;
        }
        p_i++;
        p_f++;
    }

    // Affichage des 2 tableaux apres modification
    printf("\n");
    for(int i = 0; i < 23; i++){
        printf("%i\t%f0\n",entiers[i],floats[i]);
    }

    return 0;
}
