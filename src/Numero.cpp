#include "Numero.h"
#include "Blanc.h"

Numero::Numero(int n,int c):Case(c),num(n)
{
    switch(n) {
    case 1 : symbole = "1"; color=9 ;   break; //27 le drapeau bleu
    case 2 : symbole = "2"; color=2; break; // green
    case 3 : symbole = "3";  color=13; break;//g
    case 4 : symbole = "4"; color=6; break;
    case 5 : symbole = "5"; color=11; break;
    case 6 : symbole = "6";  color=5; break;
    case 7 : symbole = "7";  break;
    case 8 : symbole = "8";  break;
}

}

Numero::~Numero()
{
    //dtor
}
