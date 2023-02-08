/*
Auteurs : Alix Deleule et Mathieu Zeman
Nom du fichier : etudiant.c

Exercice 2.5 [★★]

Objectif :
Ce programme utilisant uniquement des tableaux, initialise et affiche les détails de cinq étudiant.e.es.
Pour chaque étudiant.e, on est intéressé par son nom, son prénom, son adresse, et ses notes dans 2 modules (Programmation en C, Système d'exploitation).
*/
#include <stdio.h>

int main(){

    char data[5][5][30] = {{"Alix","Deleule","Cupertino","15","20"},
                        {"Mathieu","Zeman","Mionnay","12","16"},
                        {"Emma","Begard","Aix","10","20"},
                        {"Guillaume","Domelier","Mouson","11","5"},
                        {"Audrey","Nicolle","Bron","21","21"}}; /* Initialisation du tableau de tableau contenant des chaînes de caractère */

    for (int i = 0; i < 5; i++) { /* affichage des élèves */
        printf("\nL'élève ce prénommant %s %s habite à %s et les notes de Programmation en C et Système d'exploitation sont respectivement %s et %s\n", data[i][0], data[i][1], data[i][2], data[i][3],data[i][4]);
        printf("\n");
    }

    return 0;
}