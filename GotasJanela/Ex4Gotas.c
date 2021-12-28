//Autor: Pedro Eduardo - Tempo Decorrido: 2H:30m
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

#define Max_lin 12
#define Max_col 12

void LeituraCoordenadas(int matriz[Max_lin][Max_col]);
int InicializaMatriz(int matriz[Max_lin][Max_col]);
int Escrita(int matriz[Max_lin][Max_col]);
void MovimentaGotas(int matriz[Max_lin][Max_col]);

int main(void)
{
	int Somatorio,soma;
	int janela[Max_lin][Max_col];
	
	Somatorio=InicializaMatriz(janela);//Somando o valor que a matriz somente com as bordas possui
	LeituraCoordenadas(janela);

	//Somatorio é a soma dos elementos da matriz somente com as bordas, dessa forma vou saber quando parar de movimentar
	//as gotas na janela
	
    soma=Escrita(janela);//Inicializando a variavel soma
    system("cls");//Esse comando limpa a tela pra ficar mais visualmente agradavel
    while(soma>Somatorio)
    {
    	soma=Escrita(janela);//Quando soma chegar no mesmo valor de somatorio significa que não ha mais gotas na janela
    	MovimentaGotas(janela);
    	Sleep(800);
    	system("cls");
	}
	soma=Escrita(janela);
}

void LeituraCoordenadas(int matriz[Max_lin][Max_col])
{
	int x,y,limColuna,limLinha;
	x=1;
	y=1;
	limLinha=Max_lin-1;
	limColuna=Max_col-1;
	
	FILE *arq;
	arq=fopen("matriz.txt","r");
	while((x!=0)||(y!=0))
	{
	    fscanf(arq,"%d",&x);
	    fscanf(arq,"%d",&y);
	    if((x!=0)&&(y!=0)&&(x!=limLinha)&&(y!=limColuna)&&(y!=limLinha)&&(x!=limColuna))
	    {
		    if(x==1)
		        matriz[x][y]=2;
		    else
		        matriz[x][y]=1;
	    }
    }
    fclose(arq);
    
	
}

int Escrita(int matriz[Max_lin][Max_col])
{
	int x,y,somatorio=0;
	for(x=0; x<Max_lin; x++)
	{
        for(y=0; y<Max_col; y++)
        {
        	if(matriz[x][y]==3)//Se é 3 é a borda
            {
            	printf("[]");
            	somatorio=somatorio+3;
			}
			
			if(matriz[x][y]==0)//Se é 0 o espaco é vazio
            	printf("  ");
			
            if(matriz[x][y]==1)//Sendo 1 são as gotas que não estao na primeira linha da janela
            {
            	printf("G ");
            	somatorio=somatorio+1;
			}
			
			if(matriz[x][y]==2)//Se é 2 são as gotas que estão na primeira linha 
            {
            	printf("G ");
            	somatorio=somatorio+2;
			}
       }
       printf("\n");
    }
    return(somatorio);//toda vez que eu escrevo a matriz atualizo o valor da variavel soma la na main
}

void MovimentaGotas(int matriz[Max_lin][Max_col])
{
	int x,y,limiteLinha,limiteColuna;
	limiteLinha=Max_lin-1;
	limiteColuna=Max_col-1;
	
	for(x=limiteLinha; x>=0; x--)//Comeco ao contrario pra não perder as gotas do meio
	{
		for(y=limiteColuna; y>=0; y--)
		{
			if((matriz[x][y]==2)&&(x==limiteLinha-2))//quando a gota da primeira linha esta chegando na borda
				matriz[x][y]=0;

			if((matriz[x][y]!=3)&&(x==limiteLinha-1))//Quer dizer que a gota estava na ultima linha então ela some
			    matriz[x][y]=0;
			
			if(matriz[x][y]==1)//Se for 1 quer dizer que é gota normal então vai andar uma linha pra baixo
			{
				matriz[x+1][y]=1;
				matriz[x][y]=0;
			}
			
			if(matriz[x][y]==2)//Se for 2 é a gota da primeira linha, então vai andar 2 linhas para baixo
			{
				matriz[x+2][y]=2;
				matriz[x][y]=0;
			}
		}
	}
	
}

int InicializaMatriz(int matriz[Max_lin][Max_col])//Iniacializa a matriz colocando 3 nas bordas e 0 no resto
{
	int x,y,limiteLin,limiteCol,somatorio=0;
	limiteLin=Max_lin-1;
	limiteCol=Max_col-1;
	
	for(x=0; x<Max_lin; x++)
	{
        for(y=0; y<Max_col; y++)
        {
            if((x==0)||(x==limiteLin)||(y==0)||(y==limiteCol))
            {
                matriz[x][y]=3; //3 representa as bordas da janela
                somatorio+=3;
            }
            else
                matriz[x][y]=0;
       }
    }
    return(somatorio);
}
