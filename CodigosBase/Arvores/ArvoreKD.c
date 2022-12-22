#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void* Arvore;
typedef void* Noh;

typedef struct N{ //Onde guarda infos como, cor borda, preenchimento...
    int x,y,morte;
    char id[10];

    struct N *Pai;
    struct N *Filho_esq;
    struct N *Filho_dir;
}no;

typedef struct T{
    no *Raiz; //primeiro elemento da list
}tree;

Arvore Create()//Aloca uma list
{
    tree* arvore = (tree*) malloc(sizeof(tree));//alloca, cria variavel e faz cast de list* lista
    arvore->Raiz=NULL;

    return arvore;//retorna uma lista sem no interno
}

void Insere(Arvore t,int x, int y,char id[10],int morte)
{
    no* node = (no*) malloc(sizeof(no));
    tree* arvore = (tree*) t;
    int inserido=0,i=0;
    no* aux;

    if(arvore->Raiz == NULL)//eh inserido a raiz
    {
        node->x=x;
        node->y=y;
        node->morte=morte;
        strcpy(node->id,id);
        node->Pai=NULL;
        node->Filho_dir=NULL;
        node->Filho_esq=NULL;
        arvore->Raiz=node;
        printf("\nInserida a Raiz!");
        return;
    }else
        aux=arvore->Raiz;

    node->x=x;
    node->y=y;
    node->morte=morte;
    strcpy(node->id,id);
    node->Filho_dir=NULL;
    node->Filho_esq=NULL;
    while ((aux!=NULL)&&(inserido!=1))
    {
        if(((i % 2)==0)||(i==0))
        {
            if(x < aux->x)//vai pra esquerda por ser menor
            {
                if(aux->Filho_esq==NULL)
                {
                    aux->Filho_esq=node;
                    node->Pai=aux;
                    inserido=1;
                    break;
                }else
                    aux=aux->Filho_esq;
            }else
                {
                    if(aux->Filho_dir==NULL)
                    {
                        aux->Filho_dir=node;
                        node->Pai=aux;
                        inserido=1;
                        break;
                    }else
                        aux=aux->Filho_dir;
                }
        }else   
            {
                if(y < aux->y)//vai pra esquerda por ser menor
                {
                    if(aux->Filho_esq==NULL)
                    {
                        aux->Filho_esq=node;
                        node->Pai=aux;
                        inserido=1;
                        break;
                    }else
                        aux=aux->Filho_esq;
                }else//vai pra direita por ser maior
                    {
                        if(aux->Filho_dir==NULL)
                        {
                            aux->Filho_dir=node;
                            node->Pai=aux;
                            inserido=1;
                            break;
                        }else
                            aux=aux->Filho_dir;
                }  
            }
        i++;
    }
}

void Imprime(Noh nod)
{
    no* node = (no*) nod;
    //printf("O/\n");
    
    if(node!=NULL)
    {
         
        
        if(node->morte != 2)
            printf("[%s] %d & %d -",node->id,node->x,node->y);
        
        if(node->Filho_esq!=NULL)
            Imprime(node->Filho_esq);
        
        if(node->Filho_dir!=NULL)
            Imprime(node->Filho_dir);
          
    }   
}

void Libera(Noh nod)
{
    no* node = (no*) nod;
    if(node!=NULL)
    {
        Libera(node->Filho_dir);
        Libera(node->Filho_esq);
        free(node);
    }
}

Noh GetFirst(Arvore arv)
{
    tree* arvore = (tree*) arv;
    return arvore->Raiz;
}

Noh GetNode(Arvore arv,int x, int y)//provisoria
{
    tree* arvore = (tree*) arv;
    no* aux;
    int i=0;
    aux=arvore->Raiz;

    if(aux==NULL)
        return NULL;

    while ((aux!=NULL)&&(aux->x!=x)&&(aux->y!=y))
    {
        if((i % 2)==0)
        {
            if(x < aux->x)
                aux=aux->Filho_esq;
            else
                aux=aux->Filho_dir;  
        }else
            {
                if(y < aux->y)
                    aux=aux->Filho_esq;
                else
                    aux=aux->Filho_dir;
            }
        i++;
    }
    if((aux->x==x)&&(aux->y==y))
        return aux;
    else 
        return NULL;
}

Noh GetNodeKD(Arvore arv,int x,int y)//Pega o noh com x e y
{
    tree* arvore = (tree*) arv;
    no* aux;
    int i=0;
    aux=arvore->Raiz;

    if(aux==NULL)
    {
        printf("\nArvore Vazia!");
        return NULL;
    }
        
    while ((aux!=NULL)&&(aux->x!=x)&&(aux->y!=y))
    {
        if((i % 2)==0)
        {
            if(x < aux->x)
            {
                aux=aux->Filho_esq;
                printf("\nX menor, fui pra esquerda!");
            }else
                {
                    aux=aux->Filho_dir;
                    printf("\nX maior, fui direita!");
                }    
        }else
            {
                if(y < aux->y)
                {
                    aux=aux->Filho_esq;
                    printf("\nY menor, fui pra esquerda!");
                }else
                    {
                        aux=aux->Filho_dir;
                        printf("\nY maior, fui pra direita!");
                    }   
            }
        i++;
    }
    if(aux==NULL)
        return NULL;
    
    if((aux->x==x)&&(aux->y==y))
        return aux;
    else 
        return NULL;
}

void GetNodeID(Noh nod,char id[10],int *x,int *y)
{
    no* node = (no*) nod;

    if(node!=NULL)
    {
        
        GetNodeID(node->Filho_esq,id,x,y);
        if(strcmp(node->id,id)==0)
        {
            *x=node->x;
            *y=node->y;
        }
        GetNodeID(node->Filho_dir,id,x,y);
    }
    
}

void RemoveNohKd(Arvore arv,Noh nod)
{
    tree* arvore = (tree*) arv;
    no* node = (no*) nod;
    no* aux1;
    no* aux2;

    if(node==NULL)
    {
        printf("\nElemento inexistente na arvore!");
        return;
    }

    aux1=arvore->Raiz;
    if((node->Filho_esq == NULL)&&(node->Filho_dir == NULL))
    {
        if(node==arvore->Raiz)//se o noh eh a raiz
            arvore->Raiz=NULL;
        else//Se o noh for uma folha
            {
                aux2=node->Pai;
                if(aux2->Filho_dir == node)
                    aux2->Filho_dir=NULL;
                else
                    aux2->Filho_esq=NULL; 
            }
            
        printf("\n x:%d y:%d Nao tinha filhos e Foi removido com sucesso!",node->x,node->y);
        free(node);
        return;
    }

    if((node->Filho_esq == NULL)||(node->Filho_dir == NULL))//o noh possui so um filho
    {
        if(node==arvore->Raiz)//elemento que sera removido eh a raiz da arvore
        {
            if(node->Filho_esq==NULL)
            {
                aux1=node->Filho_dir;
                aux1->Pai=NULL;
                arvore->Raiz=aux1;
            }else
                {
                    aux1=node->Filho_esq;
                    aux1->Pai=NULL;
                    arvore->Raiz=aux1;
                }

            printf("\n x:%d y:%dTinha 1 filho e Foi removido com sucesso!",node->x,node->y);
            free(node);
            return;
        }
        aux1=node->Pai;
        if(node->Filho_esq == NULL)
            aux2= node->Filho_dir;
        else
            aux2= node->Filho_esq;

        if(aux1->Filho_dir==node)
            aux1->Filho_dir=aux2;
        else
            aux1->Filho_esq=aux2;

        aux2->Pai=aux1;
        
        printf("\n x:%d y:%d Foi removido com sucesso!",node->x,node->y);
        free(node);
        return;
    }

    if((node->Filho_esq != NULL)&&(node->Filho_dir != NULL))
    {
        node->morte=2;
        printf("\n x:%d y:%d Foi alterado com sucesso!",node->x,node->y);
        return;
    }
}

void RemoveKD(Arvore arv,Noh nod)
{
    tree* arvore = (tree*) arv;
    no* node = (no*) nod;
    no* aux;

    if(node!=NULL)
    {
        RemoveKD(arvore,node->Filho_esq);
        
        aux=node;
        if(node->morte==1)
            RemoveNohKd(arvore,node);
        
        RemoveKD(arvore,node->Filho_dir);
    }
    
}

int main()
{
    Arvore arv= Create();
    Noh node,aux;
    int X=0,Y=0,v1,v2=0;

    Insere(arv,15,7,"rect1",1);
    Insere(arv,19,8,"rect2",0);
    Insere(arv,24,7,"rect3",0);
    Insere(arv,31,12,"rect4",0);
    Insere(arv,5,6,"rect66",0);
    Insere(arv,10,3,"rect69",1);
    Insere(arv,3,11,"rect5",0);
    Insere(arv,1,9,"rect6",1);
    Insere(arv,51,9,"rect7",0);

    node=GetFirst(arv);
    printf("\nArvore:\n");
    Imprime(node);

    node=GetFirst(arv);
    printf("\nProcurando pelo id!");
    GetNodeID(node,"rect1",&X,&Y);
    node=GetNodeKD(arv,X,Y);
    RemoveNohKd(arv,node);

    node=GetFirst(arv);
    RemoveKD(arv,node);
    
    node=GetFirst(arv);
    printf("\nArvore:\n");
    Imprime(node);

    node=GetFirst(arv);
    //Libera(node);
    //free(arv);

    printf("\nArvore Liberada!");
    printf("\nPrograma Finalizado!");
    return 0;
}