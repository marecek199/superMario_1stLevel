#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <windows.h>
#include <conio.h>

#define T       1
#define F       0
#define ON      10
#define OFF     20
#define SNAKE_MAX_DLZKA 100


typedef struct{
    int X,Y;
}LAST;

typedef struct{
    float f,g,h;
    float x,y,s,v;
    int zaciatok,koniec,exp;
    int cesta,open,close,kolo,wall;
    LAST last;
    int snake;
    int snake_poradie;
}KOCKA;

typedef struct{
    int Xpocet,Ypocet;
    SDL_Renderer *renderer;

    KOCKA kocka[99][99];
    KOCKA snake_telo[SNAKE_MAX_DLZKA];

    int pocet_click,pocet_kocka;
    int xzac,yzac,xkon,ykon;
    float mini;
    int Xmouse,Ymouse,click_mouse;
    int W_click,S_click,E_click,C_click,R_click;
    int go,bod;
    float ressol_multip;

    int cesta[1000][2];
    int close_pocet,cesta_pocitadlo;
    int cesta_pocet,cesta_celk_pocet;
    int snake_game,snake_cesta;
    int a_star;
    int snake_spocitane;
    int snake_telo_dlzka;
    int snake_last[1][2];
    int exis_cesta;
    int zaciatok_nacitanie;
    int delay_cas;

} SYSTEM;


void rendering(SDL_Renderer *renderer,SYSTEM *syst);
void control(SDL_Window *window, SYSTEM *syst,int *work);
void nacitavam(int x);
void set_scene(SYSTEM *syst);
void procesing(SYSTEM *syst, int *work);
void zac_nacitanie(SYSTEM *syst);
float faabs(float x);
void nacit_udaj(SYSTEM *syst);
void nul_kolo(SYSTEM *syst);
void grey_wall(SYSTEM *syst);
void game_engine(SYSTEM *syst,int *work);
void food(SYSTEM *syst);
void textova_obrazovka(SYSTEM *syst);

#endif // MAIN_H_INCLUDED
