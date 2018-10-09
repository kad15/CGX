#include "Etudiant.h"

using namespace std;

int main(){

    Etudiant e0;
    cin>>e0;

    cout<<"Etudiant e1"<<endl;
    Etudiant e1("E1","e1",2);     //le troisieme paramètre correspond au nombre de matieres suivies
    cout<<"Saisie des matieres de l etudiant e1"<<endl;
    e1.saisirMatieres();	// saisir comme matieres c et c++

    Etudiant e2(e1); 	//appel constructeur par recopie

    Etudiant e3,e4;
    e4=e3=e1;	//appel surcharge operateur affectation

    e1.setNote("c++",10); //le premier parametre correspond au nom de la matiere, le second à la note
    e1.setNote("c",11);

    cout<<e0<<e1<<e2<<e3<<e4<<endl;

    return 0;
}
