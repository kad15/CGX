#include "Personne.h"

using namespace std;

int Personne::no_id=0;

bool Personne::operator <(const Personne& p ) const
{
    return getNom()<p.getNom();
}

istream& operator>>(istream& i, Personne& p)
{
    p.saisir();
    return i;
}
ostream& operator<<(ostream& o,const Personne& p)
{
    p.affiche();
    return o;
}

string Personne::getNom() const
{
    return nom;
}

string Personne::getPrenom() const
{
    return prenom;
}

int Personne::getId() const
{
    return id;
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
    cout<<id<<" "<<nom<< " "<<prenom<<" saisi le "<<dateSaisie<<endl;
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

Personne::Personne(const string& nom, const string& prenom):id(Personne::no_id++)
{
   setNom(nom);
   setPrenom(prenom);
}
Personne::~Personne()
{
	//cout<<"Destruction de :"<<endl;
	//affiche();
}
