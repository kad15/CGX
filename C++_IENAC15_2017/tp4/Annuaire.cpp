#include "Annuaire.h"

using namespace std;

void Annuaire::traiter(int choix)
{
    switch(choix){
        case 0:
            cout<<"A bientot !";
            break;
        case 1:
            visualiser();
            break;
        case 2:
            ajouter_personne();
            break;
        default:
            cerr<<"erreur de programmation";
    }
}
int Annuaire::selection() const
{
    int resultat;
    bool selection_valide;
    do{
        cout<<endl<<"Votre choix : ";
        cin>>resultat;  // si saisie d'un caractere boucle infinie
        selection_valide = (resultat>=0 && resultat<=2);
        if(!selection_valide)
        {
            cout<<"erreur saisie "<<endl;
        }
        // pour vider le tampon d'entree
        cin.clear(); // effacer les bits d'erreurs
        cin.ignore( numeric_limits<streamsize>::max(), '\n' ); // supprimer la ligne erronée dans le buffer

    }while(!selection_valide);

    return resultat;
}
void Annuaire::affiche_menu() const
{
    cout<<"\t\t 0 Quitter"<<endl;
    cout<<"\t\t 1 Visualiser Annuaire"<<endl;
    cout<<"\t\t 2 Ajouter Personne"<<endl;
}
void Annuaire::gerer()
{
    bool quitter;
    do{
        cout<<endl;
        affiche_menu();
        int choix = selection();
        quitter = choix == 0;
        traiter(choix);
    }while (!quitter);
}

Annuaire::~Annuaire(){}
