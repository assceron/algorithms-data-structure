#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*typedef int Item;*/
typedef char* Item;

/*INTERI*/
/*void MergeSortInt(Item *interi, int l, int r);
void MergeInt(Item *interi,int l, int q, int r);*/

/*STRINGHE*/
void MergeSortStr(Item *stringhe, int l,int r);
void MergeStr(Item *stringhe, int l, int q, int r);
int main()
{
    FILE *fp;
    int N,i,lung;
    char stringa[51],nomefile[20];
    /*Item *interi;*/
    Item *stringhe;

     printf("File input: ");
     scanf("%s", nomefile);
     fp=fopen(nomefile,"r");
     fscanf(fp,"%d",&N);

     /*INTERI*/

 /*    interi=malloc(N*sizeof(Item));*/
     /*for(i=0;i<N;i++)
     {
         fscanf(fp,"%d",&interi[i]);
     }
*/
     /*STRINGHE*/

     stringhe=malloc(N*sizeof(Item));

     for(i=0;i<N;i++)
     {
         fscanf(fp,"%s",stringa);
         lung=strlen(stringa)+1;
         stringhe[i]=malloc(lung*sizeof(char));
         strcpy(stringhe[i],stringa);
     }

     fclose(fp);

     /*INTERI*/
       /* MergeSortInt(interi,0,N);
        for(i=0;i<N;i++)
        printf("%d\n",interi[i]);*/
     /*STRINGHE*/
        MergeSortStr(stringhe,0,N-1);
        for(i=0;i<N;i++)
        printf("%s\n",stringhe[i]);
    return 0;
}
/*INTERI*//*
void MergeSortInt(Item *interi, int l, int r)
{
    int q=(l+r)/2;
    if(r<=l)
        return;
    MergeSortInt(interi,l,q);
    MergeSortInt(interi,q+1,r);
    MergeInt(interi,l,q,r);
}
void MergeInt(Item *interi,int l, int q, int r)
{
    int i,j,k;
    Item* B= (Item)malloc(sizeof(Item)*r);
    i=l; j=q+1;
    for(k=l;k<=r;k++)
    {
        if(i>q)
            B[k]=interi[j++];
        else if(j>r)
             B[k]=interi[i++];
        else if(interi[i]<interi[j] || interi[i]==interi[j])
             B[k]=interi[i++];
        else
             B[k]=interi[j++];
    }
    for(k=l;k<=r;k++)
        interi[k]=B[k];
    return;
}
*/
/*STRINGHE*/
void MergeSortStr(Item *stringhe, int l,int r)
{
     int q=(l+r)/2;
    if(r<=l)
        return;
    MergeSortStr(stringhe,l,q);
    MergeSortStr(stringhe,q+1,r);
    MergeStr(stringhe,l,q,r);
}
void MergeStr(Item *stringhe, int l, int q, int r)
{
    int i,j,k;
    char** B;

    B=malloc((r+1)*sizeof(char*));
    for(i=0;i<r+1;i++)
        B[i]=malloc(51*sizeof(char));
    i=l; j=q+1;
    for(k=l;k<=r;k++)
    {
        if(i>q)
            strcpy(B[k],stringhe[j++]);
        else if(j>r)
             strcpy(B[k],stringhe[i++]);
        else if(strcmp(stringhe[i],stringhe[j])<0 || strcmp(stringhe[i],stringhe[j])==0)
            strcpy(B[k],stringhe[i++]);
        else
            strcpy(B[k],stringhe[j++]);
    }
    for(k=l;k<=r;k++){
        strcpy(stringhe[k],B[k]);
        free(B[k]);
    }
    free(B);
    return;
}
