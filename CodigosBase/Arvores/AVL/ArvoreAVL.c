#include <stdio.h>
#include <stdlib.h>
#include "ArvoreAVL.h" //inclui os Prot�tipos

typedef struct N{ //Onde guarda infos como, cor borda, preenchimento...
    int x;
    int y;
    int altura;
    
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

int altura_NO(Noh nod)//nova*
{//recebe um noh
    no* node = (no*) nod;
    if(node == NULL)//se o noh é null retorna -1
        return -1;
    else
        return node->altura;//senao, retorna a altura desse noh
}//entendi

int fatorBalanceamento_NO(Noh nod)//nova*
{
    no* node = (no*) nod;
    return labs(altura_NO(node->Filho_esq) - altura_NO(node->Filho_dir));//retorna o modulo da altura do noh esq - noh dir
}//entendi

int maior(int x, int y)//nova*
{
    if(x > y)
        return x;
    else
        return y;
}//entendi

void emOrdem_ArvAVL(Noh nod)
{
    no* node = (no*) nod;
    if(node != NULL)
    {
        emOrdem_ArvAVL(node->Filho_esq);
        printf("No %d: H(%d) fb(%d)\n",node->x,altura_NO(node),fatorBalanceamento_NO(node));
        emOrdem_ArvAVL(node->Filho_dir);
    }
}

//=================================
void RotacaoLL(Arvore t,Noh nod)//nova*
{//LL
    printf("RotacaoLL\n");
    tree* arvore = (tree*) t;
    no* nodeA = (no*) nod;
    no* nodeB;
    int filho=0;

    if(nodeA->Pai!=NULL)//nodeA nao eh raiz da arvore
    {
        if(nodeA->Pai->Filho_dir == nodeA)
                filho=1;
            else
                filho=-1;
    }

    //B = (*A)->esq;
    nodeB=nodeA->Filho_esq;//
    
    if(nodeB->Filho_dir!=NULL)
        nodeB->Filho_dir->Pai=nodeA;
    //(*A)->esq = B->dir;
    nodeA->Filho_esq=nodeB->Filho_dir;//
    
    
    //B->dir = *A;
    nodeB->Filho_dir=nodeA;//
    
    if(arvore->Raiz == nodeA)//caso o noh passado pra balancear fosse a raiz da arvore
    {
        arvore->Raiz=nodeB;
        nodeB->Pai=NULL;
        printf("\nNova raiz eh: %d",nodeB->x);
    }else
        {
            nodeB->Pai=nodeA->Pai;
            if(filho==1)
                nodeA->Pai->Filho_dir=nodeB;
           
            if (filho == -1)
                nodeA->Pai->Filho_esq=nodeB;
        }
        
    nodeA->Pai=nodeB;
    nodeA->altura = maior(altura_NO(nodeA->Filho_esq),altura_NO(nodeA->Filho_dir)) + 1;
    nodeB->altura = maior(altura_NO(nodeB->Filho_esq),nodeA->altura) + 1;
    //*A = B; acho que atribuicao arvore->raiz=nodeB resolve
}

void RotacaoRR(Arvore t,Noh nod)//nova*
{//RR
    printf("RotacaoRR\n");
    tree* arvore = (tree*) t;
    no* nodeA = (no*) nod;
    no* nodeB;
    int filho=0;

    if(nodeA->Pai!=NULL)//nodeA nao eh raiz da arvore
    {
        if(nodeA->Pai->Filho_dir == nodeA)
                filho=1;
            else
                filho=-1;
    }
    
    //B = (*A)->dir;
    nodeB=nodeA->Filho_dir;//
    
    if(nodeB->Filho_esq!=NULL)
        nodeB->Filho_esq->Pai=nodeA;
    //(*A)->dir = B->esq;
    nodeA->Filho_dir=nodeB->Filho_esq;//

    //B->esq = (*A);
    nodeB->Filho_esq=nodeA;
    
    if(arvore->Raiz == nodeA)//caso o noh passado pra balancear fosse a raiz da arvore
    {
        arvore->Raiz=nodeB;
        nodeB->Pai=NULL;
        printf("\nNova raiz eh: %d",nodeB->x);
    }else
        {
            nodeB->Pai=nodeA->Pai; 
            if(filho==1)
                nodeA->Pai->Filho_dir=nodeB;
           
            if (filho == -1)
                nodeA->Pai->Filho_esq=nodeB;           
        }
        
    nodeA->Pai=nodeB;
    nodeA->altura = maior(altura_NO(nodeA->Filho_esq),altura_NO(nodeA->Filho_dir)) + 1;
    nodeB->altura = maior(altura_NO(nodeB->Filho_dir),nodeA->altura) + 1;
    //(*A) = B;
}

void RotacaoLR(Arvore t,Noh nod)//nova*
{//LR
    no* nodeA = (no*) nod;
    RotacaoRR(t,nodeA->Filho_esq);
    RotacaoLL(t,nodeA);
}

void RotacaoRL(Arvore t,Noh nod)//nova*
{//RL
    no* nodeA = (no*) nod;  
    RotacaoLL(t,nodeA->Filho_dir);
    RotacaoRR(t,nodeA);
}

Noh GetFirst(Arvore arv)
{
    tree* arvore = (tree*) arv;
    return arvore->Raiz;
}

int insereArvAVL(Arvore t,int x,int y)
{
    int inserido=0;
    no* anterior;
    tree* arvore = (tree*) t;

    no* novo = (no*) malloc(sizeof(no));
    novo->x=x;
    novo->y=y;
    novo->Filho_dir=NULL;
    novo->Filho_esq=NULL;
    novo->altura=0;
    if(arvore->Raiz==NULL)
    { 
        novo->Pai=NULL;
        arvore->Raiz=novo;
        anterior=NULL;
        //printf("\n[Insere]: %d Foi inserido como a Raiz!",novo->x);
        inserido=2;//inserido eh 2 pq foi inserida a raiz
    }else
        anterior=arvore->Raiz;

    while ((anterior!=NULL)&&(inserido!=1))
    {
        if(x < anterior->x)//vai pra esquerda por ser menor
        {
            if(anterior->Filho_esq==NULL)
            {
                //printf("\n[Insere]: %d Foi inserido na esquerda!",novo->x);
                anterior->Filho_esq=novo;
                novo->Pai=anterior;
                inserido=1;
            }else
                anterior=anterior->Filho_esq;
        }

        if(x > anterior->x)//vai pra direita por ser maior
        {
            if(anterior->Filho_dir==NULL)
            {
                //printf("\n[Insere]: %d Foi inserido na direita!",novo->x);
                anterior->Filho_dir=novo;
                novo->Pai=anterior;
                inserido=1;
            }else
                anterior=anterior->Filho_dir;
        }
    }//acabou a parte da inserção
    
    if(inserido==1)
    {
        while(anterior!=NULL)//vou percorrer a arvore atualizando a altura dos nohs anteriores
        {
            if(x < anterior->x)
            {
                //printf("\nNovo foi inserido a esquerda do anterior!");
                if(fatorBalanceamento_NO(anterior) >= 2)
                {
                    if(x < anterior->Filho_esq->x )
                        RotacaoLL(t,anterior);
                    else
                        RotacaoLR(t,anterior);
                }
            }else
                {
                    if(x > anterior->x)
                    {
                        //printf("\nNovo foi inserido a direita do anterior!");
                        if(fatorBalanceamento_NO(anterior) >= 2)
                        {
                            if(anterior->Filho_dir->x < x)
                                RotacaoRR(t,anterior);
                            else
                                RotacaoRL(t,anterior);
                        }
                    }
                }
            //printf("\nAnterior que foi analisado: %d",anterior->x);
            anterior->altura = maior(altura_NO(anterior->Filho_esq),altura_NO(anterior->Filho_dir)) + 1;
            anterior=anterior->Pai;
        }
    }
    return inserido;
}

Noh procuraMenor(Noh nod)//funcao retorna o menor nó a esquerda
{
    no* node = (no*) nod;
    no* nodeProx= node->Filho_esq;
    while(nodeProx != NULL)
    {
        node=nodeProx;
        nodeProx=nodeProx->Filho_esq;
    }
    return node;
}

Noh GetNode(Arvore arv,int valor)
{
    tree* arvore = (tree*) arv;
    no* aux;
    aux=arvore->Raiz;

    if(aux==NULL)
        return NULL;

    while ((aux!=NULL)&&(aux->x!=valor))
    {
        if(valor < aux->x)
            aux=aux->Filho_esq;
        else
            aux=aux->Filho_dir;
    }

    if(aux->x == valor)
        return aux;
    else 
        return NULL;
}

bool remove_ArvAVL(Arvore t, int valor)//funcao funciona perfeitamente
{
    tree* arvore = (tree*) t;
    int removido=0,lado=0,Possuiafilhos=0;
	if(arvore->Raiz == NULL)
        return false;

    no* node;
    no* anterior;
    no* aux;
    node= GetNode(arvore,valor);//retorna o noh que possui o x igual o valor passado

    if(node==NULL)
    {
        printf("\nValor inexistente!");
        return false;
    }

    printf("\nValor encontrado: %d",node->x);
    if(node->Pai!=NULL)
        printf(" Pai: %d",node->Pai->x);
    if(node->Filho_esq!= NULL)
        printf(" Esq: %d",node->Filho_esq->x);
    if(node->Filho_dir!= NULL)
        printf(" Dir: %d",node->Filho_dir->x);

    if(removido==0)
    {
        if(node->Pai!=NULL)
        {
            if(node->Pai->Filho_esq == node)
                lado=-1;//node atual é o filho esquerdo do pai
            else
                lado=1;//node atual é o filho direito do pai
        }

        if(node->Filho_esq==NULL || node->Filho_dir==NULL)//tem 1 ou nenhum filho
        {
            anterior=node->Pai;
            if(node->Filho_esq != NULL)//filho esquerdo nao eh nulo
            {
                if(lado == 1)
                    anterior->Filho_dir=node->Filho_esq;
                
                if(lado == -1)
                    anterior->Filho_esq=node->Filho_esq;

                if(lado==0)
                    arvore->Raiz=node->Filho_esq;

                Possuiafilhos=1;
            }

            if(node->Filho_dir != NULL)//filho esquerdo nao eh nulo
            {
                if(lado == 1)
                    anterior->Filho_dir=node->Filho_dir;
                
                if(lado == -1)
                    anterior->Filho_esq=node->Filho_dir;

                if(lado==0)
                    arvore->Raiz=node->Filho_dir;

                Possuiafilhos=1;
            }

            if(Possuiafilhos==0)
            {
                if(node->Pai!=NULL)
                {
                    if(lado == 1)
                        anterior->Filho_dir=NULL;//noh removido era filho direito do noh pai
                    else
                        anterior->Filho_esq=NULL;//noh removido era filho esquerdo do noh pai    
                }else
                    arvore->Raiz=NULL;
            }
            printf("\n%d Foi removido com sucesso!",valor);
            aux=anterior;
            free(node);
            removido=1;
        }

        if((node->Filho_esq!=NULL) && (node->Filho_dir!=NULL) && (removido==0))//noh tem 2 filhos
        {
            anterior=procuraMenor(node->Filho_dir);//anterior é o menor valor da subarvore direita
            printf("\nMenor valor encontrado eh: %d",anterior->x);
            if(anterior != node->Filho_dir)//o noh direito possuia menor valor
            {
                if(anterior->Pai->Filho_esq == anterior)
                    lado=-1;//node anterior é o filho esquerdo do pai
                else
                    lado=1;

                if(lado == 1)
                    anterior->Pai->Filho_dir=anterior->Filho_dir;//atribui o filho direito do noh anterior pro pai
                
                if(lado == -1)
                    anterior->Pai->Filho_esq=anterior->Filho_dir;

                node->x=anterior->x;//copia os valores do menor noh do filho direito
                node->y=anterior->y;
                aux=anterior->Pai;//atribui o pai do menor noh pro aux
                free(anterior);//libera a memoria alocada pelo menor noh
                printf("\n%d Foi removido com sucesso!",valor);
                removido=1;
            }

            if((anterior == node->Filho_dir)&&(removido==0))//o filho direito nao possui sub arvore esquerda
            {
                node->x=anterior->x;//copia os valores do menor noh do filho direito
                node->y=anterior->y;
                node->Filho_dir=NULL;
                aux=anterior->Pai;//atribui o pai do menor noh pro aux
                free(anterior);//libera a memoria alocada pelo menor noh
                printf("\n%d Foi removido com sucesso!",valor);
                removido=1;
            }
        }
    }//chegou aqui o valor que seria removido da arvore ja foi removido

    if(removido==1)
    {
        while(aux!=NULL)//vou percorrer a arvore atualizando a altura dos nohs auxes
        {
            if(valor <= aux->x)
            {
                //printf("\nNovo foi inserido a esquerda do aux!");
                if(fatorBalanceamento_NO(aux) >= 2)
                {
                    if(valor < aux->Filho_esq->x )
                        RotacaoLL(t,aux);
                    else
                        RotacaoLR(t,aux);
                }
            }else
                {
                    if(valor >= aux->x)
                    {
                        //printf("\nNovo foi inserido a direita do aux!");
                        if(fatorBalanceamento_NO(aux) >= 2)
                        {
                            if(aux->Filho_dir->x < valor)
                                RotacaoRR(t,aux);
                            else
                                RotacaoRL(t,aux);
                        }
                    }
                }
            //printf("\naux que foi analisado: %d",aux->x);
            aux->altura = maior(altura_NO(aux->Filho_esq),altura_NO(aux->Filho_dir)) + 1;
            aux=aux->Pai;
        }//finalWhile
        return true;    
	}else
        return false;
}

void ManipulacaoDot(Arvore t,char arquivo[])
{
    tree* arvore = (tree*) t;
    FILE* ArqDot = fopen(arquivo, "w");
    if(ArqDot == NULL)
    {
        printf("Nao foi possivel criar o .dot!\n");
        exit(1);
    }
    fprintf(ArqDot,"digraph Arvore {\nsize=\"80\";\nnode [color=gray, style=filled]; ");
    if(arvore->Raiz==NULL)
    {
        printf("\nArvore Vazia!");
        return;
    }   
    EscritaDot(arvore->Raiz,ArqDot);
    fprintf(ArqDot,"\n}");
}

void EscritaDot(Noh nod,FILE* arq)
{
    no* node = (no*) nod;

    char *edge = " -> ";
    char *NullNode = " [shape=point, style=\"invis\"]";
    char *invisEdge = " [style=\"invis\"]";
    char *ident = "   ";

    if (node == NULL)
      return;

    char rtkey[75];
    sprintf(rtkey,"%d",node->x);

    char lst[100];
    char rst[100];

    char lkey[100];
    char rkey[100];
    char lpreamb[100];
    char rpreamb[100];
    char lpost[100];
    char rpost[100];

    if (node->Filho_esq != NULL){
        sprintf(lpreamb,"");
        sprintf(lkey,"%d",node->Filho_esq->x);
        sprintf(lpost,"");
    }
    else{//nao existe filho esquerdo
        sprintf(lkey, "nullL%s",rtkey);
        sprintf(lpreamb,"%s%s%s;\n", ident, lkey, NullNode);
        sprintf(lpost,"%s",invisEdge);
    }

    if (node->Filho_dir != NULL){
        sprintf(rpreamb, "");
        sprintf(rkey, "%d",node->Filho_dir->x);
        sprintf(rpost,"");
    }
    else{
        sprintf(rkey,"nullR%s",rtkey);
        sprintf(rpreamb,"%s%s%s;\n",ident, rkey, NullNode);
        sprintf(rpost,"%s", invisEdge);
    }

    sprintf(lst,"%s%s%s%s%s%s ;\n",lpreamb,ident,rtkey,edge,lkey,lpost);
    sprintf(rst,"%s%s%s%s%s%s ;\n",rpreamb,ident,rtkey,edge,rkey,rpost);
    fprintf(arq,lst);
    fprintf(arq,rst);

    EscritaDot(node->Filho_esq,arq);
    EscritaDot(node->Filho_dir,arq);
}
