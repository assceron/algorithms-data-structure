#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "lista.h"
int main()
{
    LISTA start;
    int comando;
    printf("Introduci 1 e crea lista:");
    scanf("%d", &comando);
    while(comando!=0)
    {
        switch(comando)
        {
            case 1:
                start=crealista();
                break;
            case 2:
                ins_lista(start);
                stampa(start);
                break;
            case 3:
                canc(start);
                stampa(start);
                break;
            case 4:
                ricercachiave(start);
                stampa(start);
                break;
            case 0:
                distr_lista(start);
                printf("\nProcesso terminato!");
                break;
        }
        printf("\nIntroduci 2 per inserire un elemento:");
        printf("\nIntroduci 3 per eliminare un elemento:");
        printf("\nINtroduci 4 per sostituire un elemento:");
        printf("\nIntroduci 0 per terminare");
        scanf("%d",&comando);
    }
    return 0;
}
