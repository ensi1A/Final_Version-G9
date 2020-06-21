#include "Game.hpp"
#include <windows.h>
#include <fstream>
#include "globalvar.hpp"
#include "Grille.hpp"


int choicediff;
int choixlang;
int choixthem;
int affmot;
int score=0;


Game::Game(int n)
    {

        nbre_mots=n;
        //mots=new vector<string>;
        mots.resize(9);
        mots_trouves=0;
        score=0;



    }

void Game::affiche_difficulty()
    {
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,11);
        pos_curs(50,11);
        cout <<"choose difficulty: "<<endl;
        SetConsoleTextAttribute(H,15);
        pos_curs(50,12);
        cout<<"1)easy 9*11"<<endl;
        pos_curs(50,13);
        cout <<"2)normal 11*13"<<endl;
        pos_curs(50,14);
        cout <<"3)hard 12*15"<<endl;
        int choix;

        cin>>choix;
        choicediff=choix;

        system("cls");

    }

void Game::affiche_langue()
    {
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,11);

        pos_curs(50,11);
        cout <<"choose language: "<<endl;
        SetConsoleTextAttribute(H,15);
        pos_curs(50,12);
        cout<<"1)french"<<endl;
        pos_curs(50,13);
        cout <<"2)english"<<endl;
        int choice;

        cin>>choice;
        choixlang=choice;

        system("cls");

    }

void Game::affiche_theme()
    {
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,11);
        pos_curs(50,11);
        cout <<"choose theme: "<<endl;
        SetConsoleTextAttribute(H,15);
        pos_curs(50,12);
        cout<<"1)sport"<<endl;
        pos_curs(50,13);
        cout <<"2)nature"<<endl;
        pos_curs(50,14);
        cout <<"3)education"<<endl;

        int choice;
        cin >>choice ;
        choixthem=choice;
        system("cls");

    }

void Game::afficher_liste_mots()
{
        pos_curs(50,11);
        cout <<"do you want to see list of words? "<<endl;
        pos_curs(50,12);
        cout<<"1)yes"<<endl;
        pos_curs(50,13);
        cout <<"2)no"<<endl;
        int rep;int affmot;
        do
        {cin>>rep;affmot=rep;} while (rep!=1 && rep!=2);system("cls");

}

void Game::afficher_mots()
{

    int y=10;


    for (int i=0;i<8;i++)
    {
        pos_curs(100,y);
         HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(H,8);
        cout<<i<<")"<<(mots)[i]<<endl;
        y++;
        pos_curs(100,y);
        cout<<endl;y++;
    }
     HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,15);


}

void Game::pos_curs(short x,short y)//mettre le curseur a la position x y
    {
         HANDLE menu=GetStdHandle(STD_OUTPUT_HANDLE);
        COORD Pos;
        Pos.X = x;
        Pos.Y = y;
        SetConsoleCursorPosition(menu,Pos);
    }

void Game::ajouter_mot(string ch,int i)//remplir la liste de mots
    {

        mots[i]=ch;

    }

string Game::generer_mot(string dict)//va generer un seul mot dict doit etre de la fortme "dict.txt"
{

   ifstream dico(dict);

    if(dico)
    {
        string lignes[500];
        string ligne="";
        int i(0);


        while(getline(dico, ligne))
        {
            lignes[i] = ligne;
            i++;
        }

        int nbAleatoire = rand() % i;

        return(lignes[nbAleatoire]) ;
    }

    else
    {
        cout << "Erreur lors de l'ouverture du fichier." << endl;
}}

int Game::compare(string ch1,string ch2)//comparer deux string
{


    if (ch1.size()==ch2.size())
    {
        for  (int i=0;i<ch1.size();i++)
        {
            if (ch1[i]!=ch2[i]) return -1;
        }
        return 0;
    }
    return -1;

}

string Game::construire_mot(int x1,int y1 ,int x2 ,int y2,Grille G)//les cordonnées sont donnés par le joueur
{
    x1--;
    y1--;
    x2--;
    y2--;

    string ch1;
    if (x1==x2)// horiz

    {
        int maxy=max(y1,y2);
        int miny=min (y1,y2);

        for (int k=miny;k<=maxy;k++)
        {

            ch1=ch1+G.de(x1,k);

        }
    }
    else if(y1==y2)
    {
        int maxx=max(x1,x2);
        int minx=min(x1,x2);
        for (int k=minx;k<=maxx;k++)
        {

            ch1=ch1+G.de(k,y1);

        }

    }
    else if(((x1>x2)&&(y1>y2))||((x1<x2)&&(y1<y2)))
    {
        int maxx=max(x1,x2);
        int minx=min(x1,x2);
        int maxy=max(y1,y2);
        int miny=min(y1,y2);
        int i=miny;
        for (int j=minx;j<=maxx;j++)
        {
            ch1=ch1+G.de(j,i);
            i++;
        }
    }
    else if(((x1>x2)&&(y1<y2))||((x1<x2)&&(y1>y2)))
    {


        int maxx=max(x1,x2);
        int minx=min(x1,x2);
        int maxy=max(y1,y2);
        int miny=min(y1,y2);
        int i=maxy;
        for (int j=minx;j<=maxx;j++)
        {
            ch1=ch1+G.de(j,i);
            i--;
        }
    }
    return ch1;
}
string Game::construire_mot_inv(string ch1)//construire le mot inverse
{
    string ch2="";
    string extrait;
    int i;

    for (int i=ch1.size(); i>=0; i--)
    {

        extrait = ch1.substr(i,1);
        ch2 = ch2 + extrait;

    }

    return ch2;
}
bool Game::correct_answer(string mot1,string mot2)
{

    for (int i=0;i<(mots).size();i++)
    {
        if ((compare((mots)[i],mot1))==0 || compare((mots)[i],mot2)==0)
        {
            (mots)[i]="-";
            mots_trouves++;
            return true;
        }
    }
    return false;
}

bool Game::game_over()//condition d'arret
{
    return (mots_trouves==8);
}


void Game::playy(Grille  G)
{
    pos_curs(90,0);
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,4);


    pos_curs(90,1);
    cout<<"SCORE: "<<score<<endl;
    pos_curs(90,2);
        cout<<"----------";

    cout<<" "<<endl;

    SetConsoleTextAttribute(H,15);


    int x1,x2,y1,y2;
    cout<<"line number 1 :";
    cin>>x1;
     cout<<"column number 1 :";
    cin>>y1;
     cout<<"line number 2 :";
    cin>>x2;
     cout<<"column number 2 :";
    cin>>y2;

    string ch=construire_mot(x1,y1,x2,y2,G );
    string ch1=construire_mot_inv(ch);
    cout<<"";
    if (correct_answer(ch,ch1)) { cout<< "correct answer";
    cout <<"here";
    x1--;
    y1--;
    x2--;
    y2--;

    if (x1==x2)// horiz

    {
        int maxy=max(y1,y2);
        int miny=min (y1,y2);

        for (int k=miny;k<=maxy;k++)
        {

            G.setgrille1(x1,k,'-');

        }
    }
    else if(y1==y2)
    {
        int maxx=max(x1,x2);
        int minx=min(x1,x2);
        for (int k=minx;k<=maxx;k++)
        {

            G.setgrille1(k,y1,'-');

        }

    }
    else if(((x1>x2)&&(y1>y2))||((x1<x2)&&(y1<y2)))
    {
        int maxx=max(x1,x2);
        int minx=min(x1,x2);
        int maxy=max(y1,y2);
        int miny=min(y1,y2);
        int i=miny;
        for (int j=minx;j<=maxx;j++)
        {
            G.setgrille1(j,i,'-');
            i++;
        }
    }
    else if(((x1>x2)&&(y1<y2))||((x1<x2)&&(y1>y2)))
    {


        int maxx=max(x1,x2);
        int minx=min(x1,x2);
        int maxy=max(y1,y2);
        int miny=min(y1,y2);
        int i=maxy;
        for (int j=minx;j<=maxx;j++)
        {
            G.setgrille1(j,i,'-');
            i--;
        }
    }
    cout <<"here";
score+=15;}
    else {score=score-5;}











}
int Game::get_nbmots(){return nbre_mots;}


void Game::test()
{
    for (int i=0 ;i<8;i++)
        cout<<mots[i]<<"---------";
}

