#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "stude.h"

int cardinalita(stud *s)
{
    if(s==NULL)
        return 0;
    return 1+ cardinalita(s->next);
};
stud* creastud()
{
    stud *s;
    s=(stud*)malloc(sizeof (struct Studente));
    printf("\nIntroduci studente: ");
    scanf("%s %s %s %d %f", s->nome,s->cognome, s->matricola, &(s->carriera.crediti), &(s->carriera.media));
    s->next=NULL;
    return s;
};
stud* crealista()
{
    stud *head;
    head=creastud();
    head->next=NULL;

    return head;
};
stud* instesta(stud *t)
{
    stud *temp;
      if(t==NULL)
    {
        temp=crealista();
        return temp;
    }
    temp=creastud();
    temp->next=t;
    return temp;
};
stud* inscoda( stud *t)
{
    stud *temp;
    if(t==NULL)
    {
        temp=crealista();
        return temp;
    }
    temp=creastud();
    t->next=temp;
    temp->next=NULL;
    return temp;
};
void ricercanome(stud *t,char str[])
{
    stud *temp;
    for(temp=t;temp!=NULL;temp=temp->next)
    {
        if(strcmp(str,temp->nome)==0)
            printf("%s %s %s %d %f\n", temp->nome,temp->cognome, temp->matricola, (temp->carriera.crediti), (temp->carriera.media));

    }
};
void ricercacogn(stud *t,char str[])
{
    stud *temp;
    for(temp=t;temp!=NULL;temp=temp->next)
    {
        if(strcmp(str,temp->cognome)==0)
            printf("%s %s %s %d %f\n", temp->nome,temp->cognome, temp->matricola, (temp->carriera.crediti), (temp->carriera.media));

    }
};
void ricercamatr(stud *t,char str[])
{
    stud *temp;
    for(temp=t;temp!=NULL;temp=temp->next)
    {
        if(strcmp(str,temp->matricola)==0)
            printf("%s %s %s %d %f\n", temp->nome,temp->cognome, temp->matricola, (temp->carriera.crediti), (temp->carriera.media));

    }
};
stud* cancnome(stud *t, char str[])
{
     stud *temp,*prec;
    for(temp=t;temp!=NULL;temp=temp->next)
    {
        if(strcmp(str,temp->nome)==0)
        {
            if(temp==t)
            {
                t=t->next;
                free(temp);
            }
            else
            {
                prec->next=prec->next->next;
                free(temp);
            }
        }
            else
                prec=temp;

    }
    return t;
};

stud* canccogn(stud *t, char str[])
{
     stud *temp,*prec;
    for(temp=t;temp!=NULL;temp=temp->next)
    {
        if(strcmp(str,temp->cognome)==0)
        {
            if(temp==t)
            {
                t=temp->next;
                free(temp);
            }
            else
            {
                prec->next=temp->next;
                free(temp);
            }
        }
            else
                prec=temp;

}
return t;
};
stud* cancmatr(stud *t, char str[])
{
     stud *temp,*prec;
    for(temp=t;temp!=NULL;temp=temp->next)
    {
        if(strcmp(str,temp->matricola)==0)
        {
            if(temp==t)
            {
                t=temp->next;
                free(temp);
            }
            else
            {
                prec->next=temp->next;
                free(temp);
            }}
            else
                prec=temp;

}
return t;
};
void stampa(stud *t)
{
    stud *temp;
    for(temp=t;temp!=NULL;temp=temp->next)
         printf("%s %s %s %d %f\n", temp->nome,temp->cognome, temp->matricola, (temp->carriera.crediti), (temp->carriera.media));
};
void distr(stud *t)
{
    stud *temp;
    for(temp=t;temp!=NULL;temp=temp->next)
        free(temp);

}
