#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "stack.h"
#include "queue.h"
#include "prior.h"
#include "stude.h"
int main()
{
    int comando,ric;
    char str[36];
    stud *head,*tail;
    printf("\nIntroduci 0 per operazioni su lista");
    printf("\nIntroduci 1 per operazioni su pila");
    printf("\nIntroduci 2 per operazioni su coda");
    printf("\nIntroduci 3 per operazioni su coda a priorità\n");
    scanf("%d",&comando);
    switch(comando){

    /*lista non ordinata*/
    case 0:
        head=crealista();
        tail=head;

        while(comando!=7){
        printf("\nIntroduci 0 per cardinalità");
        printf("\nIntroduci 1 per inserire in testa");
        printf("\nIntroduci 2 per ins in coda");
        printf("\nIntroduci 3 per ricerca");
        printf("\nIntroduci 4 per estrazione ");
        printf("\nIntroduci 5 per visualizzazione");
        printf("\nIntroduci 6 per distruzione");
        printf("\nIntroduci 7 per teminare.\n");

        scanf("%d", &comando);

       switch (comando){

        case 0:
            printf("\nCardinalità= %d", cardinalita(head));
break;
        case 1:
            head=instesta(head);
    break;
        case 2:
            tail=inscoda(tail);
break;

        case 3:
           printf("\nVuoi cercare per nome.1, cognome.2, matricola.3   :");
           scanf("%d",&ric);
           if(ric==1)
           {
               printf("\nInserisci nome:");
               scanf("%s", str);
               ricercanome(head, str);
               break;
           }
           if(ric==2)
           {
               printf("\nInserisci cognome:");
               scanf("%s", str);
               ricercacogn(head, str);
               break;
           }
           if(ric==3)
           {
               printf("\nInserisci matricola:");
               scanf("%s", str);
               ricercamatr(head, str);
               break;
           }
break;
        case 4:
             printf("\nVuoi eliminare per nome.1, cognome.2, matricola.3   :");
           scanf("%d",&ric);
           if(ric==1)
           {
               printf("\nInserisci nome:");
               scanf("%s", str);
               head=cancnome(head, str);
               break;
           }
           if(ric==2)
           {
               printf("\nInserisci cognome:");
               scanf("%s", str);
               head=canccogn(head, str);
               break;
           }
           if(ric==3)
           {
               printf("\nInserisci matricola:");
               scanf("%s", str);
               head=cancmatr(head, str);
               break;
           }
break;
        case 5:
          stampa(head);
break;
        case 6:
           distr(head);
break;
       }}
       break;

/**/
    case 1:

        head=creastack();

        while(comando!=5){
        printf("\nIntroduci 0 per cardinalità");
        printf("\nIntroduci 1 per push");
        printf("\nIntroduci 2 per pop ");
        printf("\nIntroduci 3 per visualizzazione");
        printf("\nIntroduci 4 per distruzione");
        printf("\nIntroduci 5 per teminare.\n");
        scanf("%d", &comando);

        switch(comando)
        {
        case 0:
            printf("\nCardinalità = %d", cardinalitastack(head));
            break;
        case 1:
            head=push(head);
            break;
        case 2:
            head=pop(head);
            break;
        case 3:
            stampastack(head);
            break;
        case 4:
            distrstack(head);
            break;
        }
        }
break;

/**/
    case 2:

        head=creacoda();
        tail=head;

        while(comando!=5){
        printf("\nIntroduci 0 per cardinalità");
        printf("\nIntroduci 1 per ins coda");
        printf("\nIntroduci 2 per estr testa ");
        printf("\nIntroduci 3 per visualizzazione");
        printf("\nIntroduci 4 per distruzione");
        printf("\nIntroduci 5 per teminare.\n");
        scanf("%d", &comando);

        switch(comando)
        {
        case 0:
            printf("\nCardinalità = %d", cardinalitastack(head));
            break;
        case 1:
            tail=inscoda(tail);
            break;
        case 2:
            head=estrcoda(head);
            break;
        case 3:
            stampacoda(head);
            break;
        case 4:
            distrcoda(head);
            break;
        }
        }

break;

/**/
    case 3:


        head=creapr();

        while(comando!=5){
        printf("\nIntroduci 0 per cardinalità");
        printf("\nIntroduci 1 per inser prioritario");
        printf("\nIntroduci 2 per estr priorità mass ");
        printf("\nIntroduci 3 per visualizzazione priorità mass");
        printf("\nIntroduci 4 per distruzione");
        printf("\nIntroduci 5 per teminare.\n");
        scanf("%d", &comando);

        switch(comando)
        {
        case 0:
            printf("\nCardinalità = %d", cardinalitapr(head));
            break;
        case 1:
            head=inspr(head);
            break;
        case 2:
            head=estrpr(head);
            break;
        case 3:
            stampapr(head);
            break;
        case 4:
            distrpr(head);
            break;

        }
        }

break;




    }
return 0;
}
