#ifndef DATE_H
#define DATE_H

#include <iostream>

using namespace std;

class Date
{
    public:
        Date();

        Date(int,int,int);

        int comparer(Date);

        void affiche();

        virtual ~Date();

        int jour,mois,annee;

};

#endif // DATE_H
