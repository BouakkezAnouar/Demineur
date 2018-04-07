#include <iostream>
#include "Plateau.h"

using namespace std;

int main()
{
    //cout << "Hello world!" << endl;

    Plateau p(4,4,5)  ;
    p.afficher();
    p.initialiser();
    p.afficher();
    p.placer_chiffres();
    p.afficher();
    return 0;
}
