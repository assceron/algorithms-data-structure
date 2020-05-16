#include "item.h"
#include "fifo.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
struct item
{
    char *str;
    int num;
};
Item acquisizione()
{

    Item temp=malloc(sizeof(Item));
    char s[40];
    int l,n;
    printf("\nIntroduci elemento(stringa numero):");
    scanf("%s %d",s, &n);
    l=strlen(s);
    temp->str=malloc(l*sizeof(char));
    strcpy(temp->str,s);
    temp->num=n;
    return temp;
};
/*void salvaItem(Item v[],Item dato,int indice)
{
    strcpy(v[indice],dato->str);
    return;
};*/
void stampaItem(Item dato)
{
    printf("\n%s %d", dato->str, dato->num);
    return;
};
void salvasufile(FILE *fo,Item dato)
{
    fprintf(fo,"\n%s",dato->str);
    return;
};
int dimfile(char nome[])
{
    FILE *fp;
    int i=0;
    char s[30];
    fp=fopen(nome,"r");
    while(fscanf(fp,"%s %*d",s)!=EOF)
       {i++;}
       fclose(fp);
    return i;
};
Item caricadafile(char *s)
{   Item temp=malloc(sizeof(Item));
    int l,cifra;
    char stringa[30];
    sscanf(s,"%s%d",stringa,&cifra);
    l=strlen(stringa);
    temp->str=malloc(l*sizeof(char));
    strcpy(temp->str,stringa);
    temp->num=cifra;

    return temp;
};

