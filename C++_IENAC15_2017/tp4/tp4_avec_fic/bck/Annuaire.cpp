#include "Annuaire.h"
#include <algorithm>
#include <string>
#include <fstream>
//#define identifier replacement
//#define FIC_ANNU "annuaire.txt"

using namespace std;




Annuaire::Annuaire()
{
    string tmp;
    fic_annu="annuaire.txt";
    cout<< "Saisir le nom de l'annuaire ou taper enter pour conserver le fichier par defaut "<<fic_annu<<" : "<<endl;
    getline(cin,tmp);
    if (!tmp.empty())
        fic_annu=tmp;
    ifstream flux(fic_annu);

    if(flux.is_open())
    {
        restaurer_annuaire(fic_annu);

    }
    else
    {
        cout<<"Pas d'annuaire " << fic_annu<<". Creation du fichier "<<fic_annu<<endl;
        flux.open(fic_annu,ios::out);
        cout<<"Alimenter l'annuaire"<<endl;

    }

}

void Annuaire::vider_annuaire()
{
    ofstream flux(fic_annu);
    rep.clear();
}


void Annuaire::sauvegarder_annuaire(const string& fic)
{
    ofstream flux(fic); // ouverture en ecriture le fichier est effacé et recréé
    if(rep.empty())
    {
        cout<< "pas de personne saisie. L'annuaire est vide !"<<endl;

        return;
    }
    sort(rep.begin(),rep.end());



    if(flux)  //On teste si tout est OK
    {
        for (const Personne& p : rep)
            flux<< p.getId()<<" " << p.getNom() << " "<< p.getPrenom()<<endl;
    }
    else
    {
        cout << "ERREUR fichier "<<  fic << endl;
    }
    flux.close();
}


void Annuaire::restaurer_annuaire(const string& fichier)
{
    if(fichier.empty()) cout<<"Annuaire vide !"<<endl;
    int id;
    string nom, prenom;
    Personne p;
    ifstream flux(fichier);

    if(flux)
    {
        string ligne; //Une variable pour stocker les lignes lues

        while(getline(flux, ligne)) //Tant qu'on n'est pas à la fin, on lit
        {
            // cout << ligne << endl;
            istringstream(ligne)>> id>>nom>>prenom;
            p.setId(id);
            p.setNom(nom);
            p.setPrenom(prenom);
            rep.push_back(p);
        }
        cout <<endl;
        cout<< "L'annuaire "<<fichier<<" est charge : "<<endl;
    }
    else
    {
        cout << "ERREUR: pas d'annuaire." << endl;
    }
    return ;
}


void Annuaire::visualiser(const string& fichier)  // visualise l'annuaire rep chargé en mémoire
{
    if(rep.empty()) cout << "Annuaire vide ! "<<endl;

    for(Personne const& p : rep)
        cout<<p;
//    vector<Personne>::const_iterator it;
//    for(it=rep.begin(); it!=rep.end(); it++)
//    {
//
//        it->affiche();
//    }

}

void Annuaire::ajouter_personne()
{

    Personne p;
    cin>>p;
    rep.push_back(p);
    sort(rep.begin(),rep.end());
}



bool Annuaire::rechercher_personne() const
{
    bool trouve = false;

    if(rep.empty())
    {
        cout << "Annuaire vide ! "<<endl;
        return trouve;
    }
    string temp;
    cout<<"Nom de la personne a rechercher : ";


    getline(cin,temp);


    for(const Personne& p : rep)
    {
        if(temp==p.getNom())
        {
            cout<<p;
            trouve =true;
        }
    }
    if(!trouve)
        cout<<"Personne non-trouvee"<<endl;
    return trouve;
}


void Annuaire::supprimer_personne()
{
//saisie du nom puis affichage de tous les contacts ayant ce nom
//puis saisie de l'id du contact à supprimer


    if(rechercher_personne())
    {
        cout <<"Saisir l'id de la personne a supprimer : ";
        string temp;
        int id_saisi;
        getline(cin,temp);
        stringstream(temp)>>id_saisi;

        for(vector<Personne>::iterator it = rep.begin(); it!=rep.end(); ++it)
        {
            if(id_saisi==it->getId())
            {
                rep.erase(it);
                cout << "personne id = "<< id_saisi<< " erased !"<<endl;
                sort(rep.begin(),rep.end());
                return;
            }
        }
    }
}

void Annuaire::modifier_personne()
{
    if(rechercher_personne())
    {
        cout <<"id de la personne a modifier : ";
        string temp;
        int id_saisi;
        getline(cin,temp);
        stringstream(temp)>>id_saisi;

        for(Personne& p : rep)
        {
            if(id_saisi==p.getId())
            {
                cout<<"nouveau nom : ";
                getline(cin,temp);
                if (temp!="") p.setNom(temp);
                cout<<"nouveau prenom : ";
                getline(cin,temp);
                if (temp!="") p.setPrenom(temp);
                sort(rep.begin(),rep.end());

                return;
            }
        }
    }
}


void Annuaire::traiter(int choix)
{
    switch(choix)
    {
    case 0:
        cout<<"A bientot !";
        break;
    case 1:
        visualiser(fic_annu);
        break;
    case 2:
        ajouter_personne();
        break;
    case 3:
        rechercher_personne();
        break;
    case 4:
        supprimer_personne();
        break;
    case 5:
        modifier_personne();
    case 6:
        sauvegarder_annuaire(fic_annu);
    case 7:
        restaurer_annuaire(fic_annu);

        break;
    default:
        cerr<<"erreur de programmation";
    }
}

int Annuaire::selection() const
{
    int resultat;
    bool selection_valide;
    do
    {
        cout<<endl<<"Votre choix : ";
        cin>>resultat;  // si saisie d'un caractere boucle infinie
        selection_valide = (resultat>=0 && resultat<=7);
        if(!selection_valide)
        {
            cout<<"erreur saisie "<<endl;
        }
        // pour vider le tampon d'entree
        cin.clear(); // effacer les bits d'erreurs
        cin.ignore( numeric_limits<streamsize>::max(), '\n' ); // supprimer la ligne erronée dans le buffer

    }
    while(!selection_valide);

    return resultat;
}

void Annuaire::affiche_menu() const
{
    cout<<"\t\t 0 Quitter"<<endl;
    cout<<"\t\t 1 Visualiser Annuaire"<<endl;
    cout<<"\t\t 2 Ajouter Personne"<<endl;
    cout<<"\t\t 3 Rechercher Personne"<<endl;
    cout<<"\t\t 4 Supprimer Personne"<<endl;
    cout<<"\t\t 5 Modifier Personne"<<endl;
    cout<<"\t\t 6 sauvegarder annuaire"<<endl;
    cout<<"\t\t 7 restaurer annuaire"<<endl;
}

void Annuaire::gerer()
{
    bool quitter;
    do
    {
        cout<<endl;
        affiche_menu();
        int choix = selection();
        quitter = choix == 0;
        traiter(choix);
    }
    while (!quitter);
}

Annuaire::~Annuaire()
{
    sauvegarder_annuaire(fic_annu);
}



/////////////////////////////////////

// basic file operations
//#include <iostream>
//#include <fstream>
//using namespace std;
//
//int main () {
//  ofstream myfile;
//  myfile.open ("example.txt");
//  myfile << "Writing this to a file.\n";
//  myfile.close();
//  return 0;
//}
//
//ofstream myfile;
//myfile.open ("example.bin", ios::out | ios::app | ios::binary);
//
//ios::in	Open for input operations.
//ios::out	Open for output operations.
//ios::binary	Open in binary mode.
//ios::ate	Set the initial position at the end of the file.
//If this flag is not set, the initial position is the beginning of the file.
//ios::app	All output operations are performed at the end of the file, appending the content to the current content of the file.
//ios::trunc	If the file is opened for output operations and it already existed, its previous content is deleted and replaced by the new one.
