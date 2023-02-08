/*
Auteurs : Alix Deleule et Mathieu Zeman
Nom du fichier : opérateurs2.c

Exercice 1.8 [★★★]

Objectif :
Ce programme effectue un calcul précis déterminer a l'aide d'une variable opérateur qui en fonction de sa valeur, changera le calcul effectuer.
*/
#include <stdio.h>

int main() {

    int num1 = 45; /* initialise le premier nombre */
    int num2 = 5; /* initialise le deuxième nombre */
    int op = '-'; /* choix de l'opération*/

    switch (op)
    {
        case '+':
            printf("%d%c%d=%d", num1,op,num2,num1+num2); /* On applique l'opération choisie */
            break;
        case '-':
            printf("%d%c%d=%d", num1,op,num2,num1-num2); /* On applique l'opération choisie */
            break;
        case '*':
            printf("%d%c%d=%d", num1,op,num2,num1*num2); /* On applique l'opération choisie */
            break;
        case '/':
            printf("%d%c%d=%d", num1,op,num2,num1/num2); /* On applique l'opération choisie */
            break;
        case '%':
            printf("%d%c%d=%d", num1,op,num2,num1%num2); /* On applique l'opération choisie */
            break;
        case '&':
            printf("%d%c%d=%d", num1,op,num2,num1&&num2); /* On applique l'opération choisie */
            break;
        case '|':
            printf("%d%c%d=%d", num1,op,num2,num1||num2); /* On applique l'opération choisie */
            break;
        case '~':
            printf("%c%d=%d", op,num1,~num1); /* On applique l'opération choisie */
            break;
        default:
            break;
    }

    return 0;
}
