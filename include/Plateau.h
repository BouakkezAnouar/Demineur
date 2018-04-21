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
        void afficher(int nb_coups,int nb_m,int score);
        void afficher_tous();
        int choisir(int l ,int c);
        int testGagne();
        int setDrapeau(int l ,int c,int nb);
        int nb_couverte();



    private:
        void make_random();

        int lignes ;
        int colonnes;
        int nb_mines ;
        map<string,pair<int,int>> mines ;
        Case* plateau [50][50];

};



#endif // PLATEAU_H
