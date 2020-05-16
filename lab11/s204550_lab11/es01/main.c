#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "bst.h"
int main()
{
    int comando;
    BST bst;
    Item x;
    printf("Introduci 1 per creare BST\n");
    scanf("%d", &comando);
    while(comando!=0)
    {
        switch(comando)
        {
            case 1:
                bst=creabst();
                break;
            case 2:
                x=salva_it();
                ins_foglia(bst,x);
                break;
            case 3:
                x=salva_it();
                ins_radice(bst,x);
                break;
            case 4:
                cerca_elem(bst);
                break;
            case 5:
                min_elem(bst);
                break;
            case 6:
                max_elem(bst);
                break;
            case 7:
                pre_ordine(bst);
                break;
            case 8:
                in_ordine(bst);
                break;
            case 9:
                post_ordine(bst);
                break;
            case 10:
                altezza(bst);
                break;
            case 11:
                nodi_albero(bst);
                break;
            case 12:
                nodi_foglie(bst);
                break;
            case 13:
                salva_suf_in_ordine(bst);
                break;
            case 14:
                carica_daf(bst);
                break;
        }
    printf("\nIntroduci 0 per terminare\n");
    printf("Introduci 1 per creare BST\n");
    printf("Introduci 2 per inserire in foglia\n");
    printf("Introduci 3 per inserire in radice\n");
    printf("Introduci 4 per ricerca\n");
    printf("Introduci 5 per minimo\n");
    printf("Introduci 6 per massimo\n");
    printf("Introduci 7 per stampa pre-ordine\n");
    printf("Introduci 8 per stampa in-ordine\n");
    printf("Introduci 9 per stampa post-ordine\n");
    printf("Introduci 10 per calcolo altezza\n");
    printf("Introduci 11 per calcolo nodi\n");
    printf("Introduci 12 per calcolo foglie\n");
    printf("Introduci 13 per salvare BST su file\n");
    printf("Introduci 14 per caricare BST da file\n");
    scanf("%d", &comando);
    }
    printf("\nProcesso terminato!");
    return 0;
}
