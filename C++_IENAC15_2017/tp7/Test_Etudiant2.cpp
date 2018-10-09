#include "Etudiant.h"

using namespace std;

int main(){

	Etudiant e0;
	e0.saisir();
	e0.affiche();

    Etudiant e1("E1","e1",2);   //le troisieme paramètre correspond au nombre de matieres suivies
    cout<<"Saisie des matieres de l etudiant e1"<<endl;
    e1.saisirMatieres();	// saisir comme matieres c et c++ en y affectant deux notes

    //Construction d un Etudiant e2 a partir de e1
    Etudiant e2(e1);

    //Modification des notes de e1
    e1.setNote("c++",10); //le premier parametre correspond au nom de la matiere, le second à la note
    e1.setNote("c",11);

    //affichage des 2 etudiants
    e1.affiche();
    e2.affiche();	//les moyennes de e1 et e2 doivent normalement etre differentes

    return 0;
}
