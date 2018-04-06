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
        void remplir_plateau_initial(map<string,pair<int,int>> m);
        void afficher();


    private:

        int lignes ;
        int colonnes;
        int nb_mines ;
        Case plateau [50][50];

};



#endif // PLATEAU_H
