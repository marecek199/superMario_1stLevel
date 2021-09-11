
#include "main.h"

///=================================================================================================

int main(int argc, char *argv[]){
    SDL_Window *window;
    SDL_Renderer *renderer;     //declaracia rendere
    SYSTEM syst;
    syst.zaciatok_nacitanie = F;

    syst.ressol_multip=1.5;

    syst.Xpocet=39;
    syst.Ypocet=39;

    zac_nacitanie(&syst);
//    Nacitavanie(8);
    syst.pocet_kocka = 0;
    set_scene(&syst);
    srand(time(0));


    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);   //inicializacia SDL2
    IMG_Init(IMG_INIT_JPG);

    srand(time(0));

    window = SDL_CreateWindow("VAI",
                            SDL_WINDOWPOS_UNDEFINED,
                            SDL_WINDOWPOS_UNDEFINED,
                            (int)(640*syst.ressol_multip),
                            (int)(480*syst.ressol_multip),
                            0);

    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    syst.renderer=renderer;

    int work=1;
    while(work)
    {
            control(window,&syst,&work);
            game_engine(&syst,&work);
            procesing(&syst,&work);
            rendering(renderer, &syst);
            if(syst.go && (syst.snake_spocitane || syst.a_star) )
                SDL_Delay(syst.delay_cas);
            else
            {
                if(syst.R_click)
                {
                    syst.delay_cas=200;
                    zac_nacitanie(&syst);
                    syst.pocet_kocka = 0;
                    set_scene(&syst);
                }
            }
    //        if(!work)
    //            SDL_Delay(5000);
    }
    system("cls");
    printf("\n\n\t\t Pripravila skupina A.M.O.R.");

    //znic okno
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

    return 0;
}

///=================================================================================================

void set_scene(SYSTEM *syst)
{
    int k = 0;
    for(int i=0;i<(syst->Ypocet);i++)
    {
        for(int j=0; j<(syst->Xpocet);j++)
        {
            syst->kocka[j][i].x=(140*syst->ressol_multip + j*syst->ressol_multip*360/syst->Xpocet);
            syst->kocka[j][i].y=(60*syst->ressol_multip + i*syst->ressol_multip*360/syst->Ypocet);
            syst->kocka[j][i].s=(360*syst->ressol_multip/syst->Xpocet);
            syst->kocka[j][i].v=(360*syst->ressol_multip/syst->Ypocet);
            k++;
        }
    }
    syst->pocet_kocka=k;
}
