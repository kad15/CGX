#ifndef ANNUAIRE_H
#define ANNUAIRE_H

#include <iostream>
#include <limits>   // utilisé pour vider le buffer d entree
#include <vector>
#include "Personne.h"
#include <sstream>
#include <fstream>


class Annuaire
{

public:
    void gerer();

    Annuaire();

    virtual ~Annuaire();

    string fic_annu;


private:

    vector<Personne> rep;

    void sauvegarder_annuaire(const string&);

    void restaurer_annuaire(const string&);

    void vider_annuaire();

    //methodes gestion menu
    void affiche_menu() const;

    int selection() const;

    void traiter(int);

    //methodes a definir

    void visualiser(string const&);
    // affiche a l ecran l ensemble des contacts

    void ajouter_personne();
    // ajout d un contact

    bool rechercher_personne() const;
    // recherche des contacts selon le nom

    void supprimer_personne();
    //saisie du nom puis affichage de tous les contacts ayant ce nom
    //puis saisie de l'id du contact à supprimer

    void modifier_personne();
    //saisie du nom puis affichage de tous les contacts ayant ce nom
    //puis saisie de l id du contact à supprimer
};

#endif // ANNUAIRE_H
