#include <stdio.h>
#include <stdlib.h>
#include "ArvoreAVL.h"

int main(){//gcc -std=c99 -Wall main.c ArvoreAVL.c -o Testando
    
    //15 27 49 10 8 67 59 9 13 20 14
    Arvore avl = Create();
    Noh node;

    insereArvAVL(avl,15,1);
    
    insereArvAVL(avl,27,2);
    //ManipulacaoDot(avl,"ins27.dot");

    insereArvAVL(avl,49,3);
    //ManipulacaoDot(avl,"ins49.dot");

    insereArvAVL(avl,10,4);
    //ManipulacaoDot(avl,"ins10.dot");

    insereArvAVL(avl,8,5);
    //ManipulacaoDot(avl,"ins8.dot");

    insereArvAVL(avl,67,6);
    //ManipulacaoDot(avl,"ins67.dot");

    insereArvAVL(avl,59,7);
    //ManipulacaoDot(avl,"ins59.dot");

    insereArvAVL(avl,9,8);
    //ManipulacaoDot(avl,"ins9.dot");

    insereArvAVL(avl,13,9);
    //ManipulacaoDot(avl,"ins13.dot");

    insereArvAVL(avl,20,10);
    //ManipulacaoDot(avl,"ins20.dot");

    insereArvAVL(avl,14,11);
    
    //dot -Tsvg inser.dot -o inseriu.svg
//
    node=GetFirst(avl);
    printf("\nAVL tree:\n");
    emOrdem_ArvAVL(node);
    printf("\n\n");

    ManipulacaoDot(avl,"inicial.dot");

    remove_ArvAVL(avl,27);

    node=GetFirst(avl);
    printf("\nAVL tree:\n");
    emOrdem_ArvAVL(node);
    printf("\n\n");

    remove_ArvAVL(avl,13);

    node=GetFirst(avl);
    printf("\nAVL tree:\n");
    emOrdem_ArvAVL(node);
    printf("\n\n");

    remove_ArvAVL(avl,67);

    node=GetFirst(avl);
    printf("\nAVL tree:\n");
    emOrdem_ArvAVL(node);
    printf("\n\n");

    remove_ArvAVL(avl,10);
    remove_ArvAVL(avl,8);
    remove_ArvAVL(avl,15);
    remove_ArvAVL(avl,49);
    remove_ArvAVL(avl,20);
    remove_ArvAVL(avl,59);
    remove_ArvAVL(avl,9);
    remove_ArvAVL(avl,14);

//
    node=GetFirst(avl);
    printf("\nAVL tree:\n");
    emOrdem_ArvAVL(node);
    printf("\n\n");

    ManipulacaoDot(avl,"inser.dot");

    node=GetFirst(avl);
    Libera(node);
    free(avl);
    printf("\nArvore Liberada!");
    getchar();

    return 0;
}
