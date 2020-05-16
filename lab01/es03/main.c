#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 31
int main()
{
    char str[N],str2[N],str3[N];
    int p,i,j,t,m,k;
    int n,l1,l2,flag,band;

    printf("Stringa? ");
    gets(str);
    for (j=0;j<N;j++)
    str2[j]='\0';
    for (t=0;t<N;t++)
    str3[t]='\0';
    while(strcmp(str,"stop")!=0)
    {
        /* cerco la stringa(str2) che si ripete*/
        l1=strlen(str);
        str2[0]=str[0];
        flag=1;
    for(i=1;(i<l1 )&& (flag==1);i++){

            l2= strlen(str2);
            for(m=i;m<i+l2;m++)
            {
                str3[m-l2]=str[m];
            }
            if(strcmp(str2,str3)==0)
                flag=0;
            else
            {
                str2[i]=str[i];
                flag=1;
                for(m=i;m<i+l2;m++)
                str3[m-l2]='\0';
            }}
           l2=strlen(str2);
            if(l1%l2!=0 || flag==1)/* mi chiedo se str2 si ripete sempre tutta o se non c'è una str2 che si ripete*/
                printf("La stringa %s non e' periodica.\n",str);
            else{
                    n=l1/l2;
                    band=0;
            for(p=1;p<n && band==0;p++){
                for(k=0;k<l2 && band==0;k++){
                    if(str2[k]==str[k+(l2*p)])
                        band=0;
                    else band=1;

                }}
                if(band==0)/* str2 si ripete correttamente */
            printf("La stringa %s e' periodica,(periodo %d).\n",str,l2);
        else /* str2 non si ripete correttamente*/
             printf("La stringa %s non e' periodica.\n",str);
            }


        printf("Stringa? ");
        gets(str);
        for (j=0;j<N;j++)
        str2[j]='\0';
        for (t=0;t<N;t++)
        str3[t]='\0';
    }
    printf("Processo terminato.");
 return 0;
}
