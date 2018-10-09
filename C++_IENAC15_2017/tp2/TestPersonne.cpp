// test de la classe Personne

#include "Personne.h"

using namespace std;

int main() {

    Personne* group[4];

    //Affectation d'un objet dynamique créé via le constructeur sans paramètre :
    group[0] = new Personne();
    group[0]->saisir();
    cout<<"La premiere personne saisie s'appelle "<<group[0]->getNom()<<" "<<group[0]->getPrenom()<<endl;

    //Affectation d'un objet statique créé via le constructeur sans paramètre :
    Personne p1;
    p1.setNom("p1");
    p1.setPrenom("p1");
    group[1] = &p1;
    //Affectation d'un objet dynamique créé via le constructeur avec paramètres :
    group[2] = new Personne("p2","p2");
    //Affectation d'un objet automatique créé via le constructeur avec paramètres :
    Personne p3("p3","p3");
    group[3] = &p3;

    //Affichage des personnes du tableau :
    cout<<"Contenu du tableau"<<endl;
    for (int i = 0; i < 4; i++)
        group[i]->affiche();
    cout << endl;

    //Appels destructeurs des objets dynamiques
    delete(group[0]);
    delete(group[2]);

    return 0;
}

