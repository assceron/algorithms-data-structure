#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int comb(int pos, int val[],int sol[],int n, int max,int count)
{
    int i,num=0;
    if(pos>=n)
    {
        for(i=0;i<n;i++)
                num=num+(sol[i]*(pow(10,(n-i-1))));
        if(num%7==0){
        printf("%d\n",num);
        return count +1;}
        else
            return count;
    }
    for(i=0;i<max;i++)
    {
        sol[pos]=val[i];
        count=comb(pos+1,val, sol, n, max,count);
    }
    return count;
};
int main()
{
    int num, *val,*sol, count=0,n=3,max=4;
    val=malloc(max*sizeof(int));
    sol=malloc(n*sizeof(int));
    printf("\nInserisci 4 cifre:");
    scanf("%d %d %d %d", &val[0], &val[1], &val[2],&val[3]);
    num=comb(0,val,sol,n,max,count);
    printf("\nCi sono %d combinazioni ", num);
    return 0;
}
