#include "Vol.h"

int Vol::no_id=0;

Vol::Vol():id(Vol::no_id++)
{
    //ctor
}

Vol::~Vol()
{
    //dtor
}

/* Les attributs :
    int id;
    static int no_id;
    Date dateVol;
    string indicatif;
    string aerodrome_dep;
    string aerodrome_arr;
    int capacite;

    list<Passager> passagers; */


void Vol::affiche() const
{
    cout<< " Vol #" << id << " : " << dateVol << " sur " << indicatif  \
            << " de " << aerodrome_dep << " vers " << aerodrome_arr \
            << " avec " << capacite + passagers.size() << " passagers maximum." << endl;

    if (!passagers.size()) {
        cout << "\t(pas de passagers réservés pour le moment)" << endl;
    }

    else {
        cout << '\t' << passagers.size() << " passager(s) réservé(s) :" << endl;

        for (const Passager* p : passagers) {
            cout << "\t\t- " << p->getNom() << " (tél : " << p->getNumTel() << ")" << endl;
        }
    }
}

/* Renvoie true si indicatif de la forme X-XXXX */
bool Vol::verifier_indicatif(string ind)
{
    if(ind.size() != 6)
        return false;
    if(ind[1] != '-')
        return false;

    return true;
}

void Vol::saisir()
{
    cout << " Le vol à remplir est le #" << id << endl;
    cout << " A quelle date se déroule le vol ? (format JJ MM AAAA) " << endl;
    cin >> dateVol;

    bool indic_correct;
    do {
        cout << " Entrez l'indicatif du vol : " << endl;
        cin >> indicatif;
        indic_correct = verifier_indicatif(indicatif);
        if(!indic_correct)
        {
             cin.clear();
             cout << "L'indicatif entré est incorrect, il doit ^etre de la forme X-XXXX. Recommencez svp..." << endl;
        }
    } while(!indic_correct);

    cout << " Aérodromes de départ puis arrivée: " << endl;
    cin >> aerodrome_dep >> aerodrome_arr;

    cout << " Nombre maximal de passagers ? " << endl;
    cin >> capacite;

    // Résumé
    cout << " Merci d'avoir renseigné le vol. Pour rappel, les informations sont : " << endl;
    affiche();
}

int Vol::getCapacite() const
{
    return capacite;
}

int Vol::getId() const
{
    return id;
}

void Vol::ajouter_passager(const Passager& p)
{
    if(capacite <= 0)
    {
        cout << "Impossible d'ajouter un passager, capacité max (" \
             << capacite << ") de l'avion déjà atteinte !" << endl;
        return;
    }

    passagers.push_back(&p);   //sauvegarde de l'adresse de l'objet stocké dans comptePassagers
    capacite--;
}

istream& operator>>(istream& i, Vol& v)
{
    v.saisir();
    return i;
}

ostream& operator<<(ostream& o,const Vol& v)
{
    v.affiche();
    return o;
}


