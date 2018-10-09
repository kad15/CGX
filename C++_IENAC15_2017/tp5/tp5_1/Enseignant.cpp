#include "Enseignant.h"

using namespace std;

void Enseignant::affiche() const
{
    Personne::affiche();
	cout<<"Cout Enseignant : "<<getCoutTotal()<<endl;
}

void Enseignant::saisirMatieres()
{
	cout<<"saisie des matieres"<<endl;
	for (int i=0; i< nbMatiere; i++)
	{
        matiere temp;

		cout << "matiere " << i << " : ";
	    getline(cin,temp.nom);
	    cout << "nombre d heures : ";
	    cin>>temp.nbheures;
	    cout <<"tarif horaire : ";
	    cin>>temp.tarif;
	    cin.get();

	    mat.push_back(temp);
    }
}

void Enseignant::saisir()
{
    Personne::saisir();
    cout<<"nombre de matieres enseignees : ";
    cin>>nbMatiere;
    cin.get();

    if(nbMatiere)
        saisirMatieres();
}

float Enseignant::getCoutTotal() const
{
	float som=0;

    for (list<matiere>::const_iterator it=mat.begin() ; it!= mat.end();it++)
    {
        som = som + it->nbheures * it->tarif;
	}

	return som;
}

Enseignant::~Enseignant()
{
    cout<<"appel destructeur enseignant"<<endl;
}

Enseignant::Enseignant(string nom, string prenom,int nbMat): Personne(nom,prenom),nbMatiere(nbMat)
{
	//rien à faire
}
