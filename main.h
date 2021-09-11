#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <stdio.h>
#include "time.h"
#include <windows.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>



#define MARIO_GRAPHIX   34
#define GRAVITY         0.23f

#define XKOCKA_GRAPHIX   34.6f
#define YKOCKA_GRAPHIX   34.1f
#define VYSKA1_KOCKA    154
#define VYSKA2_KOCKA    292
#define POCET_KOCIEK    200
#define FOR_NAPASOVANIE +1
#define POCET_ZVIERAT

#define HORE            1
#define DOLE            -1

#define HRA_STATUS_ZIVOTY       0
#define HRA_STATUS_HRA          1
#define HRA_STATUS_KONEC        2
#define HRA_STATUS_VYHRA        3
#define HRA_STATUS_VYHRA_KONEC  4
#define VYPNUTE                 5


typedef struct{
    float x,y,v,s;
    float dx,dy;
    int lifes;
    int na_podlahe;
    int anim_frame;
    int vlavo_hlad;
    int spomalovanie;
    int anim_frame_skok;
    int mrtvy;
    int body;
} OBJEKT;


typedef struct{
    float x,y,v,s;
}OKRAJ;


typedef struct{
    //scrol
    float scroll;

    //objekt
    OBJEKT clovek;
    OBJEKT zviera[30];

    //hviezdicky
    OKRAJ hviezdy[100];

    //texutury
    OKRAJ podlaha[100];
    OKRAJ kocka[500];
    OKRAJ svet;


    ///KOCKA
    int cislo_kocky[6];

    ///Sound
    Mix_Chunk *bgMs, *jmpSound,*game_over,*m_die,*stage_clear;
    int musicChannel;


    //obrazok
    SDL_Texture *hviezda;
    SDL_Texture *mario[6];
    SDL_Texture *cloviecik;
    SDL_Texture *hranol;
    SDL_Texture *kocka_img[6];
    SDL_Texture *world;
    SDL_Texture *obloha;
    SDL_Texture *znacka[2];
    SDL_Texture *enemy1;

    int znackaW[2],znackaH[2];
    int prvy_raz_rychlost,prvy_raz_pad,cislo_vyhra;
    int render_stop;

    //Font
    TTF_Font *font;

    //cas
    int celk_frames;
    int StatusHry;

    //Render
    SDL_Renderer *renderer;

} StavHry;

void collideH(float mx, float my, float ms, float mv, float hx, float hy, float hs, float hv,StavHry *stav);
void kolizia_check(StavHry *stav);
void pracicka(SDL_Window *window, StavHry *stav, int *praca);
float absf(float cislo);
void inicText_koniecHry(StavHry *stav);
void random_rozmiestnenie(StavHry *stav);
void max_body(StavHry *stav);
void vyskladaj(StavHry *stav,int sirka_pocet, int vyska_pocet, int smer, int Xzaciatok);
void vyskl_svet(StavHry *stav);
void vyskl_blok0(StavHry *stav);
void vyskl_blok1(StavHry *stav);
void vyskl_blok2(StavHry *stav);
void vyskl_zelene(StavHry *stav);
void rozmiestnenie(StavHry *stav);
void nacitaj_hru(StavHry *stav);
void nacitaj_obrazky(StavHry *stav);
int ovladanie(SDL_Window *window, StavHry *stav);
void napis_vyhra_hry(StavHry *stav);
void inicText_vyhra_hry(StavHry *stav);


#endif // MAIN_H_INCLUDED
