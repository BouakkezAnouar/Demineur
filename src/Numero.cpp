#include "Numero.h"
#include "Blanc.h"

Numero::Numero(int n):Case(),num(n)
{
    switch(n) {
    case 1 : symbole = "1";
    case 2 : symbole = "2";
    case 3 : symbole = "3";
    case 4 : symbole = "4";
    case 5 : symbole = "5";
    case 6 : symbole = "6";
}
}

Numero::~Numero()
{
    //dtor
}
