#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "stude.h"



int cardinalitastack(stud *s)
{
    if(s==NULL)
        return 0;
    return 1+ cardinalitastack(s->next);
};
stud* creastudstack()
{
    stud *s;
    s=(stud*)malloc(sizeof (struct Studente));
    printf("\nIntroduci studente: ");
    scanf("%s %s %s %d %f", s->nome,s->cognome, s->matricola, &(s->carriera.crediti), &(s->carriera.media));
    s->next=NULL;
    return s;
};
stud* creastack()
{
    stud *head;
    head=creastudstack();
    head->next=NULL;

    return head;
};
stud* push(stud *t)
{
    stud *temp;
    temp=creastudstack();
    temp->next=t;
    return temp;
};
stud* pop(stud *t)
{
    stud* temp;
    temp=t->next;
    free(t);
    return temp;
};
void stampastack(stud *t)
{
    stud *temp;
    for(temp=t;temp!=NULL;temp=temp->next)
         printf("%s %s %s %d %f\n", temp->nome,temp->cognome, temp->matricola, (temp->carriera.crediti), (temp->carriera.media));
};
void distrstack(stud *t)
{
    stud *temp;
    for(temp=t;temp!=NULL;temp=temp->next)
        free(temp);

};

