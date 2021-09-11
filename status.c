#include "main.h"

void inicText_zaciatok(StavHry *stav)
{
    char zac_text[150],zac_text2[150];
    sprintf(zac_text,"%d x  Lives",stav->clovek.lifes);
    SDL_Color biela ={255, 255, 255, 255};

    SDL_Surface *tmp = TTF_RenderText_Blended(stav->font,zac_text,biela);
    stav->znackaW[0] = tmp->w/2;
    stav->znackaH[0] = tmp->h/2;
    stav->znacka[0] = SDL_CreateTextureFromSurface(stav->renderer,tmp);
    SDL_FreeSurface(tmp);

    sprintf(zac_text2,"Dostan sa na koniec!");

    SDL_Surface *tpm = TTF_RenderText_Blended(stav->font,zac_text2,biela);
    stav->znackaW[1] = tpm->w/2;
    stav->znackaH[1] = tpm->h/2;
    stav->znacka[1] = SDL_CreateTextureFromSurface(stav->renderer,tpm);
    SDL_FreeSurface(tpm);
}


void inicText_zivoty(StavHry *stav)
{
    char zivot_text[150];

    sprintf(zivot_text,"SuperMario body : %d                                    %d x  Lives",(int)(stav->clovek.x-200>0 ? stav->clovek.x : 0)/10,stav->clovek.lifes);

    SDL_Color cierna={0, 0, 0, 255};

    SDL_Surface *tmp = TTF_RenderText_Blended(stav->font,zivot_text,cierna);
    stav->znackaW[0] = tmp->w/2;
    stav->znackaH[0] = tmp->h/2;
    stav->znacka[0] = SDL_CreateTextureFromSurface(stav->renderer,tmp);
    SDL_FreeSurface(tmp);
}


void napis_zivoty(StavHry *stav)
{
    SDL_Renderer *renderer = stav->renderer;

    ///setne okno farbu
    SDL_SetRenderDrawColor(renderer,0,0,0,255);
    SDL_RenderClear(renderer);

    ///mario
    SDL_Rect mario_rect={320-50,220-stav->znackaH[0]/2,MARIO_GRAPHIX+15,MARIO_GRAPHIX+15};
    SDL_RenderCopy(renderer,stav->mario[3],NULL,&mario_rect);
    SDL_SetRenderDrawColor(renderer,255,255,255,255);


    ///text1
    SDL_Rect textRect = {70+320-stav->znackaW[0]/2,240-stav->znackaH[0]/2,stav->znackaW[0],stav->znackaH[0]};
    SDL_RenderCopy(renderer,stav->znacka[0],NULL,&textRect);

    ///text2
    SDL_Rect textRect2 = {300-stav->znackaW[1]/2,120-stav->znackaH[1]/2,stav->znackaW[1]*1.3,stav->znackaH[1]*1.3};
    SDL_RenderCopy(renderer,stav->znacka[1],NULL,&textRect2);

    SDL_RenderPresent(renderer);
}

void shutdown_status_live(StavHry *stav)
{
    SDL_DestroyTexture(stav->znacka[0]);
    SDL_DestroyTexture(stav->znacka[1]);
    stav->znacka[0]=NULL;
    stav->znacka[1]=NULL;
}

void max_body(StavHry *stav)
{
    if( (int)stav->clovek.x/10 > stav->clovek.body )
        stav->clovek.body = (int)stav->clovek.x/10 ;
//        printf("%d",stav->clovek.body);
}


void inicText_koniecHry(StavHry *stav)
{
    char zivot_text_koniec[150],zivot_text_koniec2[150];

    sprintf(zivot_text_koniec,"Koniec Hry");

    SDL_Color cierna={255, 255, 255, 255};

    SDL_Surface *tmp = TTF_RenderText_Blended(stav->font,zivot_text_koniec,cierna);
    stav->znackaW[0] = tmp->w/2;
    stav->znackaH[0] = tmp->h/2;
    stav->znacka[0] = SDL_CreateTextureFromSurface(stav->renderer,tmp);
    SDL_FreeSurface(tmp);

    sprintf(zivot_text_koniec2,"Max body %d",( -20 + stav->clovek.body < 0 ? 0 : stav->clovek.body ) );

    SDL_Surface *tpm = TTF_RenderText_Blended(stav->font,zivot_text_koniec2,cierna);
    stav->znackaW[1] = tpm->w/2;
    stav->znackaH[1] = tpm->h/2;
    stav->znacka[1] = SDL_CreateTextureFromSurface(stav->renderer,tpm);
    SDL_FreeSurface(tpm);
}

void napis_koniec_hry(StavHry *stav)
{
    SDL_Renderer *renderer = stav->renderer;

    ///setne okno farbu
    SDL_SetRenderDrawColor(renderer,0,0,0,255);
    SDL_RenderClear(renderer);

    ///mario
    float mario=1;
    SDL_Rect mario_rect={640/2-30,300-stav->znackaH[0]/2*mario,MARIO_GRAPHIX*mario,MARIO_GRAPHIX*mario};
    SDL_RenderCopy(renderer,stav->mario[0],NULL,&mario_rect);
    SDL_SetRenderDrawColor(renderer,255,255,255,255);

    ///text
    float text1=1.5;
    SDL_Rect textRect = {640/2-stav->znackaW[0]/2*text1,140-stav->znackaH[0]/2*text1,stav->znackaW[0]*text1,stav->znackaH[0]*text1};
    SDL_RenderCopy(renderer,stav->znacka[0],NULL,&textRect);

    ///text2
    float text2=1.1;
    SDL_Rect textRect2 = {640/2-stav->znackaW[1]/2*text2,240-stav->znackaH[1]/2*text2,stav->znackaW[1]*text2,stav->znackaH[1]*text2};
    SDL_RenderCopy(renderer,stav->znacka[1],NULL,&textRect2);

    SDL_RenderPresent(renderer);
}


void inicText_vyhra_hry(StavHry *stav)
{
    char zivot_text_vyhra[150],zivot_text_vyhra2[150];

    sprintf(zivot_text_vyhra,"VYHRALI STE!");

    SDL_Color cierna={255, 255, 255, 255};

    SDL_Surface *tmp = TTF_RenderText_Blended(stav->font,zivot_text_vyhra,cierna);
    stav->znackaW[0] = tmp->w/2;
    stav->znackaH[0] = tmp->h/2;
    stav->znacka[0] = SDL_CreateTextureFromSurface(stav->renderer,tmp);
    SDL_FreeSurface(tmp);

    sprintf(zivot_text_vyhra2,"Pripravilo pre vas Studio:A.M.O.R.",( -20 + stav->clovek.body < 0 ? 0 : stav->clovek.body ) );

    SDL_Surface *tpm = TTF_RenderText_Blended(stav->font,zivot_text_vyhra2,cierna);
    stav->znackaW[1] = tpm->w/3;
    stav->znackaH[1] = tpm->h/3;
    stav->znacka[1] = SDL_CreateTextureFromSurface(stav->renderer,tpm);
    SDL_FreeSurface(tpm);
}

void napis_vyhra_hry(StavHry *stav)
{
    SDL_Renderer *renderer = stav->renderer;

    ///setne okno farbu
    SDL_SetRenderDrawColor(renderer,0,0,0,255);
    SDL_RenderClear(renderer);

    ///mario
    float mario=2.2;
    SDL_Rect mario_rect={640/2-MARIO_GRAPHIX*mario/2,260-MARIO_GRAPHIX*mario/2,MARIO_GRAPHIX*mario,MARIO_GRAPHIX*mario};
    SDL_RenderCopy(renderer,stav->mario[5],NULL,&mario_rect);
    SDL_SetRenderDrawColor(renderer,255,255,255,255);

    ///text
    float text1=1.5;
    SDL_Rect textRect = {640/2-stav->znackaW[0]/2*text1,140-stav->znackaH[0]/2*text1,stav->znackaW[0]*text1,stav->znackaH[0]*text1};
    SDL_RenderCopy(renderer,stav->znacka[0],NULL,&textRect);

    ///text2
    float text2=1;
    SDL_Rect textRect2 = {640/2-stav->znackaW[1]/2*text2,420-stav->znackaH[1]/2*text2,stav->znackaW[1]*text2,stav->znackaH[1]*text2};
    SDL_RenderCopy(renderer,stav->znacka[1],NULL,&textRect2);

    SDL_RenderPresent(renderer);
}


