/*
Auteurs : Alix Deleule et Mathieu Zeman
Nom du fichier : chaine.c

Exercice 2.4 [★★]

Objectif :
Ce programme calcule le nombre de caractère dans une chaîne, copie un chaîne de caractère dans une autre et concatène deux chaines de caractères
*/
#include <stdio.h>
int main(){
    
    char tab[10] =  "abcdef-"; /* Initialise la chaine */
    int n = sizeof(tab); /* Nombre maximal de caractère, on va vérifié si il y en a moins ou non*/
    char concatenate[20]; /* Initialise la chaîne qui récupère la concaténation des chaînes*/

    char copie[10]; /* Initialise la chaîne qui récupère la copie de la chaîne*/
    int count = 0; /* Permettra de savoir combien il y a de caractère dans la chaîne*/
    for(int i = 0; i < n; i++) {
        if (tab[i]){ /* Tant qu'il y a des caractère, alors on incrémente count pour connaitre le nombre de caractère */
            count++;
        }
        int c = tab[i]; /* On viens récupérer chacun des caractères */
        copie[i] = c; /* On viens intégrer dans la chaînes vide de copie le caractère récupérer précédemment */
        concatenate[i] = c; /* On viens placer au début de la chaîne vide de concaténation, la première chaîne de caractère*/
    }
    for (int i = 0; i < count; i++) {
        concatenate[i+count] = tab[i]; /* On viens placer la deuxième chaîne de caractère dans la chaînes qui concatène les deux*/
    }
    concatenate[count*2] = tab[count];
    
    printf("\nLe Nombre de Caractère dans la chaine est : %i\n\n", count);
    printf("La chaîne est : %s\nLa copie de la chaîne est : %s\nLa chaîne concaténer est : %s\n\n",tab,copie,concatenate);

    return 0;
}