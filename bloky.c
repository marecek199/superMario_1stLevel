//#include "main.h"

//
//
//
//void rozmiestnenie(StavHry *stav)
//{
//    /// SVET
//    vyskl_svet(stav);
//
//    ///Blok0
//    vyskl_blok0(stav);
//
//    ///BLOK1
//    vyskl_blok1(stav);
//
//    ///BLOK2
//    vyskl_blok2(stav);
//
//    ///ZELENY
//    vyskl_zelene(stav);
//
//
////    ///BlOK3
////    vyskl_blok3(stav);
//
//}
//void vyskl_zelene(StavHry *stav)
//{
//    stav->cislo_kocky[3] = stav->cislo_kocky[2];
//
//    stav->kocka[stav->cislo_kocky[3]].x=958+2;
//    stav->kocka[stav->cislo_kocky[3]].y=VYSKA2_KOCKA+2*YKOCKA_GRAPHIX;
//    stav->kocka[stav->cislo_kocky[3]].s=2*XKOCKA_GRAPHIX-4;
//    stav->kocka[stav->cislo_kocky[3]].v=2*YKOCKA_GRAPHIX;
//    stav->cislo_kocky[3]++;
//
//    stav->kocka[stav->cislo_kocky[3]].x=1301+2;
//    stav->kocka[stav->cislo_kocky[3]].y=VYSKA2_KOCKA+YKOCKA_GRAPHIX;
//    stav->kocka[stav->cislo_kocky[3]].s=2*XKOCKA_GRAPHIX-4;
//    stav->kocka[stav->cislo_kocky[3]].v=3*YKOCKA_GRAPHIX;
//    stav->cislo_kocky[3]++;
//
//    stav->kocka[stav->cislo_kocky[3]].x=1575+2;
//    stav->kocka[stav->cislo_kocky[3]].y=VYSKA2_KOCKA;
//    stav->kocka[stav->cislo_kocky[3]].s=2*XKOCKA_GRAPHIX-4;
//    stav->kocka[stav->cislo_kocky[3]].v=4*YKOCKA_GRAPHIX;
//    stav->cislo_kocky[3]++;
//
//    stav->kocka[stav->cislo_kocky[3]].x=1952+2;
//    stav->kocka[stav->cislo_kocky[3]].y=VYSKA2_KOCKA;
//    stav->kocka[stav->cislo_kocky[3]].s=2*XKOCKA_GRAPHIX-4;
//    stav->kocka[stav->cislo_kocky[3]].v=4*YKOCKA_GRAPHIX;
//    stav->cislo_kocky[3]++;
//
//    stav->kocka[stav->cislo_kocky[3]].x=5579+2;
//    stav->kocka[stav->cislo_kocky[3]].y=VYSKA2_KOCKA+2*YKOCKA_GRAPHIX;
//    stav->kocka[stav->cislo_kocky[3]].s=2*XKOCKA_GRAPHIX-4;
//    stav->kocka[stav->cislo_kocky[3]].v=2*YKOCKA_GRAPHIX;
//    stav->cislo_kocky[3]++;
//
//    stav->kocka[stav->cislo_kocky[3]].x=6128+2;
//    stav->kocka[stav->cislo_kocky[3]].y=VYSKA2_KOCKA+2*YKOCKA_GRAPHIX;
//    stav->kocka[stav->cislo_kocky[3]].s=2*XKOCKA_GRAPHIX-4;
//    stav->kocka[stav->cislo_kocky[3]].v=2*YKOCKA_GRAPHIX;
//    stav->cislo_kocky[3]++;
//
//}
//
//
//
//
//void vyskl_blok2(StavHry *stav)
//{
//    stav->cislo_kocky[2] = stav->cislo_kocky[1];
//    int i;
//
//    stav->kocka[stav->cislo_kocky[2]].x=548;
//    stav->kocka[stav->cislo_kocky[2]].y=VYSKA2_KOCKA;
//    stav->kocka[stav->cislo_kocky[2]].s=XKOCKA_GRAPHIX;
//    stav->kocka[stav->cislo_kocky[2]].v=YKOCKA_GRAPHIX;
//    stav->cislo_kocky[2]++;
//
//    for(i=0; i<2; i++)
//    {
//        stav->kocka[stav->cislo_kocky[2]].x=685+XKOCKA_GRAPHIX+2*i*XKOCKA_GRAPHIX;
//        stav->kocka[stav->cislo_kocky[2]].y=VYSKA2_KOCKA;
//        stav->kocka[stav->cislo_kocky[2]].s=XKOCKA_GRAPHIX;
//        stav->kocka[stav->cislo_kocky[2]].v=YKOCKA_GRAPHIX;
//        stav->cislo_kocky[2]++;
//    }
//
//    stav->kocka[stav->cislo_kocky[2]].x=685+2*XKOCKA_GRAPHIX;
//    stav->kocka[stav->cislo_kocky[2]].y=VYSKA1_KOCKA;
//    stav->kocka[stav->cislo_kocky[2]].s=XKOCKA_GRAPHIX;
//    stav->kocka[stav->cislo_kocky[2]].v=YKOCKA_GRAPHIX;
//    stav->cislo_kocky[2]++;
//
//    stav->kocka[stav->cislo_kocky[2]].x=2634+XKOCKA_GRAPHIX;
//    stav->kocka[stav->cislo_kocky[2]].y=VYSKA2_KOCKA;
//    stav->kocka[stav->cislo_kocky[2]].s=XKOCKA_GRAPHIX;
//    stav->kocka[stav->cislo_kocky[2]].v=YKOCKA_GRAPHIX;
//    stav->cislo_kocky[2]++;
//
//    stav->kocka[stav->cislo_kocky[2]].x=3115+3*XKOCKA_GRAPHIX;
//    stav->kocka[stav->cislo_kocky[2]].y=VYSKA1_KOCKA;
//    stav->kocka[stav->cislo_kocky[2]].s=XKOCKA_GRAPHIX;
//    stav->kocka[stav->cislo_kocky[2]].v=YKOCKA_GRAPHIX;
//    stav->cislo_kocky[2]++;
//
//    for( i=0; i<3; i++)
//    {
//        stav->kocka[stav->cislo_kocky[2]].x=3628+3*i*XKOCKA_GRAPHIX;
//        stav->kocka[stav->cislo_kocky[2]].y=VYSKA2_KOCKA;
//        stav->kocka[stav->cislo_kocky[2]].s=XKOCKA_GRAPHIX;
//        stav->kocka[stav->cislo_kocky[2]].v=YKOCKA_GRAPHIX;
//        stav->cislo_kocky[2]++;
//
//        if( i==1 )
//        {
//            stav->kocka[stav->cislo_kocky[2]].x=3628+3*i*XKOCKA_GRAPHIX;
//            stav->kocka[stav->cislo_kocky[2]].y=VYSKA1_KOCKA;
//            stav->kocka[stav->cislo_kocky[2]].s=XKOCKA_GRAPHIX;
//            stav->kocka[stav->cislo_kocky[2]].v=YKOCKA_GRAPHIX;
//            stav->cislo_kocky[2]++;
//        }
//    }
//
//
//    for( i=0; i<2; i++)
//    {
//        stav->kocka[stav->cislo_kocky[2]].x=4380+XKOCKA_GRAPHIX+i*XKOCKA_GRAPHIX;
//        stav->kocka[stav->cislo_kocky[2]].y=VYSKA1_KOCKA;
//        stav->kocka[stav->cislo_kocky[2]].s=XKOCKA_GRAPHIX;
//        stav->kocka[stav->cislo_kocky[2]].v=YKOCKA_GRAPHIX;
//        stav->cislo_kocky[2]++;
//    }
//
//    stav->kocka[stav->cislo_kocky[2]].x=5750+2*XKOCKA_GRAPHIX;
//    stav->kocka[stav->cislo_kocky[2]].y=VYSKA2_KOCKA;
//    stav->kocka[stav->cislo_kocky[2]].s=XKOCKA_GRAPHIX;
//    stav->kocka[stav->cislo_kocky[2]].v=YKOCKA_GRAPHIX;
//    stav->cislo_kocky[2]++;
//
//}
//
//
//
//void vyskl_blok1(StavHry *stav)
//{
//    stav->cislo_kocky[1] = stav->cislo_kocky[0];
//    int i;
//
//    for( i=0; i<3; i++)
//    {
//        stav->kocka[stav->cislo_kocky[1]].x=685+2*i*XKOCKA_GRAPHIX;
//        stav->kocka[stav->cislo_kocky[1]].y=VYSKA2_KOCKA;
//        stav->kocka[stav->cislo_kocky[1]].s=XKOCKA_GRAPHIX;
//        stav->kocka[stav->cislo_kocky[1]].v=YKOCKA_GRAPHIX;
//        stav->cislo_kocky[1]++;
//    }
//
//    for( i=0; i<2; i++)
//    {
//        stav->kocka[stav->cislo_kocky[1]].x=2634+2*i*XKOCKA_GRAPHIX;
//        stav->kocka[stav->cislo_kocky[1]].y=VYSKA2_KOCKA;
//        stav->kocka[stav->cislo_kocky[1]].s=XKOCKA_GRAPHIX;
//        stav->kocka[stav->cislo_kocky[1]].v=YKOCKA_GRAPHIX;
//        stav->cislo_kocky[1]++;
//    }
//
//    for( i=0; i<8; i++)
//    {
//        stav->kocka[stav->cislo_kocky[1]].x=2738+i*XKOCKA_GRAPHIX;
//        stav->kocka[stav->cislo_kocky[1]].y=VYSKA1_KOCKA;
//        stav->kocka[stav->cislo_kocky[1]].s=XKOCKA_GRAPHIX;
//        stav->kocka[stav->cislo_kocky[1]].v=YKOCKA_GRAPHIX;
//        stav->cislo_kocky[1]++;
//    }
//
//    for( i=0; i<3; i++)
//    {
//        stav->kocka[stav->cislo_kocky[1]].x=3115+i*XKOCKA_GRAPHIX;
//        stav->kocka[stav->cislo_kocky[1]].y=VYSKA1_KOCKA;
//        stav->kocka[stav->cislo_kocky[1]].s=XKOCKA_GRAPHIX;
//        stav->kocka[stav->cislo_kocky[1]].v=YKOCKA_GRAPHIX;
//        stav->cislo_kocky[1]++;
//    }
//
//    stav->kocka[stav->cislo_kocky[1]].x=3115+3*XKOCKA_GRAPHIX;
//    stav->kocka[stav->cislo_kocky[1]].y=VYSKA2_KOCKA;
//    stav->kocka[stav->cislo_kocky[1]].s=XKOCKA_GRAPHIX;
//    stav->kocka[stav->cislo_kocky[1]].v=YKOCKA_GRAPHIX;
//    stav->cislo_kocky[1]++;
//
//    for(i=0;i<2;i++)
//    {
//        stav->kocka[stav->cislo_kocky[1]].x=3423+i*XKOCKA_GRAPHIX;
//        stav->kocka[stav->cislo_kocky[1]].y=VYSKA2_KOCKA;
//        stav->kocka[stav->cislo_kocky[1]].s=XKOCKA_GRAPHIX;
//        stav->kocka[stav->cislo_kocky[1]].v=YKOCKA_GRAPHIX;
//        stav->cislo_kocky[1]++;
//    }
//
//    stav->kocka[stav->cislo_kocky[1]].x=4039;
//    stav->kocka[stav->cislo_kocky[1]].y=VYSKA2_KOCKA;
//    stav->kocka[stav->cislo_kocky[1]].s=XKOCKA_GRAPHIX;
//    stav->kocka[stav->cislo_kocky[1]].v=YKOCKA_GRAPHIX;
//    stav->cislo_kocky[1]++;
//
//    for( i=0; i<3; i++)
//    {
//        stav->kocka[stav->cislo_kocky[1]].x=4141+i*XKOCKA_GRAPHIX;
//        stav->kocka[stav->cislo_kocky[1]].y=VYSKA1_KOCKA;
//        stav->kocka[stav->cislo_kocky[1]].s=XKOCKA_GRAPHIX;
//        stav->kocka[stav->cislo_kocky[1]].v=YKOCKA_GRAPHIX;
//        stav->cislo_kocky[1]++;
//    }
//
//    for( i=0; i<4; i++)
//    {
//        stav->kocka[stav->cislo_kocky[1]].x=4380+i*XKOCKA_GRAPHIX;
//        if(i==0 || i==3)
//            stav->kocka[stav->cislo_kocky[1]].y=VYSKA1_KOCKA;
//        else if(i==1 || i==2)
//            stav->kocka[stav->cislo_kocky[1]].y=VYSKA2_KOCKA;
//        stav->kocka[stav->cislo_kocky[1]].s=XKOCKA_GRAPHIX;
//        stav->kocka[stav->cislo_kocky[1]].v=YKOCKA_GRAPHIX;
//        stav->cislo_kocky[1]++;
//    }
//
//    for( i=0; i<4; i++)
//    {
//        if( i!=2 )
//        {
//            stav->kocka[stav->cislo_kocky[1]].x=5750+i*XKOCKA_GRAPHIX;
//            stav->kocka[stav->cislo_kocky[1]].y=VYSKA2_KOCKA;
//            stav->kocka[stav->cislo_kocky[1]].s=XKOCKA_GRAPHIX;
//            stav->kocka[stav->cislo_kocky[1]].v=YKOCKA_GRAPHIX;
//            stav->cislo_kocky[1]++;
//        }
//    }
//
//    ///dorabka 3ky bloky
//
//    stav->kocka[stav->cislo_kocky[1]].x=2191;
//    stav->kocka[stav->cislo_kocky[1]].y=VYSKA2_KOCKA-YKOCKA_GRAPHIX;
//    stav->kocka[stav->cislo_kocky[1]].s=XKOCKA_GRAPHIX;
//    stav->kocka[stav->cislo_kocky[1]].v=YKOCKA_GRAPHIX;
//    stav->cislo_kocky[1]++;
//
//}
//
//
//
//void vyskl_blok0(StavHry *stav)
//{
//    vyskladaj(stav,4,4,HORE,4588);
//    vyskladaj(stav,4,4,DOLE,4794);
//    vyskladaj(stav,5,4,HORE,5067);
//    vyskladaj(stav,4,4,DOLE,5307);
//    vyskladaj(stav,9,8,HORE,6195);
//    stav->cislo_kocky[0]++;
//    stav->kocka[stav->cislo_kocky[0]-1].x=6780;
//    stav->kocka[stav->cislo_kocky[0]-1].y=393;
//    stav->kocka[stav->cislo_kocky[0]-1].s=XKOCKA_GRAPHIX;
//    stav->kocka[stav->cislo_kocky[0]-1].v=YKOCKA_GRAPHIX;
//}
//
//
//
//void vyskl_svet(StavHry *stav)
//{
//    stav->svet.x=0;
//    stav->svet.y=0;
//    stav->svet.v=224*2.14;
//    stav->svet.s=3384*2.14;
//}
//
//void vyskladaj(StavHry *stav,int sirka_pocet, int vyska_pocet, int smer, int Xzaciatok)
//{
//    int sirka=sirka_pocet;
//    int vyska=vyska_pocet;
//
//    float zaciatok = Xzaciatok;
//
//    if(smer == 1)
//        {
//            for(int r=0; r<vyska; r++)
//            {
//                for(int s=0; s < sirka; s++)
//                {
//                    stav->kocka[stav->cislo_kocky[0]].x = zaciatok + XKOCKA_GRAPHIX*(r+s);
//                    stav->kocka[stav->cislo_kocky[0]].y = 393-r*YKOCKA_GRAPHIX;
//                    stav->kocka[stav->cislo_kocky[0]].s = XKOCKA_GRAPHIX;
//                    stav->kocka[stav->cislo_kocky[0]].v = YKOCKA_GRAPHIX;
//                    stav->cislo_kocky[0]++;
//                }
//                sirka--;
//            }
//        }
//    else if (smer == -1)
//          {
//            for(int r=0; r<vyska; r++)
//            {
//                for(int s=0; s < sirka; s++)
//                {
//                    stav->kocka[stav->cislo_kocky[0]].x = zaciatok + XKOCKA_GRAPHIX*s;
//                    stav->kocka[stav->cislo_kocky[0]].y = 393-r*YKOCKA_GRAPHIX;
//                    stav->kocka[stav->cislo_kocky[0]].s = XKOCKA_GRAPHIX;
//                    stav->kocka[stav->cislo_kocky[0]].v = YKOCKA_GRAPHIX;
//                    stav->cislo_kocky[0]++;
//                }
//                sirka--;
//            }
//        }
//    else
//        {
//            printf("Zadali ste zly smer 'kockovania' ");
//            exit(1);
//        }
//}
