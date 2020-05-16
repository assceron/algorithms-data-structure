#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define cap_val 3.500
#define MAX 21
typedef struct ele
{
    char ogg[MAX];
    float peso;
    int valore;
}elenco;
typedef struct sol
{
    int *v;
}bsol1;
typedef struct bsol
{
    elenco *bsol_res;
    int b_num;
    int *ind;
}bsol2;
bsol1 riempibagalio(int pos, elenco *lista,int *sol,int n,float cap_bag,float curr_cap,int curr_val,int *bv,bsol1 bsol);
bsol2 riempivaligie(int pos,elenco *lista_res, elenco *sol, bsol2 res,int mark[],int k, float curr_cap, float cap, int n_val,int ind[]);

int main(int argc, char *argv[])
{
    FILE *f_in,*f_out1,*f_out2;
    int n,i,j,k,*ind,*sol,*bv,n_res=0,*mark;
    float cap_bag;
    elenco *lista,*lista_res,*sol_res;
    bsol1 bsol;
    bsol2 res;

            /*RIEMPI BAGAGLIO*/

    f_in=fopen(argv[1],"r");
    fscanf(f_in,"%d",&n);
    lista=malloc(n*sizeof(elenco));
    for(i=0;i<n;i++)
        fscanf(f_in,"%s %f %d", lista[i].ogg, &lista[i].peso,&lista[i].valore);
    fclose(f_in);
    for(i=0;i<n;i++)
    {
        printf("%s %.3f %d\n",lista[i].ogg,lista[i].peso,lista[i].valore);
    }
    printf("Introduci peso massimo del bagaglio a mano:");
    scanf("%f",&cap_bag);
    sol=malloc(n*sizeof(int));
    bsol.v=malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
        sol[i]=0;
        bsol.v[i]=0;
    }
    bv=malloc(sizeof(int*));
    *bv=0;
    bsol=riempibagalio(0,lista,sol,n,cap_bag,0,0,bv,bsol);
    f_out1=fopen(argv[2],"w");
    for(i=0;i<n;i++)
    {
        if(bsol.v[i]==1)
            {fprintf(f_out1,"%s\n",lista[i].ogg);
            }
        else
            n_res++;
    }
    fclose(f_out1);
            /*RIEMPI VALIGIE*/

    lista_res=malloc(n_res*sizeof(elenco));
    j=0;
     for(i=0;i<n;i++)
    {
        if(bsol.v[i]==0)
        {
            strcpy(lista_res[j].ogg,lista[i].ogg);
            lista_res[j].peso=lista[i].peso;
            j++;
        }
    }
    sol_res=malloc(n_res*sizeof(elenco));
    res.bsol_res=malloc(n_res*sizeof(elenco));
    mark=malloc(n_res*sizeof(int));
    res.ind=malloc(n_res*sizeof(int));
    ind=malloc(n_res*sizeof(int));
    ind[0]=0;
    res.b_num=n_res;
  for(j=0;j<n_res;j++)
        { mark[j]=0;}
    res=riempivaligie(0,lista_res,sol_res,res,mark,n_res,0,cap_val,1,ind);
    printf("\nNumero valigie minime %d\n",res.b_num);
    f_out2=fopen(argv[3],"w");
    k=0;
    for(j=0;j<n_res;j++)
    {
        if(j==res.ind[k])
        {
           fprintf(f_out2,"\nVALIGIA %d:\n",k+1);
            fprintf(f_out2,"%s\n",res.bsol_res[j].ogg);
            k++;
        }
         else
            fprintf(f_out2,"%s\n",res.bsol_res[j].ogg);
    }

    fclose(f_out2);
    return 0;
}
bsol1 riempibagalio(int pos, elenco *lista,int sol[],int n,float cap_bag,float curr_cap,int curr_val,int *bv,bsol1 bsol)
{
    int j;
    if(pos>=n)
    {
        if(curr_val>*bv)
        {
            for(j=0;j<n;j++)
                bsol.v[j]=sol[j];
                *bv=curr_val;
        }
        return bsol;
    }
    if((curr_cap + lista[pos].peso)>cap_bag)
    {
        sol[pos]=0;
        bsol=riempibagalio(pos+1,lista,sol,n,cap_bag,curr_cap,curr_val,bv,bsol);
        return bsol;
    }
    sol[pos]=1;
    curr_cap+=lista[pos].peso;
    curr_val+=lista[pos].valore;
    bsol=riempibagalio(pos+1,lista,sol,n,cap_bag,curr_cap,curr_val,bv,bsol);

    sol[pos]=0;
    curr_cap-=lista[pos].peso;
    curr_val-=lista[pos].valore;
    bsol=riempibagalio(pos+1,lista,sol,n,cap_bag,curr_cap,curr_val,bv,bsol);
    return bsol;

};
bsol2 riempivaligie(int pos,elenco *lista_res, elenco *sol, bsol2 res,int mark[],int k, float curr_cap, float cap, int n_val,int ind[])
{
    int j;
    if(pos>=k)
    {
        for(j=0;j<k;j++)
        {
            if((curr_cap+sol[j].peso)>cap)
            {
                n_val++;
                ind[n_val-1]=j;
                curr_cap=sol[j].peso;
            }
            else
                curr_cap+=sol[j].peso;
        }
        if(n_val<res.b_num)
        {
            for(j=0;j<k;j++)
                {strcpy(res.bsol_res[j].ogg,sol[j].ogg);
                 res.bsol_res[j].peso=sol[j].peso;
                 res.ind[j]=ind[j];}
            res.b_num=n_val;
            n_val=1;
        }
        return res;
    }
    for(j=0;j<k;j++)
    {
        if(mark[j]==0){
                mark[j]=1;
            strcpy(sol[pos].ogg,lista_res[j].ogg);
            sol[pos].peso=lista_res[j].peso;
            res=riempivaligie(pos+1,lista_res,sol,res,mark,k,curr_cap,cap,n_val,ind);
            mark[j]=0;}
    }
    return res;
};
