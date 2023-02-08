#include <iostream>
#include <string>
#include <list>

struct Personne{
    std::string prenom;
    std::string nom;

    Personne(){
        prenom = "inconnue";
        nom = "inconnue";
    }

    Personne(std::string pprenom, std::string pnom){
        prenom = pprenom;
        nom = pnom;
    }
};

class Etudiant : public Personne{
public:
    int note;
    
    Etudiant(std::string pprenom, std::string pnom, int pnote) : Personne(pprenom,pnom){
        note = pnote;
    }
    Etudiant(std::string pprenom, std::string pnom) : Personne(pprenom,pnom){
        note = 0;
    }

};

void denomer(Personne p)
{
    std::cout<<p.nom<<" "<<p.prenom<<std::endl;
}

int main()
{
    Etudiant A("Franck","Ribery",2);
    Etudiant B("Einstein","Albert",18);
    Personne C("Huster","Francis");
    std::list<Personne> L;
    L.push_back(A);
    L.push_front(B);
    L.push_front(C);
    for(Personne p : L)
        denomer(p);
    return 0;
}