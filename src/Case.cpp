#include "Case.h"
#include<string>
using namespace std ;
Case::Case(int c, string s, bool f,bool d):decouverte(d),drapeau(f),symbole(s),color(c)
{

}

Case::~Case()
{
    //dtor
}

string Case::getSymbole(){
    return symbole;
}
int Case::getColor(){
    return color;
}
bool Case::getDecouverte(){
    return decouverte;
}

void Case::setDecouverte(bool b)
{
    decouverte = b ;
}

