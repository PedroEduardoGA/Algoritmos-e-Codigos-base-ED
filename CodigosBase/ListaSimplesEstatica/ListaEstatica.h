#ifndef _LISTAESTATICA_H
#define _LISTAESTATICA_H

typedef void* TipoItem;//Cast

typedef void* ListaEst;//Cast

ListaEst InicializaLista(int Tamanho);
void LiberaEstatica(ListaEst L);
int Vazia (ListaEst L);
void InsereValor(ListaEst L, int elemento,int elemento2,int Tamanho);
void Imprime (ListaEst L);
int TamanhoEst(ListaEst L);
void RemoveElemen(ListaEst L,int p);
void InsereBefore(ListaEst L,int elemento,int pos, int Tamanho);
void InsereAfter(ListaEst L,int elemento,int pos, int Tamanho);
//=============================//
int GetPosicaoElemento(ListaEst L, int X, int* coordenada);
int GetPrevious(ListaEst L, int pos);
int GetLastEst(ListaEst L);
int GetFirstEst(ListaEst L);
int GetNext(ListaEst L, int pos);
void Teste(ListaEst L);

#endif
