#ifndef GAME_HPP_INCLUDED
#define GAME_HPP_INCLUDED
#include <vector>
#include <string>
#include "Grille.hpp"
#include "globalvar.hpp"

using namespace std;

class Grille;
class Game{
private:
    vector<string> mots;

    int nbre_mots;
    int mots_trouves;
public:
    Game(int n);

    void affiche_difficulty();
    void affiche_langue();
    void affiche_theme();
    void afficher_liste_mots();
    void afficher_mots();
    void ajouter_mot(string ch,int i);
    void pos_curs(short x,short y);
    bool game_over();
    string generer_mot(string dict);
    string construire_mot(int x1,int y1 ,int x2 ,int y2,Grille G);
    string construire_mot_inv(string ch);
    bool correct_answer(string mot1,string mot2);
    int compare(string ch1,string ch2);
    void playy(Grille G);
    int get_nbmots();
    void test();



};


#endif // GRILLE_HPP_INCLUDED

