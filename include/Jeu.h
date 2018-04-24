#ifndef JEU_H
#define JEU_H


class Jeu
{
    public:
        Jeu(int s=0, int nb_c=0 );
        virtual ~Jeu();
        void affiche_menu();
        void jeu();
        bool jouer(int l, int c , int m);
        void setNb_mines(int a);
        void lire_score();

    protected:

    private:
        int nb_mines;
        int nb_coups;
        int score;
};

#endif // JEU_H
