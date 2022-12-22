#include <stdio.h>
#include <stdlib.h>
#include "ListaDinDuplamente.h"

void main()
{

    Lista lista= Create();

    for(int i=0; i<=25; i++)
        insert(lista,i);

    
    printf("\nTamanho da lista = %d ",Tamanho(lista));
    print(lista);

    RemoveElemento(lista,0);
    
    printf("\nTamanho da lista = %d ",Tamanho(lista));
    print(lista);

    printf("\nInserindo depois!");
    InsereAfter(lista,69,24);
    print(lista);
    
    printf("\nTamanho da lista = %d ",Tamanho(lista));
    printf("\nInserindo antes!");
    InsereBefore(lista,55,25);
    print(lista);

    printf("\nTamanho da lista = %d ",Tamanho(lista));
    TrocarValor(lista,100);
    print(lista);

    liberalist(lista);
    printf("\nLista Liberada com sucesso!");  
}