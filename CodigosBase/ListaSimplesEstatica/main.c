#include <stdio.h>
#include "ListaEstatica.h"

int main()//Teste da implementacao da lista
{
    //Erro: apos remover um elemento aquela posicao fica inutilizavel!
    int taman,F,valornormal;
    int *valor;
    printf("\nQual o tamanho da lista?\n");
    scanf("%d",&taman);

    ListaEst lista= InicializaLista(taman);
    int x=1;
    for(int i=0; i<10; i++)
    {
        InsereValor(lista,x,(x*2),taman);
        x++;
    }
    
    printf("\nTamanho da lista = %d ",TamanhoEst(lista));
    Imprime(lista);
    //RemoveElemen(lista,2);
    //printf("\nRemoveu!");
    //F=GetPosicaoElemento(lista,6,valor);
    //printf("\nValor = %d",*valor);

    F=GetPosicaoElemento(lista,6,&valornormal);
    printf("\nValorNormal = %d",valornormal);
    printf("\nValor de F= %d",F);
    
    printf("\nFirst: %d",GetFirstEst(lista));
    printf("\nLast: %d",GetLastEst(lista));
    printf("\nAnterior a posicao 5: %d",GetPrevious(lista,5));
    InsereBefore(lista,66,5,taman);
    Imprime(lista);

    printf("\nLast: %d",GetLastEst(lista));
    printf("\nProx do 7: %d",GetNext(lista,7));
    InsereAfter(lista,69,5,taman);
    Imprime(lista);
    //Teste(lista);
    
    LiberaEstatica(lista);
    printf("\nLista Liberada com sucesso!");
    
    return 0;
}