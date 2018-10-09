// test de la classe Personne

#include "Personne.h"

using namespace std;

int main() {

    Personne* pers[4];

    //Affectation d'un objet dynamique créé via le constructeur sans paramètre :
    pers[0] = new Personne();
    cout<<"Saisie d'une personne"<<endl;
    cin>>*pers[0];


    //Affectation d'un objet statique créé via le constructeur sans paramètre :
    Personne p1;
    p1.setNom("p1");
    p1.setPrenom("p1");
    pers[1] = &p1;
    //Affectation d'un objet dynamique créé via le constructeur avec paramètres :
    pers[2] = new Personne("p2","p2");
    //Affectation d'un objet automatique créé via le constructeur avec paramètres :
    const Personne p3("p3","p3");

    //Affichage des personnes du tableau :
    cout<<"Contenu du tableau"<<endl;
    for (int i = 0; i < 3; i++)
        cout<<*pers[i];
    cout<<p3;
    cout << endl;

    //Appels destructeurs des objets dynamiques
    delete(pers[0]);
    delete(pers[2]);

    return 0;
}

