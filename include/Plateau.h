#ifndef PLATEAU_H
#define PLATEAU_H
#include "Case.h"
#include<string>
#include <sstream>
#include<map>
using namespace std ;


class Plateau
{
    public:
        Plateau(int l,int c,int m);
        virtual ~Plateau();
        void initialiser();
        void remplir_plateau_initial();
        void placer_chiffres();
        void afficher();
        void afficher_tous();
        bool choisir(int l ,int c);



    private:
        void make_random();

        int lignes ;
        int colonnes;
        int nb_mines ;
        int nb_coups;
        map<string,pair<int,int>> mines ;
        Case plateau [50][50];

};



#endif // PLATEAU_H
