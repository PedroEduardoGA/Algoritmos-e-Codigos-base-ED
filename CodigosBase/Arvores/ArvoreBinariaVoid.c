#include <stdio.h>
#include <stdlib.h>

typedef void* Arvore;
typedef void* Noh;

typedef struct N{ //Onde guarda infos como, cor borda, preenchimento...
    int num;

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

void Insere(Arvore t,int valor)
{
    no* node = (no*) malloc(sizeof(no));
    tree* arvore = (tree*) t;
    int inserido=0;
    no* aux;

    if(arvore->Raiz == NULL)//eh inserido a raiz
    {
        node->num=valor;
        node->Pai=NULL;
        node->Filho_dir=NULL;
        node->Filho_esq=NULL;
        arvore->Raiz=node;
        printf("\nInserida a Raiz!");
        return;
    }else
        aux=arvore->Raiz;

    node->num=valor;
    node->Filho_dir=NULL;
    node->Filho_esq=NULL;
    while ((aux!=NULL)&&(inserido!=1))
    {
        if(valor < aux->num)//vai pra esquerda por ser menor
        {
            if(aux->Filho_esq==NULL)
            {
                aux->Filho_esq=node;
                node->Pai=aux;
                inserido=1;
                break;
            }else
                aux=aux->Filho_esq;
        }

        if(valor > aux->num)//vai pra direita por ser maior
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
}

void Imprime(Arvore t,Noh nod)
{
    tree* arvore = (tree*) t;
    no* node = (no*) nod;

    if(arvore->Raiz==NULL)
        printf("\nArvore Vazia!");

    if(node!=NULL)
    {
        
        Imprime(arvore,node->Filho_esq);
        printf("%d -",node->num);
        Imprime(arvore,node->Filho_dir);
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

Noh GetNode(Arvore arv,int valor)
{
    tree* arvore = (tree*) arv;
    no* aux;
    aux=arvore->Raiz;

    if(aux==NULL)
        return NULL;

    while ((aux!=NULL)&&(aux->num!=valor))
    {
        if(valor < aux->num)
            aux=aux->Filho_esq;
        else
            aux=aux->Filho_dir;
    }

    if(aux->num == valor)
        return aux;
    else 
        return NULL;
}

int ExisteValor(Arvore arv,int valor)
{
    tree* arvore = (tree*) arv;
    no* aux;
    aux=arvore->Raiz;
    while ((aux!=NULL)&&(aux->num!=valor))
    {
        if(valor < aux->num)
            aux=aux->Filho_esq;
        else
            aux=aux->Filho_dir;
    }

    if(aux==NULL)
        return 0;

    if(aux->num == valor)
    {
        printf("\n%d Existe na arvore!",aux->num);
        return 1;
    }else
        {
            printf("\n%d Nao Existe na arvore!",aux->num);
            return 0;
        }
}

Noh MaiorMenor(Noh Node,int i)
{
    no* node = (no*) Node;
    if(i==0)//0 pq o noh passado eh o filho esquerda
    {
        while (node->Filho_dir!=NULL)
            node=node->Filho_dir;//retorna o maior valor da sub arvore esquerda
    }else
        {
            while (node->Filho_esq!=NULL)
            node=node->Filho_esq;
        }

    return node;
}

void RemoveNoh(Arvore arv,int valor)
{
    tree* arvore = (tree*) arv;
    no* aux1;
    no* node;
    no* aux2;

    if(ExisteValor(arvore,valor)==0)
    {
        printf("\n%d Nao existe na arvore, logo nao pode ser removido!",valor);
        return;
    }

    aux1=arvore->Raiz;
    node=GetNode(arvore,valor);
    if((node->Filho_esq == NULL)&&(node->Filho_dir == NULL))//Se o noh for uma folha
    {
        if(node==arvore->Raiz)
            arvore->Raiz=NULL;
        else
            {
                aux2=node->Pai;
                if(aux2->Filho_dir==node)
                    aux2->Filho_dir=NULL;
                else
                    aux2->Filho_esq=NULL; 
            }
        free(node);
        printf("\n%d Foi removido com sucesso!",valor);
        return;
    }

    if((node->Filho_esq == NULL)||(node->Filho_dir == NULL))//o noh possui so um filho
    {
        if(node==arvore->Raiz)//elemento que sera removido eh a raiz da arvore
        {
            if(node->Filho_esq==NULL)
            {
                aux1=node->Filho_dir;
                arvore->Raiz=aux1;
                aux1->Pai=NULL;

                free(node);
                printf("\n%d Foi removido com sucesso!",valor);
            }else
                {
                    aux1=node->Filho_esq;
                    arvore->Raiz=aux1;
                    aux1->Pai=NULL;

                    free(node);
                    printf("\n%d Foi removido com sucesso!",valor);
                }
            
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
        free(node);
        printf("\n%d Foi removido com sucesso!",valor);
        return;
    }

    no* anterior;
    if((node->Filho_esq != NULL)&&(node->Filho_dir != NULL))//o noh possui os 2 filhos
    {
        if(node==aux1)//o elemento removido eh a raiz da arvore
        {
            aux2=MaiorMenor(node->Filho_esq,0);//aux 2 vai receber o noh com maior valor encontrado na arvore esquerda
            anterior=aux2->Pai;
            if(aux2->Filho_esq!=NULL)
                anterior->Filho_dir=aux2->Filho_esq;
            else
                anterior->Filho_dir=NULL;
            
            aux1=node->Filho_esq;
            aux1->Pai=aux2;
            aux1=node->Filho_dir;
            aux1->Pai=aux2;
            aux2->Filho_dir=node->Filho_dir;//noh que vai no lugar do node recebe filho direito da raiz
            aux2->Filho_esq=node->Filho_esq;
            aux2->Pai=NULL;
            arvore->Raiz=aux2;
    
            free(node);
            printf("\n%d Foi removido com sucesso!",valor);
            return;
        }

        aux2=MaiorMenor(node->Filho_esq,0);//aux 2 vai receber o noh com maior valor encontrado na arvore esquerda
        anterior=aux2->Pai;
        if((aux2->Filho_esq==NULL)&&(aux2->Filho_dir==NULL))//se o noh que vai no lugar do removido nao possui filhos
        {
            anterior->Filho_dir=NULL;
            aux2->Filho_dir=node->Filho_dir;
            aux2->Filho_esq=node->Filho_esq;
            aux1=node->Pai;
            if(aux1->Filho_dir==node)
                aux1->Filho_dir=aux2;
            else
                aux1->Filho_esq=aux2;

            aux2->Pai=aux1;
            free(node);
            printf("\n%d Foi removido com sucesso!",valor);
            return;
        }

        if(anterior==node)
        {
            anterior=node->Pai;
            aux2->Filho_dir=node->Filho_dir;
            aux2->Pai=anterior;

            if(anterior->Filho_dir==node)
                anterior->Filho_dir=aux2;
            else
                anterior->Filho_esq=aux2;

            free(node);
            printf("\n%d Foi removido com sucesso!",valor);
            return;
        }
        if(aux2->Filho_esq!=NULL)
            anterior->Filho_dir=aux2->Filho_esq;
        else
            anterior->Filho_dir=NULL;
            
        aux1=node->Filho_esq;
        aux1->Pai=aux2;//filho esquerdo do node vai receber o aux2 como pai
        aux1=node->Filho_dir;
        aux1->Pai=aux2;//filho direito do node vai receber o aux2 como pai
        aux2->Filho_dir=node->Filho_dir;//noh que vai no lugar do node recebe filho direito da raiz
        aux2->Filho_esq=node->Filho_esq;
        anterior=node->Pai;//anterior eh o noh pai do node q sera removido
        
        if(anterior->Filho_esq==node)
            anterior->Filho_esq=aux2;
        else
            anterior->Filho_esq=aux1;
        
        aux2->Pai=anterior;
        free(node);
        printf("\n%d Foi removido com sucesso!",valor);
    }
}

int main()
{
    Arvore arv= Create();
    Noh node;

    Insere(arv,30);
    Insere(arv,28);
    Insere(arv,1);
    Insere(arv,10);
    Insere(arv,24);
    Insere(arv,11);
    Insere(arv,12);
    Insere(arv,13);
    Insere(arv,29);
    
    /*Insere(arv,34);
    Insere(arv,33);
    Insere(arv,38);
    Insere(arv,35);*/

    node=GetFirst(arv);
    printf("\nArvore:\n");
    Imprime(arv,node);
    
    RemoveNoh(arv,28);

    node=GetFirst(arv);
    printf("\nArvore:\n");
    Imprime(arv,node);

    printf("\nIniciando liberamento da memoria!");
    node=GetFirst(arv);
    Libera(node);
    free(arv);

    printf("\nArvore Liberada!");
    printf("\nPrograma Finalizado!");
    return 0;
}