#ifndef _ARVOREAVL_H
#define _ARVOREAVL_H
#include <stdbool.h>
typedef void* Arvore;
typedef void* Noh;

Arvore Create();

void Libera(Noh nod);
int altura_NO(Noh nod);
int fatorBalanceamento_NO(Noh nod);

void RotacaoLL(Arvore t,Noh nod);
void RotacaoRR(Arvore t,Noh nod);
void RotacaoLR(Arvore t,Noh nod);
void RotacaoRL(Arvore t,Noh nod);

Noh procuraMenor(Noh nod);
Noh GetNode(Arvore arv,int valor);
Noh GetFirst(Arvore arv);
int insereArvAVL(Arvore t,int x,int y);
bool remove_ArvAVL(Arvore t, int valor);

void emOrdem_ArvAVL(Noh nod);
void ManipulacaoDot(Arvore t,char arquivo[]);
void EscritaDot(Noh nod,FILE* arq);

#endif
