#include "Personne.h"

using namespace std;

int Personne::nb_pers=0;

string Personne::getNom() const
{
    return nom;
}

string Personne::getPrenom() const
{
    return prenom;
}

void Personne::setPrenom(const string& nouveau_prenom)
{
    prenom = nouveau_prenom;
}
void Personne::setNom(const string& nouveau_nom)
{
    nom = nouveau_nom;
}
void Personne::affiche() const
{
    cout<<id<<" "<<nom<< " "<<prenom<<" saisi le ";
    date_saisie.affiche();
    cout<<endl;
}
void Personne::saisir()
{
    string temp;

    cout<<"Donnez le nom de la personne : ";
    getline(cin,temp);  //permet de saisir une chaine avec des espaces
    setNom(temp);

    cout<<"Donnez son prenom : ";
    getline(cin,temp);
    setPrenom(temp);
}

Personne::Personne(const string& nom,const  string& prenom):id(nb_pers++)
{
    setNom(nom);
    setPrenom(prenom);
}

Personne::Personne():nom("inconnu"),prenom("inconnu"),id(nb_pers++)
{}

Personne::~Personne()
{
    cout<<"Destruction de :"<<endl;
    affiche();
}

