#ifndef PASSAGER_H
#define PASSAGER_H

#include "Personne.h"
#include <sstream>

class Passager : public Personne
{
    public:
        Passager(string nom="inconnu", string prenom="inconnu", int numTel=-1);
        virtual ~Passager();

        int getNumTel() const;
        void affiche() const;
        void saisir();

    private:
        int numTel;
};

#endif // PASSAGER_H
