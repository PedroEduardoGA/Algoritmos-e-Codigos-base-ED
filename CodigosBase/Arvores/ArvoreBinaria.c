#include <stdio.h>
#include <stdlib.h>

typedef void* Arvore;

typedef struct tree
{
  int num;
  struct tree *Filho_dir;
  struct tree *Filho_esq;
}Tree;

/* Função que cria uma árvore */
Arvore createTree()
{
  /* Uma árvore é representada pelo endereço do nó raiz,
     essa função cria uma árvore com nenhum elemento,
     ou seja, cria uma árvore vazia, por isso retorna NULL. */
  return NULL;
}//Def

/* Função que verifica se uma árvore é vazia */
int treeIsEmpty(Arvore t)
{
  /* Retorna 1 se a árvore for vazia e 0 caso contrário */
  Tree* arvore= (Tree*) t;

  if(arvore==NULL)
    return 1;
  else
    return 0;
}//Def

/* Função que mostra a informação da árvore */
void showTree(Arvore t)
{
  Tree* arvore= (Tree*) t;

  if(treeIsEmpty(arvore)!=1) /* se a árvore não for vazia... */
  {
    printf("%d ", arvore->num); /* mostra a raiz */
    showTree(arvore->Filho_esq); /* mostra a sae (subárvore à esquerda) */
    showTree(arvore->Filho_dir); /* mostra a sad (subárvore à direita) */
  }
}//Def

/* Função que insere um dado na árvore */
void insertTree(Arvore* t, int num)
{
  Tree** arvore= (Tree*) t;
  /* Essa função insere os elementos de forma recursiva */
  if(*arvore == NULL)
  {
    *arvore = (Tree*)malloc(sizeof(Tree)); /* Aloca memória para a estrutura */
    printf("\nMemoria alocada!");
    (*arvore)->Filho_esq = NULL; /* Subárvore à esquerda é NULL */
    (*arvore)->Filho_dir = NULL; /* Subárvore à direita é NULL */
    (*arvore)->num = num; /* Armazena a informação */
    printf("%d ", (*arvore)->num);
    
    return;
  }
  printf("\nPasso pro if!");
  if(num < (*arvore)->num) /* Se o número for menor então vai pra esquerda */
      insertTree(&(*arvore)->Filho_esq, num);/* Percorre pela subárvore à esquerda */
    
  if(num > (*arvore)->num) /* Se o número for maior então vai pra direita */
      insertTree(&(*arvore)->Filho_dir, num);/* Percorre pela subárvore à direita */
}//Def

/* Função que verifica se um elemento pertence ou não à árvore */
int isInTree(Arvore t, int valor) 
{
  Tree* arvore= (Tree*) t;

  if(treeIsEmpty(arvore)==1)/* Se a árvore estiver vazia, então retorna 0 */
    return 0;
  
  if(arvore->num == valor)
    return 1;
  else
      return isInTree(arvore->Filho_esq, valor) || isInTree(arvore->Filho_dir, valor);
}//Def

void LiberaArvore(Arvore* t)
{
  Tree** arvore= (Tree*) t;
  
  if(*arvore!=NULL)
  {
    LiberaArvore(&(*arvore)->Filho_esq);
    LiberaArvore(&(*arvore)->Filho_dir);
    free(*arvore);
  }
}

void RemoveNoh(Arvore* t, int valor)
{
  Tree** arvore= (Tree*) t;
  
}

int main()
{
  Arvore t = createTree(); /* cria uma árvore */
  
  insertTree(&t, 12); /* insere o elemento 12 na árvore */
  insertTree(&t, 15); /* insere o elemento 15 na árvore */
  insertTree(&t, 10); /* insere o elemento 10 na árvore */
  insertTree(&t, 13); /* insere o elemento 13 na árvore */
   
  printf("\nArvore:\n"); 
  showTree(t); /* Mostra os elementos da árvore em pré-ordem */
  
  if(treeIsEmpty(t)==1) /* Verifica se a árvore está vazia */
    printf("\n\nArvore vazia!!\n");
  else
    printf("\n\nArvore NAO vazia!!\n");
  
  if(isInTree(t, 15)==1) /* Verifica se o número 15 pertence a árvore */
    printf("\nO numero 15 pertence a arvore!\n");
  else 
    printf("\nO numero 15 NAO pertence a arvore!\n");
  
  if(isInTree(t, 22)==1) /* Verifica se o número 22 pertence a árvore */
    printf("\nO numero 22 pertence a arvore!\n\n");
  else
    printf("\nO numero 22 NAO pertence a arvore!\n\n");
  
  //free(t); /* Libera a memória alocada pela estrutura árvore */
  LiberaArvore(&t);
  printf("\nArvore Liberada!");
  return 0;
}