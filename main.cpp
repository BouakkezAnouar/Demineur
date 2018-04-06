#include <iostream>
#include "Plateau.h"

using namespace std;

int main()
{
    //cout << "Hello world!" << endl;

    Plateau p(8,7,15)  ;

    p.initialiser();
    p.afficher();
    return 0;
}
