#ifndef CASE_H
#define CASE_H
#include <string>
using namespace std ;

class Case
{
    public:
        Case( int color=7, string s="#" , bool f=false , bool d=false );
        virtual ~Case();
        string getSymbole();
         int getColor();
         bool getDecouverte();
         bool getDrapeau();
         void setDrapeau(bool t);
         void setDecouverte(bool b);
        void afficher();

    protected:

    protected:
        bool decouverte;
        bool drapeau ;
        string symbole;
        int color ;

};

#endif // CASE_H
