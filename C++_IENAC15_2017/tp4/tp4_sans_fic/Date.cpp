#include "Date.h"
#include <time.h>

Date& Date::operator++()
{
    this->jour++;
    return *this;
}

int Date::operator<(const Date& d) const
{
    return this->comparer(d)==-1;
}

istream& operator>>(istream& i, Date& d)
{
    int moisTemp;
    i>>d.jour>>moisTemp>>d.annee;
    d.mois = moisTemp-1;    //valeur mois compris entre 0 et 11

    return i;
}

ostream& operator<<(ostream& o,const Date* d)
{
    d->affiche();
    return o;
}

ostream& operator<<(ostream& o, const Date& d)
{
    d.affiche();
    return o;
}

Date::Date()
{
    //cout<<"appel constructeur Date  sans parametre"<<endl;
    time_t t;
    time(&t);
    tm date= *localtime(&t);
    jour=date.tm_mday;
    mois=date.tm_mon; //de 0 à 12  cf affichage
    annee=1900+date.tm_year;
}

Date::Date(int j,int m,int a):jour(j),mois(m),annee(a)
{
    //cout<<"appel constructeur Date avec parametre"<<endl;
}

void Date::affiche() const
{
    string t[] = {"janvier","fevrier","mars","avril","mai","juin",
                  "juillet","aout","septembre","octobre","novembre","decembre"
                 };
    cout<<jour<<" "<<t[mois]<<" "<<annee;
}

int Date::comparer(const Date& d) const
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
    //cout<<"appel destructeur Date sur : ";
    //affiche();
}
