#include <stdio.h>
#include <stdlib.h>
#define Max 100
void converti(int n_dieci, int base, int n[], int i);
int main()
{
    int n_dieci, base,n[Max],i=0;
    printf("Introduci numero in base 10 da convertire : ");
    scanf("%d", &n_dieci);
    printf("Introduci base in cui convertire: ");
    scanf("%d",&base);
    converti(n_dieci,base,n,i);

    return 0;
}
void converti(int n_dieci, int base,int n[],int i)
{
    int j=0,d;
    i++;

    if(n_dieci!=0)
    {
        d=n_dieci/base;
        n[i]=n_dieci%base;
        converti(d,base,n,i);
    }
    else
    {
        for(j=i-1;j>0;j--)
            printf("%d", n[j]);
    }
    free(n);
    return;
}
