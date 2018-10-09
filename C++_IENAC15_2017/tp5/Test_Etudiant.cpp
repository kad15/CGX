#include "Etudiant.h"
#include <cstdlib>
#include <cstdio>

using namespace std;

int main(){

    //on utilise ici un tableau de pointeurs sur personnes pour stocker les etudiants
	Personne *t[4];

	cout<<"Saisie de l'etudiant e0"<<endl;
	Etudiant e0;
    cin>>e0;
    cout<<e0;
    t[0]=&e0;

    Etudiant e1("E1","e1",2);   //le troisieme parametre correspond au nombre de matieres suivies
    cout<<"Saisie des matieres de e1"<<endl;
    e1.saisirMatieres();
    t[1] = &e1;

    cout<<"Saisie d'un etudiant e2 en memoire dynamique"<<endl;
    t[2] = new Etudiant();
    cin>>*t[2];				//on doit saisir ici aussi le nombre de matiere, les matieres, les notes...

    cout<<"Saisie des matieres de e3"<<endl;
    t[3] = new Etudiant("E3","e3",2);
    //t[3].saisirMatieres();  erreur car saisirMatieres n existe pas dans Personne
    ((Etudiant*)t[3])->saisirMatieres();

    e0.setNote("c",18); //le premier parametre correspond au nom de la matiere, le second à la note
    e1.setNote("c++",10);
    e1.setNote("c",15);

    for(int i=0;i<4;i++)
    	cout<<*t[i];    //on doit avoir egalement les caracteristiques de l etudiant

    delete t[2];	//le destructeur de Personne doit etre virtual !!!
    delete t[3];

    return 0;
}
