/*
Auteurs : Alix Deleule et Mathieu Zeman
Nom du fichier : binaire.c

Exercice 1.9 [★★★]

Objectif :
Ce programme affiche la version binaire de n'importe quel nombre entier
*/
#include <stdio.h>
#include <math.h>

int main() {
    
    int x = 5544; /* Initialisation du nombre a transformer en binaire*/
    int mask = 0b100000000000000000;

    printf("\nl'écriture binaire de %i est : ", x);

    for (int i = 0; i < 18; i++) { /* le mask étant large de 17, on va faire 18 rotation*/

        if (x&mask) { /* si le 1 du mask tombe sur le 1 de l'écriture binaire, alors c'est qu'il y a un 1 a cette endroit donc on va afficher un 1 dans la console */
            printf("1");
        }
        else { /* Sinon, on affiche un 0 */
            printf("0");
        }
        mask = mask>>1; /* On fait un rotation bit a bit pour décaler le 1 et pour vérifier tout les bits */
    }
    printf("\n\n");
    return 0;
}
