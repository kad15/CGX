#ifndef VOL_H
#define VOL_H

#include <list>
#include <iostream>

#include "Date.h"

using namespace std;

typedef struct{
    string nom;
}Passager;

class Vol
{
    int id;
    static int no_id;
    Date dateVol;
    string indicatif;
    string aerodrome_dep;
    string aerodrome_arr;
    int capacite;

    list<Passager> passagers;


    public:
        void affiche() const;
        void saisir();
        int getCapacite() const;
        int getId() const;
        void ajouter_passager();

        Vol();
        virtual ~Vol();

        //bool operator<(const Vol& v) const; // Pour le tri, compare par dates des vols
    protected:
    private:
        bool verifier_indicatif(string ind);
};

istream& operator>>(istream& i, Vol& v);
ostream& operator<<(ostream& o,const Vol& v);



#endif // VOL_H
