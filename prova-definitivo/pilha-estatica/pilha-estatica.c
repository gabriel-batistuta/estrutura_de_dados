#include <stdio.h>
#define TAM 5

int main(){
   int pilha[TAM], opcao, index = -1, x; // x é usada na iteração dos laços for

   do{
      printf("\nDigite uma opcao:\n");
      printf("1- INSERIR\n");
      printf("2- REMOVER\n");
      printf("3- PERCURSO\n");
      printf("4- SAIR\n");
      printf("opcao: ");
      scanf("%d", &opcao);

      switch(opcao){
         case 1:
            if(index == TAM-1){ // verifica se a pilha não está cheia antes que o usuario digite o elemeto
               printf("\nIMPOSSIVEL INSERIR, PILHA CHEIA\n");
            }else{ // se não estiver cheia, solicita o elemento ao usuario 
               printf("\nQUAL O ELEMENTO A SER INSERIDO?:\n");
               index++; // o index se desloca para o elemento que o usuario digitar se atribuido no local correto
               scanf("%d", &pilha[index]); // o elemento digitado é atribuido diretamente a pilha
            }
            break;

         case 2:
            if(index < 0){ // se o valor da variavel index for menor que 0, isso significa que a pilha está fazia
               printf("\nIMPOSSIVEL REMOVER, PILHA VAZIA\n");
            }else{
               index--; // na pilha só remove o ultimo elemento, então basta decrementar o index para remover o elemento
            }
            break;

         case 3:
            if(index == -1){ // verifica o index para saber se a pilha está vazia ou não, se não estiver vazia a pilha é percorrida
               printf("\nA PILHA ESTA VAZIA\n");
            }else{
               printf("\nPILHA ATUAL: => ");
               printf("[");
               for(x = 0; x <= index; x++) { // iteração pra imprimir automaticamente na tela cada item da pilha até chegar no valor da variavel index
                  printf("'%d', ", pilha[x]);
               }
               printf("\b\b]\n"); // apaga os dois últimos caracteres impressos na tela: ['SPACE', '-'] pra melhor vizualização do usuario
            }
            break;

         case 4:
            printf("SAINDO DO PROGRAMA...\n"); // digitar 4 faz sair do programa pois não está dentro do escopo do ('Do While'), assim saindo do loop de repetição
            break;

         default: printf("OPCAO INVALIDA\n"); // se o usuario digitar um valor que seja diferente de um numero entre 1 até 4, o loop se repetira
      }
   } while(opcao != 4); // condição para que o programa continue rodando é que seja diferente de [4] (numero de sair)

   return 0;
}
