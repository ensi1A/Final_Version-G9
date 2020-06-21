#include "Grille.hpp"
#include "Game.hpp"
#include "globalvar.hpp"
#include <iostream>
#include <ctime>
#include <chrono>
#include <windows.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <random>
#include <fstream>
#include "alphabet.hpp"
using namespace std;


int main(){



    HANDLE in,out;  //input and output handles
    DWORD info;
    CONSOLE_SCREEN_BUFFER_INFO scrinfo;
    INPUT_RECORD inp;

    int i,j; //loop variables
    in=GetStdHandle(STD_INPUT_HANDLE);
    out=GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(out,&scrinfo);
    printstr(22,10,"mots meles",219,_LIGHTBLUE); //prints the title screen. defined in alphabet2.h


    COORD pos={80,25};SetConsoleCursorPosition(out,pos);
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,12);
    cout<<"Made by :";
            SetConsoleTextAttribute(H,15);

    cout<<"MHALLA Hajer"<<endl;

    pos={89,26};SetConsoleCursorPosition(out,pos);
    cout<<"ELAINI Jameleddine"<<endl;

    pos={89,27};SetConsoleCursorPosition(out,pos);
    cout<<"DAGHSNI Ahlem"<<endl;

    pos={89,28};SetConsoleCursorPosition(out,pos);
    cout<<"MARZOUK Eya"<<endl;





    pos={24,16};

    SetConsoleCursorPosition(out,pos);


    system("pause");system("cls");
    SetConsoleTitle("MOTS MELES");


    srand(time(0));
    Game gm(8);

    do    {gm.affiche_difficulty();}while (choicediff!=1 && choicediff!=2 &&choicediff!=3);
    do
    {gm.affiche_langue();} while (choixlang!=1 && choixlang !=2);
    do
    {gm.affiche_theme();} while (choixthem!=1 &&choixthem!=2 && choixthem!=3);
    int a,b;
    if (choicediff==1){a=9;b=11;}
    else if (choicediff==2){a=11;b=13;}
    else {a=12;b=15;}
    Grille gr(a,b);
    gr.remplissage(gm);
    gr.remplissage_reste();
    gm.afficher_mots();

    gr.affiche_grille();

    time_t startTimeSeconds = time(NULL); // must include 'ctime'
    gm.pos_curs(0,0);
     cout<<"TIME LEFT : "<<120-(time(NULL) - startTimeSeconds) <<" S"<<endl;


    i=0;
    for (j=0;j<100;j++)
    {
    gm.playy(gr);

    //system("cls");main();
    if (time(NULL) - startTimeSeconds >= 180) // two minutes
    {
        system("cls");
        gm.pos_curs(50,7);
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,4);

        cout<<" Time's up"<<endl;SetConsoleTextAttribute(H,2);
        gm.pos_curs(50,8);
        cout<<"your score is : ";
        cout<<score<<endl;
        gm.pos_curs(50,9);
        SetConsoleTextAttribute(H,15);
        cout<<"do you want to restart y/n"<<endl;
        char restartt ;
        cin>>restartt;
        if (restartt=='y') {system("cls");main();}
        else {
            SetConsoleTextAttribute(H,2);
        gm.pos_curs(50,10);
                cout <<"thanks for playing";
                SetConsoleTextAttribute(H,15);return 1;}}
        if (gm.game_over()){
        system("cls");
        gm.pos_curs(50,7);
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,4);

        cout<<" you win "<<endl;SetConsoleTextAttribute(H,15);
        gm.pos_curs(50,8);
        cout<<"your score is : ";
        cout<<score<<endl;
        gm.pos_curs(50,9);
        cout<<"do you want to restart y/n"<<endl;
        char restartt ;
        cin>>restartt;
        if (restartt=='y') {system("cls");main();}
        else {
            SetConsoleTextAttribute(H,2);
        gm.pos_curs(50,10);
                cout <<"thanks for playing";
                SetConsoleTextAttribute(H,15);return 1;}}
    system("cls");
    cout<<"still "<<180-(time(NULL) - startTimeSeconds) <<" secondes"<<endl;
    gr.affiche_grille();

    gm.afficher_mots();



    }





return 1;



}

