#include "Application.h"
#include <algorithm>

void Application::proposer_vol()
{
    Vol temp;
	cin >> temp;
	appli.push_back(temp);
}

void Application::visualiser() const
{
	for(const Vol& v : appli){
        cout << v;
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
                int id_passager;
                cout << "Donner le numéro du compte passager : ";
                cin >> id_passager;
                cin.get();

                std::map<int,Passager>::iterator it = comptesPassagers.find(id_passager);
                if(it!=comptesPassagers.end()){
                    v.ajouter_passager(it->second);
                }else{
                    cout << "Le numéro saisi ne correspond à aucun passager" << endl;
                }
            } else {
                cout << "Ce vol n'a plus de places libres"<<endl;
            }
            return;
        }
	}
    cout << "L'id saisi ne correspond à aucun vol" << endl;
}

void Application::visualiser_dispo() const
{
    for(const Vol& v : appli){
        if(v.getCapacite()!=0){
            cout<<v;
        }
	}
}

void Application::inscrire_passager()
{
    Passager p;
    cin >> p;
    comptesPassagers[p.getId()] = p ;
    cout << "Bienvenue " << p.getPrenom() \
         << " ! Votre numéro de compte est : " << p.getId();

    // j'utilise l'identifiant de Personne pour l'identifiant du compte
    // on aurait pu utiliser un vector et considérer l'index comme identifiant
    // pour éviter de chercher linéairement le passager dans la liste
    // (mais plus limitant si on ajoute la possibilité de supprimer un compte...)
}

void Application::visualiser_passagers() const
{
    for(map<int,Passager>::const_iterator it = comptesPassagers.begin(); it!=comptesPassagers.end();it++)
        cout<<it->second;
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
        case 5:
             inscrire_passager();
             break;
        case 6:
             visualiser_passagers();
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
        selection_valide = (resultat>=0 && resultat<=6);
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
    cout<<"\t\t 5 Créer un compte passager"<<endl;
    cout<<"\t\t 6 Visualiser les comptes passagers"<<endl;
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
