A* algoritmus pouzity na hru na Snake

Spustenie programu pomocu PROJEKT.EXE

Prvotne nastavenie v mode A*star hladania cesty. Algoritmus vykresluje jednotlive kroky hladania,
ako aj nasledne najdenu najkratsiu cestu. Pole bodov je mozne si menit z prednastavenych 39x39
bodov na lubovolne zvolene (do 99) pri spustenie .exe suboru. 

Mode Snake vyhladava najkratsiu cestu len 1x za cyklus, nedeje sa teda o "dynamicke" hladanie v 
kazdom bode posuvu. Je tomu kvoli zrychlenie vypoctov a zjednoduseniu celeho algoritmu. Moze to 
ale vytvarat moznosti kedy cesta teoreticky existuje pri posunuti o random policko ale algoritmus
ju vyhodnoti ako neexistujucu. Najma sa to deje so zvacsovanim snakea, kedy jeho telo moze 
zaberat dolezite body cesty. 
Pre nasledne zlepsenie by sa dalo spravit napr. presuvanie na nahodne body a v nich by sa zakazdym
vypocitavala cesta az dokym by sa nenasla / alebo dokym by mal Snake este volne moznosti bodov.

Vytvaranie aj nicenie prekazok, pomocou klaves #W a #C ide pri Snake mode robit aj pocas "behu"
algoritmu. Kliky mysou sa daju len v #stopnutom rezime.

Vysvetlivky k nastaveniu algoritmu by sa mali vypisovat pre jednotlive mody v klasickom C okne.

Na grafiku algoritmu je pouzita SDL_2.0 kniznica. 


