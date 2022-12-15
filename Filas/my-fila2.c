#include <stdio.h>
#define TAM 5

int main(){
   int fila[TAM], opcao, indice = -1, x;

   do{
      printf("\nDigite uma opcao:\n");
      printf("1- INSERIR\n");
      printf("2- REMOVER\n");
      printf("3- PERCURSO\n");
      printf("4- SAIR\n");
      scanf("%d", &opcao);

      switch(opcao){
         case 1:
            if(indice == TAM-1){
               printf("\nIMPOSSIVEL INSERIR, FILA CHEIA");
            }else{
               printf("\nQUAL O ELEMENTO A SER INSERIDO?: ");
               indice++;
               scanf("%d", &fila[indice]);
            }
            break;

         case 2:
            if(indice == -1){
               printf("\nIMPOSSIVEL REMOVER, FILA VAZIA");
            }else if(indice == 0){
               indice = -1;
            }else{
               for(x = 0; x < indice; x++){
                  fila[x] = fila[x+1];
               }
               indice--;
            }
            break;

         case 3:
            if(indice == -1){
               printf("\nA FILA ESTÁ VAZIA");
            }else{
               printf("\nFILA ATUAL: ");
               for(x = 0; x <= indice; x++){
                  printf("%d - ", fila[x]);
               }
               printf("\b\b");
            }
            break;

         case 4:
            printf("\nSAINDO DO ALGORITMO\n");
            break;

         default: printf("\nOPCAO DIGITADA INVALIDA\n");
      }
   }while(opcao != 4);

   return 0;
}
