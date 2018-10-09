#include "Annuaire.h"

using namespace std;
void Annuaire::modifier_personne(){
	if(rechercher_personne()){
		string temp;
		int tempId;
		cout<<"id de la personne à modifier :";
		getline(cin,temp);
		stringstream(temp)>>tempId;

		for(const Personne&p : annu)
            if(tempId==p.getId()){
                cout<<p;
                //tri si nom modifié
                sort(annu.begin(),annu.end());
                return;
            }
    }
}
void Annuaire::supprimer_personne(){

	if(rechercher_personne()){
		string temp;
		int tempId;
		cout<<"id de la personne à supprimer :";
		getline(cin,temp);
		stringstream(temp)>>tempId;

        for(vector<Personne>::iterator it=annu.begin();it!=annu.end();it++)
            if(tempId==it->getId()){
                annu.erase(it);
                return;
            }
	}
}
bool Annuaire::rechercher_personne() const{

	bool trouve = false;
	string temp;
	cout<<"Nom de la personne à rechercher : ";
	getline(cin,temp);

	// recherche sur un vector trié
	for(vector<Personne>::const_iterator it =annu.begin();it!=annu.end() && !trouve ;it++)
        if(temp==it->getNom()){
            trouve = true;
            while(it!=annu.end() && it->getNom()==temp)
                cout<<*it++;    //affichage puis incrementation de l iterateur
        }

	if(!trouve)
			cout<<"Personne non-trouvee"<<endl;

	return trouve;
}

void Annuaire::ajouter_personne(){
	Personne temp;
	cin>>temp;
	annu.push_back(temp);
	//tri
	sort(annu.begin(),annu.end());
}

void Annuaire::visualiser() const {
	for(const Personne& p : annu)
        cout<<p;
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
             rechercher_personne();
             break;
        case 4:
             supprimer_personne();
             break;
        case 5:
             modifier_personne();
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
        selection_valide = (resultat>=0 && resultat<=5);
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
    cout<<"\t\t 3 Rechercher Personne"<<endl;
    cout<<"\t\t 4 Supprimer Personne"<<endl;
    cout<<"\t\t 5 Modifier Personne"<<endl;
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
