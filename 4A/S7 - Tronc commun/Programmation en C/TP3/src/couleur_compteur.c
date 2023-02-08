/*
Auteurs : Alix Deleule et Mathieu Zeman
Nom du fichier : couleur_compteur.c

Exercice 3.7 [★★★]

Objectif:
Ce programme stocke 100 couleurs dans un tableau et affiche les couleurs distinctes et leur nombre dans le tableau.
Pour cet exercice, il y a trois étapes principales :
1. Tout d'abord, créez une structure pour stocker les détails d'une couleur : R, G, B et A
2. Créez un tableau de 100 couleurs en utilisant la structure ci-dessus.
3. Comptez le nombre de couleurs distinctes.

Lors de l'affichage des tableaux, il y a leur indice sur la gauche pour mieux se reperer dedans
*/
#include <stdio.h> // importation d'une librairie standard en C
#include <stdlib.h> // importation d'une librairie pour la fonction rand afin d'obtenir des entiers "aleatoires"

// Creation de la structure couleur qui contient des valeurs de 0 a 255 pour les 4 canaux(r,g,b,a)
struct couleur
{
    short r;
    short g;
    short b;
    short a;
};

typedef struct couleur couleur; // On peut utiliser 'couleur' au lieu de 'struct couleur'

// Cette fonction retourne 1 si les couleurs c1 et c2 sont egales par valeurs sinon 0(simule ==)
unsigned int eqCol(couleur c1, couleur c2){
    return c1.a == c2.a && c1.r == c2.r && c1.g == c2.g && c1.b == c2.b;
}

//Cette fonction retourne l'indice de la couleur dans le tableau de couleur, si elle n'est pas presente -1 est retourne
int getInd(couleur color, couleur *colors){
    for (int i = 0; i < 100; i++){
        if (eqCol(color,colors[i])){
            return i;
        }
    }
    return -1;
}

int main(){
    couleur cols[100];// Creation d'un tableau de 100 couleurs
    couleur cols2[100];// Creation d'un tableau qui contiendra les memes couleurs que cols mais sans repetition
    
    for (int i = 0; i < 100; i++){ // Remplissage du tableau par des valeurs aleatoires entre 0 et 255
        couleur c;
        c.r = rand()%256;//on peut reduire 256 a 4 pour mieux voire les repetitions
        c.g = rand()%256;
        c.b = rand()%256;
        c.a = rand()%256;
        cols[i] = c;

        cols2[i].r = -1;//initialisation de toutes les couleurs de cols2 avec les valeurs rouges a -1
    }

    int effectif[100];// tableau d'entier contenant les effectifs du tableau cols2(ex. si a l'indice 2 
    //il y a un 3 alors cela signifie qu'il y a 3 repetitions de la couleur a l'indice 2 de cols2)
    int j = 0;//cette indicateur d'indice permet de savoir ou placer la prochaine nouvelle couleur
    // On compte le nombre de couleurs repete
    for(int i = 0; i < 100; i++){
        couleur c = cols[i];
        int x = getInd(c,cols2);
        printf("%i\t%x %x %x %x\t\t%i\n", i, c.r, c.g, c.b, c.a, x);
        if(x>=0){//si couleur deja dans cols2
            effectif[x] += 1;
        }else{
            cols2[j]=cols[i];
            effectif[j]=1;
            j++;
        }
    }
    //Affichage sans repetitions
    printf("\n\n");
    for (short i = 0; i < 100; i++) { // Affichage de toutes les couleurs avec leurs valeurs en hexa
        couleur c = cols2[i];
        if (c.r == -1){break;}
        printf("%i\t%x %x %x %x\t\t%i\n",i, c.r, c.g, c.b, c.a, effectif[i]);
    }

    return 0;
}

















