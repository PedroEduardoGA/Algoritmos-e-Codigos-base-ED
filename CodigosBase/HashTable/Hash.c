#include"HashT.h"
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<stdio.h>

typedef struct registrado{
    char* key;
    char cpf[40];
    int x,y;
    struct registrado *next;//apontador pra outro noh pra qnd ocorre repeticao de chave
}noh;

typedef struct registros{
    noh *reg;
}nohs;

typedef struct tabela{
    int tamanho;
    nohs *reg;
}table;

int hashFunction(char* a, int tabSize)//funcao calcula a posicao dado uma chave a
{
    int primos[] = {2, 3, 5, 7, 11, 13, 17, 23, 29, 31, 37, 41, 43, 47,53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449};
    int somatorio = 0;
    for(unsigned int i=0;i<strlen(a);i++)
        somatorio += a[i]*primos[i];

    //int valor = 7;
    //for(i=0; i< strlen(a);i++)
    //  valor = 31*valor+(int) a[i];
    //return valor;
    
    somatorio = somatorio % tabSize;//a posicao vai ser o valor do resto, da divisao do somatorio pelo tamanho da tabela
    return somatorio;
}

HashTable criaTabela(int tam)
{
    if(tam<=0)
        return NULL;//caso o tamanho informado seja menor ou igual zero, retorna null
    
    nohs* registros = (nohs*) malloc(sizeof(nohs) * tam);//aloca memoria pra estrutura dos "nohs" de acordo com o tamanho
    table* tabela = (table*) malloc(sizeof(table));//aloca memoria pra estrutura da tabela

    for(int i=0;i<tam;i++)
        registros[i].reg = NULL;//zera todos os nohs da tabela

    tabela->tamanho = tam;
    tabela->reg = registros;
    for(int i=0;i<tam;i++)
        tabela->reg[i].reg = NULL;//zera todos os registros internos da tabela
    
    return tabela;
}

int insereRegistro(HashTable tab, char* key, char cpf[],int x,int y)//modificada
{
    table* Tabela= (table*) tab;//cast
    int posic = hashFunction(key, Tabela->tamanho);//calcula a posicao que sera inserido de acordo com a chave

    noh* aux = malloc(sizeof(noh));
    if(!aux)
    {
        printf("\nErro ao alocar memoria para o registro!");
        return -1;
    }

    aux->key = malloc(strlen(key)+1);
    if(!aux->key)
    {
        printf("\nErro ao alocar memoria para a chave!");
        return -1;
    }
    strcpy(aux->key, key);
    strcpy(aux->cpf,cpf);
    aux->x=x;
    aux->y=y;
    
    aux->next = Tabela->reg[posic].reg;//o noh->prox vai receber o noh que ocupava a posicao, basicamente vai ser empurrado pra frente
    Tabela->reg[posic].reg = aux;//posicao vai receber o noh novo com as informacoes novas
    return posic;
}

bool existeChave(HashTable tab, char* key)
{
    table* Tabela= (table*) tab;//cast
    int posic = hashFunction(key, Tabela->tamanho);//calcula a posicao da chave
    if(Tabela->reg[posic].reg == NULL)//se o registro naquela posicao eh null entao a chave nao existe na tabela
        return false;
    
    return true;
}

int removeChave(HashTable tab, char* key)
{
    if(!existeChave(tab, key))//oposto da existechave nesse caso é true, senao existe a chave retorna false e o oposto é true
        return -1;
    
    table* Tabela= (table*) tab;//cast
    int posic = hashFunction(key, Tabela->tamanho);//calcula a posicao da chave

    noh *toBeDeleted = Tabela->reg[posic].reg;//o noh que sera deletado recebe o registro da posicao calculada
    if(strcmp(toBeDeleted->key, key)==0)//se a chave no noh deletado eh igual a da chave passada ele eh removido
    {
        Tabela->reg[posic].reg = toBeDeleted->next;//a posicao da tabela vai receber o proximo noh
        free(toBeDeleted->key);//free da chave do noh que sera deletado
        toBeDeleted->key = NULL;
        free(toBeDeleted);//free da estrutura do noh que sera deletado
        toBeDeleted = NULL;
        return posic;//retorna a posicao do noh que foi deletado
    }
    
    noh *previous = toBeDeleted;//caso a chave do noh nao seja igual a passada
    while(strcmp(toBeDeleted->key, key) != 0)//percorro a "lista" daquele noh posicao procurando pela chave que desejo remover
    {
        previous = toBeDeleted;
        toBeDeleted = toBeDeleted->next;
        if(toBeDeleted == NULL)//chave nao existe
            return -1;
    }

    previous->next = toBeDeleted->next;//encontrou o noh com a chave, atribui pro noh anterior o proximo noh do node que sera removido
    free(toBeDeleted->key);
    toBeDeleted->key = NULL;
    free(toBeDeleted);
    toBeDeleted = NULL;

    return posic;//retorna a posicao do noh que foi deletado
}

void ImprimeRegistro(HashTable tab, char* key)
{
    table* Tabela= (table*) tab;//cast
    if(!existeChave(tab, key))//oposto da existechave nesse caso é true, senao existe a chave retorna false e o oposto é true
    {
        printf("\n%s nao existe!",key);
        return;
    }  

    int posic = hashFunction(key, Tabela->tamanho);
    noh *node=Tabela->reg[posic].reg;//node recebe o primeiro noh da posicao calculada
    while(node != NULL)//percorre todos nohs daquela posicao
    {
        printf("\nKey[%d]= %s \nCPF: %s X: %d e Y: %d",posic,node->key,node->cpf,node->x,node->y);
        node=node->next;
    }
}

void LiberaHashtable(HashTable tab)
{
    table* Tabela= (table*) tab;//cast
    if(Tabela == NULL){
        printf("\nTabela nao existe!");
        return;
    }

    noh *aux, *aux2;
    int posic;
    for(posic=0; posic<Tabela->tamanho; posic++)//percorre todas posicoes da tabela
    {
        nohs registro = Tabela->reg[posic];
        if(registro.reg != NULL)//se a posicao ja esta ocupada
        {
            aux2 = registro.reg;//noh aux vai receber o primeiro noh da posicao
            while(aux2 != NULL)//vai percorrer todos nohs daquela posicao
            {
                aux = aux2;//aux é o noh anterior
                aux2 = aux->next;
                if(aux->key != NULL)//libera o noh anterior ao aux2
                {
                    free(aux->key);
                    free(aux);
                    aux = NULL;
                }
            }
        }
    }
    free(Tabela->reg);//libera os registros da tabela
    Tabela->reg = NULL;
    free(Tabela);//libera a tabela
    Tabela = NULL;
}