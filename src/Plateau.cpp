#include <cstdlib>
#include <iostream>
#include <ctime>
#include <string>
#include "Plateau.h"
#include "Mine.h"
#include "Blanc.h"
#include "Numero.h"
#include <map>
#include<typeinfo>
#include <utility>      // std::pair


using namespace std ;


 // use current time as seed for random generator
Plateau::Plateau(int l, int c , int m):lignes(l),colonnes(c),nb_mines(m)
{

}

Plateau::~Plateau()
{

}

string to_string(int n){
        ostringstream str1 ;
        str1.str("");str1.clear();
        str1 << n ;
        return str1.str();
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
                    plateau[i][j] =Mine();
                else
                    plateau[i][j] = Blanc();
            }
    }
}

void Plateau::placer_chiffres(){
    int compteur ;
    for(int i=0 ; i<lignes ; i++){
        for (int j=0 ; j<colonnes ;j++)
            {
                compteur = 0 ;
                if (plateau[i][j].getSymbole()=="X")
                  {
                    if ( (i-1 >=0)  && (j-1 >= 0) )
                            if (plateau[i-1][j-1].getSymbole()=="M") compteur++;
                    if ( (i-1 >=0) && (j >= 0) )
                            if (plateau[i-1][j].getSymbole()=="M") compteur++;
                    if ( (i-1 >=0) && (j+1 >= 0) && (j+1<colonnes) )
                            if (plateau[i-1][j+1].getSymbole()=="M") compteur++;

                    if ( (i >=0) && (j+1 >= 0) && (j+1 <colonnes))
                            if (plateau[i][j+1].getSymbole()=="M") compteur++;
                    if ( (i >=0) && (j-1 >= 0) )
                            if (plateau[i][j-1].getSymbole()=="M") compteur++;

                    if ( (i+1 >=0) && (j-1 >= 0) && (i+1 <lignes) )
                            if (plateau[i+1][j-1].getSymbole()=="M") compteur++;
                    if ( (i+1 >=0) && (j >= 0) && (i+1 <lignes) )
                            if (plateau[i+1][j].getSymbole()=="M") compteur++;
                    if ( (i+1 >=0) && (j+1 >= 0) && (i+1 <lignes) && (j+1 <colonnes) )
                            if (plateau[i+1][j+1].getSymbole()=="M") compteur++;
                 }

                 if (plateau[i][j].getSymbole()=="X" && compteur >0)
                    plateau[i][j]=Numero(compteur);

            }
    }
}


// placer les mines et les autres cases sans numeros
void Plateau::initialiser(){
        make_random();
        map<string,pair<int,int> >::iterator it;
        //placer les bombes dans les plateau
        for( it=mines.begin(); it!=mines.end();it++)
             plateau[it->second.first][it->second.second] = Mine() ;
             // remplir le plateau initialement
        remplir_plateau_initial() ;
}


//affichage plateau
void Plateau::afficher(){
    std::system("cls");
    cout << "Nombre de mines: "<<nb_mines<<endl;
    cout << "Nombre de coups: "<<nb_coups<<endl ;
    for(int i=0; i<lignes;i++){
        for(int j=0; j<colonnes;j++)
        cout <<"    "<<plateau[i][j].getSymbole()<<" " ;
    cout << endl ;
    }

}








