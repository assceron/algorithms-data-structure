#include "st.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct symbletable{
    char **a;
    int n;
    int m;};

ST STinit(int maxN){
    ST st;
    int i;
    st=malloc(sizeof(*st));
    st->n=0;
    st->m=maxN;
    st->a=malloc(maxN*sizeof(char*));
    for(i=0;i<st->m;i++)
        {st->a[i]=malloc(11*sizeof(char));
         st->a[i][0]='\0';}
    return st;
}

int hasha(char *v, int M){
    int h=0, base=127;
    for(;*v!='\0';v++)
        h=(base*h + *v)%M;
    return h;
}

int STinsert(ST st, char *s){
    int i=hasha(s,st->m);
    while(st->a[i][0]!='\0')
        i=(i+1)%st->m;
    strcpy(st->a[i],s);
    st->n++;
    return i;
}

int STsearch(ST st, char *c){
    int i=hasha(c, st->m);
    if(strcmp(st->a[i],"\0")==0)
        return -1;
    while(strcmp(st->a[i],"\0")!=0)
        if(strcmp(c,st->a[i])==0)
            return i;
        else
            i=(i+1)%st->m;
        return i;
}
char* STsearch_str(ST st, int i)
{
    return st->a[i];
}
