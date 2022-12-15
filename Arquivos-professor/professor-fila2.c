#include <stdio.h>
//#include <conio.h>
#define TAM 5

int main()
{
	int fila[TAM], inicio, fim, i, j, novo, opcao;
	inicio = -1;
	fim = -1;
	opcao = 0;
    do{
	   printf("Digite uma opcao:\n 1- INSERIR\n 2- REMOVER\n 3- PERCURSO\n 4- SAIR ");
	   scanf("%d", &opcao);
	   switch(opcao){
		   case 1: printf("\nQUAL O ELEMENTO A SER INSERIDO?");
		           scanf("%d",&novo);
		           if(inicio == -1)
		           {
					   inicio = 0;
					   fim = 0;
					   fila[fim] = novo;
				   }
		        else if(fim == TAM-1)
		           {
					printf("\nIMPOSSIVEL INSERIR!!! FILA CHEIA!!!");
				   }
		       else
		          {
					  fim++;
					  fila[fim] = novo;
		          }
			   break;
		   case 2: if(inicio == -1)
		   			{
			   		printf("\nIMPOSSIVEL REMOVER!!! FILA VAZIA!!!");
		   			}
		           else if(fim == 0)
 		   			{
					   inicio = -1;
					   fim = -1;
  				    }
		          else
		   			{
					   for(i=0;i<=fim;i++)
							   fila[i] = fila[i+1];
					   fim--;
		   			}
			    break;
		   case 3: if(inicio == -1)
			          printf("\nA FILA ESTA VAZIA!!!");
		   			else
		   			{
						  printf("\nFILA ATUAL: ");
						  for(i = 0;i <= fim; i++)
							  printf("%d - ", fila[i]);
						  printf("\b\b");
					 }
			   break;
		   case 4: printf("SAIR DO ALGORITMO");
		       break;
		   default: printf("OPCAO INVALIDA");
	   }
    }while(opcao !=4);

return 0;
}

