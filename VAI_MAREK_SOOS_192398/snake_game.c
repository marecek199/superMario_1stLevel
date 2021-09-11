
#include "main.h"


void game_engine(SYSTEM *syst,int *work)
{
    if( syst->snake_spocitane && syst->go && syst->snake_game)
    {
        int i = --syst->cesta_pocet;
        int pole[SNAKE_MAX_DLZKA][2];

        if( syst->cesta_pocet > 0 )
        {
            int x0=syst->cesta[i][0];
            int y0=syst->cesta[i][1];
            int x1=syst->cesta[i-1][0];
            int y1=syst->cesta[i-1][1];

                // HLAVA
            syst->kocka[x0][y0].zaciatok=F;
            syst->kocka[x1][y1].zaciatok=T;
            syst->xzac=x1;
            syst->yzac=y1;
            pole[0][0] = x0;
            pole[0][1] = y0;

            for(int i=0;i<(syst->Ypocet);i++)
            {
                for(int j=0; j<(syst->Xpocet);j++)
                {
                    for(int pocet=1; pocet <= syst->snake_telo_dlzka ;pocet++)
                    {
                        if( syst->kocka[j][i].snake && syst->kocka[j][i].snake_poradie==pocet)
                        {
                            pole[pocet][0] = j;
                            pole[pocet][1] = i;
                            syst->kocka[j][i].snake=F;
                            syst->kocka[j][i].snake_poradie=0;
                            if( pocet == syst->snake_telo_dlzka )
                            {
                                syst->snake_last[0][0]=j;
                                syst->snake_last[0][1]=i;
                            }
                        }
                    }
                }
            }


            for(int pocet=0; pocet < syst->snake_telo_dlzka ;pocet++)
            {
                int a = pole[pocet][0];
                int b = pole[pocet][1];
                syst->kocka[a][b].snake=T;
                syst->kocka[a][b].snake_poradie=pocet+1;
            }

        }
        else
        {
                // DEALOKACIA PAMATI
//            for(int d=0; d < syst->cesta_celk_pocet ;d++)
//            {
//                free(syst->cesta[d]);
//            }
//            free(syst->cesta);
            food(syst);
        }
    }
}

void food(SYSTEM *syst)
{
    if( syst->xzac == syst->xkon && syst->yzac == syst->yzac )
    {
        for(int i=0;i<(syst->Ypocet);i++)
        {
            for(int j=0; j<(syst->Xpocet);j++)
            {
                syst->kocka[j][i].open=F;
                syst->kocka[j][i].close=F;
                syst->kocka[j][i].koniec=F;
                syst->kocka[j][i].cesta=F;
                syst->kocka[j][i].kolo=F;
                syst->kocka[j][i].f=10001;
                syst->kocka[j][i].g=10001;
                syst->kocka[j][i].h=10001;
            }
        }

        syst->bod=F;
        syst->close_pocet=0;
        syst->cesta_pocet=0;
        syst->cesta_celk_pocet=0;
        syst->cesta_pocitadlo=0;
        syst->exis_cesta = 0;
        syst->snake_spocitane=F;

            syst->snake_telo_dlzka++;
            int a,b;
            a = syst->snake_last[0][0];
            b = syst->snake_last[0][1];
            syst->kocka[a][b].snake=T;
            syst->kocka[a][b].snake_poradie=syst->snake_telo_dlzka;


        syst->kocka[syst->xzac][syst->yzac].open = T;
        syst->kocka[syst->xzac][syst->yzac].f = 10000;

        do
        {
            syst->xkon = rand() % (syst->Xpocet);
            syst->ykon = rand() % (syst->Ypocet);
        }while( syst->kocka[syst->xkon][syst->ykon].snake || syst->kocka[syst->xkon][syst->ykon].wall );

        syst->kocka[syst->xkon][syst->ykon].koniec=T;
        syst->mini=10000;

    }
}
