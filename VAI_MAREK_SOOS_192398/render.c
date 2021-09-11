
#include "main.h"

void rendering(SDL_Renderer *renderer, SYSTEM *syst)
{
    if(!syst->go || syst->snake_spocitane || syst->a_star)
    {
        SDL_SetRenderDrawColor(renderer,128,128,255,255);
        SDL_RenderClear(renderer);

        //Vypis kosticiek
        SDL_SetRenderDrawColor(renderer,255,255,255,255);

        for(int i=0;i<(syst->Ypocet);i++)
        {
            for(int j=0; j<(syst->Xpocet);j++)
            {
            SDL_Rect rect={syst->kocka[j][i].x,syst->kocka[j][i].y,syst->kocka[j][i].s,syst->kocka[j][i].v};
            SDL_RenderDrawRect(renderer,&rect);

                if (syst->snake_game)
                {
                    if( syst->kocka[j][i].zaciatok==T)
                    {
                        SDL_SetRenderDrawColor(renderer,0,70,0,200);
                        SDL_Rect rect={syst->kocka[j][i].x+1,syst->kocka[j][i].y+1,syst->kocka[j][i].s-2,syst->kocka[j][i].v-2};
                        SDL_RenderFillRect(renderer,&rect);
                        SDL_SetRenderDrawColor(renderer,255,255,255,255);
                    }
                    else if( syst->kocka[j][i].koniec==T)
                    {
                        SDL_SetRenderDrawColor(renderer,240,0,0,255);
                        SDL_Rect rect={syst->kocka[j][i].x+1,syst->kocka[j][i].y+1,syst->kocka[j][i].s-2,syst->kocka[j][i].v-2};
                        SDL_RenderFillRect(renderer,&rect);
                        SDL_SetRenderDrawColor(renderer,255,255,255,255);
                    }
                    else if( syst->kocka[j][i].snake==T)
                    {
                        SDL_SetRenderDrawColor(renderer,0,220,0,200);
                        SDL_Rect rect={syst->kocka[j][i].x+1,syst->kocka[j][i].y+1,syst->kocka[j][i].s-2,syst->kocka[j][i].v-2};
                        SDL_RenderFillRect(renderer,&rect);
                        SDL_SetRenderDrawColor(renderer,255,255,255,255);
                    }
                    else if( syst->kocka[j][i].wall==T)
                    {
                        SDL_SetRenderDrawColor(renderer,100,100,100,200);
                        SDL_Rect rect={syst->kocka[j][i].x+1,syst->kocka[j][i].y+1,syst->kocka[j][i].s-2,syst->kocka[j][i].v-2};
                        SDL_RenderFillRect(renderer,&rect);
                        SDL_SetRenderDrawColor(renderer,255,255,255,255);
                    }
                    else if( syst->kocka[j][i].cesta==T)
                    {
                        if(syst->snake_cesta)
                        {
                            SDL_SetRenderDrawColor(renderer,0,0,255,200);
                            SDL_Rect rect={syst->kocka[j][i].x+1,syst->kocka[j][i].y+1,syst->kocka[j][i].s-2,syst->kocka[j][i].v-2};
                            SDL_RenderFillRect(renderer,&rect);
                            SDL_SetRenderDrawColor(renderer,255,255,255,255);
                        }
                    }

                }

                if (syst->a_star)
                {
                    if( syst->kocka[j][i].zaciatok==T)
                    {
                        SDL_SetRenderDrawColor(renderer,255,182,193,255);
                        SDL_Rect rect={syst->kocka[j][i].x+1,syst->kocka[j][i].y+1,syst->kocka[j][i].s-2,syst->kocka[j][i].v-2};
                        SDL_RenderFillRect(renderer,&rect);
                        SDL_SetRenderDrawColor(renderer,255,255,255,255);
                    }
                    else if( syst->kocka[j][i].koniec==T)
                    {
                        SDL_SetRenderDrawColor(renderer,0,0,0,200);
                        SDL_Rect rect={syst->kocka[j][i].x+1,syst->kocka[j][i].y+1,syst->kocka[j][i].s-2,syst->kocka[j][i].v-2};
                        SDL_RenderFillRect(renderer,&rect);
                        SDL_SetRenderDrawColor(renderer,255,255,255,255);
                    }
                    else if( syst->kocka[j][i].cesta==T)
                    {
                        SDL_SetRenderDrawColor(renderer,0,0,255,200);
                        SDL_Rect rect={syst->kocka[j][i].x+1,syst->kocka[j][i].y+1,syst->kocka[j][i].s-2,syst->kocka[j][i].v-2};
                        SDL_RenderFillRect(renderer,&rect);
                        SDL_SetRenderDrawColor(renderer,255,255,255,255);
                    }
                    else if( syst->kocka[j][i].close==T)
                    {
                        SDL_SetRenderDrawColor(renderer,220,0,0,200);
                        SDL_Rect rect={syst->kocka[j][i].x+1,syst->kocka[j][i].y+1,syst->kocka[j][i].s-2,syst->kocka[j][i].v-2};
                        SDL_RenderFillRect(renderer,&rect);
                        SDL_SetRenderDrawColor(renderer,255,255,255,255);

                    }
                    else if( syst->kocka[j][i].open==T)
                    {
                        SDL_SetRenderDrawColor(renderer,220,220,0,200);
                        SDL_Rect rect={syst->kocka[j][i].x+1,syst->kocka[j][i].y+1,syst->kocka[j][i].s-2,syst->kocka[j][i].v-2};
                        SDL_RenderFillRect(renderer,&rect);
                        SDL_SetRenderDrawColor(renderer,255,255,255,255);
                    }
                    else if( syst->kocka[j][i].wall==T)
                    {
                        SDL_SetRenderDrawColor(renderer,100,100,100,200);
                        SDL_Rect rect={syst->kocka[j][i].x+1,syst->kocka[j][i].y+1,syst->kocka[j][i].s-2,syst->kocka[j][i].v-2};
                        SDL_RenderFillRect(renderer,&rect);
                        SDL_SetRenderDrawColor(renderer,255,255,255,255);
                    }
                }

            }
        }

        SDL_RenderPresent(renderer);
    }
}
