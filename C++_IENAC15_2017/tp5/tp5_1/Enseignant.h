#ifndef ENSEIGNANT_H
#define ENSEIGNANT_H

#include <list>

#include "Personne.h"

typedef struct{
    string nom;
    float nbheures;
    float tarif;
}matiere;

class Enseignant : public Personne
{
    // Attributs
	int nbMatiere;

	float coutHoraire;
	// par defaut egal a 10

    list<matiere> mat ;
	// liste des matieres enseignees

    public:
    Enseignant(string nom="inconnu", string prenom="inconnu",int nbre_matieres_ens=0);
    // constructeur Enseignant

    virtual ~Enseignant();
    //destructeur

    void affiche() const;
    //affiche les caracteristiques d'une Personne plus le cout total
    //(on pourrait egalement afficher l'ensemble des matieres suivies avec le nombre d heures...)

    void saisir();
    //saisie du nombre de matieres et du cout horaire, appelle saisirMatieres

    void saisirMatieres();
    //saisie des n matieres

    float getCoutTotal() const;
    // retourne le cout total de  l Enseignant

};   // fin de la classe

#endif
