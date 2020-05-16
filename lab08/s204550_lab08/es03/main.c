#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 9
void crea_comb(int pos,char val[],int mark[],char sol[],int n,char str1[],char str2[],char str3[], int l)
{
 int i,R;
 if(pos>=n)
 {

    R=contr_stamp(sol,str1,str2,str3,l);
    if(R==1)
        printf("ok");
    return;
 }
 for(i=0;i<n;i++)
 {
     if(mark[i]==0)
     {
         mark[i]=1;
         sol[pos]=val[i];
         crea_comb(pos+1,val,mark,sol,n,str1,str2,str3,l);
         mark[i]=0;
     }
 }
 return;
};
int contr_stamp(char sol[],char str1[],char str2[],char str3[], int l)
{
     int cont=0, j,n1,n2,n3;
    char st1[l+1],st2[l+1],st3[l+1];
    strcpy(st1,str1);
    strcpy(st2,str2);
    strcpy(st3,str3);

        for(j=0;j<l && cont<3;j++)
        {
            if(st1[j]=='_')
            {
                st1[j]=sol[cont];
                cont++;
            }
        }
        for(j=0;j<l && cont<6 && cont>=3;j++)
        {
            if(st2[j]=='_')
            {
                st2[j]=sol[cont];
                cont++;
            }
        }
        for(j=0;j<l &&cont<9 && cont>=6;j++)
        {
            if(st3[j]=='_')
            {
                st3[j]=sol[cont];
                cont++;
            }
        }
    if(cont!=9)return 0;
    n1=atoi(st1);
    n2=atoi(st2);
    n3=atoi(st3);
    if(n1+n2==n3)
    {
        printf("\n%d +",n1);
        printf("\n%d =",n2);
        printf("\n-------------------");
        printf("\n%d ",n3);
        return 1;
    }
    else return 0;
};
int main(int argc, char *argv[])
{
    int l,mark[max],i=0;
    char *str1,*str2,*str3,sol[max+1],val[max+1];
   if(argc!=5)
   {
       printf("Errore cmd.");
       exit (1);
   }
   l=atoi(argv[1]);
    str1=malloc((l+1)*sizeof(char));
    str2=malloc((l+1)*sizeof(char));
    str3=malloc((l+1)*sizeof(char));
    strcpy(str1,argv[2]);
    strcpy(str2,argv[3]);
    strcpy(str3,argv[4]);
    mark[i]=0;
    val[i]='1';
    for(i=1;i<max;i++){
        mark[i]=0;
        val[i]=val[i-1]+1;
    }
    crea_comb(0,val,mark,sol,max,str1,str2,str3,l);
    return 0;
}
