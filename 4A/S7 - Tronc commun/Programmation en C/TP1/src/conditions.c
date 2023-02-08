/*
Auteurs : Alix Deleule et Mathieu Zeman
Nom du fichier : conditions.c

Exercice 1.7 [★★]

Objectif :
Ce programme affiche les nombres entres 0 et 1000 qui respecte les conditions suivantes : le nombre est un multiple de 2 et à 15, le nombre est un multiple à 103 ou à 107 ou le nombre est un multiple à 7 ou à 5 mais pas à 3.
*/
#include <stdio.h>
#include <stdbool.h>

int main() {

    for (int i = 0; i <= 1000; i++) { /* Initialisation de la boucle qui testera les nombres de 0 à 1000 pour ensuite vérifier les conditions */
        bool a = i%2==0 && i%15==0; /* crée un booléen pour la première condition qui est la multiplicité à 2 et à 15 */
        bool b = i%103==0 || i%107==0; /* crée un booléen pour la deuxième condition qui est la multiplicité à 103 ou à 107 */
        bool c = (i % 7 == 0 || i % 5 == 0) && i % 3 != 0; /* crée un booléen pour la troixème condition qui est la multiplicité à 7 ou à 5 mais pas à 3 */
        if (a){ /*on vérifie si le booléen est vrai ou faux, si il est vrai on affiche le nombre avec l'explication*/
            printf("divisible par 2 et 15\t");
        }
        if (b){ /*on vérifie si le booléen est vrai ou faux, si il est vrai on affiche le nombre avec l'explication*/
            printf("divisible par 103 ou 107\t");
        }
        if (c){ /*on vérifie si le booléen est vrai ou faux, si il est vrai on affiche le nombre avec l'explication*/
            printf("divisible par 7 ou 5 et pas 3\t");
        }
        if (a||b||c){
            printf("%i\n",i);
        }
    }

    return 0;
}