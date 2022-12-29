#include <stdio.h>
#include <stdbool.h>
#include"HashT.h"

int main()
{
    //gcc -std=c99 -Wall main.c Hash.c -o TestHash
    HashTable tabela1= criaTabela(11);
    insereRegistro(tabela1,"86010","120222",10,8);
    insereRegistro(tabela1,"86012","120333",12,4);
    insereRegistro(tabela1,"86013","120444",14,6);
    insereRegistro(tabela1,"86015","120555",13,9);
    insereRegistro(tabela1,"86017","120666",1,2);

    insereRegistro(tabela1,"84543","222",10,8);
    insereRegistro(tabela1,"84331","333",12,4);
    insereRegistro(tabela1,"85234","444",14,6);
    insereRegistro(tabela1,"87621","555",13,9);
    insereRegistro(tabela1,"86979","666",1,2);
    insereRegistro(tabela1,"89979","699",8,3);
    insereRegistro(tabela1,"89972","777",1,2);
    removeChave(tabela1,"86010");

    ImprimeRegistro(tabela1,"86010");
    printf("\n");
    ImprimeRegistro(tabela1,"8607");
    printf("\n");
    ImprimeRegistro(tabela1,"86012");
    printf("\n");
    ImprimeRegistro(tabela1,"86013");
    printf("\n");

    removeChave(tabela1,"86015");
    ImprimeRegistro(tabela1,"86015");
    printf("\n");
    ImprimeRegistro(tabela1,"86017");
    printf("\n");
    ImprimeRegistro(tabela1,"84543");
    printf("\n");
    ImprimeRegistro(tabela1,"87621");
    printf("\n");
    ImprimeRegistro(tabela1,"84331");

    LiberaHashtable(tabela1);
    printf("\nTabela liberada e programa finalizado!");

    getchar();
    return 0;
}