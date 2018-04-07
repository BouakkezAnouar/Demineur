#include "Numero.h"
#include "Blanc.h"

Numero::Numero(int n,int c):Case(c),num(n)
{
    switch(n) {
    case 1 : symbole = "1";   break;
    case 2 : symbole = "2";  break;
    case 3 : symbole = "3";   break;
    case 4 : symbole = "4";  break;
    case 5 : symbole = "5";  break;
    case 6 : symbole = "6";  break;
    case 7 : symbole = "7";  break;
    case 8 : symbole = "8";  break;
}

}

Numero::~Numero()
{
    //dtor
}
