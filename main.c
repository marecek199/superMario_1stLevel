
#include "main.h"



void nacitaj_hru(StavHry *stav)
{
    nacitaj_obrazky(stav);

    ///nacitat font
    stav->font = NULL;
    stav->font = TTF_OpenFont("\FONT\\Crazy-Pixels.ttf",48);
    if(!stav->font)
    {
        printf("TTF_OpenFont : %s\n", TTF_GetError());
        SDL_Quit();
        return 0;
//        exit(1);
    }

//    ///nacitat sound
    stav->bgMs = Mix_LoadWAV("\Music\\overworld.ogg");
    if(stav->bgMs == NULL)
    {
        printf("MIX : %s\n", Mix_GetError());
        SDL_Quit();
        return 0;
//        exit(1);

    }
    Mix_VolumeChunk(stav->bgMs,7);
    stav->jmpSound = Mix_LoadWAV("\Music\\jump_super.wav");
    if(stav->jmpSound == NULL)
    {
        printf("MIX : %s\n", Mix_GetError());
        SDL_Quit();
        return 0;
    }
    Mix_VolumeChunk(stav->jmpSound,6);

    stav->game_over = Mix_LoadWAV("\Music\\game_over.wav");
    if(stav->game_over == NULL)
    {
        printf("MIX : %s\n", Mix_GetError());
        SDL_Quit();
        return 0;
    }
    Mix_VolumeChunk(stav->game_over,6);

    stav->stage_clear = Mix_LoadWAV("\Music\\stage_clear.wav");
    if(stav->stage_clear == NULL)
    {
        printf("MIX : %s\n", Mix_GetError());
        SDL_Quit();
        return 0;
    }
    Mix_VolumeChunk(stav->stage_clear,6);

    stav->m_die = Mix_LoadWAV("\Music\\mario_die.wav");
    if(stav->m_die == NULL)
    {
        printf("MIX : %s\n", Mix_GetError());
        SDL_Quit();
        return 0;
    }
    Mix_VolumeChunk(stav->m_die,6);



    stav->znacka[0]=NULL;
    stav->znacka[1]=NULL;


    stav->clovek.x=200;
    stav->clovek.y=300;
    stav->clovek.dy=0;
    stav->clovek.dx=0;
    stav->clovek.na_podlahe=0;
    stav->celk_frames=0;
    stav->clovek.anim_frame=0;
    stav->clovek.vlavo_hlad=0;
    stav->clovek.spomalovanie=0;
    stav->clovek.lifes=3;
    stav->scroll=0;
    stav->clovek.mrtvy=0;
    stav->clovek.body=0;
    stav->cislo_kocky[0]=0;
    stav->cislo_kocky[1]=0;
    stav->cislo_kocky[2]=0;
    stav->cislo_kocky[3]=0;
    stav->prvy_raz_rychlost=0;
    stav->prvy_raz_pad=0;
    stav->clovek.anim_frame_skok=3;
    stav->render_stop=0;
    stav->cislo_vyhra=VYPNUTE;


    stav->StatusHry=HRA_STATUS_ZIVOTY;
    inicText_zaciatok(stav);

    rozmiestnenie(stav);
    umiestni_zvierata(stav);

    for(int k=0 ; k < 14 ; k++)
        stav->zviera[k].vlavo_hlad=2;

}


void nacitaj_obrazky(StavHry *stav)
{
    SDL_Surface *obrazec= NULL;

    if( (obrazec=IMG_Load("\IMAGES\\world.GIF")) == NULL )
    {
        printf("Neotvorilo obrazok");
        IMG_GetError();
        SDL_Quit();
        return 0;
//        exit(1);
    }
    stav->world = SDL_CreateTextureFromSurface(stav->renderer, obrazec);
    SDL_FreeSurface(obrazec);

    if( (obrazec=IMG_Load("\IMAGES\\mario1.PNG")) == NULL )
    {
        printf("Neotvorilo obrazok");
        IMG_GetError();
        SDL_Quit();
        return 0;
//        exit(1);
    }
    stav->mario[0] = SDL_CreateTextureFromSurface(stav->renderer, obrazec);
    SDL_FreeSurface(obrazec);

    if( (obrazec=IMG_Load("\IMAGES\\mario3.PNG")) == NULL )
    {
        printf("Neotvorilo obrazok");
        IMG_GetError();
        SDL_Quit();
        return 0;
//        exit(1);
    }
    stav->mario[1] = SDL_CreateTextureFromSurface(stav->renderer, obrazec);
    SDL_FreeSurface(obrazec);

    if( (obrazec=IMG_Load("\IMAGES\\mario4.PNG")) == NULL )
    {
        printf("Neotvorilo obrazok");
        IMG_GetError();
        SDL_Quit();
        return 0;
//        exit(1);
    }
    stav->mario[2] = SDL_CreateTextureFromSurface(stav->renderer, obrazec);
    SDL_FreeSurface(obrazec);

    if( (obrazec=IMG_Load("\IMAGES\\mario5.PNG")) == NULL )
    {
        printf("Neotvorilo obrazok");
        IMG_GetError();
        SDL_Quit();
        return 0;
//        exit(1);
    }
    stav->mario[3] = SDL_CreateTextureFromSurface(stav->renderer, obrazec);
    SDL_FreeSurface(obrazec);

    if( (obrazec=IMG_Load("\IMAGES\\mario_rope.PNG")) == NULL )
    {
        printf("Neotvorilo obrazok");
        IMG_GetError();
        SDL_Quit();
        return 0;
//        exit(1);
    }
    stav->mario[4] = SDL_CreateTextureFromSurface(stav->renderer, obrazec);
    SDL_FreeSurface(obrazec);

    if( (obrazec=IMG_Load("\IMAGES\\mario_win.PNG")) == NULL )
    {
        printf("Neotvorilo obrazok");
        IMG_GetError();
        SDL_Quit();
        return 0;
//        exit(1);
    }
    stav->mario[5] = SDL_CreateTextureFromSurface(stav->renderer, obrazec);
    SDL_FreeSurface(obrazec);

    if( (obrazec=IMG_Load("\IMAGES\\priserka1.PNG")) == NULL )
    {
        printf("Neotvorilo obrazok");
        IMG_GetError();
        SDL_Quit();
        return 0;
//        exit(1);
    }
    stav->enemy1 = SDL_CreateTextureFromSurface(stav->renderer, obrazec);
    SDL_FreeSurface(obrazec);



    if( (obrazec=IMG_Load("\IMAGES\\obloha.PNG")) == NULL )
    {
        printf("Neotvorilo obrazok");
        IMG_GetError();
        SDL_Quit();
        return 0;
//        exit(1);
    }
    stav->obloha = SDL_CreateTextureFromSurface(stav->renderer, obrazec);
    SDL_FreeSurface(obrazec);


    if( (obrazec=IMG_Load("\IMAGES\\blok0.JPG")) == NULL )
    {
        printf("Neotvorilo obrazok");
        IMG_GetError();
        SDL_Quit();
        return 0;
//        exit(1);
    }
    stav->kocka_img[0] = SDL_CreateTextureFromSurface(stav->renderer, obrazec);
    SDL_FreeSurface(obrazec);


    if( (obrazec=IMG_Load("\IMAGES\\blok1.JPG")) == NULL )
    {
        printf("Neotvorilo obrazok");
        IMG_GetError();
        SDL_Quit();
        return 0;
//        exit(1);
    }
    stav->kocka_img[1] = SDL_CreateTextureFromSurface(stav->renderer, obrazec);
    SDL_FreeSurface(obrazec);

    if( (obrazec=IMG_Load("\IMAGES\\blok2.JPG")) == NULL )
    {
        printf("Neotvorilo obrazok");
        IMG_GetError();
        SDL_Quit();
        return 0;
//        exit(1);
    }
    stav->kocka_img[2] = SDL_CreateTextureFromSurface(stav->renderer, obrazec);
    SDL_FreeSurface(obrazec);

    if( (obrazec=IMG_Load("\IMAGES\\blok3.JPG")) == NULL )
    {
        printf("Neotvorilo obrazok");
        IMG_GetError();
        SDL_Quit();
        return 0;
//        exit(1);
    }
    stav->kocka_img[3] = SDL_CreateTextureFromSurface(stav->renderer, obrazec);
    SDL_FreeSurface(obrazec);

    if( (obrazec=IMG_Load("\IMAGES\\blok4.JPG")) == NULL )
    {
        printf("Neotvorilo obrazok");
        IMG_GetError();
        SDL_Quit();
        return 0;
//        exit(1);
    }
    stav->kocka_img[4] = SDL_CreateTextureFromSurface(stav->renderer, obrazec);
    SDL_FreeSurface(obrazec);

}

void umiestni_zvierata(StavHry *stav)
{
    stav->zviera[0].x=919;
    stav->zviera[0].y=350;
    stav->zviera[0].dx=0;
    stav->zviera[0].dy=0;

    stav->zviera[1].x=1543;
    stav->zviera[1].y=350;
    stav->zviera[1].dx=0;
    stav->zviera[1].dy=0;

    stav->zviera[2].x=1900;
    stav->zviera[2].y=350;
    stav->zviera[2].dx=0;
    stav->zviera[2].dy=0;

    stav->zviera[3].x=1800;
    stav->zviera[3].y=350;
    stav->zviera[3].dx=0;
    stav->zviera[3].dy=0;

    stav->zviera[4].x=2905;
    stav->zviera[4].y=110;
    stav->zviera[4].dx=0;
    stav->zviera[4].dy=0;

    stav->zviera[5].x=2840;
    stav->zviera[5].y=110;
    stav->zviera[5].dx=0;
    stav->zviera[5].dy=0;

    stav->zviera[6].x=3800;
    stav->zviera[6].y=350;
    stav->zviera[6].dx=0;
    stav->zviera[6].dy=0;

    stav->zviera[7].x=3950;
    stav->zviera[7].y=350;
    stav->zviera[7].dx=0;
    stav->zviera[7].dy=0;

    stav->zviera[8].x=4350;
    stav->zviera[8].y=350;
    stav->zviera[8].dx=0;
    stav->zviera[8].dy=0;

    stav->zviera[9].x=4400;
    stav->zviera[9].y=350;
    stav->zviera[9].dx=0;
    stav->zviera[9].dy=0;

    stav->zviera[10].x=4450;
    stav->zviera[10].y=350;
    stav->zviera[10].dx=0;
    stav->zviera[10].dy=0;


    stav->zviera[11].x=4500;
    stav->zviera[11].y=350;
    stav->zviera[11].dx=0;
    stav->zviera[11].dy=0;

    stav->zviera[12].x=6080;
    stav->zviera[12].y=350;
    stav->zviera[12].dx=0;
    stav->zviera[12].dy=0;

    stav->zviera[13].x=6010;
    stav->zviera[13].y=350;
    stav->zviera[13].dx=0;
    stav->zviera[13].dy=0;

}



void rozmiestnenie(StavHry *stav)
{
    /// SVET
    vyskl_svet(stav);

    ///Blok0
    vyskl_blok0(stav);

    ///BLOK1
    vyskl_blok1(stav);

    ///BLOK2
    vyskl_blok2(stav);

    ///ZELENY
    vyskl_zelene(stav);


//    ///BlOK3
//    vyskl_blok3(stav);

}

void vyskl_zelene(StavHry *stav)
{
    stav->cislo_kocky[3] = stav->cislo_kocky[2];

    stav->kocka[stav->cislo_kocky[3]].x=958+2;
    stav->kocka[stav->cislo_kocky[3]].y=VYSKA2_KOCKA+2*YKOCKA_GRAPHIX;
    stav->kocka[stav->cislo_kocky[3]].s=2*XKOCKA_GRAPHIX-4;
    stav->kocka[stav->cislo_kocky[3]].v=2*YKOCKA_GRAPHIX;
    stav->cislo_kocky[3]++;

    stav->kocka[stav->cislo_kocky[3]].x=1301+2;
    stav->kocka[stav->cislo_kocky[3]].y=VYSKA2_KOCKA+YKOCKA_GRAPHIX;
    stav->kocka[stav->cislo_kocky[3]].s=2*XKOCKA_GRAPHIX-4;
    stav->kocka[stav->cislo_kocky[3]].v=3*YKOCKA_GRAPHIX;
    stav->cislo_kocky[3]++;

    stav->kocka[stav->cislo_kocky[3]].x=1575+2;
    stav->kocka[stav->cislo_kocky[3]].y=VYSKA2_KOCKA;
    stav->kocka[stav->cislo_kocky[3]].s=2*XKOCKA_GRAPHIX-4;
    stav->kocka[stav->cislo_kocky[3]].v=4*YKOCKA_GRAPHIX;
    stav->cislo_kocky[3]++;

    stav->kocka[stav->cislo_kocky[3]].x=1952+2;
    stav->kocka[stav->cislo_kocky[3]].y=VYSKA2_KOCKA;
    stav->kocka[stav->cislo_kocky[3]].s=2*XKOCKA_GRAPHIX-4;
    stav->kocka[stav->cislo_kocky[3]].v=4*YKOCKA_GRAPHIX;
    stav->cislo_kocky[3]++;

    stav->kocka[stav->cislo_kocky[3]].x=5579+2;
    stav->kocka[stav->cislo_kocky[3]].y=VYSKA2_KOCKA+2*YKOCKA_GRAPHIX;
    stav->kocka[stav->cislo_kocky[3]].s=2*XKOCKA_GRAPHIX-4;
    stav->kocka[stav->cislo_kocky[3]].v=2*YKOCKA_GRAPHIX;
    stav->cislo_kocky[3]++;

    stav->kocka[stav->cislo_kocky[3]].x=6128+2;
    stav->kocka[stav->cislo_kocky[3]].y=VYSKA2_KOCKA+2*YKOCKA_GRAPHIX;
    stav->kocka[stav->cislo_kocky[3]].s=2*XKOCKA_GRAPHIX-4;
    stav->kocka[stav->cislo_kocky[3]].v=2*YKOCKA_GRAPHIX;
    stav->cislo_kocky[3]++;

}




void vyskl_blok2(StavHry *stav)
{
    stav->cislo_kocky[2] = stav->cislo_kocky[1];
    int i;

    stav->kocka[stav->cislo_kocky[2]].x=548;
    stav->kocka[stav->cislo_kocky[2]].y=VYSKA2_KOCKA-2;
    stav->kocka[stav->cislo_kocky[2]].s=XKOCKA_GRAPHIX;
    stav->kocka[stav->cislo_kocky[2]].v=YKOCKA_GRAPHIX;
    stav->cislo_kocky[2]++;

    for(i=0; i<2; i++)
    {
        stav->kocka[stav->cislo_kocky[2]].x=685+XKOCKA_GRAPHIX+2*i*(XKOCKA_GRAPHIX-FOR_NAPASOVANIE);
        stav->kocka[stav->cislo_kocky[2]].y=VYSKA2_KOCKA-2;
        stav->kocka[stav->cislo_kocky[2]].s=XKOCKA_GRAPHIX;
        stav->kocka[stav->cislo_kocky[2]].v=YKOCKA_GRAPHIX;
        stav->cislo_kocky[2]++;
    }

    stav->kocka[stav->cislo_kocky[2]].x=683+2*XKOCKA_GRAPHIX;
    stav->kocka[stav->cislo_kocky[2]].y=VYSKA1_KOCKA;
    stav->kocka[stav->cislo_kocky[2]].s=XKOCKA_GRAPHIX;
    stav->kocka[stav->cislo_kocky[2]].v=YKOCKA_GRAPHIX;
    stav->cislo_kocky[2]++;

    stav->kocka[stav->cislo_kocky[2]].x=2634+XKOCKA_GRAPHIX;
    stav->kocka[stav->cislo_kocky[2]].y=VYSKA2_KOCKA-2;
    stav->kocka[stav->cislo_kocky[2]].s=XKOCKA_GRAPHIX;
    stav->kocka[stav->cislo_kocky[2]].v=YKOCKA_GRAPHIX;
    stav->cislo_kocky[2]++;

    stav->kocka[stav->cislo_kocky[2]].x=3115+3*XKOCKA_GRAPHIX;
    stav->kocka[stav->cislo_kocky[2]].y=VYSKA1_KOCKA;
    stav->kocka[stav->cislo_kocky[2]].s=XKOCKA_GRAPHIX;
    stav->kocka[stav->cislo_kocky[2]].v=YKOCKA_GRAPHIX;
    stav->cislo_kocky[2]++;

    for( i=0; i<3; i++)
    {
        stav->kocka[stav->cislo_kocky[2]].x=3628+3*i*(XKOCKA_GRAPHIX-FOR_NAPASOVANIE);
        stav->kocka[stav->cislo_kocky[2]].y=VYSKA2_KOCKA-2;
        stav->kocka[stav->cislo_kocky[2]].s=XKOCKA_GRAPHIX;
        stav->kocka[stav->cislo_kocky[2]].v=YKOCKA_GRAPHIX;
        stav->cislo_kocky[2]++;

        if( i==1 )
        {
            stav->kocka[stav->cislo_kocky[2]].x=3628+3*i*(XKOCKA_GRAPHIX-FOR_NAPASOVANIE);
            stav->kocka[stav->cislo_kocky[2]].y=VYSKA1_KOCKA-2;
            stav->kocka[stav->cislo_kocky[2]].s=XKOCKA_GRAPHIX;
            stav->kocka[stav->cislo_kocky[2]].v=YKOCKA_GRAPHIX;
            stav->cislo_kocky[2]++;
        }
    }


    for( i=0; i<2; i++)
    {
        stav->kocka[stav->cislo_kocky[2]].x=4380+XKOCKA_GRAPHIX+i*(XKOCKA_GRAPHIX-FOR_NAPASOVANIE);
        stav->kocka[stav->cislo_kocky[2]].y=VYSKA1_KOCKA-2;
        stav->kocka[stav->cislo_kocky[2]].s=XKOCKA_GRAPHIX;
        stav->kocka[stav->cislo_kocky[2]].v=YKOCKA_GRAPHIX;
        stav->cislo_kocky[2]++;
    }

    stav->kocka[stav->cislo_kocky[2]].x=5750+2*XKOCKA_GRAPHIX;
    stav->kocka[stav->cislo_kocky[2]].y=VYSKA2_KOCKA-2;
    stav->kocka[stav->cislo_kocky[2]].s=XKOCKA_GRAPHIX;
    stav->kocka[stav->cislo_kocky[2]].v=YKOCKA_GRAPHIX;
    stav->cislo_kocky[2]++;

}



void vyskl_blok1(StavHry *stav)
{
    stav->cislo_kocky[1] = stav->cislo_kocky[0];
    int i;

    for( i=0; i<3; i++)
    {
        stav->kocka[stav->cislo_kocky[1]].x=685+2*i*(XKOCKA_GRAPHIX-FOR_NAPASOVANIE);
        stav->kocka[stav->cislo_kocky[1]].y=VYSKA2_KOCKA-2;
        stav->kocka[stav->cislo_kocky[1]].s=XKOCKA_GRAPHIX;
        stav->kocka[stav->cislo_kocky[1]].v=YKOCKA_GRAPHIX;
        stav->cislo_kocky[1]++;
    }

    for( i=0; i<2; i++)
    {
        stav->kocka[stav->cislo_kocky[1]].x=2634+2*i*(XKOCKA_GRAPHIX-FOR_NAPASOVANIE);
        stav->kocka[stav->cislo_kocky[1]].y=VYSKA2_KOCKA-2;
        stav->kocka[stav->cislo_kocky[1]].s=XKOCKA_GRAPHIX;
        stav->kocka[stav->cislo_kocky[1]].v=YKOCKA_GRAPHIX;
        stav->cislo_kocky[1]++;
    }

    for( i=0; i<8; i++)
    {
        stav->kocka[stav->cislo_kocky[1]].x=2738+i*(XKOCKA_GRAPHIX-FOR_NAPASOVANIE);
        stav->kocka[stav->cislo_kocky[1]].y=VYSKA1_KOCKA;
        stav->kocka[stav->cislo_kocky[1]].s=XKOCKA_GRAPHIX;
        stav->kocka[stav->cislo_kocky[1]].v=YKOCKA_GRAPHIX;
        stav->cislo_kocky[1]++;
    }

    for( i=0; i<3; i++)
    {
        stav->kocka[stav->cislo_kocky[1]].x=3115+i*(XKOCKA_GRAPHIX-FOR_NAPASOVANIE);
        stav->kocka[stav->cislo_kocky[1]].y=VYSKA1_KOCKA;
        stav->kocka[stav->cislo_kocky[1]].s=XKOCKA_GRAPHIX;
        stav->kocka[stav->cislo_kocky[1]].v=YKOCKA_GRAPHIX;
        stav->cislo_kocky[1]++;
    }

    stav->kocka[stav->cislo_kocky[1]].x=3115+3*XKOCKA_GRAPHIX;
    stav->kocka[stav->cislo_kocky[1]].y=VYSKA2_KOCKA-2;
    stav->kocka[stav->cislo_kocky[1]].s=XKOCKA_GRAPHIX;
    stav->kocka[stav->cislo_kocky[1]].v=YKOCKA_GRAPHIX;
    stav->cislo_kocky[1]++;

    for(i=0;i<2;i++)
    {
        stav->kocka[stav->cislo_kocky[1]].x=3423+i*(XKOCKA_GRAPHIX-FOR_NAPASOVANIE);
        stav->kocka[stav->cislo_kocky[1]].y=VYSKA2_KOCKA-2;
        stav->kocka[stav->cislo_kocky[1]].s=XKOCKA_GRAPHIX;
        stav->kocka[stav->cislo_kocky[1]].v=YKOCKA_GRAPHIX;
        stav->cislo_kocky[1]++;
    }

    stav->kocka[stav->cislo_kocky[1]].x=4039;
    stav->kocka[stav->cislo_kocky[1]].y=VYSKA2_KOCKA-2;
    stav->kocka[stav->cislo_kocky[1]].s=XKOCKA_GRAPHIX;
    stav->kocka[stav->cislo_kocky[1]].v=YKOCKA_GRAPHIX;
    stav->cislo_kocky[1]++;

    for( i=0; i<3; i++)
    {
        stav->kocka[stav->cislo_kocky[1]].x=4141+i*(XKOCKA_GRAPHIX-FOR_NAPASOVANIE);
        stav->kocka[stav->cislo_kocky[1]].y=VYSKA1_KOCKA;
        stav->kocka[stav->cislo_kocky[1]].s=XKOCKA_GRAPHIX;
        stav->kocka[stav->cislo_kocky[1]].v=YKOCKA_GRAPHIX;
        stav->cislo_kocky[1]++;
    }

    for( i=0; i<4; i++)
    {
        stav->kocka[stav->cislo_kocky[1]].x=4380+i*(XKOCKA_GRAPHIX-FOR_NAPASOVANIE);
        if(i==0 || i==3)
            stav->kocka[stav->cislo_kocky[1]].y=VYSKA1_KOCKA-2;
        else if(i==1 || i==2)
            stav->kocka[stav->cislo_kocky[1]].y=VYSKA2_KOCKA-2;
        stav->kocka[stav->cislo_kocky[1]].s=XKOCKA_GRAPHIX;
        stav->kocka[stav->cislo_kocky[1]].v=YKOCKA_GRAPHIX;
        stav->cislo_kocky[1]++;
    }

    for( i=0; i<4; i++)
    {
        if( i!=2 )
        {
            stav->kocka[stav->cislo_kocky[1]].x=5750+i*(XKOCKA_GRAPHIX-FOR_NAPASOVANIE);
            stav->kocka[stav->cislo_kocky[1]].y=VYSKA2_KOCKA-2;
            stav->kocka[stav->cislo_kocky[1]].s=XKOCKA_GRAPHIX;
            stav->kocka[stav->cislo_kocky[1]].v=YKOCKA_GRAPHIX;
            stav->cislo_kocky[1]++;
        }
    }

    ///dorabka 3ky bloky
    stav->kocka[stav->cislo_kocky[1]].x=2191;
    stav->kocka[stav->cislo_kocky[1]].y=VYSKA2_KOCKA-YKOCKA_GRAPHIX;
    stav->kocka[stav->cislo_kocky[1]].s=XKOCKA_GRAPHIX;
    stav->kocka[stav->cislo_kocky[1]].v=YKOCKA_GRAPHIX;
    stav->cislo_kocky[1]++;

}



void vyskl_blok0(StavHry *stav)
{
    vyskladaj(stav,4,4,HORE,4588);
    vyskladaj(stav,4,4,DOLE,4794);
    vyskladaj(stav,5,4,HORE,5067);
    vyskladaj(stav,4,4,DOLE,5307);
    vyskladaj(stav,9,8,HORE,6195);
    stav->cislo_kocky[0]++;
    stav->kocka[stav->cislo_kocky[0]-1].x=6780;
    stav->kocka[stav->cislo_kocky[0]-1].y=393;
    stav->kocka[stav->cislo_kocky[0]-1].s=XKOCKA_GRAPHIX;
    stav->kocka[stav->cislo_kocky[0]-1].v=YKOCKA_GRAPHIX;
}



void vyskl_svet(StavHry *stav)
{
    stav->svet.x=0;
    stav->svet.y=0;
    stav->svet.v=224*2.14;
    stav->svet.s=3384*2.14;
}

void vyskladaj(StavHry *stav,int sirka_pocet, int vyska_pocet, int smer, int Xzaciatok)
{
    int sirka=sirka_pocet;
    int vyska=vyska_pocet;

    float zaciatok = Xzaciatok;

    if(smer == 1)
        {
            for(int r=0; r<vyska; r++)
            {
                for(int s=0; s < sirka; s++)
                {
                    stav->kocka[stav->cislo_kocky[0]].x = zaciatok + XKOCKA_GRAPHIX*(r+s);
                    stav->kocka[stav->cislo_kocky[0]].y = 393-r*YKOCKA_GRAPHIX;
                    stav->kocka[stav->cislo_kocky[0]].s = XKOCKA_GRAPHIX;
                    stav->kocka[stav->cislo_kocky[0]].v = YKOCKA_GRAPHIX;
                    stav->cislo_kocky[0]++;
                }
                sirka--;
            }
        }
    else if (smer == -1)
          {
            for(int r=0; r<vyska; r++)
            {
                for(int s=0; s < sirka; s++)
                {
                    stav->kocka[stav->cislo_kocky[0]].x = zaciatok + XKOCKA_GRAPHIX*s;
                    stav->kocka[stav->cislo_kocky[0]].y = 393-r*YKOCKA_GRAPHIX;
                    stav->kocka[stav->cislo_kocky[0]].s = XKOCKA_GRAPHIX;
                    stav->kocka[stav->cislo_kocky[0]].v = YKOCKA_GRAPHIX;
                    stav->cislo_kocky[0]++;
                }
                sirka--;
            }
        }
    else
        {
            printf("Zadali ste zly smer 'kockovania' ");
            return 0;
//            exit(1);
        }
}







void vyrendruj(SDL_Renderer *renderer, StavHry *stav)
{
    ///ZACIATOK
    if(stav->StatusHry == HRA_STATUS_ZIVOTY)
    {
        //napis_koniec_hry(stav);
        napis_zivoty(stav);
    }
    ///HRA
    else if(stav->StatusHry == HRA_STATUS_HRA || stav->StatusHry == HRA_STATUS_VYHRA)
    {
        SDL_SetRenderDrawColor(renderer,128,128,255,255);
        SDL_RenderClear(renderer);

        SDL_Rect world_rect={stav->scroll+stav->svet.x,stav->svet.y,stav->svet.s,stav->svet.v};
        SDL_RenderCopy(renderer,stav->world,NULL,&world_rect);

        // Vyrendruva modru oblohu

        //blok1
        for(int i=stav->cislo_kocky[0]; i < stav->cislo_kocky[1] ; i++)
        {
            SDL_Rect kocka_rect={stav->scroll+stav->kocka[i].x,stav->kocka[i].y,stav->kocka[i].s*2,stav->kocka[i].v*2};
            SDL_RenderCopy(renderer,stav->obloha,NULL,&kocka_rect);
        }

        //blok2
        for(int i=stav->cislo_kocky[1] ; i < stav->cislo_kocky[2] ; i++)
        {
            SDL_Rect kocka_rect={stav->scroll+stav->kocka[i].x,stav->kocka[i].y,stav->kocka[i].s*2,stav->kocka[i].v*2};
            SDL_RenderCopy(renderer,stav->obloha,NULL,&kocka_rect);
        }
       // Vyrendruva kocky
//        ///blok0
//        for(int i=0; i < stav->cislo_kocky[0] ; i++)
//        {
//            SDL_Rect kocka_rect={stav->scroll+stav->kocka[i].x,stav->kocka[i].y,stav->kocka[i].s,stav->kocka[i].v};
//            SDL_RenderCopy(renderer,stav->kocka_img[0],NULL,&kocka_rect);
//        }
        //Vymodri zvierata
        SDL_Rect kocka_rect0={stav->scroll+5920,390,94,4+MARIO_GRAPHIX};
        SDL_RenderCopy(renderer,stav->obloha,NULL,&kocka_rect0);

        SDL_Rect kocka_rect1={stav->scroll+694,390,46,4+MARIO_GRAPHIX};
        SDL_RenderCopy(renderer,stav->obloha,NULL,&kocka_rect1);

        SDL_Rect kocka_rect2={stav->scroll+4217,390,211,4+MARIO_GRAPHIX};
        SDL_RenderCopy(renderer,stav->obloha,NULL,&kocka_rect2);

        SDL_Rect kocka_rect3={stav->scroll+1370,390,44,4+MARIO_GRAPHIX};
        SDL_RenderCopy(renderer,stav->obloha,NULL,&kocka_rect3);

        SDL_Rect kocka_rect4={stav->scroll+1792,390,95,4+MARIO_GRAPHIX};
        SDL_RenderCopy(renderer,stav->obloha,NULL,&kocka_rect4);

        SDL_Rect kocka_rect5={stav->scroll+2687,200,60,10+MARIO_GRAPHIX};
        SDL_RenderCopy(renderer,stav->obloha,NULL,&kocka_rect5);

        SDL_Rect kocka_rect6={stav->scroll+2787,120-4,50,60};
        SDL_RenderCopy(renderer,stav->obloha,NULL,&kocka_rect6);

        SDL_Rect kocka_rect7={stav->scroll+3235,390,230,4+MARIO_GRAPHIX};
        SDL_RenderCopy(renderer,stav->obloha,NULL,&kocka_rect7);




        //blok1
        for(int i=stav->cislo_kocky[0]; i < stav->cislo_kocky[1] ; i++)
        {
            SDL_Rect kocka_rect={stav->scroll+stav->kocka[i].x,stav->kocka[i].y,stav->kocka[i].s,stav->kocka[i].v};
            SDL_RenderCopy(renderer,stav->kocka_img[1],NULL,&kocka_rect);
        }

        //blok2
        for(int i=stav->cislo_kocky[1] ; i < stav->cislo_kocky[2] ; i++)
        {
            SDL_Rect kocka_rect={stav->scroll+stav->kocka[i].x,stav->kocka[i].y,stav->kocka[i].s,stav->kocka[i].v};
            SDL_RenderCopy(renderer,stav->kocka_img[2],NULL,&kocka_rect);
        }

        //zvierata

        for(int i=0; i<14; i++ )
        {
            SDL_Rect zviera_rect={stav->scroll+stav->zviera[i].x,stav->zviera[i].y,MARIO_GRAPHIX,MARIO_GRAPHIX};
            SDL_RenderCopyEx(renderer,stav->enemy1,NULL,&zviera_rect,0,NULL, (stav->zviera[i].anim_frame==1) );
        }

        //MARIO
        if(!stav->render_stop)
        {
            SDL_Rect mario_rect={stav->scroll+stav->clovek.x,stav->clovek.y,MARIO_GRAPHIX,MARIO_GRAPHIX};
            if(stav->clovek.na_podlahe!=0)
                SDL_RenderCopyEx(renderer,stav->mario[stav->clovek.anim_frame],NULL,&mario_rect,0,NULL, (stav->clovek.vlavo_hlad==1));
            else
                SDL_RenderCopyEx(renderer,stav->mario[stav->clovek.anim_frame_skok],NULL,&mario_rect,0,NULL, (stav->clovek.vlavo_hlad==1));
        }
        //TEXT ZIVOTOV
        inicText_zivoty(stav);
        SDL_Rect textRect = {320-stav->znackaW[0]/2,55-stav->znackaH[0]/2,stav->znackaW[0],stav->znackaH[0]};
        SDL_RenderCopy(renderer,stav->znacka[0],NULL,&textRect);

        SDL_RenderPresent(renderer);
    }

    ///VYHRA
    else if(stav->StatusHry == HRA_STATUS_VYHRA_KONEC)
        {

                    SDL_SetRenderDrawColor(renderer,128,128,255,255);
                    SDL_RenderClear(renderer);

                    SDL_Rect world_rect={stav->scroll+stav->svet.x,stav->svet.y,stav->svet.s,stav->svet.v};
                    SDL_RenderCopy(renderer,stav->world,NULL,&world_rect);

                    //blok1
                    for(int i=stav->cislo_kocky[0]; i < stav->cislo_kocky[1] ; i++)
                    {
                        SDL_Rect kocka_rect={stav->scroll+stav->kocka[i].x,stav->kocka[i].y,stav->kocka[i].s,stav->kocka[i].v};
                        SDL_RenderCopy(renderer,stav->kocka_img[1],NULL,&kocka_rect);
                    }
                    //TEXT ZIVOTOV
                    inicText_zivoty(stav);
                    SDL_Rect textRect = {320-stav->znackaW[0]/2,55-stav->znackaH[0]/2,stav->znackaW[0],stav->znackaH[0]};
                    SDL_RenderCopy(renderer,stav->znacka[0],NULL,&textRect);

                    SDL_RenderPresent(renderer);
            SDL_Delay(700);
            inicText_vyhra_hry(stav);
            napis_vyhra_hry(stav);
            SDL_Delay(3000);
            exit(1);
        }


    ///GAME_OVER
    else if(stav->StatusHry == HRA_STATUS_KONEC)
        {
            inicText_koniecHry(stav);
            napis_koniec_hry(stav);
            SDL_Delay(3000);
            return 0;
//            exit(1);
        }
}



void proces(StavHry *stav)
{
    if(stav->clovek.lifes>0)
    {
        stav->celk_frames++;

        if(stav->celk_frames == 150)
        {
            //shutdown_status_live(stav);
            stav->cislo_vyhra=0;
            stav->StatusHry=HRA_STATUS_HRA;
            stav->musicChannel = Mix_PlayChannel(-1,stav->bgMs,-1);
        }

        if ( (stav->StatusHry == HRA_STATUS_HRA || stav->StatusHry == HRA_STATUS_VYHRA) )
        {
            ///HRA
            if(!stav->clovek.mrtvy && stav->clovek.x < 6777 )
            {
                ///MARIO
                stav->clovek.x += stav->clovek.dx;
                stav->clovek.y += stav->clovek.dy;
                stav->clovek.dy += GRAVITY;

                /// Animacia maria
                if(stav->clovek.dx != 0 && stav->clovek.na_podlahe && stav->clovek.spomalovanie==0)
                {
                    if( (stav->celk_frames)%9 == 0 )
                    {
                        if(stav->clovek.anim_frame == 0)
                            stav->clovek.anim_frame=1;
                        else
                            stav->clovek.anim_frame=0;
                    }
                }
                stav->scroll = 200-stav->clovek.x;
                if(stav->scroll > 0)
                    stav->scroll=0;
                if(stav->scroll < -6600)
                    stav->scroll = -6600;

                printf("X-%f  Y-%f\n",stav->clovek.x,stav->clovek.y);
                //printf("%d\n",stav->clovek.mrtvy);

                ///-----------------------------------------------------------------------

                //ZVIERATA
                for(int k=0;k<14;k++)
                {
                    stav->zviera[k].x += stav->zviera[k].vlavo_hlad;
                    stav->zviera[k].y += stav->zviera[k].dy;
                    stav->zviera[k].dy += GRAVITY;

                    if( (stav->celk_frames)%9 == 0 )
                    {
                        if(stav->zviera[k].anim_frame == 0)
                            stav->zviera[k].anim_frame = 1;
                        else
                            stav->zviera[k].anim_frame = 0;
                    }
                }


            }
            /// VYHRA
            else if (stav->clovek.x >= 6777)
            {


                // Lano
                if( (stav->clovek.x > 6777 && stav->clovek.x < 6783) && !stav->clovek.na_podlahe)
                    {

                        if( !stav->prvy_raz_rychlost )
                        {
                            stav->cislo_vyhra=VYPNUTE;
                            Mix_HaltChannel(stav->musicChannel);
                            Mix_PlayChannel(-1,stav->stage_clear,0);
                            stav->StatusHry=HRA_STATUS_VYHRA;
                            stav->clovek.dx=0;
                            stav->clovek.dy=0;
                            stav->clovek.spomalovanie=0;
                            stav->prvy_raz_rychlost=1;
                            stav->clovek.anim_frame_skok=4;
                        }

                        stav->clovek.y += stav->clovek.dy;
                        if(stav->clovek.dy < 3.5)
                        stav->clovek.dy += GRAVITY*0.7;

                    }

                // Na kocke
                else
                {
                    if(stav->clovek.x < 6983)
                       {
                            if(stav->clovek.dx < 1.5)
                                stav->clovek.dx+=0.2;
                            stav->clovek.x += stav->clovek.dx;
                            stav->clovek.y += stav->clovek.dy;
                            stav->clovek.dy += GRAVITY;

                           /// Animacia maria
                            if( stav->clovek.dx != 0 && stav->clovek.na_podlahe )
                            {
                                if( ( stav->celk_frames)%10 == 0 )
                                {
                                        if( stav->clovek.anim_frame == 1)
                                            {
                                                //printf("%d%d",stav->clovek.anim_frame);
                                                stav->clovek.anim_frame=0;
                                            }
                                        else if( stav->clovek.anim_frame == 0)
                                            {
                                                //printf("%d",stav->clovek.anim_frame);
                                                stav->clovek.anim_frame=1;
                                            }
                                }
                            }
                            stav->scroll = 200-stav->clovek.x;
                            if(stav->scroll < -6600)
                                stav->scroll = -6600;
                       }
                    else
                    {
                        stav->render_stop=1;
                        stav->StatusHry=HRA_STATUS_VYHRA_KONEC;
                    }
                }

            }
            /// Mrtvy
            else
            {
                Mix_HaltChannel(stav->musicChannel);
                Mix_PlayChannel(-1,stav->m_die,0);
                SDL_Delay(700);

                stav->clovek.lifes--;
                max_body(stav);
                inicText_zaciatok(stav);
                stav->StatusHry=HRA_STATUS_ZIVOTY;

                stav->clovek.x=200;
                stav->clovek.y=300;
                stav->clovek.dy=0;
                stav->clovek.dx=0;
                stav->clovek.na_podlahe=0;
                stav->celk_frames=0;
                stav->clovek.anim_frame=0;
                stav->clovek.vlavo_hlad=0;
                stav->clovek.spomalovanie=0;
                stav->scroll=0;
                stav->clovek.mrtvy=0;
            }
    }
}

    /// Koniec hry
    else
    {
        Mix_HaltChannel(stav->musicChannel);
        Mix_PlayChannel(-1,stav->m_die,0);
        SDL_Delay(800);
        Mix_PlayChannel(-1,stav->game_over,0);
        stav->StatusHry=HRA_STATUS_KONEC;
    }
}






///=============================================================================================================================================================================================
int main(int argc, char* argv[])
{
    SDL_Window *window;         //deklaracia okna
    SDL_Renderer *renderer;     //declaracia rendere
    StavHry stavhry;

    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);   //inicializacia SDL2
    IMG_Init(IMG_INIT_JPG);
    TTF_Init();

    Mix_OpenAudio(MIX_DEFAULT_FREQUENCY,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,4096);

    srand(time(0));

    window = SDL_CreateWindow("Hraci vokno",
                            SDL_WINDOWPOS_CENTERED,
                            SDL_WINDOWPOS_CENTERED,
                            640,
                            480,
                            0);
    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    stavhry.renderer=renderer;

    nacitaj_hru(&stavhry);
    int praca=1;

    while(praca)
    {
        praca = ovladanie(window, &stavhry);
        proces(&stavhry);
        kolizia_check(&stavhry);
        vyrendruj(renderer, &stavhry);
    }

    ///uvolni pamet..

    for(int i=0;i<4;i++)
        SDL_DestroyTexture(stavhry.mario[i]);

    for(int k=0;k<2;k++)
        {
            if(stavhry.znacka[k]!= NULL)
            {
                SDL_DestroyTexture(stavhry.znacka[k]);
            }
        }
    Mix_FreeChunk(stavhry.bgMs);
    Mix_FreeChunk(stavhry.jmpSound);
    Mix_FreeChunk(stavhry.game_over);
    Mix_FreeChunk(stavhry.stage_clear);
    Mix_FreeChunk(stavhry.m_die);
    TTF_CloseFont(stavhry.font);

    //znic okno
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    TTF_Quit();
    Mix_CloseAudio();
    SDL_Quit();

    return 0;
}

///=============================================================================================================================================================================================














void collideH(float mx, float my, float ms, float mv, float hx, float hy, float hs, float hv,StavHry *stav)
{
    if( mx+ms>hx && mx<hx+hs && my+mv>hy && my<hy+hv )
        stav->clovek.mrtvy=1;
}


int ovladanie(SDL_Window *window, StavHry *stav)
{
    SDL_Event event;
    int praca=1;

        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
                case SDL_WINDOWEVENT_CLOSE:
                    {
                        if(window)
                        {
                            SDL_DestroyWindow(window);
                            window= NULL;
                            praca=0;
                            return 0;
//                            exit(1);
                        }
                    }
                break;
                case SDL_KEYDOWN:
                    {
                        switch(event.key.keysym.sym)
                        {
                        case SDLK_ESCAPE:
                            praca=0;
                            return 0;
//                            exit(1);
                        break;
                        case SDLK_UP:
                            if( stav->cislo_vyhra != VYPNUTE)
                            {
                                if(stav->clovek.na_podlahe && stav->clovek.dy<=GRAVITY)
                                {
                                    stav->clovek.dy = -6;
                                    stav->clovek.na_podlahe=0;
                                    Mix_PlayChannel(-1,stav->jmpSound,0);
                                }
                            }

                        break;
                        }
                    }
                break;

                case SDL_QUIT:
                    {
                        praca=0;
                        return 0;
//                        exit(1);
                    }
                break;
            }
        }

    if( stav->cislo_vyhra != VYPNUTE)
    {
            const Uint8 *state = SDL_GetKeyboardState(NULL);


            if(state[SDL_SCANCODE_UP])
            {
                stav->clovek.dy -= 0.1;
            }

            if(state[SDL_SCANCODE_RIGHT])
            {
                if(stav->clovek.dx < 5)
                    stav->clovek.dx+=0.5;
                stav->clovek.vlavo_hlad=0;
                stav->clovek.spomalovanie=0;
            }

            else if(state[SDL_SCANCODE_LEFT])
            {
                if(stav->clovek.dx > -5)
                    stav->clovek.dx-=0.5;
                stav->clovek.vlavo_hlad=1;
                stav->clovek.spomalovanie=0;
            }

            else
            {
                    if( stav->clovek.spomalovanie == 0 )
                    {
                        stav->clovek.spomalovanie=1;
                        stav->clovek.anim_frame=0;
                    }

                    stav->clovek.dx *= 0.7f;
                    if( absf(stav->clovek.dx) < 0.1f)
                    {
                        stav->clovek.dx = 0.0f;
                    }

            }
    }
    return praca;
}




void kolizia_check(StavHry *stav)
{
    float mx = stav->clovek.x;
    float my = stav->clovek.y;
    float mv = MARIO_GRAPHIX;
    float ms = MARIO_GRAPHIX;

    if(mx<0)
        stav->clovek.x=0;

    if( !( (mx > 2355 && mx<2405 && my>=430-mv) || ( mx>2940 && mx<3020 && my>=430-mv) || (mx > 5235 && mx<5275 && my>=430-mv) ) )
    {
        if( (my+mv) > 430)
        {
            stav->clovek.na_podlahe=1;
            stav->clovek.dy = 0;
            stav->clovek.y=430-mv;
        }
    }
    else
    {
        stav->clovek.dx *= 0.6;
            if(my+mv>510)
                stav->clovek.mrtvy=1;
    }

    for(int i = 0; i < ( stav->cislo_kocky[0]+29+25); i++)
    {
        float px=stav->kocka[i].x;
        float py=stav->kocka[i].y;
        float pv=stav->kocka[i].v;
        float ps=stav->kocka[i].s;
        float dlzka[4],min=1000;
        int ind_min;

        dlzka[0]=-px+(mx+ms);
        dlzka[1]=px+ps-mx;
        dlzka[2]=-py+(my+mv);
        dlzka[3]=(py+pv)-my;

        if(  mx+ms>px && mx<px+ps && my+mv>py && my<py+pv)
        {
            for(int j=0;j<4;j++)
            {
                if( dlzka[j] < min)
                {
                    min=dlzka[j];
                    ind_min=j;
                }
            }
            switch(ind_min)
                {
                    case 0 :
                        {
                            stav->clovek.x=px-ms;
                            stav->clovek.dx=0;
                        }
                    break;
                    case 1 :
                        {
                            stav->clovek.x=px+ps;
                            stav->clovek.dx=0;
                        }
                    break;
                    case 2:
                        {
                            stav->clovek.y=py-ms;
                            stav->clovek.dy=0;
                            stav->clovek.na_podlahe=1;
                        }
                    break;
                    case 3:
                        {
                            stav->clovek.y=py+pv+1;
                            stav->clovek.dy=0;
                        }
                    break;
                }
        }
    }

    ///------------------------------------------------------------------

    //ZVIERA
    for(int k=0;k<14;k++)
    {
            float zx = stav->zviera[k].x;
            float zy = stav->zviera[k].y;
            float zv = MARIO_GRAPHIX;
            float zs = MARIO_GRAPHIX;

            for(int k=0;k<14;k++)
                collideH(mx,my,ms,mv,stav->zviera[k].x,stav->zviera[k].y,stav->zviera[k].s,stav->hviezdy[k].v,stav);

            if( zx < 0 )
                {
                    stav->zviera[k].x=0;
                    stav->zviera[k].vlavo_hlad*=-1;
                }

            if( k == 4 )
            {
                for(int j=0 ; j<2 ; j++)
                {
                    if( stav->zviera[k+j].x < 2426 )
                    {
                        stav->zviera[k+j].x=2426;
                        stav->zviera[k+j].vlavo_hlad*=-1;
                    }
                    if( stav->zviera[k+j].x > 2910 )
                    {
                        stav->zviera[k+j].x=2910;
                        stav->zviera[k+j].vlavo_hlad*=-1;
                    }
                }
            }

            if( k == 6 )
            {
                for(int j=0 ; j<5 ; j++)
                {
                    if( stav->zviera[k+j].x < 3045 )
                    {
                        stav->zviera[k+j].x=3045;
                        stav->zviera[k+j].vlavo_hlad*=-1;
                    }
                }
            }


            if( !( (zx > 2355 && zx<2405 && zy>=430-zv) || ( zx>2940 && zx<3020 && zy>=430-zv) || (zx > 5235 && zx<5275 && zy>=430-zv) ) )
            {
                if( (zy+zv) > 430)
                {
                    stav->zviera[k].dy = 0;
                    stav->zviera[k].y=430-zv;
                }
            }

            for(int i = 0; i < ( stav->cislo_kocky[0]+29+25); i++)
            {
                float px=stav->kocka[i].x;
                float py=stav->kocka[i].y;
                float pv=stav->kocka[i].v;
                float ps=stav->kocka[i].s;
                float dlzka[4],min=1000;
                int ind_min;

                dlzka[0]=-px+(zx+zs);
                dlzka[1]=px+ps-zx;
                dlzka[2]=-py+(zy+zv);
                dlzka[3]=(py+pv)-zy;

                if(  zx+zs>px && zx<px+ps && zy+zv>py && zy<py+pv)
                {
                    for(int j=0;j<4;j++)
                    {
                        if( dlzka[j] < min)
                        {
                            min=dlzka[j];
                            ind_min=j;
                        }
                    }
                    switch(ind_min)
                        {
                            case 0 :
                                {
                                    stav->zviera[k].x=px-zs;
                                    stav->zviera[k].vlavo_hlad*=-1;
                                }
                            break;
                            case 1 :
                                {
                                    stav->zviera[k].x=px+ps;
                                    stav->zviera[k].vlavo_hlad*=-1;
                                }
                            break;
                            case 2:
                                {
                                    stav->zviera[k].y=py-zs;
                                    stav->zviera[k].dy=0;

                                }
                            break;
                            case 3:
                                {
                                    stav->zviera[k].y=py+pv+1;
                                    stav->zviera[k].dy=0;
                                }
                            break;
                        }
                }
            }
    }
}


float absf(float cislo)
{
    if(cislo < 0.0)
            return -cislo;
    return cislo;
}




