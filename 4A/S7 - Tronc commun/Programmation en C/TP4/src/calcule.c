/* 
Auteurs : Alix Deleule et Mathieu Zeman
Exercice 4.4 [★★]

Ce programme créé une commande calcule qui utilise l'interface en
ligne de commande. Il y a trois options pour cette commande: opérateur
(+, -, *, /, %, &, |, ~), numéro un et numéro deux. Par exemple, si
l'utilisateur écrit "calcule 4-5", le programme affiche "4-5=-1"
*/
#include <stdio.h>
#include <string.h>
#include "operator.h"

int main(){
    //Recuperation de la commande de l'utilisateur
    int num1, num2;
    char op;
    char command[30];
    char message[100];
    printf("Entrez une commande ( sous la forme : calcule 4-5 ): \n");
    scanf("%s",command);

    if ( strcmp(command,"calcule") == 0 ){// si la commande est bien calcule
        // recuperation des parametres
        scanf("%d",&num1);
        scanf("%c",&op);
        scanf("%d",&num2);

        //Calcule et affichage
        printf("\n");
        switch (op) {
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
    } else { // si la commande n'est pas calcule
        printf("%s is not a command\n",command);
    }
    return 0;
}