/*
Auteurs : Alix Deleule et Mathieu Zeman
Nom du fichier : fibonacci.c

Exercice 2.3 [★]

Objectif :
Ce programme affiche les n termes de la suite de fibonacci
*/
#include <stdio.h>

int main(){

    int n = 20; /* Iniitalisation du nombre de terme souhaitée*/
    printf("\nla suite de fibonacci entre 0 et %i est :\n\n", n);
    int tab[10000] = {}; /* Initialisation d'un tableau qui viendra stocker nos valeurs*/
    for (int i = 0; i <= n; i++) {
        if (i==0){ /* Dans le cas de U0 on est sur une donnée initial donc on l'exclue de la routine de sommation */
            tab[i] = 0;
        } else if (i==1) { /* Dans le cas de U1 on est sur une donnée initial donc on l'exclue de la routine de sommation */
            tab[i] = 1;
        } else {
            tab[i] = tab[i-1]+tab[i-2]; /* Dans le reste des cas, on est sur la somme classique des deux termes précédent. */
        }
        printf("u%i = %i\n", i, tab[i]); /* On affiche le résulats ici après l'avoir stocker*/
    }
    return 0;
}