#ifndef DATE_H
#define DATE_H

#include <iostream>

using namespace std;

class Date
{
    int jour,mois,annee;

    public:
        Date();

        Date(int,int,int);

        int comparer(const Date&) const ;

        void affiche() const ;

        virtual ~Date();

};

#endif // DATE_H
