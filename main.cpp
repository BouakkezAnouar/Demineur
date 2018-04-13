#include <iostream>
#include "Plateau.h"
#include <conio.h>

using namespace std;

void jouer()
{
    int l,c,m,lignes,colonnes,a ;
    bool perdu=false;
        cout << "lignes : ";
        cin >>lignes ;
        cout <<endl<< "colonnes : ";
        cin >>colonnes ;
        cout <<endl << "nombres de mines : ";
        cin >>m ;
        Plateau p(lignes,colonnes,m);

        p.initialiser();
         p.afficher();


         p.afficher_tous();
         int x = 0;

         do {
                perdu =false ;


         do {

           do {
                cout <<"choix : " ;
    cin >> l >> c ;
           } while ( l-1>=lignes ||  c-1 >= colonnes);

     a = p.choisir(l-1,c-1);
    if (a == 1) perdu = true ;
    p.afficher();
    p.afficher_tous();
    if (perdu==true)
        cout <<"vous aver perdu"<<endl ;

         } while (perdu!=true);

         cout <<" veuiller rejouez tapez 1" <<endl;
         cout << "veuiller quitter tapez 2 "<<endl ;

        cin >> x ;

}while(x!=2);

}

int main()
{

    jouer();
    return 0;
}


