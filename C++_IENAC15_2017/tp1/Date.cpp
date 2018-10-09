#include "Date.h"

Date::Date()
{
    cout<<"appel constructeur Date  sans parametre"<<endl;
    time_t t;
    time(&t);
    tm date= *localtime(&t);
    jour=date.tm_mday;
    mois=date.tm_mon; //de 0 à 11  cf affichage
    annee=1900+date.tm_year;
}

Date::Date(int j,int m,int a):jour(j),mois(m-1),annee(a)
{   cout<<"appel constructeur Date avec parametre"<<endl;}

void Date::affiche()
{
    string t[] = {"janvier","fevrier","mars","avril","mai","juin",
                    "juillet","aout","septembre","octobre","novembre","decembre"};
    cout<<jour<<" "<<t[mois]<<" "<<annee<<endl;
}

int Date::comparer(Date d)
{
	if (annee!= d.annee)
    {
        if(annee<d.annee)
            return -1;
        else
            return 1;
    }
	else if (mois != d.mois)
        return ((mois<d.mois)?-1:1);	// utilisation ici de l operateur ternaire
    else if (jour!=d.jour)
        return ((jour<d.jour)?-1:1);
    else
        return 0;
}

Date::~Date()
{
    cout<<"appel destructeur Date sur : ";
    affiche();
}
