/* 
Auteurs : Alix Deleule et Mathieu Zeman
Exercice 4.3 [★★]

Ici, on cherche a crée un programme qui sauvegarde les noms, prénoms, adresses,
et les notes dans un fichier etudiant.txt pour 5 étudiant(e)s (une ligne
pour chaque étudiant(e)). De plus, le programme recevra les informations pour chaque
étudiant de l'utilisateur au travers de la commande scanf pour le programme
*/

#include "fichier.h"
#include "operator.h"
#include <stdio.h>
#include <string.h>
struct etudiant// Creation de la structure etudiant qui contient le nom, prenom, la ville, et 2 notes
{
    char prenom[30];
    char nom[30];
    char ville[30];
    int note_progC;
    int note_SE;
};

typedef struct etudiant etudiant;// On peut utiliser 'etudiant' au lieu de 'struct etudiant'

int main(){
    // Creation d'un tableau contenant les 5 etudiants
    etudiant etudiants[5];

// Dans cette boucle, on viens itérer 5 fois la demmande a l'utilisateur des données de
// de ses étudiant pour ensuite les ajouter a la struct de l'étudiant.
    for (int i = 0; i < 5; i++) {
        printf("\nSaisissez un etudiant (prenom nom ville note1 note2): ");
        
        etudiant etu;
        char buffer[100];
        int note;

        scanf("%s",buffer);
        strcpy(etu.prenom, buffer);

        scanf("%s",buffer);
        strcpy(etu.nom, buffer);

        scanf("%s",buffer);
        strcpy(etu.ville, buffer);

        scanf("%d",&note);
        etu.note_progC = note;

        scanf("%d",&note);
        etu.note_SE = note;

    }

    char contenu[1000] = "";

// on viens ici concatener les infos donnée par rl'utilisateur dans une string qui 
// servira a être inscrite dans le fichier etudiant.txt
    for (int i = 0; i < 5; i++) {
        char message[100];
        memset(message,0,sizeof(message));
        sprintf(message,"%s %s %s %d %d",etudiants[i].prenom,etudiants[i].nom, etudiants[i].ville, etudiants[i].note_progC, etudiants[i].note_SE);
        strcat(contenu,message);
        strcat(contenu,"\n");
    }
// On va utiliser la fonction ecrire_dans_fichier qui sert a copiée une chaine de caractère
// dans un fichier.
    ecrire_dans_fichier("etudiant.txt",contenu);
    return 0;
}