#include "Annuaire.h"

using namespace std;


void Annuaire::visualiser() const{

vector<Personne>::const_iterator it;
for(it=rep.begin();it!=rep.end();it++)
{

   it->affiche();
}

}


      void Annuaire::ajouter_personne(){

      Personne toto;
       string nom,prenom;
      cout << "nom ? "<<endl;
      cin>> nom;
      toto.setNom(nom);
       cout << "prenom ? "<<endl;
      cin>> nom;
      toto.setPrenom(prenom);
      rep.push_back(toto);
      }

bool Annuaire::rechercher_personne() const {
    string nom;
    bool boule = false;
    cout<< "taper nom de la personne à rechercher/supprimer : ";
    cin>> nom;
    for (const Personne & p:rep)
    {
        if(p.getNom()==nom) {
        p.affiche();
        boule = true;
  }
  return boule;

}

}

void Annuaire::supprimer_personne(){
//saisie du nom puis affichage de tous les contacts ayant ce nom
//puis saisie de l'id du contact à supprimer
bool boule = rechercher_personne();




}

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
               case 3:
            supprimer_personne();
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
    cout<<"\t\t 3 Supprimer Personne"<<endl;
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
