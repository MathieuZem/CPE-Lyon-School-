/* 
Auteurs : Alix Deleule et Mathieu Zeman
Exercice 4.7 [★★★]  (fait avec l'aide de Augustin Laprais)
Une erreur de segmentation survient, nous n'avons pas reussi a fixer le probleme

Ce programme permet d'inserer des couleurs dans 
une liste de couleur et d'afficher la liste
*/
#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

/* La fonction insertion prends deux entrées:
pointer d'une couleur RGB et pointeur d'une liste de couleurs
et insère la couleur dans la liste.*/
void insertion (couleur * color, liste_couleurs * list_c) {
	couleur * col = list_c->first;
	printf("test\n");
	while (col!= NULL) {
		color = col->next;
	}
	col = color;
	color->next = NULL;
	return;
}

/*La fonction parcours prend le pointeur
d'une liste de couleurs et affiche les couleurs dans la liste. */
void parcours(liste_couleurs * list_c){
	couleur * col = list_c->first;

	if(col == NULL) {// si liste vide
		printf("List empty\n");
		return;
	}
	
	while(col != NULL) {// affichage
		printf("r: 0x%x g: 0x%x b: 0x%x a: 0x%x \n", col->r,col->g,col->b,col->a);
		col = col->next;
	}
    return;
}

int main(){
	// Creation d'une liste cotenant couleur
    liste_couleurs * list_c;
	for (short i = 0; i < 10; i++) {
    	struct couleur c;
		c.r = rand() % 256;
		c.g = rand() % 256;
		c.b = rand() % 256;
		c.a = rand() % 256;
		insertion(&c, list_c);
	}

	// Affichage de la liste
    parcours(list_c);
    return 0;
}