#include <iostream>
#include <string>

struct Conteneur{
    
    int entier;
    std::string mot;

    void affiche(){
        std::cout<<"Je contient l'entier "<<entier<<" et le mot "<<mot<<std::endl;

    }

};

int main()
{
std::string variable="Ma variable";
variable += " a moi.";
std::cout<<variable<<std::endl;

Conteneur conteneur_1;
conteneur_1.entier = 6;
conteneur_1.mot = "coucou";

conteneur_1.affiche();

Conteneur conteneur_2 = {4,"bonjour"};
conteneur_2.affiche();

Conteneur tableau[]={ {18,"poisson"},
{12,"charcuterie"},
{2,"soda"},
{0,"eau"} };
for(auto valeur : tableau)
    valeur.affiche();


return 0;
}
