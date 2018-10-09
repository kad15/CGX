#ifndef _ETUDIANT_H
#define _ETUDIANT_H

#include <list>
#include <sstream> //pour transformer une chaine en flottant

#include "Personne.h"

class Etudiant : public Personne
{
    typedef struct{
        string nom;
        float note;
    }matiere;

    // Attributs
    int nbMatieres;
    //nombre de matieres suivies

    list<matiere> matieres ;
	// liste des matieres suivies

    // Implementation
    public:

    Etudiant(string nom="inconnu", string prenom="inconnu",int nbre_matieres_suivies=0);
    // constructeur avec (ou sans) parametres.

    virtual ~Etudiant();

    void affiche() const;
    //affiche les caracteristiques d'un Etudiant

    void saisir();
    //saisie d un Etudiant

    void saisirMatieres();
    //saisie des matieres

    float getMoyenneGlobale() const;
    // retourne la moyenne globale de l'etudiant.

    void setNote(string matiere, float note);
    // ajoute une note a la matiere specifiee.

};   // fin de la classe

#endif
