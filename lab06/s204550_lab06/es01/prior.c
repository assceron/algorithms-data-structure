#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prior.h"
#include "stude.h"


int cardinalitapr(stud *s)
{
    if(s==NULL)
        return 0;
    return 1+ cardinalitapr(s->next);
};
stud* creastudpr()
{
    stud *s;
    s=(stud*)malloc(sizeof (struct Studente));
    printf("\nIntroduci studente: ");
    scanf("%s %s %s %d %f", s->nome,s->cognome, s->matricola, &(s->carriera.crediti), &(s->carriera.media));
    s->next=NULL;
    return s;
};
stud* creapr()
{
    stud *head;
    head=creastudpr();
    head->next=NULL;

    return head;
};
stud* inspr(stud *s)
{
  int flag;
  stud *temp,*app;

  if(s==NULL)
  {
      temp=creapr();
      return temp;
  }
  else {
        temp=creastudpr();
  if(strcmp(temp->nome,s->nome)<0)
  {
      temp->next=s;
      return temp;
  }
   else {
        flag=0;
        for(app=s;app->next!=NULL && flag==0;app=app->next)
    {

        if(strcmp(temp->nome,app->nome)>0 && (strcmp(temp->nome,app->next->nome)<0))
           {
                temp->next=app->next;
                app->next=temp;
                flag=1;}
        else
            {
                if(strcmp(temp->nome,app->nome)==0)
                {
                    temp->next=app->next;
                    app->next=temp;
                    flag=1;
                }

                    else
                    flag=0;
            }


    }
    if(flag==0)
    {
        app->next=temp;
        temp->next=NULL;
    }
    }}
    return s;
};
stud* estrpr(stud *t)
{
    stud* temp;
    temp=t->next;
    free(t);
    return temp;
};
void stampapr(stud *t)
{
    stud *temp;
    for(temp=t;temp!=NULL;temp=temp->next)
         printf("%s %s %s %d %f\n", temp->nome,temp->cognome, temp->matricola, (temp->carriera.crediti), (temp->carriera.media));
};
void distrpr(stud *t)
{
    stud *temp;
    for(temp=t;temp!=NULL;temp=temp->next)
        free(temp);

};
