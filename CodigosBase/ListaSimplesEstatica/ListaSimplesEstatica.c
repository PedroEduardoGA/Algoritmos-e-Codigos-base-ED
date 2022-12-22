#include <stdio.h>
#include <stdlib.h>
#include "ListaEstatica.h"

typedef struct node{//Define a estrutra do no, aqui eh armazenado as informacoes
    int valor;
    int valor2;
    int prox;
    /* outros componentes */
}Noh;//Nomeia essa estrutura como Noh

typedef struct list{//Define uma estrutura da lista, armazena um vetor de noh com MaxTam
    Noh *Item;//crio um vetor com nome Item do tipo struct de noh 
    int Taman,Primeiro, Ultimo;
}Estatica;//Nomeia essa estrutura como Estatica

/* Inicializa uma lista */
ListaEst InicializaLista(int Tamanho)
{
    Estatica* lista = (Estatica*)malloc(sizeof(Estatica));//Casting e alloca espaco pra uma variavel lista da struct Estatica
    lista->Item= (Noh*)malloc(Tamanho*sizeof(Noh));

    lista->Primeiro=-1;
    lista->Ultimo=0;
    lista->Taman=0;

    return lista;//Retorna a lista vazia
}

void LiberaEstatica(ListaEst L)
{   
    Estatica* Lista = (Estatica*) L;
    free(Lista->Item);
    free(Lista);
}

int Vazia (ListaEst L)//Verifica se a lista esta vazia
{
    Estatica* Lista = (Estatica*) L;

    if(Lista->Primeiro == Lista->Ultimo)//Compara se o primeiro elemento eh igual ao ultimo
        return 1;//se for volta 1 dizendo que a lista eh vazia
    else
        return 0;//senao volta 0 dizendo q a lista nao eh vazia
}

int GetPosicaoElemento(ListaEst L, int X,int *coordenada)
{
    Estatica* lista = (Estatica*) L;
    int pos;

    pos=lista->Primeiro;
    while((lista->Item[pos].prox != -1)&&(lista->Item[pos].valor != X))
        pos=lista->Item[pos].prox;

    if(lista->Item[pos].valor!=X)
    {
        printf("\nElemento inexistente!");
        return 0;
    }  

    *coordenada= lista->Item[pos].valor2;

    return pos;
}

void Teste(ListaEst L)
{
    Estatica* lista = (Estatica*) L;
    int aux;
    //aux=GetElemento(lista,69);
    printf("\nDentro de teste Posicao %d contem 69!",aux);
}

void InsereBefore(ListaEst L,int elemento,int pos, int Tamanho)//insere elemento antes da posicao
{
    Estatica* lista = (Estatica*) L;
    int x;
    
    if (lista->Taman > Tamanho-1)
    {
        printf ("Lista esta cheia!\n");
        return;
    }
    
    if(pos==0)
    {
        printf("\nPosicao invalida, impossivel inserir em posicoes menores que 0!");
        return;
    }

    x=lista->Primeiro;
    while(lista->Item[x].prox!=pos)
        x=lista->Item[x].prox;//pega elemento anterior ao pos

    lista->Item[x].valor=elemento;
    lista->Item[x].prox=pos;
    lista->Taman++;
}

void InsereAfter(ListaEst L,int elemento,int pos, int Tamanho)//insere elemento antes da posicao
{
    Estatica* lista = (Estatica*) L;
    int x,y;
    
    if (lista->Taman > Tamanho-1)
    {
        printf ("Lista esta cheia!\n");
        return;
    }
    
    if(pos== lista->Taman-1)
    {
        printf("\nPosicao invalida, impossivel inserir em posicoes maiores que o fim da lista!");
        return;
    }

    x=lista->Primeiro;
    while(lista->Item[x].prox!=pos)
        x=lista->Item[x].prox;//pega elemento anterior ao pos

    x=lista->Item[x].prox;//elemento do pos
    x=lista->Item[x].prox;
    y=lista->Item[x].prox;
    lista->Item[x].valor=elemento;
    lista->Item[x].prox=y;
    lista->Taman++;
}

void InsereValor(ListaEst L, int elemento,int elemento2, int Tamanho)
{
    Estatica* lista = (Estatica*) L;

    if (lista->Taman > Tamanho-1)
    {
        printf ("Lista esta cheia!\n");
        return;
    }//Se ultimo elemento da lista for indice maior ou igual ao tamanho qr dizer q a lista ta cheia

    lista->Item[lista->Taman].valor=elemento;
    lista->Item[lista->Taman].valor2=elemento2;

    if(lista->Primeiro == -1)//eh o primeiro elemento da lista
        lista->Primeiro=0;
    else
        lista->Item[lista->Taman-1].prox=lista->Taman;
    
    lista->Item[lista->Taman].prox=-1;
    lista->Ultimo=lista->Taman;
    lista->Taman++;
    
    return;
}

/*Imprime os itens da lista na ordem de ocorrência */
void Imprime (ListaEst L)
{
    Estatica* lista = (Estatica*) L;
    if(Vazia (lista)==1)
    {
        printf("\nLista Vazia!");
        return;
    }
    int x= lista->Primeiro;
    
    printf ("\nLista Estatica: ");
    while( x != 66)//imprime do primeiro elemento ao ultimo da lista //era x!= -1, mas da pau em linux
    {
        printf ("\n[%d] = %d e %d ->Prox= %d", x,lista->Item[x].valor,lista->Item[x].valor2,lista->Item[x].prox);//imprime o valor da posicao x da lista
        x=lista->Item[x].prox;
        if(x == -1)
            break;
        //if(lista->Item[x].prox == -1)
        //  break;
    }
}

int TamanhoEst(ListaEst L)
{
    Estatica* Lista = (Estatica*) L;//Estatica typedef da struct da lista

    return Lista->Taman;
}

void RemoveElemen(ListaEst L,int p)
{
    Estatica* Lista = (Estatica*) L;
    int x;

    if(Lista->Ultimo == Lista->Primeiro)//Só tem um elemento na lista
    {
        Lista->Primeiro=-1;
        Lista->Ultimo=-1;
    }else if(p == Lista->Primeiro)//Se a posicao eh o primeiro noh
        {
            Lista->Primeiro=Lista->Item[p].prox;
        }else if(Lista->Ultimo != p)
            {
                x=Lista->Primeiro;
                while (Lista->Item[x].prox != p)
                    x=Lista->Item[x].prox;
                
                Lista->Item[x].prox=Lista->Item[p].prox;
            }

            else if(Lista->Ultimo == p)//se p eh a ultima posicao
                {
                    x=Lista->Primeiro;
                    while (Lista->Item[x].prox != p)
                        x=Lista->Item[x].prox;
                    
                    Lista->Ultimo=x;
                    Lista->Item[x].prox=-1;
                }

    Lista->Taman--;
}

int GetFirstEst(ListaEst L)
{
    Estatica* Lista = (Estatica*) L;
    return Lista->Primeiro;
}

int GetLastEst(ListaEst L)
{
    Estatica* Lista = (Estatica*) L;
    return Lista->Ultimo;
}

int GetPrevious(ListaEst L, int pos)
{
    Estatica* Lista = (Estatica*) L;
    int x;
    x=Lista->Primeiro;
    if(x==pos)
    {
        return -1;
    }else
        {
            while(Lista->Item[x].prox != pos)
                x=Lista->Item[x].prox;

            return x;
        }
}

int GetNext(ListaEst L, int pos)
{
    Estatica* Lista = (Estatica*) L;
    return Lista->Item[pos].prox;
}