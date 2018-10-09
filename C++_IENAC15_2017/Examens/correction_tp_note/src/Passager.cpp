#include "Passager.h"

using namespace std;

Passager::Passager(string nom, string prenom, int numTel): Personne(nom, prenom), numTel(numTel) {}

Passager::~Passager() {}

int Passager::getNumTel() const {
    return numTel;
}

void Passager::saisir()
{
    Personne::saisir();
    cout << "Numéro de téléphone : ";
    string temp;
    getline(cin, temp);
    stringstream(temp) >> numTel;
}

void Passager::affiche() const
{
    Personne::affiche();
    cout << "\tNuméro de téléphone : " << numTel << endl;
}
