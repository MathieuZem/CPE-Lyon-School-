/*
Auteurs : Alix Deleule et Mathieu Zeman
Nom du fichier : couleurs.c

Exercice 2.7 [★★]

Objectif:
Une couleur en format RGBA contient 4 valeurs : rouge (R), vert (G),
bleu (B) et alpha (A). Chaque valeur est un octet. 

Créez un programme *couleurs.c* en utilisant struct. 
Ensuite, créez et initialisez un
tableau de 10 couleurs. Pensez à initialiser les couleurs en notation
hexadécimale (r : 0xef, g : 0x78 etc.).
*/

#include <stdio.h> // importation d'une librairie standard en C

// Creation de la structure couleur qui contient des valeurs de 0 a 255 pour les 4 canaux(r,g,b,a)
struct couleur
{
    short r;
    short g;
    short b;
    short a;
};

typedef struct couleur couleur; // On peut utiliser 'couleur' au lieu de 'struct couleur'

int main(){
    couleur cols[10] = {// Creation d'un tableau de 10 couleurs
        {0xef, 0xef, 0xef, 0xef},
        {0xad, 0xef, 0xef, 0xef},
        {0xef, 0x45, 0xef, 0xef},
        {0xef, 0xef, 0xe7f, 0xef},
        {0xef, 0xef, 0xcf, 0xef},
        {0xef, 0xef, 0xe5, 0xef},
        {0xef, 0xef, 0xef, 0xef},
        {0xef, 0xef, 0xef, 0xee},
        {0xef, 0xf7, 0xef, 0xef},
        {0xef, 0xef, 0xbf, 0xef}
    };

    for (short i = 0; i < 10; i++) { // Affichage de toutes les couleurs avec leurs valeurs en hexa
        printf("%x %x %x %x\n",cols[i].r,cols[i].g,cols[i].b,cols[i].a);
    }
    return 0;
}