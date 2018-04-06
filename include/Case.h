#ifndef CASE_H
#define CASE_H
#include <string>


class Case
{
    public:
        Case( std::string s="X" , bool f=false , bool d=false);
        virtual ~Case();
        std::string getSymbole();

    protected:

    protected:
        bool decouverte;
        bool drapeau ;
        std::string symbole;
};

#endif // CASE_H
