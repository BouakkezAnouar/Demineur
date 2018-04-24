#include "Jeu.h"
#include "Plateau.h"
#include<iostream>
#include<stdio.h>
#include <fstream>
#include <bits/stdc++.h>
#include <string>

#include <windows.h>
void ClearScreen()   {   HANDLE        hStdOut;   CONSOLE_SCREEN_BUFFER_INFO csbi;   DWORD                      count;   DWORD                      cellCount;   COORD                      homeCoords = { 0, 0 };    hStdOut = GetStdHandle( STD_OUTPUT_HANDLE );   if (hStdOut == INVALID_HANDLE_VALUE) return;    /* Get the number of cells in the current buffer */   if (!GetConsoleScreenBufferInfo( hStdOut, &csbi )) return;   cellCount = csbi.dwSize.X *csbi.dwSize.Y;    /* Fill the entire buffer with spaces */   if (!FillConsoleOutputCharacter(     hStdOut,     (TCHAR) ' ',     cellCount,     homeCoords,     &count     )) return;    /* Fill the entire buffer with the current colors and attributes */   if (!FillConsoleOutputAttribute(     hStdOut,     csbi.wAttributes,     cellCount,     homeCoords,     &count     )) return;    /* Move the cursor home */   SetConsoleCursorPosition( hStdOut, homeCoords );   }
void coutcc(int color, string output){
HANDLE handle= GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute( handle, color);
cout<< output;
SetConsoleTextAttribute( handle,7 );
}
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
/*
coutcc(3,"=======================================================================================================");cout <<endl;
coutcc(3,"        ==================================Jeu Mineur BY NAW=============================");cout<<endl;
coutcc(3,"=======================================================================================================");cout<<endl;
*/




     printf("\n\n\n\n");
      coutcc(60,"                                                                                                           \n\n");
            coutcc(9,"                /\\    /\\     ---------         /\\         /    --------      ---------     \n");
            coutcc(3,"               /  \\  /  \\        |            /  \\       /     |             |           \n");
            coutcc(14,"              /    \\/    \\       |           /    \\     /      | -----       |--------     \n");
            coutcc(13,"             /            \\      |          /      \\   /       |                      |        \n");
        coutcc(10,"            /              \\  ---------    /        \\ /        | ------       ------- |    \n\n\n");
           coutcc(7,"                                                                          BY BOUAKKEZ ANOUAR");
        coutcc(60,"                                                                                                           \n\n\n\n");


cout <<endl<<endl ;

cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~Menu~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
cout <<endl;
}


bool Jeu::jouer(int l, int c ,int m )
{ int  a ,ligne,colonne;
    int ch ;
bool perdu ,gagner;
   ClearScreen();
        Plateau p(l,c,m);
        p.initialiser();

            gagner=false ;
            perdu=false ;
            ClearScreen();
            int nb_mines_rec = nb_mines ;
            p.afficher(nb_coups,nb_mines_rec,score);
                 do { //ClearScreen();
                            //p.afficher(nb_coups,nb_mines,score);
                            //p.afficher_tous();
                            //p.afficher_tous();

                         //do {cout <<"choix : " ;cin >> ligne >> colonne ;
                         //   } while ( ligne-1>=l ||  colonne-1 >= c);

                            do {
                                cout << "1. choix colonne a decouvrir"<<endl  ;
                                cout<<  "2. Drapeau"<<endl ;
                                cin >> ch ;
                            }while(ch!=1 && ch!=2);

                            if (ch==1)
                            {
                                ClearScreen();
                                p.afficher(nb_coups,nb_mines_rec,score);
                                do {cout <<"choix : " ;cin >> ligne >> colonne ;
                                    } while ( ligne-1>=l ||  colonne-1 >= c);

                                     a = p.choisir(ligne-1,colonne-1);

                             if (a==2) {score++; nb_coups++; }
                              if (a==0){score+=3; nb_coups++;}
                             ClearScreen();
                              p.afficher(nb_coups,nb_mines_rec,score);
                             // p.afficher_tous();
                            if (a == 1) perdu = true ;
                            else { if (p.testGagne()==0) gagner=true ;}

                            }

                            else {
                                    ClearScreen();
                                p.afficher(nb_coups,nb_mines_rec,score);
                                do {cout <<"Drapeau : " ;cin >> ligne >> colonne ;
                                    } while ( ligne-1>=l ||  colonne-1 >= c);



                                    int r = p.setDrapeau(ligne-1,colonne-1,nb_mines_rec);

                                    if (r==-1) nb_mines_rec+=1;
                                    else if (r==1 ) nb_mines_rec-=1;

                                        if (nb_mines_rec==0) {if (p.testGagne()==0) gagner=true ;}

                                      ClearScreen();
                              p.afficher(nb_coups,nb_mines_rec,score);
                            }




                } while (perdu==false && gagner==false);

                if (gagner==true) return true;
                    else return false ;

}


void inserer_score(string nom ,int score){
  string const nomFichier("C:/Users/asus/Desktop/2ème-semestre/Programmation-Orienté-Objet(C++)/Tps/c++/projet_POO/jeu.txt");
    ofstream monFlux(nomFichier.c_str(), ios::app);

    if(monFlux)
    {
        monFlux << nom << ",";
        monFlux <<score << endl;
    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
    }
       monFlux.close();
}




vector<string> split (string s , char a){
string r= "";
vector<string> result ;
s+=a;
    for (int i=0 ; i<s.size() ;i++ )
    {
        if (s[i]!=a)
        r +=s[i];
        else {
            result.push_back(r);
            r="";
        }
    }
    return result ;
}


void Jeu::lire_score()
{
    vector<string>v ;
multimap<int,string> m ;
string i ;
string j;
int s =1 ;


     ifstream fichier("C:/Users/asus/Desktop/2ème-semestre/Programmation-Orienté-Objet(C++)/Tps/c++/projet_POO/jeu.txt");

   if(fichier)
   {
      string ligne;
      while(getline(fichier, ligne))
      {
             v=split(ligne,',');
             i = v[1];
             int value = atoi(i.c_str());
             j=v[0];
             m.insert ( std::pair<int,string>(-value,j) );
      }
        cout << "                         ------------------------------------------------------"<<endl;
        coutcc(10, "                        |         Nom              |               score       |\n");
        cout << "                         ------------------------------------------------------"<<endl;
      for(multimap<int,string> :: iterator it = m.begin();s<4 ; it++ )
         {cout <<"                        |       " <<s<<". "<<it->second;
         int lg =32-(it->second).size();
            for(int l=0; l< lg;l++) cout <<" ";
                s++;
              cout << -it->first<<endl ;}

   }
   else
   {
      cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
   }

}


void Jeu::jeu(){
    bool gagner ; string nom ;
    int choix,choix1,choix2,choix3,lignes,colonnes,nb_mines ,l,c,m;




     printf("\n\n\n\n");
      coutcc(60,"                                                                                                           \n\n");
            coutcc(9,"                /\\    /\\     ---------         /\\         /    --------      ---------     \n");
            coutcc(3,"               /  \\  /  \\        |            /  \\       /     |             |           \n");
            coutcc(14,"              /    \\/    \\       |           /    \\     /      | -----       |--------     \n");
            coutcc(13,"             /            \\      |          /      \\   /       |                      |        \n");
        coutcc(10,"            /              \\  ---------    /        \\ /        | ------       ------- |    \n\n\n");
           coutcc(7,"                                                                          BY BOUAKKEZ ANOUAR\n");
        coutcc(60,"                                                                                                           \n\n\n\n");



            coutcc(10, "                                         Nom  : ");
            cin >> nom ;


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
                       else  if (choix1==6) continue ;
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
                                inserer_score(nom,score);

                                do{
                                    if (gagner==true)  {cout<<endl<<"felicitations vous avez gagner !!!!";  coutcc(14,":) "); cout <<"bravo !!"<<endl<<endl;
                                    }
                                    else   {cout<<endl<<"vous avez perdu! "; coutcc(14,":( !"); cout << endl ;}
                                    cout<<"1. retourner au menu principale"<<endl;
                                    cout<<"2.quitter"<<endl;

                                cout << "choix : "; cin >> choix2 ;
                                   }while(choix2 <1 || choix2 >2);

                                if (choix2==2)  choix=3;
                                else continue ;

                           }


            }

            else  if (choix == 2) {
                    ClearScreen();
                    affiche_menu();
                     lire_score();
                        cout <<endl<<endl ;
                     cout <<"1. nouvelle Partie"<<endl;
                     cout <<"3. quitter"<<endl;
                    cin >> choix;
             }

            else  choix=3 ; //quitter


        }while(choix!=3);



}

