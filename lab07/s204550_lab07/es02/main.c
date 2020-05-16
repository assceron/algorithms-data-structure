#include <stdio.h>
#include <stdlib.h>
int vocale(char car)
{
    if(car=='a'|| car=='e'||car=='i'||car=='o'||car=='u')
        return 1;
    else return 2;
};
int comb(int pos, int n, int max,char val[], char sol[],int count,FILE *ff)
{
    int i;
    if(pos>=n)
    {
        sol[pos]='\0';
        if(vocale(sol[0])!=1 && vocale(sol[1])==1 && vocale(sol[2])!=1 && vocale(sol[3])==1)
        {
            fprintf(ff,"%s\n",sol);
            return count+1;
        }
        else
            return count;
    }
    for(i=0;i<max;i++)
    {
        sol[pos]=val[i];
        count=comb(pos+1,n,max,val,sol,count,ff);
    }
    return count;
};
int main(int argc, char *argv[])
{
    FILE *fo;
    int i,n=4,count=0,num,max=21;
    char *sol,*val;
    sol=malloc(n*sizeof(char));
    val=malloc(max*sizeof(char));
    val[0]='a';
    for(i=1;i<=max;i++)
        val[i]=val[i-1]+1;
    fo=fopen(argv[1],"w");
    num=comb(0,n,max,val,sol,count,fo);
    printf("\nNumero combinazioni: %d", num);
    fclose(fo);
    return 0;
}
