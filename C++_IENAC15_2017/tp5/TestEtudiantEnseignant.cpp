#include "Etudiant_Enseignant.h"
#include "Etudiant.h"
using namespace std;

class Etudiant_ENAC : public Etudiant
{
    public :
    Etudiant_ENAC(string nom, string prenom):Etudiant(nom,prenom,0){}
};

int main(){

    Etudiant_Enseignant ee1;
    cin>>ee1;
    cout<<ee1;

    Etudiant_Enseignant ee2("ee2","ee2",2,1);	// param : nbre matieres suivies, nbre matieres enseignees
    cout<<"Saisie matieres suivies ee2"<<endl;
    ee2.Etudiant::saisirMatieres();
    cout<<"Saisie matieres enseignees ee2"<<endl;
    ee2.Enseignant::saisirMatieres();
    cout<<ee2;

    Etudiant e1 ("e1","e1",0);
    cout<<e1;

    Etudiant_ENAC e2("e2","e2");
    cout<<e2;     //probleme ?

    return 0;
}
