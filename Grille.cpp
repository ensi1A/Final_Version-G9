#include "Grille.hpp"
#include <vector>
#include <time.h>

#include<windows.h>
class Game;
Grille::Grille(int nbl,int nbc)
    {
        nb_ligne=nbl;nb_colonne=nbc;
        grid=new vector<vector<char>>;
        grid->resize(nb_ligne);
        for (int i = 0; i < nb_ligne; ++i)
            (*grid)[i].resize(nb_colonne);
            for (int i=0;i<nb_ligne;i++)
        {
            for (int j=0;j<nb_colonne;j++)
            {
                set_case(i,j,' ');
            }

        }
        //remplissage de la grille 1
        grid1=new vector<vector<char>>;
        grid1->resize(nb_ligne);
        for (int i = 0; i < nb_ligne; ++i)
            (*grid1)[i].resize(nb_colonne);
            for (int i=0;i<nb_ligne;i++)
        {
            for (int j=0;j<nb_colonne;j++)
            {
                (*grid1)[i][j] = 'a';
            }

        }


        motss=new vector<string>;
        motss->resize(8);



    }

Grille::~Grille()
    {
        delete grid;
    }

void Grille::set_case(int x,int y, char value)
    {

        (*grid)[x][y] = value;
    }

char Grille::generate_case_randomly()
    {

      return (rand()%(90-65))+65;
    }


void Grille::remplissage_reste()
    {


        for (int i=0;i<nb_ligne ;i++)
        {
            for (int j=0;j<nb_colonne;j++)
            {
                if (de(i,j)==' ')
                {
                    (*grid)[i][j]=generate_case_randomly();
                }


            }
        }
    }



void Grille::insererHG(string word  ,int x ,int y)
    {
        int i=0;
            for (int j=y;j!=y-word.size();j--)
            {
                set_case(x,j,word[i]);i++;
            }

    }

void Grille::insererHD(string word  ,int x ,int y)
    {
        int i=0;
        {
            for (int j=y;j!=y+word.size();j++)
            {
                set_case(x,j,word[i]);
                i++;
            }
        }
    }

void Grille::insererVB(string word  ,int x ,int y)


        {
            int i=0;
            for (int j=x;j!=x+word.size();j++)
            {
                set_case(j,y,word[i]);
                i++;
            }
        }


void Grille::insererVH(string word  ,int x ,int y)
    {
        int i=0;
        {
            for (int j=x;j!=x-word.size();j--)

            {
                set_case(j,y,word[i]);
                i++;
            }
        }
    }
void Grille::inserer_diagonaleDB(string word  ,int x ,int y)
{
    int i=x;int j=y;
           for (int k=0;k<word.size();k++)
           {
               set_case(i,j,word[k]);
               i++;
               j++;
           }
}
void Grille::inserer_diagonaleDH(string word  ,int x ,int y)
{
        int i=x;int j=y;
           for (int k=0;k<word.size();k++)
           {
               set_case(i,j,word[k]);
               i--;
               j++;
           }

}
void Grille::inserer_diagonaleGH(string word  ,int x ,int y)
{ int i=x;int j=y;
           for (int k=0;j<word.size();k++)
           {
               set_case(i,j,word[k]);
               i--;
               j--;
           }
}
void Grille::inserer_diagonaleGB(string word  ,int x ,int y)
{ int i=x;int j=y;
           for (int k=0;k<word.size();k++)
           {
               set_case(i,j,word[k]);
               i++;
               j--;
           }
}




//affichage grille
void Grille::affiche_grille()
     {int k=7;
         for (int i = 0; i < nb_ligne; ++i)
            {pos_curs(48,k);

                k++;
                for (int j = 0; j < nb_colonne; ++j)
                {
                    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,3);
                    cout << "| ";SetConsoleTextAttribute(H,15);
                    if ((*grid1)[i][j] =='-')
                    {SetConsoleTextAttribute(H,79);}

                    cout<<(*grid)[i][j];
                }
                cout<<endl;
                pos_curs(48,k);
                k++;
                HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,3);

                for (int j = 0; j < nb_colonne; ++j)
                    {cout << "___";}
                        cout<<endl;
	}
	                HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);

	        SetConsoleTextAttribute(H,15);


}
void Grille::pos_curs(short x,short y)
    {
        HANDLE menu=GetStdHandle(STD_OUTPUT_HANDLE);
        COORD Pos;
        Pos.X = x;
        Pos.Y = y;
        SetConsoleCursorPosition(menu,Pos);
    }
//retourne la valeur d'une case
char Grille::de(int i ,int j)
{
    return (*grid)[i][j];
}
bool Grille::verifier_espace(string word,int n,int &x,int &y)
{

    if (n==3 ) {if (nb_ligne-x<=word.size()) {return false;}}
    else if(n==4) {if(x<=word.size()){return false;}}
    else if (n==2){if (y<=word.size()) {{return false;}}}
    else if  (n==1){if (nb_colonne-y<=word.size()) {return false ;}}
    else if (n==5 )
        {if (nb_ligne-x<=word.size()) {return false;}
        if(nb_colonne-y<=word.size()) {return false;}
        }

    else if  (n==6)
        {if (nb_ligne-x<=word.size()) {return false;}
        if(y<=word.size()) {return false;}
       }
    else if  (n==7)
        {if (x<=word.size()){return false;}
          if (nb_colonne-y<=word.size()){return false;}
          }
    return true;


}
int Grille::compare(string ch1,string ch2)
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
void Grille::remplissage(Game& Ga)
{
    int m=0;//compter le nombre de mots
    Game G (1);
    string diico;
    if ((choixlang==1)&&(choixthem==1)) diico="fsport.txt";
    else if((choixlang==1)&&(choixthem==2))diico="fnature.txt";
    else if((choixlang==1)&&(choixthem==3))diico="feducation.txt";
    else if ((choixlang==2)&&(choixthem==1)) diico="esport.txt";
    else if((choixlang==2)&&(choixthem==2))diico="enature.txt";
    else if((choixlang==2)&&(choixthem==3))diico="eeducation.txt";


    do
    {
        string mot=G.generer_mot(diico);
        int x=(rand()%nb_ligne);
        int y=(rand()%nb_colonne);
        int n=rand()%7+1;//generation de direction
        if (verifier_espace(mot,n,x,y)&&verifier_intersection(mot,n,x,y))
        {


            Ga.ajouter_mot(mot,m);m++;
            if (n==3)insererVB(mot,x,y);
            else if(n==4) insererVH(mot,x,y);
            else if(n==2) insererHG(mot,x,y);
            else if(n==1) insererHD(mot,x,y);
            else if(n==6) inserer_diagonaleGB(mot,x,y);
            else if(n==7) inserer_diagonaleDH(mot,x,y);
            else if(n==5) inserer_diagonaleDB (mot,x,y);
        }





    }
    while (m<8);
}
bool Grille::verifier_intersection(string word ,int n, int x , int y)
{

    if (n==3)
    {

        int j=0;
        for (int i=x;i<=x+word.size();i++)
        {
           if ((((*grid)[i][y])!=' ')&&(((*grid)[i][y])!=word[j])){return false;}
            j++;
        }
    }
    else if(n==4)
    {
        int j=0;
        for (int i=x;i>=x-word.size();i--)
        {
           if ((((*grid)[i][y])!=' ')&&(((*grid)[i][y])!=word[j])){return false;}
            j++;
        }

    }
    else if(n==1)
    {
        int j=0;
        for (int i=y ;i<y+word.size();i++)
        {
           if ((((*grid)[x][i])!=' ')&&(((*grid)[x][i])!=word[j])){return false;}
           j++;
        }
    }
    else if(n==2)
    {
        int j=0;
        for (int i=y ;i>=y-word.size();i--)
        {
           if ((((*grid)[x][i])!=' ')&&(((*grid)[x][i])!=word[j])){return false;}
           j++;
        }
    }
    else if (n==5)
    {
        int j=0;
        int k=y;
        for (int i=x;i<=x+word.size();i++)
        {
            if ((((*grid)[i][k])!=' ')&&(((*grid)[i][k])!=word[j])){return false;}
            k++;
            j++;
        }
    }
    else if (n==6)
    {
        int j=0;
        int k=y;
        for (int i=x;i<=x+word.size();i++)
        {
            if ((((*grid)[i][k])!=' ')&&(((*grid)[i][k])!=word[j])){return false;}
            k--;
            j++;
        }
    }
    else if (n==7)
    {
        int j=0;
        int k=y;
        for (int i=x;i>=x-word.size();i--)
        {
            if ((((*grid)[i][k])!=' ')&&(((*grid)[i][k])!=word[j])){return false;}
            k++;
            j++;
        }
    }
    return true;

}
void Grille::setgrille1(int x, int y , char c)
{
    (*grid1)[x][y]=c;
}



