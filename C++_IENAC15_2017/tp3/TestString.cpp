#include "String.h"

using namespace std;

#define string MaString::string

int main()
{
    cout<<"saisie d'une chaine :";

	string s0;
    cin>>s0;
    cout<<s0<<endl;

    string s1("toto");
    cout<<s1<<endl;

    string s2="toto";
    cout<<s2<<endl;

    const char* toto ="toto";


    if(s2==s1)
        cout<<"test1 Ok"<<endl;

    if(s1==toto)
        cout<<"test2 Ok"<<endl;

    if(toto==s1)
        cout<<"test3 Ok"<<endl;

    s2[0]='a';
    cout<<s2<<endl;
    if(s1!=s2)
        cout<<"test 7 Ok"<<endl;
    if(s2<s1)
        cout<<"test 8 Ok"<<endl;
    if(s1>s2)
        cout<<"test 9 Ok"<<endl;
    if(s1<=s2)
        cout<<"probleme"<<endl;

    s1+=s2;
        cout<<s1<<endl;
    string s3("test");

    s2=s2+s3;
        cout<<s2<<endl;

    return 0;
}
