// Autor Pedro Eduardo - Tempo Decorrido 3H:40m
#include <stdio.h>
#include <stdlib.h>

void LinhaColuna(int **matriz, int vari, int *soluciona);
void MiniMatrizes(int **matriz, int *soluciona);
void ZeroDoze(int **sudo, int *soluciona);
void Diagonais(int **matriz,int Diago,int *soluciona);

int main(void)
{
 int x,y,solucao,var,diagonal;
 int **sudoku;
 
 FILE *arq;
 arq= fopen("sudoku12x12.txt","r");
 
 sudoku= (int **)malloc(12*sizeof(int *));
 
 for (x=0; x<12; x++)
  sudoku[x]= (int *) malloc(12*sizeof(int));

 //Leitura		
 for(x=0; x<12; x++)
 {
  for(y=0; y<12; y++)
  {
   fscanf(arq,"%d",(*(sudoku+x)+y));
  }
 }
 fclose(arq);
 
 //Escrita
 for(x=0; x<12; x++)
 {
  for(y=0; y<12; y++)
  {
   if(sudoku[x][y]>9)//Essa parte � s� pra exibir a matriz certinho, porque sen�o fica tudo junto e desalinhado
    printf("%d ",sudoku[x][y]);
   else
    printf("%d  ",sudoku[x][y]);
  }
  printf("\n");
 }
 
 ZeroDoze(sudoku,&solucao);//Funcao verifica se algum elemento da matriz � menor que 0 ou maior que 12
//Se a variavel solucao for pra 0 automaticamente vai aparecer que nao � correta
 
 if(solucao==1)
 {
  MiniMatrizes(sudoku,&solucao);//Verificacao das mini-matrizes 3x3
 }
 
 if(solucao==1)
 {
  var=0;
  while((var<12)&&(solucao==1))
  {
   LinhaColuna(sudoku,var,&solucao);//Verificacao das linhas e colunas
   var++;
  }
 }
 
 diagonal=0;//Diagonal 0 � pra verificiar a diagonal principal primaria!
 if(solucao==1)
 {
  if(diagonal=0)
    Diagonais(sudoku,diagonal,&solucao);//Verifica a diagonal primaria
    
  diagonal++;
  if(diagonal=1)
    Diagonais(sudoku,diagonal,&solucao);//Verifica a diagonal secundaria  
 }
 
 if(solucao==1)
  printf("\nSolucao correta para o sudoku!");
 else
  printf("\nSolucao incorreta para o sudoku!");

  getchar();
}
 
 void ZeroDoze(int **sudo,int *soluciona)
 {
  *soluciona=1;//Iniciando a variavel, caso algum elemento da matriz seja 0 ou maior que 12 soluciona vai pra 0 sendo assim uma solucao invalida!
  int x,y;
  for(x=0; x<12; x++)
  {
   for(y=0; y<12; y++)
   {
    if((sudo[x][y]>=13)||(sudo[x][y]<=0))
     *(soluciona)=0;
   }
  }

 }//Fim funcao
 
 void MiniMatrizes(int **matriz, int *soluciona)//Verifica se nenhum elemento � repetido nas submatrizes 3x4
 {
  int minX=0, maxX=3, minY=0, maxY=4,soma=0,x,y;
  int mini=1;//Representa a mini matriz em que esta
  
  while((*soluciona==1)&&(soma<=78)&&(minY<12))
  {
   soma=0;
   for(x=minX; x<maxX; x++)
   {
    for(y=minY; y<maxY; y++)
    {
     soma+=matriz[x][y];//Prof usei essa forma porque � mais simples, mas a "formula" ta sendo usada na leitura
    }
   }
   mini++;
   
   if((mini==4)||(mini==7)||(mini==10))
   {
   	minX+=3;
   	maxX+=3;
   	minY=0;
   	maxY=4;
   }
   
   minY+=4;
   maxY+=4;
   
   if(soma!=78)
    *soluciona=0;
  }	
  
 }//Fim funcao
 
 
 void LinhaColuna(int **matriz, int vari,int *soluciona)//Verifica se nenhum elemento � repetido nas linhas e nas colunas
 {
  int x,soma;
  soma=0;
  for(x=0; x<12; x++)//Soma linha
  {
   soma+=matriz[x][vari];//Prof usei essa forma porque � mais simples, mas a "formula" ta sendo usada na leitura
  }
  
  if(soma==78)//Note que a soma s� � possivel nesse valor distribuindo os numeros de 1 a 12, s� vai dar 78 sen�o tiver repetindo
   *soluciona=1;
  else
   *soluciona=0;
   
  if(*soluciona==1)
  {
   soma=0;
   for(x=0; x<12; x++)//Soma coluna
   {
   	soma+=matriz[vari][x];//Prof usei essa forma porque � mais simples, mas a "formula" ta sendo usada na leitura
   }
   
   if(soma==78)
    *soluciona=1;
   else
    *soluciona=0;
  }
  
 }//Fim funcao
 
 void Diagonais(int **matriz,int Diago, int *soluciona)
 {
    int soma=0,x,y;
    
    if(Diago==0)//Este la�o percorre a diagonal principal prim�ria!
    {
	   x=0;
       y=0;
       while(x<12)
       {
    	   soma+=matriz[x][y];
    	   x++;
    	   y++;
	   }
	
	   if(soma==78)
	       *soluciona=1;
	   else
	       *soluciona=0;
    }
    
    if(Diago==1)//Este la�o percorre a diagonal principal secund�ria!
    {
	   x=11;
       y=0;
       while(y<12)
       {
    	   soma+=matriz[x][y];
    	   x--;
    	   y++;
	   }
	
	   if(soma==78)
	       *soluciona=1;
	   else
	       *soluciona=0;
    }

 }//Fim funcao
