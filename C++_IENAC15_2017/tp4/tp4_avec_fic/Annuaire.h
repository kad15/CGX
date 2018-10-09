#ifndef ANNUAIRE_H
#define ANNUAIRE_H

#include <iostream>
#include <vector>
#include <limits>   // utilisé pour vider le buffer d entree
#include <sstream>
#include <algorithm>
#include <fstream>

#include "Personne.h"

class Annuaire
{
    std::vector<Personne> annu;

public:
    void gerer();

    ~Annuaire();

private:

    void sauvegarder() const ;

    void restaurer();

    //methodes gestion menu
    void affiche_menu() const;

    int selection() const;

    void traiter(int);

    //methodes a definir

    void visualiser() const;
    // affiche a l ecran l ensemble des contacts

    void ajouter_personne();
    // ajout d un contact

    bool rechercher_personne() const ;
    // recherche des contacts selon le nom

    void supprimer_personne();
    //saisie du nom puis affichage de tous les contacts ayant ce nom
    //puis saisie de l id du contact à supprimer

    void modifier_personne();
    //saisie du nom puis affichage de tous les contacts ayant ce nom
    //puis saisie de l id du contact à supprimer
};

#endif // ANNUAIRE_H
