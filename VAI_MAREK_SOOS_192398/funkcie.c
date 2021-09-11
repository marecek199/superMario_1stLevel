
#include "main.h"

void procesing(SYSTEM *syst, int *work)
{
    if(syst->go && syst->snake_spocitane==0 ) //syst->snake_spocitane==0
    {
        int Xlast,Ylast,going=T;
        for(int i=0;i<(syst->Ypocet);i++)
        {
            if(!going) break;
            for(int j=0; j<(syst->Xpocet);j++)
            {
                if(!syst->bod)
                {                              /// Skumanie okolitych buniek, pokial mozne -> ich otvorenie
                    if( syst->kocka[j][i].open == T && syst->kocka[j][i].koniec != T && syst->kocka[j][i].kolo != T )
                    {
                        if( syst->kocka[j][i].f == syst->mini )                   ///Rozsiruj len open && f_min
                            {
                                    if (syst->exis_cesta == 0)
                                        {
                                            syst->exis_cesta=T;
                                        }
                                    ///vpravo
                                    if(j+1 >=0 && j+1<syst->Xpocet && syst->kocka[j+1][i].close != T && syst->kocka[j+1][i].wall != T && syst->kocka[j+1][i].snake!=T )   /// Rozsir kazdym smerom, !nie Close!
                                    {
                                        syst->kocka[j+1][i].g=faabs(j+1-syst->xzac)+faabs(i-syst->yzac);
                                        syst->kocka[j+1][i].h=faabs(j+1-syst->xkon)+faabs(i-syst->ykon);

                                        syst->kocka[j+1][i].f=syst->kocka[j+1][i].g+syst->kocka[j+1][i].h;
                                        if(syst->kocka[j+1][i].open==F)
                                            syst->kocka[j+1][i].open = T;
                                        syst->kocka[j+1][i].kolo = T;

                                            syst->kocka[j+1][i].last.X=j;
                                            syst->kocka[j+1][i].last.Y=i;
                                    }

                                    ///vlavo
                                    if(j-1 >=0 && j-1<syst->Xpocet && syst->kocka[j-1][i].close != T && syst->kocka[j-1][i].wall != T && syst->kocka[j-1][i].snake != T)
                                    {
                                        syst->kocka[j-1][i].g=faabs(j-1-syst->xzac)+faabs(i-syst->yzac);
                                        syst->kocka[j-1][i].h=faabs(j-1-syst->xkon)+faabs(i-syst->ykon);

                                        syst->kocka[j-1][i].f=syst->kocka[j-1][i].g+syst->kocka[j-1][i].h;
                                        if(syst->kocka[j-1][i].open==F)
                                            syst->kocka[j-1][i].open = T;
                                        syst->kocka[j-1][i].kolo = T;

                                        syst->kocka[j-1][i].last.X=j;
                                        syst->kocka[j-1][i].last.Y=i;
                                    }

                                    ///hore
                                    if(i-1 >=0 && i-1<syst->Ypocet && syst->kocka[j][i-1].close != T && syst->kocka[j][i-1].wall != T && syst->kocka[j][i-1].snake != T)
                                    {
                                        syst->kocka[j][i-1].g=faabs(j-syst->xzac)+faabs(i-1-syst->yzac);
                                        syst->kocka[j][i-1].h=faabs(j-syst->xkon)+faabs(i-1-syst->ykon);

                                        syst->kocka[j][i-1].f=syst->kocka[j][i-1].g+syst->kocka[j][i-1].h;
                                        if(syst->kocka[j][i-1].open==F)
                                            syst->kocka[j][i-1].open = T;
                                        syst->kocka[j][i-1].kolo = T;


                                        syst->kocka[j][i-1].last.X=j;
                                        syst->kocka[j][i-1].last.Y=i;

                                    }

                                    ///dole
                                    if(i+1 >=0 && i+1<syst->Ypocet && syst->kocka[j][i+1].close != T && syst->kocka[j][i+1].wall != T && syst->kocka[j][i+1].snake != T )
                                    {
                                        syst->kocka[j][i+1].g=faabs(j-syst->xzac)+faabs(i+1-syst->yzac);
                                        syst->kocka[j][i+1].h=faabs(j-syst->xkon)+faabs(i+1-syst->ykon);

                                        syst->kocka[j][i+1].f=syst->kocka[j][i+1].g+syst->kocka[j][i+1].h;
                                        if(syst->kocka[j][i+1].open==F)
                                            syst->kocka[j][i+1].open = T;
                                        syst->kocka[j][i+1].kolo = T;

                                        syst->kocka[j][i+1].last.X=j;
                                        syst->kocka[j][i+1].last.Y=i;

                                    }

                                    syst->kocka[j][i].open = F;
                                    syst->kocka[j][i].close = T;
                                    syst->close_pocet++;
                            }
                    }

                    else if(syst->kocka[j][i].koniec==T && syst->kocka[j][i].open == T )
                    {
//                        printf("\n\n\n\tNasiel sa bod!\n");
                        syst->bod=T;
                        if (syst->exis_cesta == 0)
                        {
                            syst->exis_cesta=T;
                        }
                    }

                }

                                        ///Zpatny chod - vykreslovanie cesty
                else
                {
                            ///Koncovy bod
                            if(syst->kocka[j][i].koniec==T && syst->kocka[j][i].open == T && syst->kocka[j][i].cesta!=T )
                                {
                                    if (syst->exis_cesta == 0)
                                        {
                                            syst->exis_cesta=T;
                                        }
                                    syst->kocka[j][i].cesta=T;
                                    syst->kocka[j][i].close=F;
                                    Xlast=syst->kocka[j][i].last.X;
                                    Ylast=syst->kocka[j][i].last.Y;
                                    syst->kocka[Xlast][Ylast].cesta=T;
                                    going=F;
                                    if (syst->exis_cesta == 0)
                                        {
                                            syst->exis_cesta=T;
                                        }


    //                                        if(syst->cesta == NULL)
    //                                            {
    //                                                printf("Chyba alokacie");
    //                                                exit(1);
    //                                            }
    //                                        (syst->cesta) = (int**) malloc( (syst->close_pocet)*sizeof(int*) );
    //                                        for(int s=0; s<syst->close_pocet ;s++)
    //                                        {
    //                                            syst->cesta[s] = (int*) malloc(2*sizeof(int));
    //                                                if(syst->cesta[s] == NULL)
    //                                                {
    //                                                    printf("Chyba alokacie");
    //                                                    exit(1);
    //                                                }
    //                                        }

                                    /// suradnice cesty
                                    syst->cesta[0][0] = j;
                                    syst->cesta[0][1] = i;
                                    syst->cesta_pocet++;
                                    syst->cesta[1][0] = Xlast;
                                    syst->cesta[1][1] = Ylast;
                                    syst->cesta_pocet++;

                                    break;
                                }

                            ///Osatne body
                            else if( syst->kocka[j][i].cesta == T && syst->kocka[j][i].close == T)
                                {
                                    if (syst->exis_cesta == 0)
                                        {
                                            syst->exis_cesta=T;
                                        }
                                    if (syst->kocka[j][i].zaciatok == T)
                                    {
                                        if(syst->a_star)
                                            syst->go=F;
//                                        printf("\n\tKoniec!");
                                        going=F;
//                                        printf("\n");
//                                        printf("\n");
                                        syst->cesta_celk_pocet=syst->cesta_pocet;
                                        syst->snake_spocitane=T;
                                        break;
                                    }

                                    syst->kocka[j][i].close=F;
                                    Xlast=syst->kocka[j][i].last.X;
                                    Ylast=syst->kocka[j][i].last.Y;
                                    syst->kocka[Xlast][Ylast].cesta=T;
                                    going=F;

                                    /// suradnice cesty
                                    syst->cesta[syst->cesta_pocet][0] = Xlast;
                                    syst->cesta[syst->cesta_pocet][1] = Ylast;
                                    syst->cesta_pocet++;

                                    break;
                                }
                }
            }
        }
        syst->mini=10000;
        nul_kolo(syst);
    }

                        /// ZACIATOCNE KLIKANIE STARTU,KONCA,PREKAZKY
    else
    {
            if(syst->click_mouse && syst->pocet_click==1 || syst->S_click==T && syst->snake_spocitane==0 )
            {
                for(int i=0;i<(syst->Ypocet);i++)
                {
                    for(int j=0; j<(syst->Xpocet);j++)
                    {
                       if( syst->kocka[j][i].zaciatok==T )
                       {
                           syst->kocka[j][i].zaciatok=F;
                           syst->kocka[j][i].open=F;
                           syst->kocka[j][i].f=10001;
                       }
                    }
                }

            for(int i=0;i<(syst->Ypocet);i++)
            {
                for(int j=0; j<(syst->Xpocet);j++)
                {
                    if(  syst->Xmouse>=(int)syst->kocka[j][i].x && syst->Xmouse<=(int)syst->kocka[j][i].x+(int)syst->kocka[j][i].s    &&    syst->Ymouse>=(int)syst->kocka[j][i].y && syst->Ymouse<=(int)syst->kocka[j][i].y+(int)syst->kocka[j][i].v)
                    {
                        syst->xzac=j;
                        syst->yzac=i;
                        syst->kocka[j][i].zaciatok=T;
                        syst->kocka[j][i].open=T;
                        syst->kocka[j][i].f=10000;
                    }
                }
            }
            syst->click_mouse=F;
            syst->S_click=F;
            if( !(syst->pocet_click>0) )
                syst->pocet_click++;
            }

         else if(syst->click_mouse && syst->pocet_click==2 || syst->E_click==T && syst->snake_spocitane==0)
         {
            for(int i=0;i<(syst->Ypocet);i++)
            {
                for(int j=0; j<(syst->Xpocet);j++)
                {
                   if( syst->kocka[j][i].koniec==T )
                   {
                       syst->kocka[j][i].koniec=F;
                   }
                }
            }
            for(int i=0;i<(syst->Ypocet);i++)
            {
                for(int j=0; j<(syst->Xpocet);j++)
                {
                    if(  syst->Xmouse>=(int)syst->kocka[j][i].x && syst->Xmouse<=(int)syst->kocka[j][i].x+(int)syst->kocka[j][i].s    &&    syst->Ymouse>=(int)syst->kocka[j][i].y && syst->Ymouse<=(int)syst->kocka[j][i].y+(int)syst->kocka[j][i].v)
                    {
                        syst->xkon=j;
                        syst->ykon=i;
                        syst->kocka[j][i].koniec=T;
                    }
                }
            }
            syst->click_mouse=F;
            syst->E_click=F;
            if( !(syst->pocet_click>1) )
                syst->pocet_click++;
         }

        else if(syst->click_mouse && syst->pocet_click>2 && syst->snake_spocitane==0 )
        {
            for(int i=0;i<(syst->Ypocet);i++)
            {
                for(int j=0; j<(syst->Xpocet);j++)
                {
                    if(  syst->Xmouse>=(int)syst->kocka[j][i].x && syst->Xmouse<=(int)syst->kocka[j][i].x+(int)syst->kocka[j][i].s    &&    syst->Ymouse>=(int)syst->kocka[j][i].y && syst->Ymouse<=(int)syst->kocka[j][i].y+(int)syst->kocka[j][i].v)
                    {
                        if(syst->kocka[j][i].wall==F)
                            syst->kocka[j][i].wall=T;
                        else
                            syst->kocka[j][i].wall=F;
                    }
                }
            }
            syst->click_mouse=F;
        }

        else if( syst->W_click==T )
            {
            for(int i=0;i<(syst->Ypocet);i++)
            {
                for(int j=0; j<(syst->Xpocet);j++)
                {
                    if(  syst->Xmouse>=(int)syst->kocka[j][i].x && syst->Xmouse<=(int)syst->kocka[j][i].x+(int)syst->kocka[j][i].s    &&    syst->Ymouse>=(int)syst->kocka[j][i].y && syst->Ymouse<=(int)syst->kocka[j][i].y+(int)syst->kocka[j][i].v)
                    {
                        syst->kocka[j][i].wall=T;
                    }
                }
            }
            syst->W_click=F;
            }

        else if( syst->C_click==T )
            {
            for(int i=0;i<(syst->Ypocet);i++)
            {
                for(int j=0; j<(syst->Xpocet);j++)
                {
                    if(  syst->Xmouse>=(int)syst->kocka[j][i].x && syst->Xmouse<=(int)syst->kocka[j][i].x+(int)syst->kocka[j][i].s    &&    syst->Ymouse>=(int)syst->kocka[j][i].y && syst->Ymouse<=(int)syst->kocka[j][i].y+(int)syst->kocka[j][i].v)
                    {
                        syst->kocka[j][i].wall=F;
                    }
                }
            }
            syst->C_click=F;
        }
    }
}




 float faabs(float x)
 {
     if(x < 0)
        x*=-1;
     return x;
 }




void nul_kolo(SYSTEM *syst)
{
    for(int i=0;i<(syst->Ypocet);i++)
    {
        for(int j=0; j<(syst->Xpocet);j++)
        {
            syst->kocka[j][i].kolo = F;
            if(syst->kocka[j][i].f < syst->mini && syst->kocka[j][i].close != T )
                syst->mini=syst->kocka[j][i].f;
        }
    }
    if (syst->exis_cesta == 0)
    {
        system("cls");
        printf("\n\n\t\tCesta z tohoto bodu neexistuje!");
        printf("\n\n\t Pre resetovanie");
        printf("\n\t\t =>stlacte klavesu R");
        printf("\n\n\t Pre ukoncenie");
        printf("\n\t\t =>stlacte klavesu Esc");
        syst->go = F;
    }
    syst->exis_cesta = F;
}



void control(SDL_Window *window, SYSTEM *syst,int *work)
{
    SDL_Event event;

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
                            *work=0;
//                            exit(1);
                        }
                    }
                break;
                case SDL_KEYDOWN:
                    {
                        switch(event.key.keysym.sym)
                        {
                            case SDLK_ESCAPE:
                            {
                                *work=0;
                            }
                            break;
                            case SDLK_SPACE:
                            {
                                if(syst->go==F)
                                    syst->go=T;
                                else
                                    syst->go=F;
                            }
                            break;
                            case SDLK_s :
                            {
                                syst->S_click=T;
                                syst->pocet_click++;
                            }
                            break;
                            case SDLK_e :
                            {
                                syst->E_click=T;
                                syst->pocet_click++;
                            }
                            break;
                            case SDLK_r :
                            {
                                syst->R_click=T;
                                syst->pocet_click=0;
                            }
                            break;
                            case SDLK_n :
                            {
                                if(syst->a_star)
                                {
                                    syst->a_star=F;
                                    syst->snake_game=T;
                                }
                                else
                                {
                                    syst->a_star=T;
                                    syst->snake_game=F;
                                }
                                syst->R_click=T;
                                syst->pocet_click=0;
                            }
                            break;
                            case SDLK_p :
                            {
                                if(syst->snake_game)
                                {
                                    if(syst->snake_cesta)
                                        syst->snake_cesta=F;
                                    else
                                        syst->snake_cesta=T;
                                }
                                syst->pocet_click=0;
                            }
                            break;
                            case SDLK_DOWN :
                            {
                                syst->delay_cas+=10;
                            }
                            break;
                            case SDLK_UP :
                            {
                                if( syst->delay_cas >= 10 )
                                    syst->delay_cas-=10;
                            }
                            break;
                        }
                    }
                break;

                if(!syst->go)
                {
                        case SDL_MOUSEMOTION:
                        {
                            syst->Xmouse = event.motion.x;
                            syst->Ymouse = event.motion.y;
                        }
                        break;
                        case SDL_MOUSEBUTTONDOWN:
                            {
                                syst->click_mouse=T;
                                syst->pocet_click++;
                            }
                        break;

                }
                case SDL_QUIT:
                    {
                        *work=0;
                    }
                break;
            }
        }


        if(!syst->go || 1)
        {
            const Uint8 *state = SDL_GetKeyboardState(NULL);

            if(state[SDL_SCANCODE_W])
            {
                syst->W_click=T;
            }
            else if(state[SDL_SCANCODE_C])
            {
                syst->C_click=T;
            }
        }
}
