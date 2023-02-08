/* 
Auteurs : Alix Deleule et Mathieu Zeman
Exercice 2.6 [★★] 

Objectif:
Ce porgramme gere des données d'étudiant.e.es (5 étudiant.e.es) en utilisant struct. 
Les détails pour chaque étudiant.e restent les mêmes comme pour l'exercice précédent
(nom, prénom etc.).

*/
#include <stdio.h> // importation d'une librairie standard en C

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
    // Creation de 5 etudiants
    etudiant etu1 = {"Alix","Deleule","Cupertino",15,20};
    etudiant etu2 = {"Mathieu","Zeman","Mionnay",12,16};
    etudiant etu3 = {"Emma","Begard","Aix",10,20};
    etudiant etu4 = {"Guillaume","Domelier","Mouson",11,5};
    etudiant etu5 = {"Audrey","Nicolle","Bron",21,21};
    
    // Creation d'un tableau contenant les 5 etudiants
    etudiant data[5] = {etu1, etu2, etu3, etu4, etu5};


    // Affichage des donnees de chaque eleves sous forme d'une phrase.
    for (int i = 0; i < 5; i++) {
        printf("L'élève ce prénommant %s %s habitant à %s dont les notes de ProgC et SE sont respectivement %d, %d\n", data[i].prenom, data[i].nom, data[i].ville, data[i].note_progC,data[i].note_SE);
        printf("\n");
    }

    return 0;
}