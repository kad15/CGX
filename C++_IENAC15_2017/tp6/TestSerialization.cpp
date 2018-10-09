#include <iostream>
#include <fstream>
#include "Date.h"
#include "Personne.h"

using namespace std;

int main()
{
	//partie Test Date
     {
        Date d1, * d2= new Date(1,1,2016);
        //sauvegarde
        ofstream ofs("Date.sav");
        {
            boost::archive::text_oarchive oa(ofs);
            oa<<d1;
            oa<<*d2;
        }
        delete d2;

        //chargement
        Date d3,*d4;
        d4 = new Date();
        ifstream ifs("Date.sav");
        {
            boost::archive::text_iarchive ia(ifs);
            ia>>d3>>*d4;
        }

        cout<<"Affichage des dates rechargees"<<endl;
        cout<<d3<<endl<<d4<<endl;

        delete d4;
    }
    //partie Test Personne
    Personne p1;
    p1.setNom("de la vega");
    p1.setPrenom("diego");
    const Personne p2("p2","p2");

    //sauvegarde
    ofstream ofs("Personne.sav");
    {
        boost::archive::text_oarchive oa(ofs);
        oa<<p1;
        oa<<p2;
    }

    //chargement
    Personne p3,*p4;
    p4= new Personne();
    ifstream ifs("Personne.sav");
    {
        boost::archive::text_iarchive ia(ifs);
        ia>>p3>>*p4;
    }

    cout<<"Affichage des Personnes rechargees"<<endl;
    cout<<p3<<*p4<<endl;

    delete p4;


	return 0;
}
