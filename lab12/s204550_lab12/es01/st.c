#include <stdlib.h>
#include <stdio.h>
#include "st.h"
#include "item.h"
#include <string.h>

struct symbletable{
    Item *a;
    int n;
    int m;};

ST STinit(int maxN){
    ST st;
    int i;
    st=malloc(sizeof(*st));
    st->n=0;
    st->m=maxN;
    st->a=malloc(maxN*sizeof(Item));
    for(i=0;i<st->m;i++)
        st->a[i]=NULLitem();
    return st;
}

int hasha(char *v, int M){
    int h=0, base=127;
    for(;*v!='\0';v++)
        h=(base*h + *v)%M;
    return h;
}

void STinsert(ST st, Item it){
    int i=hasha(key(it),st->m);
    while(full(st->a[i])==0)
        i=(i+1)%st->m;
    st->a[i]=it;
    st->n++;
}

int STsearch(ST st, char *c){
    int i=hasha(c, st->m);
    while(strcmp(key(st->a[i]),"\0")!=0)
        if(strcmp(c,key(st->a[i]))==0)
            return i;
        else
            i=(i+1)%st->m;
        return i;
}
void stampa_gradi(ST st,int* vett)
{
     int v;
    for (v=0; v < st->m; v++){
        stampaItem(st->a[v]);
        printf("Grado = %d\n",vett[v]);
}
}

void search2(ST st, int i){
    stampaItem(st->a[i]);}

Item regione(ST st, int i){
    return st->a[i];
}
