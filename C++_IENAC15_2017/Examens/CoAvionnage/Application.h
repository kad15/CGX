#ifndef APPLICATION_H
#define APPLICATION_H

#include <iostream>
#include <limits>
#include <list>
#include <sstream>

#include "Vol.h"

using namespace std;

class Application
{
    std::list<Vol> appli;

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
};

#endif // APPLICATION_H
