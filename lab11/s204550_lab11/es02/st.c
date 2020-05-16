#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "st.h"

struct symboltable{
    Item *item;
    int N;
    int M;
    };
struct ac
{
    char id[26];
    int kb;
    int durata;
};
ST crea(int maxN)
{
    ST st;
    int i;
    st=malloc(sizeof *st);
    st->N=0;
    st->M=maxN;
    st->item=malloc(maxN*sizeof(Item));
    for(i=0;i<maxN;i++)
        st->item[i]=NULLITEM();
    return st;
}
void inserisci(ST st, Item item)
{
    int i=hash(item,st->M);
    while(eq(st->item[i],"\0")!=1)
        i=(i+1)%st->M;
    st->item[i]=item;
    st->N++;
    return;
}
Item cerca(ST st, accessi traccia)
{
    char id[26];
    strcpy(id,traccia->id);
    int i=hash2(id,st->M);
    while(eq(st->item[i],id)!=1)
    {
            i=(i+1)%st->M;
    }
    return st->item[i];
}
int hash2(char *v,int M)
{
    int h=0, base=127;
    for(;*v!='\0';v++)
        h=(base*h + *v) % M;
    return h;
}
FILE* elenca(ST st, accessi *traccia, int cont2,FILE *fp)
{
    int i,j,n_acc,n_kb,n_dur;
    for(i=0;i<st->M;i++)
    {
         n_acc=n_kb=n_dur=0;
        for(j=0;j<cont2;j++)
        {
            if(eq(st->item[i],traccia[j]->id)==1)
             {
                 n_acc++;
                n_kb+=traccia[j]->kb;
                n_dur+=traccia[j]->durata;
             }
        }
        fp=stampa_cliente(fp,st->item[i]);
        fprintf(fp,"\tacc=%d\n\t%d\n\t%d\n",n_acc,n_kb,n_dur);
    }
    return fp;
}
accessi* salva_acc(FILE *f_in2, accessi *traccia,int cont2)
{
   int i;
    traccia=malloc(cont2*sizeof(accessi));
    for(i=0;i<cont2;i++)
    {
        traccia[i]=malloc(sizeof(struct ac));
        fscanf(f_in2,"%s %d %d",traccia[i]->id, &traccia[i]->kb, &traccia[i]->durata);
    }
    fclose(f_in2);
    return traccia;
}
int estrai_kb(accessi traccia)
{
    return traccia->kb;
}
