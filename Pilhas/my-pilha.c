#include <stdio.h>
#define TAM 5

int main(){
   int fila[TAM], opcao = 0, end = -1, i, new;

   do{
      printf("Digite uma opcao:\n");
      printf("1- INSERIR\n");
      printf("2- REMOVER\n");
      printf("3- PERCURSO\n");
      printf("4- SAIR\n");
      scanf("%d", &opcao);

      switch(opcao){
         case 1:
            printf("\nQUAL ELEMENTO A SER INSERIDO: ");
            scanf("%d", &new);
            if(end == -1){
               end = 0;
               fila[end] = new;
            }else if(end == TAM-1){
               printf("\nIMPOSSIVEL INSERIR!!! PILHA CHEIA!!!");
            }else{
               end++;
               fila[end] = new;
            }
            break;

         case 2:
            if(end == -1){
               printf("\nIMPOSSIVEL REMOVER!!! PILHA VAZIA!!!");
            }else if(end == 0){
               end = -1;
            }else{
               end--;
            }
            break;

         case 3:
            if(end == -1){
               printf("\nA PILHA ESTA VAZIA!!!");
            }else{
               printf("\nPILHA ATUAL: ");
               for(i = 0; i <= end; i++){
                  printf("%d - ", fila[i]);
               }
               printf("\b\b");
            }
            break;

         case 4:
            printf("SAIR DO ALGORITMO");
            break;

         default: printf("OPCAO INVALIDA");
      }

   }while(opcao != 4);

   return 0;
}
