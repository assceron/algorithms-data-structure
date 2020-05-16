#include <stdio.h>
#include <stdlib.h>
struct persona{
char codice[10+1];
struct persona *link;
};
int main()
{
    int comando;
    struct persona *p,*punt,*t;

    p =(struct persona*)malloc(sizeof *p);
    printf("\nPrima persona della fila.Inserire codice: ");
    scanf("%s", p->codice);
    t=p;
    punt=p;
    punt->link=NULL;
    printf("\nIntroduci 0 per aggiungere una persona in fondo alla fila");
    printf("\nIntroduci 1 per estrarre una persona dall'inizio della fila");
    printf("\nIntroduci 2 per stampare l'elenco di persone dal primo all'ultimo");
    printf("\nIntroduci 3 per terminare");
    printf("\nCOMANDO: ");
    scanf("%d", &comando);
     while(comando!=3)
     {
         switch(comando){

         case 0:
                punt->link =(struct persona*)malloc(sizeof *punt);
                punt=punt->link;
                printf("\nInserire codice: ");
                scanf("%s",punt->codice);
                punt->link=NULL;
                break;

         case 1:
                if(t->link!=NULL)
                {
                    p=t->link;
                    t=p;}
                else
                    printf("\nUltima persona rimasta.");
                break;


         case 2:
             printf("\n\nLista:\n");
             p=t;
             while(p!=NULL)
             {
                 printf("%s\n", p->codice);
                 p=p->link;
             }
             printf("FINE !\n");
             break;
     }
     printf("\nIntroduci 0 per aggiungere una persona in fondo alla fila");
    printf("\nIntroduci 1 per estrarre una persona dall'inizio della fila");
    printf("\nIntroduci 2 per stampare l'elenco di persone dal primo all'ultimo");
    printf("\nIntroduci 3 per terminare");
    printf("\nCOMANDO: ");
    scanf("%d", &comando);
     }

     printf("\nProcesso terminato! ");

    return 0;
}
