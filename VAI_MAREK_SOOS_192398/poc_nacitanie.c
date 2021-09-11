
#include "main.h"

void zac_nacitanie(SYSTEM *syst)
{
    int a,b,c;

    if(!syst->zaciatok_nacitanie)
    {
        printf("\n\n\t\t Vitajte!");
        printf("\n\n\t Pokial si prajete zadat velkost mriezky hry");
        printf("\n\t\t (defaultne - %dx%d) ", syst->Xpocet,syst->Ypocet);
        printf("\n\t\t =>stlacte 0 ");
        printf("\n\n\t Pre pokracovanie bez zmeny ");
        printf("\n\t\t => stlacte lubovolnu klavesnicu \n");
        while(!kbhit)
            {
            }
        c = getch();
        if ( c == 0 || c == 48)
        {
            Nacitavie(8);
            system("cls");
            printf("\n\n\tZadajte pocet kociek X a Y (max 99):\n");
            printf("\n\tPotvrdte klavesou #enter");
            printf("\n\tZadajte pocet v X smere : ");
            scanf("%d",&syst->Xpocet);
            printf("\tZadajte pocet v Y smere : ");
            scanf("%d",&syst->Ypocet);
//            printf("\nZvolte suradnice pociatku [x,y] : ");
//            scanf("%d %d",&a,&b);
        }
        syst->zaciatok_nacitanie=T;
        Nacitavie(8);

        syst->snake_game=0;
        syst->a_star=1;
        syst->delay_cas=200;
    }

    system("cls");
    textova_obrazovka(syst);

//                        syst->Xpocet=25;
//                        syst->Ypocet=25;
    syst->bod=F;
    syst->go=F;
    syst->pocet_click=0;
    syst->close_pocet=0;
    syst->cesta_pocet=0;
    syst->cesta_pocitadlo=0;
    syst->exis_cesta = 0;
    syst->snake_cesta = 0;



    syst->snake_spocitane=0;
    syst->snake_telo_dlzka=1;
            syst->snake_last[0][0]=0;
            syst->snake_last[0][1]=0;

    syst->S_click=F;
    syst->E_click=F;
    syst->W_click=F;
    syst->C_click=F;
    syst->R_click=F;
    syst->click_mouse=F;
    nacit_udaj(syst);
    syst->mini=10000;

    ///Zvolenie zac/konca/steny
    //grey_wall(syst);

//                    a=1;b=1;
//    syst->xzac=a-1;
//    syst->yzac=b-1;
//    syst->kocka[a-1][b-1].zaciatok=T;
//    syst->kocka[a-1][b-1].open=T;
//    syst->kocka[a-1][b-1].f=10000;
//
//                    a=7;b=2;
//    syst->xkon=a-1;
//    syst->ykon=b-1;
//    syst->kocka[a-1][b-1].koniec=T;
//

}

void textova_obrazovka(SYSTEM *syst)
{
    syst->a_star ? system("color C") : system("color A");

//    printf("\t Vysvetlivky");
    printf("\t\t *  MODE : %s  *", syst->a_star ? "A* algoritmus" : "Snake");
    printf("\n\n\t *Pre zmenu MODE -> %s*", syst->a_star ? "Snake" : "A* algoritmus" );
    printf("\n\t\t =>stlacte N");
    if (syst->snake_game)
    {
        printf("\n\n\t *Pre vykreslovanie cesty*");
        printf("\n\t\t => stlacte P");
    }
    printf("\n\n\t *Pre zadanie zaciatocneho bodu*");
    printf("\n\t\t =>stlacte/podrzte S, alebo 1.klik mysou");

    printf("\n\n\t *Pre zadanie koncoveho bodu*");
    printf("\n\t\t =>stlacte/podrzte E, alebo 2.klik mysou");

    printf("\n\n\t *Prekazka*");
    printf("\n\t\t Pre vytvorenie => stlacte W ");
    printf("\n\t\t Pre vymazanie  => stlacte C");
    printf("\n\t\t CLICK myskou ");

    printf("\n\n\t *START/STOP algoritmu*");
    printf("\n\t\t =>stlacte medzernik/spacebar");

    printf("\n\n\t *Zrychlenie/Spomalenie algoritmu*");
    printf("\n\t\t Zrychlenie => sipka HORE");
    printf("\n\t\t Spomalenie => sipka DOLE");

    printf("\n\n\t *Pre resetovanie*");
    printf("\n\t\t =>stlacte R");
    printf("\n\t *Pre ukoncenie*");
    printf("\n\t\t =>stlacte Esc");
}

void grey_wall(SYSTEM *syst)
{
    for(int i=0;i<10;i++)
    {
    syst->kocka[12][7+i].wall=T;
    }
    for(int i=0;i<4;i++)
    {
    syst->kocka[12+i][16].wall=T;
    }

}



void nacit_udaj(SYSTEM *syst)
{
    for(int i=0;i<(syst->Ypocet);i++)
    {
        for(int j=0; j<(syst->Xpocet);j++)
        {
            syst->kocka[j][i].open=F;
            syst->kocka[j][i].close=F;
            syst->kocka[j][i].koniec=F;
            syst->kocka[j][i].wall=F;
            syst->kocka[j][i].cesta=F;
            syst->kocka[j][i].kolo=F;
            syst->kocka[j][i].zaciatok=F;
            syst->kocka[j][i].f=10001;
            syst->kocka[j][i].g=10001;
            syst->kocka[j][i].h=10001;
            syst->kocka[j][i].snake=F;
            syst->kocka[j][i].snake_poradie=0;
        }
    }
}


void Nacitavie(int x)
{
    int k;
    printf("\n\tNacitavam");
    for(int j=0;j<x;j++)
        {
            for(int i=0;i<150000000;i++)
                k=0;
            printf(".");
        }
}
