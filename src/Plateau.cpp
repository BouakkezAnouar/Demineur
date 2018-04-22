#include <cstdlib>
#include<stdio.h>
#include <iostream>
#include <windows.h>
#include <ctime>
#include <string>
#include "Plateau.h"
#include "Drapeau.h"
#include "Mine.h"
#include "Blanc.h"
#include "Numero.h"
#include <map>
#include<typeinfo>
#include <utility>      // std::pair

 //void ClearScreen()   {   HANDLE                     hStdOut;   CONSOLE_SCREEN_BUFFER_INFO csbi;   DWORD                      count;   DWORD                      cellCount;   COORD                      homeCoords = { 0, 0 };    hStdOut = GetStdHandle( STD_OUTPUT_HANDLE );   if (hStdOut == INVALID_HANDLE_VALUE) return;    /* Get the number of cells in the current buffer */   if (!GetConsoleScreenBufferInfo( hStdOut, &csbi )) return;   cellCount = csbi.dwSize.X *csbi.dwSize.Y;    /* Fill the entire buffer with spaces */   if (!FillConsoleOutputCharacter(     hStdOut,     (TCHAR) ' ',     cellCount,     homeCoords,     &count     )) return;    /* Fill the entire buffer with the current colors and attributes */   if (!FillConsoleOutputAttribute(     hStdOut,     csbi.wAttributes,     cellCount,     homeCoords,     &count     )) return;    /* Move the cursor home */   SetConsoleCursorPosition( hStdOut, homeCoords );   }


using namespace std ;

Plateau::Plateau(int l, int c , int m):lignes(l),colonnes(c),nb_mines(m)
{

}

Plateau::~Plateau()
{

}

enum Colors { hide=0,blue=1,green=2,cyan=3,red=4};
enum Colors2 { magenta=5,yellow=6,white=7,grey=8,bblack=8,gray=8};
enum Colors3 { bblue=9,bgreen=10,bcyan=11,bred=12,bmagenta=13};
enum Colors4 { byellow=14,bwhite=15,unholy=18,phantom=27,acid=32};
enum Colors5 { slimer=42,demonic=64,pinkpurp=93,forest=162};
enum Colors6 { clearday=191,warning=207,notation=240};
void coutc(int color, string output){
HANDLE handle= GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute( handle, color);
cout<< output;
SetConsoleTextAttribute( handle,7 );
}

string to_string(int n){
        ostringstream str1 ;
        str1.str("");str1.clear();
        str1 << n ;
        return str1.str();
}

int Plateau::nb_couverte(){
    int compteur =0 ;
        for (int i=0 ; i<lignes ; i++)
            for(int j=0 ; j<colonnes;j++)
                if (plateau[i][j]->getDecouverte()==false)
                   compteur++;
    return compteur ;
}



 void Plateau::make_random(){
    int random_ligne,random_colonne;
    bool trouve ;
    string s ;
    srand(time(NULL));
    for (int i=0 ; i<nb_mines; i++)
    {
        // pour creer des nombres aletoires differents
        //on stocke les valeurs anciens dans un map pour ne pas le repeter
        do {
             trouve =false;
             random_ligne = rand()%lignes;
             random_colonne = rand()%colonnes;

            s = to_string(random_ligne) +","+ to_string(random_colonne); // convertir int to string
             //creer des nombres aleatoires sans répétition
             if (mines.count(s)==0)
               {
                   mines[s]=make_pair(random_ligne,random_colonne);// s'il n'existe pas stocke dans le map
                   trouve=true ;
               }
            } while(!trouve);
    }
}



void Plateau::remplir_plateau_initial( ){
string s ;
    for(int i=0; i<lignes;i++){
        for(int j=0; j<colonnes;j++){
                s = to_string(i)+","+to_string(j);
                if (mines.count(s)==1)
                    plateau[i][j] = new Mine();
                else
                    plateau[i][j] = new Blanc();
            }
    }
}

void Plateau::placer_chiffres(){
    int compteur ;
    for(int i=0 ; i<lignes ; i++){
        for (int j=0 ; j<colonnes ;j++)
            {
                compteur = 0 ;
                if (plateau[i][j]->getSymbole()=="X")
                  {
                    if ( (i-1 >=0)  && (j-1 >= 0) )
                            if (plateau[i-1][j-1]->getSymbole()=="M") compteur++;
                    if ( (i-1 >=0) && (j >= 0) )
                            if (plateau[i-1][j]->getSymbole()=="M") compteur++;
                    if ( (i-1 >=0) && (j+1 >= 0) && (j+1<colonnes) )
                            if (plateau[i-1][j+1]->getSymbole()=="M") compteur++;

                    if ( (i >=0) && (j+1 >= 0) && (j+1 <colonnes))
                            if (plateau[i][j+1]->getSymbole()=="M") compteur++;
                    if ( (i >=0) && (j-1 >= 0) )
                            if (plateau[i][j-1]->getSymbole()=="M") compteur++;

                    if ( (i+1 >=0) && (j-1 >= 0) && (i+1 <lignes) )
                            if (plateau[i+1][j-1]->getSymbole()=="M") compteur++;
                    if ( (i+1 >=0) && (j >= 0) && (i+1 <lignes) )
                            if (plateau[i+1][j]->getSymbole()=="M") compteur++;
                    if ( (i+1 >=0) && (j+1 >= 0) && (i+1 <lignes) && (j+1 <colonnes) )
                            if (plateau[i+1][j+1]->getSymbole()=="M") compteur++;
                 }

                 if (plateau[i][j]->getSymbole()=="X" && compteur >0)
                    plateau[i][j]= new Numero(compteur);

            }
    }
}


int Plateau::setDrapeau(int l, int c,int nb){
   if (plateau[l][c]->getDecouverte()==true && plateau[l][c]->getDrapeau()==false )
        return 2 ;
    //else {
        if ( plateau[l][c]->getDrapeau()==true)
        {plateau[l][c]->setDrapeau(false); return -1; }
        else { if (nb >0 ) {plateau[l][c]->setDrapeau(true);
                            return 1;}
                            else return 2 ;}
       // }

}

int Plateau::testGagne(){
    for (int i=0; i<lignes;i++)
        for(int j=0 ; j<colonnes;j++)
            {
                if (plateau[i][j]->getSymbole()=="M")
                        if (plateau[i][j]->getDrapeau()==false)
                            return 1 ;
            }

            return 0 ;
}


// placer les mines et les autres cases sans numeros
void Plateau::initialiser(){
        make_random();
      //  map<string,pair<int,int> >::iterator it;
        //placer les bombes dans les plateau
      //  for( it=mines.begin(); it!=mines.end();it++)
          //   plateau[it->second.first][it->second.second] = Mine() ;
             // remplir le plateau initialement
        remplir_plateau_initial() ;
        placer_chiffres();
}



//affichage plateau
void Plateau::afficher(int nb_coups,int nb_m,int score){
    string s ;
    int c ;
     int margin;
       // ClearScreen();
    cout << "Nombre de mines: "<<nb_m<<"                        ";
    cout << "Nombre de coups: "<<nb_coups<<"              score : " <<score<<endl ;

    coutc(3,"   *****************************************************************************************************");cout<<endl ;
    coutc(3,"   *                                                                                                   *");cout<<endl;
    coutc(3,"   *");
            if (colonnes%2!=0)  margin = (32-colonnes)/2;
            else margin = (31-colonnes)/2;


             cout <<"   ";
             if (margin==0) cout<<"   ";
             for(int p=0 ;p<margin;p++ ) cout<<"   "; //3 espace a decaler
      for (int i=1 ;i<=colonnes; i++)
       {
           if (i<10)
           cout <<i<<"  ";// afficher les chifrres en haut
           else cout <<i<<" "; // nombre avec 2chiffres
       }
        for(int p=0;p<=margin;p++) cout<<"   ";

            if (colonnes%2==0 && margin !=0) cout<<"   ";
           coutc(3,"*");
          cout <<endl;


         for(int i=0; i<lignes;i++){

            coutc(3,"   *"); if (margin==0) cout <<"   ";for(int p=0 ;p<margin;p++ ) cout<<"   ";
           if (i+1<10) cout <<i+1<<"  ";  else if (i+1>=10) cout <<i+1<<" ";  else  cout <<i+1;

        for(int j=0; j<colonnes;j++)
               {
                   s="#";
                   c =7;
                   if(plateau[i][j]->getDecouverte()==true)
                    {s=plateau[i][j]->getSymbole();
                    c=plateau[i][j]->getColor();
                    }
                    if (plateau[i][j]->getDrapeau()!=true)
                     {coutc(c, s);cout <<"  ";}
                   else  {coutc(93,"D");cout <<"  ";}

               }
                             // if (margin==0) cout<<"  ";
                    for(int p=0;p<=margin;p++) cout<<"   ";
                        if (colonnes%2==0 && margin!=0) cout<<"   ";
                        coutc(3,"*");

         cout <<"  "<< endl ;

    }
    coutc(3,"   *                                                                                                   *");cout<<endl;
    coutc(3,"   *****************************************************************************************************");
    cout <<endl;

}

void Plateau::afficher_tous(){
    string s;

    for(int i=0; i<lignes;i++){
            if (i+1<10)cout <<i+1<<"  ";  else if (i+1>=10) cout <<i+1<<" ";  else  cout <<i+1;

        for(int j=0; j<colonnes;j++)
                   coutc(plateau[i][j]->getColor(),plateau[i][j]->getSymbole()); cout <<" ";

        cout <<"  " << endl ;
        }
}

int Plateau::choisir(int i,int j)
{



                 if (i <lignes && j <colonnes && i>=0 && j>=0  && plateau[i][j]->getDecouverte()==false  )
                 {

                       if (plateau[i][j]->getDrapeau()==true)
                          return 4;
                        plateau[i][j]->setDecouverte(true);

                       if (plateau[i][j]->getSymbole()=="M")
                           return 1 ;

                   if (typeid(*plateau[i][j]) == typeid(Numero))
                        return 2 ;

                    choisir(i-1,j-1);
                    choisir(i-1,j);
                    choisir(i-1,j+1);
                    choisir(i,j+1);
                    choisir(i,j-1);
                    choisir(i+1,j-1);
                    choisir(i+1,j);
                    choisir(i+1,j+1);

                    return 0 ; // tout va bien !
                 }

                   return -1 ; // ligne ou colonne donnée est erronée
}











