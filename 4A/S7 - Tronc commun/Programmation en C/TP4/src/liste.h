/* 
Auteurs : Alix Deleule et Mathieu Zeman
Exercice 4.7 [★★★]  (fait avec l'aide de Augustin Laprais)

Ce programme permet intialise des fonctions et creer 2 struct
Une pour contenir une couleur c'est a dire 4 valeurs(RGBa)
Une pour contenir une liste de couleurs
*/ 
struct couleur{
        short r, g, b, a;
        struct couleur * next;
};
typedef struct couleur couleur;

struct liste_couleurs{
        struct couleur *first;
};
typedef struct liste_couleurs liste_couleurs;

void insertion (struct couleur *, liste_couleurs *);                
void parcours (liste_couleurs *);