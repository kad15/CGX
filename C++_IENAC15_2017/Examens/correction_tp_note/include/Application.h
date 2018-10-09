#ifndef APPLICATION_H
#define APPLICATION_H

#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <sstream>

#include "Vol.h"

using namespace std;

class Application
{
    list<Vol> appli;
    map<int,Passager> comptesPassagers;

    public:
        void gerer();
        virtual ~Application();
    protected:
    private:
        void affiche_menu() const;
        int selection() const;
        void traiter(int);
        void visualiser() const;
        void proposer_vol();
        void visualiser_dispo() const;
        void reserver_place();
        void inscrire_passager();
        void visualiser_passagers() const;
};

#endif // APPLICATION_H
