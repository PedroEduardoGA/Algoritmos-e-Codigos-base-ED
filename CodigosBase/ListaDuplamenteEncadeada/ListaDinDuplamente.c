#include <stdio.h>
#include <stdlib.h>
#include "ListaDinDuplamente.h"

typedef struct N{ //Onde guarda infos como, cor borda, preenchimento...
    int info;
    struct N *ant;
    struct N *prox;
}no;

typedef struct L{
    no *primeiro; //primeiro elemento da list
    no *ultimo;   //ultimo elemento da list]
    int size;
}list;

Lista Create()//Aloca uma list
{
    list* lista = (list*) malloc(sizeof(list));//alloca, cria variavel e faz cast de list* lista
    //lista do tipo [primeiro][ultimo] 

    lista->primeiro= NULL;
    lista->ultimo= NULL;
    lista->size=0;

    return lista;//retorna uma lista sem no interno
}

void insert(Lista l, int info)//info é o que passa pra inserir na lista e l eh uma lista!
{
    no* node = (no*) malloc(sizeof(no));//faz cast de node com no e eh alocado struct do tipo no
    //node contem a struct de no que tem [*ant][informacao][*prox] 

    node->info= info;//armazena a informacao no nó

    list* lista = (list*) l;//cast de list com l, cria variavel lista do tipo [primeiro][ultimo]

    if(lista->primeiro==NULL)//Verifica se ja existe um no da lista, se for null vai ser criado o primeiro no
    {
        node->ant=NULL;//o campo [ant] do primeiro no recebe NULL pois eh o primeiro no da lista
        
        lista->primeiro=node;
        //lista eh do tipo [primeiro][ultimo] que apontam para o primeiro no e o ultimo no da lista
        
    }else//se ja existe um no
        {
            lista->ultimo->prox= node;//vai armazenar no campo [prox] do ultimo no o endereco para o no atual
            node->ant =lista->ultimo;//vai armazenar no campo[ant]do no atual o endereco para o no anterior
        }

    node->prox=NULL;//vai armazenar no campo [proximo]do no atual o NULL
    lista->size++;
    lista->ultimo=node;//o [ultimo] de lista recebe o endereco do no atual criado
}

void print(Lista l)//Os comentario que estao com $ eh caso queira imprimir de tras pra frente
{
    list* lista = (list*) l;//Cast da variavel lista com list*

    if(lista->primeiro == NULL)
        printf("\nLista Esta Vazia!");
    

    no* node= lista->primeiro;//struct node recebe endereco para o primeiro no da lista
    //$ lista->ultimo

    int i=0;
    while(node!=NULL)//$ node->ant //enquanto nao chega no ultimo no vai imprimindo
    {
        printf("\nno %d -> %d ",i,node->info);//i serve como um indice, node->info imprimi info do no atual
        node= node->prox;//percorre todos os nos da lista
        //$ node->ant
        
        i++;
    }
}

void liberalist(Lista l)
{
    list *lista = (list *) l;//faz cast de l com a struct de list
    no *node = lista->primeiro;//criado um node do tipo no, que aponta pro primeiro elemento da lista
    no *aux;//criado um aux do tipo no

    while(node != NULL)
    {
        aux = node;//atribui a aux o valor de node atual
        node = node->prox;// atribui a node o proximo noh
        //free(aux->ant);//limpa o noh anterior
        free(aux);//free no noh atual de aux
    }
    free(node);
    free(lista);//libera a malloc da lista
}

int Tamanho(Lista l)
{
    list *lista = (list *) l;//faz cast de l com a struct de list e nomeia l de lista
    
    if(lista->primeiro == NULL)
    {
        printf("\nLista Vazia!");
        return 0;
    }

    return lista->size;
}

void RemoveElemento(Lista l, int elemento)
{
    list *lista = (list *) l;//faz cast de l com a struct de list e nomeia l de lista
    no *node = lista->primeiro;//criado um node do tipo no, que aponta pro primeiro elemento da lista
    no *aux;

    while((node->info != elemento)&&(node!=NULL))//Quando encontrar o elemento vai parar no noh em que o elemento se encontra
    {
        if(node->ant!=NULL)
            aux=node;//aux recebe noh anterior

        node = node->prox;// atribui a node o proximo noh
    }

    if(lista->primeiro == node)//elemento eh o primeiro da lista
    {
        //eh o primeiro noh da lista tratamento diferente
        if(node->prox == NULL)//indica que esse eh o unico noh da lista
        {
            lista->primeiro=NULL;
            lista->ultimo=NULL;
            printf("\nElemento: %d era o unico da lista e foi removido com sucesso!",elemento);
            free(node);
            lista->size--;
            return;
        }

        aux=node->prox;//aux eh o segundo elemento da lista
        aux->ant=NULL;
        lista->primeiro=aux;//Primeiro elemento da lista vai apontar para o proximo
        printf("\nElemento: %d era o primeiro da lista e foi removido com sucesso!",elemento);
        free(node);
        lista->size--;
        return;
    }

    if(lista->ultimo == node)//elemento eh o ultimo da lista
    {
        //eh o primeiro noh da lista tratamento diferente
        aux=node->ant;//aux eh o noh anterior
        aux->prox=NULL;
        lista->ultimo=aux;//Ultimo elemento da lista vai apontar para o anterior
        printf("\nElemento: %d era o ultimo da lista e foi removido com sucesso!",elemento);
        free(node);
        lista->size--;
        return;
    }

    if(node->info == elemento)
    {
        aux->prox=node->prox;//Campo proximo do noh anterior vai receber o proximo noh do atual
        node->prox->ant=aux;//Campo anterior do proximo noh vai receber o noh aux
        free(node);
        printf("\nElemento: %d removido com sucesso!",elemento);
        lista->size--;
        return;
    }

    printf("\nElemento inexistente!");
    return;
}

void InsereAfter(Lista L, int elemento, int i)
{
    list *lista = (list *) L;//faz cast de l com a struct de list e nomeia l de lista
    no *node=lista->primeiro;
    int x=0;

    if((i>=lista->size)||(i<0))
    {
        printf("\nPosicao inexistente!");
        return;
    }

    while (x<i)
    {
        node=node->prox;
        x++;
    }

    no* aux= (no*) malloc(sizeof(no));
    aux->info=elemento;//aux eh o novo q sera inserido

    aux->prox=node->prox;//prox de aux recebe o endereco do proximo do noh
    node->prox=aux;
    aux->ant=node;

    if(i==(lista->size - 1))//se i for a ultima posicao da lista
        lista->ultimo=aux;

    lista->size++;
}

void InsereBefore(Lista L, int elemento, int i)
{
    list *lista = (list *) L;//faz cast de l com a struct de list e nomeia l de lista
    no *node=lista->primeiro;
    int x=0;

    if((i>=lista->size)||(i<0))
    {
        printf("\nPosicao inexistente!");
        return;
    }

    while (x<i)
    {
        node=node->prox;
        x++;
    }

    if(node==lista->primeiro)//caso queira inserir antes do primeiro elemento
    {
        no* aux= (no*) malloc(sizeof(no));
        aux->info=elemento;//aux eh o novo q sera inserido

        aux->ant=node->ant;
        node->ant=aux;
        aux->prox=node;
        lista->size++;
        lista->primeiro=aux;
        
        return;
    }

    if(node==lista->ultimo)//caso queira inserir antes do primeiro elemento
    {
        no* aux= (no*) malloc(sizeof(no));
        aux->info=elemento;//aux eh o novo q sera inserido

        aux->prox=node;//prox de aux recebe o endereco do noh atual
        aux->ant=node->ant;
        node->ant->prox=aux;
        node->ant=aux;
        lista->size++;
        
        return;
    }    

    no* aux= (no*) malloc(sizeof(no));
    aux->info=elemento;//aux eh o novo q sera inserido

    printf("==\nAux= %d, node= %d, nodeAnt= %d e nodePro= %d",aux->info,node->info,node->ant->info,node->prox->info);
    aux->prox=node;//prox de aux recebe o endereco do noh atual
    aux->ant=node->ant;
    node->ant->prox=aux;
    node->ant=aux;
    
    lista->size++;
}

No GetLast(Lista L)
{
    list *lista = (list *) L;

    if(lista->size==0)
        return NULL;

    return lista->ultimo;
}

No GetFirst(Lista L)
{
    list *lista = (list *) L;

    if(lista->size==0)
        return NULL;

    return lista->primeiro;
}

No GetNext(Lista L,int pos)
{
    list *lista = (list *) L;
    no* node= lista->primeiro;

    int x=0;
    if(lista->size==0)
        return NULL;

    while((x<pos)&&(node!=NULL))
    {
        node=node->prox;
        x++;
    }

    return node->prox;
}

No GetPrevious(Lista L, int pos)
{
    list *lista = (list *) L;
    no* node= lista->primeiro;

    if(node==NULL)//lista vazia
        return NULL;

    int x=0;
    while((x<pos)&&(node!=NULL))
    {
        node=node->prox;
        x++;
    }
    return node->ant;
}

No GetElemento(Lista L, int elemento)
{
    list *lista = (list *) L;
    no* node= lista->primeiro;

    if(node==NULL)//lista vazia
        return NULL;

    while((node->info!=elemento)&&(node!=NULL))
        node=node->prox;


    return node;
}

void TrocarValor(Lista L,int valor)
{
    list *lista = (list *) L;
    no* aux= (no*) malloc(sizeof(no));

    aux=GetElemento(lista,14);
    if(aux==NULL)
        return;

    aux->info=valor;
    //aux=aux->prox;
}

