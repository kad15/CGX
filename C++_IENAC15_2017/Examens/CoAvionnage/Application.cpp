#include "Application.h"
#include <algorithm>

void Application::proposer_vol()
{
    Vol temp;
	cin>>temp;
	appli.push_back(temp);
}

void Application::visualiser() const
{
	for(const Vol& v : appli){
        cout<<v;
	}
}

void Application::reserver_place()
{
    int id_temp;
    cout<<"Donner l'id du vol à reserver : ";
    cin>>id_temp;
    cin.get();

    for(Vol& v : appli){
        if(id_temp==v.getId()){
            if(v.getCapacite()>0){
                v.ajouter_passager();
            } else {
                cout<<"Ce vol n'a plus de places libres"<<endl;
            }
        }
	}
}

void Application::visualiser_dispo() const
{
    for(const Vol& v : appli){
        if(v.getCapacite()!=0){
            cout<<v;
        }
	}
}

void Application::traiter(int choix)
{
    switch(choix){
        case 0:
            cout<<"A bientot !";
            break;
        case 1:
            proposer_vol();
            break;
        case 2:
            visualiser();
            break;
        case 3:
             reserver_place();
             break;
        case 4:
             visualiser_dispo();
             break;
        default:
            cerr<<"erreur de programmation";
    }
}

int Application::selection() const
{
    int resultat;
    bool selection_valide;
    do{
        cout<<endl<<"Votre choix : ";
        cin>>resultat;  // si saisie d'un caractere boucle infinie
        selection_valide = (resultat>=0 && resultat<=4);
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

void Application::affiche_menu() const
{
    cout<<"\t\t 0 Quitter"<<endl;
    cout<<"\t\t 1 Proposer un nouveau vol"<<endl;
    cout<<"\t\t 2 Visualiser les vols"<<endl;
    cout<<"\t\t 3 Réserver une place"<<endl;
    cout<<"\t\t 4 Visualiser les vols avec des places disponibles"<<endl;
}

void Application::gerer()
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

Application::~Application()
{
    //dtor
}
