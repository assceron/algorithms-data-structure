#include <stdio.h>
#include <stdlib.h>
#include "fifo.h"
#include "item.h"
int main()
{
    int comando,maxN;
    CODA punt;
    Item it;
    printf("\nPremere 1 per creare coda:");
    scanf("%d",&comando);
    while(comando!=0)
    {
        switch(comando)
        {
        case 1:
            printf("\nNumero massimo di elementi??");
            scanf("%d",&maxN);
            punt=creaCODA(maxN);
            break;

            case 2:
                printf("\nNumero dati in coda:");
                stampaNum(punt);
            break;

            case 3:

              if(pienaCODA(punt)!= maxN)
               {
                it=acquisizione();
                putCODA(punt,it);}
                 else
                    printf("\nCoda piena!");
            break;

            case 4:
                if(vuotaCODA(punt)!=0)
            {
                it=getCODA(punt);
                stampaItem(it);
                }
            else
                printf("\nCoda vuota.");
            break;

            case 5:
                stampaCODA(punt);
            break;

            case 6:
                salvaCODA(punt);
            break;

            case 7:
                caricaCODA(punt);
            break;

        }
       printf("\nPremere 1 per creare coda:");
       printf("\nPremere 2 per stampare numero dati in coda:");
       printf("\nPremere 3 per inserire in coda:");
       printf("\nPremere 4 per estrarre dalla coda:");
       printf("\nPremere 5 per visualizzare tutti gli elementi della coda:");
       printf("\nPremere 6 per salvare su file:");
       printf("\nPremere 7 per caricare da file:");
       printf("\nPremere 0 per terminare:");
        scanf("%d",&comando);
    }
     printf("\nProcesso terminato.");
    return 0;
}
