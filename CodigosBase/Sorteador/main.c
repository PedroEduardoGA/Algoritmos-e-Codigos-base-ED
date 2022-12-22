#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Sorteador.h"

int main(void)
{
    char Cores[30];
    
    for(int x=0; x<6; x++)
    {
        strcpy(Cores,Sorteio());//Sorteia uma nova e ja copia pra Cores
        strtok(Cores," ");//Formata a string
        printf("\nCores: %s",Cores);
    }
    
    printf("\nObrigado por utilizar o GarbossaSorteador, licensiado e distribuido por Ferrados S.A!\n");
}