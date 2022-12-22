#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
int impressao(int mapinha[20][30]);

int main(void) //Funcao principal
{
 int mapa[20][30],x,y;
 int movimentos=0,X,Y,antx,anty,movimentou,possibilidade,anteriorX,anteriorY;
 int var1,var2,rabox,raboy;

 FILE *arq;
 arq= fopen("obstaculos.txt","r");

 for(x=0; x<20; x++)
 {
  for(y=0; y<30; y++)
  {
  fscanf(arq,"%d",&mapa[x][y]); //Leitura da matriz
  }
 }
 fclose(arq);
 
 for(x=0; x<20; x++)
 {
  for(y=0; y<30; y++)
  {
   if(mapa[x][y]==4)//Percorrendo a matriz em busca da cabeca para comecar a movimentar
   {
   	antx=x;
   	anty=y;
   }
   
   if(mapa[x][y]==3)
   {
   	anteriorX=x;
   	anteriorY=y;
   }
   
   if(mapa[x][y]==2)
   {
    rabox=x;
    raboy=y;
   }
  }
 }
 
 
 while(movimentos<100)//Quantidade de movimentos que a cobrinha vai realizar
 {
  movimentou=1;
  while(movimentou!=0)
  {
   possibilidade=0;
   X= rand() % 20;
   Y= rand() % 30; 
   
   var1=antx+1;
   var2=antx-1;
   if((X==var1)||(X==var2))
   {
   	var1=anty+1;
   	var2=anty-1;
   	if((Y==var1)||(Y==var2))
   	{
   	 if(mapa[X][Y]==0)
	  possibilidade=1; 
	}
   }
   
   if((mapa[X][Y]==0)&&(possibilidade==1))
   {
    mapa[rabox][raboy]=0;   
    mapa[anteriorX][anteriorY]=2;
    mapa[antx][anty]=3;
    mapa[X][Y]=4;
    rabox=anteriorX;
    raboy=anteriorY;
    anteriorX=antx;
    anteriorY=anty;
	antx=X;
    anty=Y;
    movimentou=0;
   } 
   
  }
  impressao(mapa);
  Sleep(400);
  system("cls");
  movimentos++; 
 }
 impressao(mapa);
}

/*Comentarios: Professor, tive dificuldades pra conseguir fazer esse exercicio, principalmente pra dar um longo comprimento pra cobra e na parte
  do programa finalizar ao pressionar qualquer tecla, entao coloquei um laço pra mostrar 100 movimentos! Para execução: 4 representa a cabeça da
  cobrinha, 3 o pescoço e 2 o rabinho, eu troquei os caracteres pra exibir na tela representando a cobrinha pra ficar mais facil de visualizar!*/

int impressao(int mapinha[20][30]) //Funcao para aparecer na tela o cercado e a cobrinha
{
 int x,y;
 for(x=0; x<20; x++)
 {
  for(y=0; y<30; y++)
  {
   if(mapinha[x][y]==0)
    printf("  ");
    
   if(mapinha[x][y]==1)
    printf("[]");
    
   if(mapinha[x][y]==2)
    printf("-=");
  
   if(mapinha[x][y]==3)
    printf("==");
    
   if(mapinha[x][y]==4)
    printf("=©");
  }
 printf("\n");
 }	
}
