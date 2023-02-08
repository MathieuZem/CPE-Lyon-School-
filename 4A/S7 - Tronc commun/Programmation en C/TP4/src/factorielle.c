/* 
Auteurs : Alix Deleule et Mathieu Zeman
Exercice 4.5 [★★]

Le but de ce programme est de testez la fonction factorielle avec
différents entiers naturels.
*/

#include "fichier.h"
#include "fichier.c"
#include "operator.h"
#include <stdio.h>
#include <string.h>

//Prédécrlare la fonction factorielle
int factorielle(int);

int main() {
// Initialise le premier entier de test
    unsigned long long int n = 4;
// Initialise la variable de résulatas du calcul
    unsigned long long int res;

// On lance la fonction factorielle et on récupère le résultat que l'on va ensuite afficher
    res = factorielle(n);
    printf("Le factorielle de %lli est : %lli\n",n,res);
// On lance la fonction factorielle avec un autre nombre
    n = 8;
    res = factorielle(n);
    printf("Le factorielle de %lli est : %lli\n",n,res);

//on permet a l'utilisateut de tester la fonction factorielle avec un nombre qu'il choisie
    printf("\nSaisissez un nombre : ");
    scanf("%lli",&n);
    res = factorielle(n);
    printf("\nLe factorielle de %lli est : %lli\n",n,res);
    

    return 0;
}

// fonction factorielle donner par l'énoncer
int factorielle (int num) {
    if (num == 0) {
        return 1;
    } else {
    
    return (num * factorielle (num-1));
    }
}