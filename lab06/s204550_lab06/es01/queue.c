#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"
#include "stude.h"
int cardinalitacoda(stud *s)
{
    if(s==NULL)
        return 0;
    return 1+ cardinalitacoda(s->next);
};
stud* creastudcoda()
{
    stud *s;
    s=(stud*)malloc(sizeof (struct Studente));
    printf("\nIntroduci studente: ");
    scanf("%s %s %s %d %f", s->nome,s->cognome, s->matricola, &(s->carriera.crediti), &(s->carriera.media));
    s->next=NULL;
    return s;
};
stud* creacoda()
{
    stud *head;
    head=creastudcoda();
    head->next=NULL;

    return head;
};
stud* inscodacoda( stud *t)
{
    stud *temp;
    temp=creastudcoda();
    t->next=temp;
    temp->next=NULL;
    return temp;
};
stud* estrcoda(stud *t)
{
    stud* temp;
    temp=t->next;
    free(t);
    return temp;
};
void stampacoda(stud *t)
{
    stud *temp;
    for(temp=t;temp!=NULL;temp=temp->next)
         printf("%s %s %s %d %f\n", temp->nome,temp->cognome, temp->matricola, (temp->carriera.crediti), (temp->carriera.media));
};
void distrcoda(stud *t)
{
    stud *temp;
    for(temp=t;temp!=NULL;temp=temp->next)
        free(temp);

}
