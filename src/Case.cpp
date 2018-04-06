#include "Case.h"
#include<string>
Case::Case(std::string s,bool f,bool d):decouverte(d),drapeau(f),symbole(s)
{

}

Case::~Case()
{
    //dtor
}

std::string Case::getSymbole(){
    return symbole;
}
