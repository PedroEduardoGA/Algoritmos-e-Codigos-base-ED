#ifndef HASH_T
#define HASH_T

//	Funções referentes à Tabela de Espalhamento
#include<stdbool.h>

typedef void* HashTable;	//Ponteiro genérico para uma tabela de espalhamento	//Ponteiro genérico para um dado qualquer

//Cria uma nova tabela de tamanho n;
//Pré-requisito: n maior que 0;
//Pós condição: retorna um ponteiro para a tabela criada.
HashTable criaTabela(int n);

//Insere um registro em uma posição determinada por uma função interna (hashFunction);
//Pré-requisito: existir a tabela e chave não nula;
//Pós condição: novo registro {"chave" => Info} na tabela, retorna a posição onde o registro foi inserido.
int insereRegistro(HashTable tab, char* key, char cpf[],int x,int y);

//Exclui a chave 'key' da tabela, e retorna a posição excluída (-1 caso não encontre);
//Pré-requisito: tabela existe e chave não nula;
//Pós condição: chave excluída da tabela.
int removeChave(HashTable, char* key);

void ImprimeRegistro(HashTable tab, char* key);

//Verifica se existe a chave;
//Pré-requisito: tabela existe e chave não nula;
//Pós condição: -.
bool existeChave(HashTable, char* key);

//Deleta a tabela e todos os seus registros;
//Pré-requisito: tabela existe;
//Pós condição: tabela não existe mais.
void LiberaHashtable(HashTable tab);
#endif