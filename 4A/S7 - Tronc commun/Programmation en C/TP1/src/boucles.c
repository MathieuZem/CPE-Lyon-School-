/*
Auteurs : Alix Deleule et Mathieu Zeman
Nom du fichier : boucles.c

Exercice 1.6 [★★]

Objectif :
Ce programme affiche un triangles rectangle avec de * et des #, l'intérieur contient des # et l'extérieur contient des *
*/
#include <stdio.h>

int main() {

    int compteur = 5; /* variable qui joue sur le paramétrage du programme */
printf("\nLa taille du triangle est de %i\n\n",compteur);

// Programme fait avec la boucle for
    for (int i = 1; i <= compteur; i++) { /* La boucle for est constituer de la déclaration de la variable, de la condition sur la boucle et de l'incrémentation*/
// il y a 4 cas différent
        if (i == compteur){ /* Le cas où on est sur la dernière ligne et qu'on l'on affiche que des étoiles*/
            for (int j = 1; j <= compteur; j++){ /* On boucle autant de fois que la taille du compteur (dernière ligne, taille max du triangle) */
                printf("*");
            }
        }else if (i >= 3) { /* Le cas où on est pas dans la dernière ligne et pas dans les deux premières, c'est donc celui où on met que des # bornée par des * */
            printf("*");
            for (int j = 1; j <= i - 2; j++) {
                printf("#");    
            }
            printf("*");
            
        } else if (i == 1) { /* le cas où on est a la première itération, il n'y a qu'une * */
            printf("*");
        } else {
            printf("**"); /* le cas où on est a la deuxième itération, il y a deux * */
        }
        printf("\n");
    }

    printf("\n");
    
// Programme fait avec la boucle while
    int i = 1;
    while(i <= compteur){
        /* Même principe pour la partie conditonelle algorithme que la boucle for */
        if (i == compteur){
            for (int j = 1; j <= compteur; j++){
                printf("*");
            }
        }else if (i >= 3) {
            printf("*");
            for (int j = 1; j <= i - 2; j++) {
                printf("#");    
            }
            printf("*");
            
        } else if (i == 1) {
            printf("*");
        } else {
            printf("**");
        }
        printf("\n");
        i++;
    }

    printf("\n");


// Programme fait avec la boucle do while
    i = 1;
    do {
        /* Même principe pour la partie conditonelle algorithme que la boucle for */
        if (i == compteur){
            for (int j = 1; j <= compteur; j++){
                printf("*");
            }
        }else if (i >= 3) {
            printf("*");
            for (int j = 1; j <= i - 2; j++) {
                printf("#");    
            }
            printf("*");
            
        } else if (i == 1) {
            printf("*");
        } else {
            printf("**");
        }
        printf("\n");
        i++;
    } while (i <= compteur);
    
    return 0;
}