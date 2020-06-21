
#ifndef GRILLE_HPP_INCLUDED
#define GRILLE_HPP_INCLUDED
#include <vector>
#include<string>
#include <stdio.h>
#include <iostream>
#include "Game.hpp"

using namespace std ;

class Game;
class Grille{
private:
    int nb_ligne,nb_colonne;
    vector< vector<char> > *grid;
    vector< vector<char> > *grid1;
    vector<string> *motss;
    vector<string>::iterator it;     //Un itérateur sur un vector de chaine


public:
    Grille(int nbl,int nbc);
    ~Grille();
    void set_case(int x,int y, char value);
    char generate_case_randomly();
    void remplissage_reste();
    void pos_curs(short x,short y);
    void insererHG(string word  ,int x ,int y);
    void insererHD(string word  ,int x ,int y);
    void insererVB(string word ,int x ,int y);
    void insererVH(string word  ,int x ,int y);
    void inserer_diagonaleDB(string word  ,int x ,int y);
    void inserer_diagonaleDH(string word  ,int x ,int y);
    void inserer_diagonaleGH(string word  ,int x ,int y);
    void inserer_diagonaleGB(string word  ,int x ,int y);
    void affiche_grille();
    char de(int i ,int j);
    bool verifier_espace(string word,int n,int &x,int &y);
    void remplissage(Game& Ga);
    void remplissage(vector<string> vect);
    int compare(string ch1,string ch2);
    bool verifier_intersection(string word ,int n, int x , int y);
    void setgrille1(int x , int y , char m);




};


#endif // GRILLE_HPP_INCLUDED

