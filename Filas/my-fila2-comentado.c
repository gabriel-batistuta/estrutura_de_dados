#include <stdio.h>
#define TAM 5
            // a vantagem de se usar esse simbolo no vetor, é que caso queiramos aumentar ou diminui-lo, basta apenas mudar o valor do simbolo
            // aumentar ou dimnuir vetores estativos só pode ser feito antes da compilação, como é estatico nunca pode ser auterado em tempo de execução
int main(){
   int fila[TAM], opcao, indice = -1, x; //essa variavel x é usada na iteração dos laços for

   do{
      printf("\nDigite uma opcao:\n");
      printf("1- INSERIR\n");
      printf("2- REMOVER\n");
      printf("3- PERCURSO\n");
      printf("4- SAIR\n");
      scanf("%d", &opcao);

      switch(opcao){
         case 1:
            if(indice == TAM-1){ //antes de solicitar ao usuario que digite o elemeto, se verifica se a fila não está cheia
               printf("\nIMPOSSIVEL INSERIR, FILA CHEIA");
            }else{ // caso não esteja cheia, aí sim podemos solicitar ao usuario
               printf("\nQUAL O ELEMENTO A SER INSERIDO?: ");
               indice++; // desloca o indice para o elemnto que o usuario digitar se atribuido no local correto
               scanf("%d", &fila[indice]); // o elemento que o usuario digitou é atribuido diretamente a fila, removendo a necessidade de uma variavel auxiliar
            }
            break;

         case 2:
            if(indice == -1){ //se o valor da variavel indive for menor que 0, isso significa que a fila está fazia, escolhermos indicar isso por -1 apenas para manter um padrão
               printf("\nIMPOSSIVEL REMOVER, FILA VAZIA");
            }else if(indice == 0){
               indice = -1; // mudando o valor do indice para -1, não precisamos remover literalmente o item da fila, ele ainda está lá, mas os itens que importam são os que estão antes do indice do fim
            }else{
               for(x = 0; x < indice; x++){ // como vamos remover o primeiro item da lista, precisamos mover todos os outros itens para o começo da lista
                  fila[x] = fila[x+1]; //caso não quisesse fazer esse procedimento de deslocar os itens, seria necessario uma variavel indicando onde é o começo da fila
               }
               indice--; // apos deslocarmos todos os itens, decremetamos o indice para que ele se posicione no ultimo item da fila
            }
            break;

         case 3:
            if(indice == -1){ // verifica o indice para saber se a fila está vazia ou não, pois não tem necessidade de percorrer a fila se ela estiver vazia
               printf("\nA FILA ESTÁ VAZIA");
            }else{
               printf("\nFILA ATUAL: ");
               for(x = 0; x <= indice; x++){ //iteração imprimindo na tela cada item da nossa fila até chegar no valor da varivel indice
                  printf("%d - ", fila[x]);
               }
               printf("\b\b"); // apaga o ultimo dois ultimos caracteres impressos na tela, não nessesariamente visiveis
            }
            break;

         case 4:
            printf("\nSAINDO DO ALGORITMO\n"); // digitar 4 não satisfaz mais a condição do while, saindo do loop "do while"
            break;

         default: printf("\nOPCAO DIGITADA INVALIDA\n"); // caso o usuario digite um valor que esteja fora do intervalo 1 até 4, o loop se repetirar
      }
   }while(opcao != 4);

   return 0;
}
