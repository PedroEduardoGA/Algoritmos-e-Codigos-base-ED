#ifndef _LISTADINDUPLAMENTE_H
#define _LISTADINDUPLAMENTE_H

typedef void* No;
typedef void* Lista;

Lista Create();//Cria uma lista vazia, retorna uma lista vazia e Sem requerimentos

void insert(Lista l, int info);//Insere um elemento na lista, necessita de uma lista iniciada, nao retorna nada

void print(Lista l);//Imprimi todos elementos da lista, precisa de uma lista com pelo menos 1 elemento, retorna nada

void liberalist(Lista l);//Libera a memoria da lista, recebe uma lista, libera memoria de seus nohs inteirores e a lista

int Tamanho(Lista l);//Devolve o tamanho da lista, recebe uma lista, percorre os nohs inteirores contabilizando o tamanho da lista

void RemoveElemento(Lista l, int elemento);//Remove o elemento informado da lista, recebe a lista e o elemento, percorre a lista ate achar

void InsereAfter(Lista L, int elemento, int i);
//=>funcao insertAfter(L: Lista<<Item>>, p: Posic, info: Item): Posic
    //-pre condicao: p deve indicar um elemento existente em L.
    //-pos condicao: insere o item info na posicao imediatamente posterior ao
    //item indicado por p. O comprimento da lista  ́e acrescido de 1 elemento.
    //Retorna um indicador para o elemento acrescentado.

void InsereBefore(Lista L, int elemento, int i);
//=>funcao insertBefore(L: Lista<<Item>>, p: Posic, info: Item): Posic
    //-pre condicao: p deve indicar um elemento existente em L.
    //-pos condicao: insere o item info na posicao imediatamente anterior ao
    //item indicado por p. O comprimento da lista  ́e acrescido de 1 elemento.
    //Retorna um indicador para o elemento acrescentado.

No GetLast(Lista L);
//=>funcao  getLast(L: Lista<<Item>>): Posic
    //-pos condicao: retorna o indicador do  ́ultimo elemento de L. Se
    //tamanho=0, retorna NULL.

No GetFirst(Lista L);
//=>funcao getFirst(L: Lista<<Item>>): Posic
    //-pos condicao: retorna o indicador do primeiro elemento de L. Se
    //tamanho=0, retorna NULL.

No GetNext(Lista L,int pos);
//=>funcao getNext(L: Lista<<Item>>, p: Posic): Posic
    //-pre condicao: p deve indicar um elemento existente em L.
    //-pos condicao: retorna o indicador do elemento de L seguinte ao elemento
    //indicado por p. Se p for o  ́ultimo elemento da lista, retorna NULL.

No GetElemento(Lista L, int elemento);
//=>funcao get(L: Lista<<Item>>, ele: elemento): Item 
    //-pre condicao: ele deve indicar um elemento existente em L.
    //-pos condicao: retorna o no que possui elemento como info

No GetPrevious(Lista L, int pos);
//=>funcao  getPrevious(L: Lista<<Item>>, p: Posic): Posic
    //-pre condicao: p deve indicar um elemento existente em L.
    //-pos condicao: retorna o indicador do elemento de L anterior ao elemento
    //indicado por p. Se p for o primeiro elemento da lista, retorna NULL.

void TrocarValor(Lista L,int valor);//temporariio

#endif
