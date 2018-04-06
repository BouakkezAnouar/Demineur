#include <cstdlib>
#include <iostream>
#include <ctime>
#include <string>
#include "Plateau.h"
#include <map>
#include "Mine.h"
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

 map<string,pair<int,int>> make_random(int nb_mines,int lignes, int colonnes){
    int random_ligne,random_colonne;
    bool trouve ;
    string s ;
    map<string,pair<int,int>> m ;
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
             if (m.count(s)==0)
               {
                   m[s]=make_pair(random_ligne,random_colonne);// s'il n'existe pas stocke dans le map
                   trouve=true ;
               }

        } while(!trouve);
}
    return m ;
}


void Plateau::remplir_plateau_initial( map<string,pair<int,int>>  m){

string s ;
    for(int i=0; i<lignes;i++){
        for(int j=0; j<colonnes;j++)
            {
                s = to_string(i)+","+to_string(j);
                if (m.count(s)==1)
                    plateau[i][j] =Mine();
                else
                    plateau[i][j] = Case();
            }

    }
}


// placer les mines et les autres cases sans numeros
void Plateau::initialiser(){
        map<string,pair<int,int> > m = make_random(nb_mines,lignes,colonnes);

    for( map<string,pair<int,int> >::iterator it=m.begin(); it!=m.end();it++)
             plateau[it->second.first][it->second.second] = Mine() ;

    remplir_plateau_initial(m) ; // remplir le plateau initialement
}


//affichage plateau
void Plateau::afficher(){
    cout << endl<<endl ;
    for(int i=0; i<lignes;i++){
        for(int j=0; j<colonnes;j++)
        cout <<"    "<<plateau[i][j].getSymbole()<<" " ;
    cout << endl ;
    }

}








