#include <iostream>
#include "Date.h"
//#include "Duree.h"

using namespace std;

int main()
{
	Date d1;
    Date d2(14,7,1789);
	Date* d3 = new Date(12,6,2001);

    //affichages
    cout<<d1<<endl;
    cout<<d1<<"\t"<<d2<<"\t"<<d3<<endl;
    cout<<d3<<endl;

    //saisie et affichage
    cout<<"Saisissez une date selon le format jj mm aaaa :";
    cin>>d1;
    cout<<"Date modifiée :"<<endl<<d1<<endl;

	//comparaison
	cout<<"Dates triées :"<<endl;
	if(d1<d2)
        cout<<d1<<endl<<d2<<endl;
    else
        cout<<d2<<endl<<d1<<endl;

    cout<<"Date incrémentée :"<<endl<<++d1<<endl;

	delete d3;

	return 0;
}
