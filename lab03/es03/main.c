#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int ricercadicot(char *vett[],int a, int b, char *str);
#define max_r 100
#define max_c 25
int main()
{
    int comando,l_str,i,l,flag, r=0,j,pos,k;
    char str[max_c], *vett[max_r];

    while(comando!=0){

    for(k=0;k<r;k++)
    {
        printf("\n");
        printf("%s\n",vett[k]);
    }
     printf("\nIntroduci 0 per terminare ");
     printf("\nInserisci 1 per introdurre una nuova stringa");
     printf("\nInserisci 2 per eliminare una stringa ");
     printf("\nInserisci 3 per ricercare una stringa");
     printf("\nComando:");
     scanf("%d",& comando);

     if(comando >3 || isalnum(comando)!=0)
            {
                printf("\nComando errato. ");
                break;
            }

    switch(comando){

        case 1:
            printf("\nInserisci stringa:");
            scanf("%s",str);
            l_str=strlen(str);
            flag=1;
            for(i=0;i<r && flag==1;i++)
            {
                l=strlen(vett[i]);
                if(strcmp(vett[i],str)>0)
                {
                    flag=0;
                    for(j=r;j>i;j--)
                    {
                        vett[j]=malloc((strlen(vett[j-1])*sizeof(char)));
                        strcpy(vett[j],vett[j-1]);
                    }
                    vett[i]=malloc(l_str*sizeof(char));
                    strcpy(vett[i],str);
                }
            }
            if(flag==1)
            {
                vett[r]=malloc(l_str*sizeof(char));
                strcpy(vett[r],str);
            }
            r++;
            break;

        case 2:
            printf("\nIntrodurre stringa da eliminare:");
            scanf("%s", str);
            flag=0;
            for(i=0;i<r && flag==0;i++)
            {
                if(strcmp(vett[i],str)==0)
                {
                    vett[i]='\0';
                    for(j=i+1;j<r;j++)
                    {
                        l=strlen(vett[j]);
                        vett[j-1]=malloc(l*sizeof(char));
                        strcpy(vett[j-1],vett[j]);
                    }
                    r--;
                    flag=1;
                }
            }

                if(flag==0)
                    printf("\n Stringa non trovata!");
                break;
            case 3:
            printf("\nIntrodurre stringa da ricercare:");
            scanf("%s", str);
             pos=ricercadicot(vett,0,r,str);
            if(pos>=0)
            printf("\n Stringa '%s' e' nella riga %d", str, pos+1);
            else
                printf("\nStringa non presente.");
                break;
        case 0:
            printf("\nProcesso terminato. Arrivederci!");
            return 0;



    }
    }
    return 0;
}
int ricercadicot(char *vett[],int a, int b, char *str)
{
    int c;
        c=(a+b)/2;
    if(strcmp(vett[c],str)==0)
        return c;
        if(strcmp(vett[c],str)>0)
                return(ricercadicot(vett,0,c,str));
            else
                return(ricercadicot(vett,c+1,b,str));
}
