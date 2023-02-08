/* 
Auteurs : Alix Deleule et Mathieu Zeman
*/
#include <stdio.h>
#include "operator.h"
#include "fichier.h"

int main() {
    // Exercice 4.1 [★] 
    int num1 = 45; /* initialise le premier nombre */
    int num2 = 5; /* initialise le deuxième nombre */
    int op = '-'; /* choix de l'opération*/

    switch (op)
    {
        case '+':
            printf("%d%c%d=%d\n", num1,op,num2,add(num1,num2)); /* On applique l'opération choisie */
            break;
        case '-':
            printf("%d%c%d=%d\n", num1,op,num2,soust(num1,num2)); /* On applique l'opération choisie */
            break;
        case '*':
            printf("%d%c%d=%d\n", num1,op,num2,mult(num1,num2)); /* On applique l'opération choisie */
            break;
        case '/':
            printf("%d%c%d=%d\n", num1,op,num2,div(num1,num2)); /* On applique l'opération choisie */
            break;
        case '%':
            printf("%d%c%d=%d\n", num1,op,num2,mod(num1,num2)); /* On applique l'opération choisie */
            break;
        case '&':
            printf("%d%c%d=%d\n", num1,op,num2,et(num1,num2)); /* On applique l'opération choisie */
            break;
        case '|':
            printf("%d%c%d=%d\n", num1,op,num2,ou(num1,num2)); /* On applique l'opération choisie */
            break;
        case '~':
            printf("%c%d=%d\n", op,num1,neg(num1)); /* On applique l'opération choisie */
            break;
        default:
            break;
    }

    //Exercice 4.2 [★] 
    lire_fichier("operator.h");
    char message[100];
    printf("\nEcrivez un message : ");
    fgets(message,sizeof(message),stdin);
    ecrire_dans_fichier("ecrire.txt",message);
    
    return 0;
}