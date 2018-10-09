#ifndef _PERSONNE_H
#define _PERSONNE_H

#include <iostream>

using std::string;

#include "Date.h"

class Personne
{
    static int nb_pers;
    //compteur du nombre de personnes

    string nom;
    // le nom de la personne(objet string).

    string prenom;
    // le prenom de la personne (objet string).

    const int id;
    //identifiant personne

    const Date date_saisie;
    // date ou la personne a été construite

    public:
    Personne();
    // construit une personne non initialisee (donc non valide).

    Personne(const string& nom, const string& prenom);
    // construit une personne valide.

    string getNom() const;
    //retourne le prenom de la personne

    void setNom(const string& nouveau_nom);
    // change le nom de la personne.

    string getPrenom() const;
    // retourne le prenom de la personne.

    void setPrenom(const string& nouveau_prenom);
    // change le prenom de la personne.

    void saisir();
    // saisie une personne

    void affiche() const;
    //affiche une personne

    ~Personne();
    // detruit cette personne et ses ressources allouees.

};   // fin de la classe Personne


#endif
