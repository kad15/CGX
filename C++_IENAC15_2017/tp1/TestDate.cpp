#include <iostream>
#include "Date.h"

using namespace std;

int main()
{
    //partie1
    Date d1;
    Date d2(14,7,1789);
    {
        Date d3(12,6,2001);
        d3.affiche();
    }
    d1.affiche();
    d2.affiche();

	cout<<"Comparaison de dates :"<<endl;
	//partie2
	if(d1.comparer(d2)<0)
    {
        d1.affiche();
        d2.affiche();
    }
    else
    {
        d2.affiche();
        d1.affiche();
    }

	return 0;
}
