#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "item.h"
struct nodo
{
    ITEM person;
    link next;
};
struct lista
{
    link head;
    int N;
    link tail;
};
link NEW(ITEM item, link next)
{
   link x=malloc(sizeof *x);
   x->person=item;
   x->next=next;
   return x;
};
LISTA crealista()
{
    LISTA l=malloc(sizeof(*l));
    l->N=0;
    l->head=l->tail=NEW(itemnullo(), NULL);
    return l;
};
void ins_lista(LISTA l)
{
    ITEM item=malloc(sizeof(ITEM));
    item=new_item();
    l->head=NEW(item,l->head);
    l->N++;
    return;
};
void ricercachiave(LISTA l)
{
    char key[11],sost[11];
    printf("\nINserire codice da ricercare e da sostituire:");
    scanf("%s %s",key,sost);
    cerca_sost(l->head,key,sost,l->tail);
    return;
};
void cerca_sost(link h, char key[],char sost[],link t)
{
    if(h==t)
    {
        printf("\nLista vuota.");
        return;
    }
    if(verificakey(h->person,key)==1)
    {
        h->person=sostkey(h->person,sost);
        return;
    }
    cerca_sost(h->next,key,sost,t);
};
void  canc(LISTA l)
{
    char key[11];
    printf("\nInserisci codice da cancellare:");
    scanf("%s",key);
    l->head=canc_k(l->head,key);
    l->N--;
    return;
};
link canc_k(link x, char key[])
{
    if(x==NULL)
        return NULL;
    if(verificakey(x->person,key)==1)
        {link t=x->next;
        free(x);
        return t;}
        x->next=canc_k(x->next,key);
        return x;
};
void stampa(LISTA l)
{
    int i;
    link t=l->head;
    for(i=0;i<l->N;i++)
    {
        stampaitem(t->person);
        t=t->next;
    }
};
void distr_lista(LISTA l)
{
    free(l);
    return;
};
