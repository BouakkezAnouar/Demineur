#include "Jeu.h"
#include "Plateau.h"
#include<iostream>

#include <windows.h>
void ClearScreen()   {   HANDLE                     hStdOut;   CONSOLE_SCREEN_BUFFER_INFO csbi;   DWORD                      count;   DWORD                      cellCount;   COORD                      homeCoords = { 0, 0 };    hStdOut = GetStdHandle( STD_OUTPUT_HANDLE );   if (hStdOut == INVALID_HANDLE_VALUE) return;    /* Get the number of cells in the current buffer */   if (!GetConsoleScreenBufferInfo( hStdOut, &csbi )) return;   cellCount = csbi.dwSize.X *csbi.dwSize.Y;    /* Fill the entire buffer with spaces */   if (!FillConsoleOutputCharacter(     hStdOut,     (TCHAR) ' ',     cellCount,     homeCoords,     &count     )) return;    /* Fill the entire buffer with the current colors and attributes */   if (!FillConsoleOutputAttribute(     hStdOut,     csbi.wAttributes,     cellCount,     homeCoords,     &count     )) return;    /* Move the cursor home */   SetConsoleCursorPosition( hStdOut, homeCoords );   }

using namespace std;

Jeu::Jeu(int s, int nb_c ):score(s),nb_coups(nb_c)
{
    //ctor
}

Jeu::~Jeu()
{
    //dtor
}

void Jeu::setNb_mines(int a){
    nb_mines =a ;
}

void Jeu::affiche_menu(){

cout<<"======================================================================================================="<<endl;
cout<<"        ==================================Jeu Mineur BY NAW============================="<<endl;
cout<<"======================================================================================================="<<endl;

cout <<endl<<endl ;

cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~Menu~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
cout <<endl;
}


bool Jeu::jouer(int l, int c ,int m )
{ int  a ,ligne,colonne;
bool perdu ,gagner;
   ClearScreen();
        Plateau p(l,c,m);
        p.initialiser();

            gagner=false ;
            perdu=false ;
                 do { ClearScreen();
                            p.afficher(nb_coups,nb_mines,score);
                            //p.afficher_tous();
                         do {cout <<"choix : " ;cin >> ligne >> colonne ;
                            } while ( ligne-1>=l ||  colonne-1 >= c);

                             a = p.choisir(ligne-1,colonne-1);

                             if (a==2) {score++; nb_coups++; }
                              if (a==0){score+=3; nb_coups++;}
                             ClearScreen();
                              p.afficher(nb_coups,nb_mines,score);
                            if (a == 1) perdu = true ;
                           if (nb_mines==p.nb_couverte()) gagner=true ;

                } while (perdu==false && gagner==false);

                if (gagner==true) return true;
                    else return false ;

}


void Jeu::jeu(){
    bool gagner ;
    int choix,choix1,choix2,choix3,lignes,colonnes,nb_mines ,l,c,m;

    do {


        do{ ClearScreen();
            affiche_menu();
            cout <<"1. nouvelle Partie"<<endl;
            cout <<"2. Meilleure score"<<endl;
            cout <<"3. quitter"<<endl;

            cout << "choix : ";   cin >> choix ;
              }while(choix <1 || choix >3);

            if  (choix == 1)
            {
                  do{ClearScreen();
                    affiche_menu();
                    cout <<"1. facile"<<endl;
                    cout <<"2. Normal"<<endl;
                    cout <<"3. Difficile"<<endl;
                    cout <<"4. Expert"<<endl;
                    cout <<"5. Partie personalisé(choix de lignes colonnes et mines)"<<endl;
                    cout <<"6. Retourner au menu principale"<<endl;

                            cout << "choix : "; cin >> choix1 ;
                        }while(choix1 <1 || choix1 >6);

                        ClearScreen();
                        if (choix1 ==1)  {l=5;c=5;m=2;setNb_mines(m);}
                        else if(choix1==2) {l=10;c=10;m=20;setNb_mines(m);}
                        else if(choix1==3) {l=20;c=20;m=100;setNb_mines(m);}
                        else if (choix1==4) {l=30;c=30;m=400;setNb_mines(m);}
                        else if (choix1==5){

                                   do { ClearScreen();affiche_menu();
                                        cout << "lignes : ";
                                        cin >>l ;
                                        cout <<endl<< "colonnes : ";
                                        cin >>c ;
                                        cout <<endl << "nombres de mines : ";
                                        cin >>m ;
                                   }while(l>30 || c >30 || m >l*c);
                                    setNb_mines(m);
                              }

                        if (choix1==1 || choix1==2 || choix1 ==3 || choix1==4 || choix1==5)
                           {
                               gagner =jouer(l,c,m);

                                do{
                                    if (gagner==true) cout<<endl<<"felicitations vous avez gagner !!!! :) bravo !!"<<endl<<endl;
                                    else cout<<endl<<"vous avez perdu! :( "<<endl;
                                    cout<<"1. retourner au menu principale"<<endl;
                                    cout<<"2.quitter"<<endl;

                                cout << "choix : "; cin >> choix2 ;
                                   }while(choix2 <1 || choix2 >2);

                                if (choix2==2)  choix=3;
                                else continue ;

                           }


            }


           // else if (choix==2) meuilleure_score();

            else {
                choix=3 ; //quitter
            }


        }while(choix!=3);



}

