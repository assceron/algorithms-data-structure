#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#define max 26
struct item{
    char idCl[max];
    char cognome[max];
    char nome[max];
    char categoria[max];
    };
struct ka
{
    char cat[26];
    Item *clienti;
    int *n_clienti;
    int kb_tot;
};
Item NULLITEM()
{
    Item a;
    a=malloc(sizeof *a);
    strcpy(a->idCl,"\0");
    strcpy(a->cognome,"\0");
    strcpy(a->nome,"\0");
    strcpy(a->categoria,"\0");
    return a;
}
int hash(Item item, int M)
{
    char *v;
    int h=0, base=127;
    v=malloc(sizeof *v);
    v=item->idCl;
    for(;*v!='\0';v++)
        h=(base*h + *v) % M;
    return h;
}

int eq(Item item1, char str[])
{
    if(strcmp(item1->idCl,str)==0)
        return 1;
    else return 0;
}
Item salva_item(char *s)
{
    Item tmp;
    tmp=malloc(sizeof *tmp);
    sscanf(s,"%s %s %s %s",tmp->idCl,tmp->cognome,tmp->nome, tmp->categoria);
    return tmp;
}
Item copia(Item a, Item b)
{
    strcpy(a->idCl,b->idCl);
    strcpy(a->nome,b->nome);
    strcpy(a->cognome,b->cognome);
    strcpy(a->categoria,b->categoria);
    return a;
}
int salva_cat(Item item,kate *categ, int n_cat,int KB)
{
    int i,posi=0,flag=0;

        for(i=0;i<n_cat && flag==0;i++)
    {
        if(strcmp(categ[i]->cat,item->categoria)==0)
            flag=1;
    }
     if(flag==0)
    {
        strcpy(categ[n_cat]->cat,item->categoria);
        posi=(*categ[n_cat]->n_clienti);
        categ[n_cat]->clienti[posi]=item;
        (*categ[n_cat]->n_clienti)++;
        categ[n_cat]->kb_tot+=KB;
        n_cat++;
    }
    else
    {
        i--;
        posi=(*categ[i]->n_clienti);
        categ[i]->clienti[posi]=item;
        (*categ[i]->n_clienti)++;
        categ[i]->kb_tot+=KB;
    }
    return n_cat;
}
FILE* stampa_cliente(FILE *fp,Item item)
{
    fprintf(fp,"%s %s\n",item->nome, item->cognome);
    return fp;
}
FILE* stampa_clienti(FILE *fp,kate categ)
{
    int j;
    for(j=0;j<(*categ->n_clienti);j++)
        fp=stampa_cliente(fp,categ->clienti[j]);
    return fp;
}
kate* ini_cat(kate *categ,int cont1)
{
    int i,j;
        categ=malloc(cont1* sizeof(kate));
    for(i=0;i<cont1;i++)
    {
        categ[i]=malloc(sizeof(struct ka));
     strcpy(categ[i]->cat,"\0");
    categ[i]->n_clienti=malloc(sizeof (int*));
    (*categ[i]->n_clienti)=0;
    categ[i]->kb_tot=0;
     categ[i]->clienti=malloc(cont1*sizeof(Item));
     for(j=0;j<cont1;j++)
        categ[i]->clienti[j]=NULLITEM();
    }
    return categ;
}

FILE* stampa_kb_cat(FILE *fp, kate categ)
{
    fprintf(fp,"%s--> dati trasmessi: %d KB\n",categ->cat,categ->kb_tot);
    return fp;
}
FILE* stampa_cat(FILE *fp, kate categ)
{
    fprintf(fp,"\n-%s:\n",categ->cat);
    return  fp;
}
