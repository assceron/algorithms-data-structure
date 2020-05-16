#include <stdio.h>
#include <stdlib.h>
int Catalan(int num, int n, int Cat[]);
int main()
{
    int num,*Cat,n=0,res;
    printf("introduci intero: ");
    scanf("%d",&num);
    Cat=malloc(num*sizeof(int));
    Cat[n]=1;
    n++;
    res=Catalan(num,n,Cat);
    printf("Il numero di Catalan ricercato e' %d", res);
    return 0;
}
int Catalan(int num, int n, int Cat[])
{
    int i,p;
        Cat[n]=0;
        for(i=0;i<n;i++)
            Cat[n]+=Cat[i]* Cat[n-1-i];
            printf("Cat[%d]= %d\n", n, Cat[n]);
        if(n+1<=num)
            Cat[n+1]=Catalan(num,n+1,Cat);
        else
            {p=Cat[n];
            return p;}
}
