#include <iostream>
#include "Plateau.h"
#include <conio.h>

using namespace std;

void jouer()
{
    int l,c,m ;
    bool perdu=false;
        cout << "lignes : ";
        cin >>l ;
        cout <<endl<< "colonnes : ";
        cin >>c ;
        cout <<endl << "nombres de mines : ";
        cin >>m ;
        Plateau p(l,c,m);
        p.afficher();
        p.initialiser();
        p.placer_chiffres();

    cin >> l >> c ;

    int a = p.choisir(l-1,c-1);
    p.afficher();
    p.afficher_tous();





    }



int main()
{

    jouer();
    return 0;
}


