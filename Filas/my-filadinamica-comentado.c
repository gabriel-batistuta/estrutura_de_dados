#include <stdio.h>
#include <stdlib.h>

struct no{
   int dado;
   struct no *prox;
};

struct no *inserir(struct no *i, int novo){ //o tipo da função referesse ao tipo de dado que ela vai retornar, neste caso vai ser um ponteiro do tipo struct no
   struct no *atual = i, *novo_no; // *atual usaremos para percorrer toda a lista, *novo_no usaremos para receber o endereço da memoria recem alocada
   novo_no = (struct no *)malloc(sizeof(struct no)); // a função malloc retorna o endereço de memoria para um ponteiro do tipo void, depois usamos o parametro de conversão (struct no *) para converter para o tipo que precisamos
   novo_no->dado = novo; // fazemos  dado apontar para a variavel do tipo inteiro chamada novo que está armazenando o nosso elemento
   novo_no->prox = NULL; // fazemos o ponteiro da struct recem alocada apontar para nada, null, porque? por que essa struct ficará no final da lista, e o ponteiro da ultima struct tem que apontar para null para indicar que não existe mais itens depois, é o fim da fila

   while(atual != NULL && atual->prox != NULL){ //este laço faz com que o ponteiro *atual vá para a ultima struct da lista, essa ultima struct tem o ponteiro prox que está apontando para null
      atual = atual->prox; // aqui diz que o ponteiro atual receba o endereço de memoria da proxima struct, esse endereço da proxima struct está guardado em prox
   }

   if(atual != NULL){ //este if verifica se o ponteiro *atual está apontando para alguma struct
      atual->prox = novo_no; //caso seja verdade, ele faz com que o ponteiro da ultima struct aponte para a memoria recem alocada
   }else{ //caso o ponteiro não esteja apontando para lugar nenhum
      i = novo_no; // nós fazemos o ponteiro i, que nesse momento aponta para null, fazemos apontar para a memoria recem alocada
   }

   return i; // retornamos o endereço que ir está apontando, e gurdamos lá naquele ponteiro onde a funnção foi chamada
}

struct no *remover(struct no *i){
   struct no *aux; // esse ponteiro sera usado para pegar o mesmo endereço que i está apontando
	aux = i; // ness momento i e aux estão apontando para a mesma struct
	i = i->prox; //estamos fazendo com que i deixe de apontar para a struct que estava apontando e agora aponte para a proxima struct
	free(aux); //estamos desalocando a memoria que i estava pontando anteriormente, e que comecou a apontar para a struct seguinte
	return i;
}

void percurso(struct no *i){
   printf("Fila atual: ");

   while(i != NULL){ // enquanto não chegar no final da fila, null, o laço continua rodando
      printf("%d - ", i->dado);
      i = i->prox; // i recebe o endereço de memoria do proximo struct, começando do endereço que estava em i até chegar em null
   }
   printf("fim");
}

int main(){
   struct no *inicio = NULL; //na primeira execução do codigo, definimos o ponteiro para null para dizer que ele não está apontando para nada
   int opcao, novo;

   do{
      printf("\nEscolha uma opcao:\n");
      printf("1- Inserir\n");
      printf("2- Remover\n");
      printf("3- Mostrar\n");
      printf("4- Sair\n");
      scanf("%d", &opcao);

      switch(opcao){
         case 1:
            printf("Qual o elemento a ser inserido?: ");
            scanf("%d", &novo);
            inicio = inserir(inicio, novo);
            break;

         case 2:
            if(inicio == NULL){ // perceba que a função remover não verifica se a fila está vazia, esse if que está dentro do switch é quem desepenha o papel, e tambem é ele que direciona para chamar a função
               printf("A fila esta vazia\n");
            }else{
               inicio = remover(inicio);
            }
            break;

         case 3:
            if(inicio == NULL){
               printf("A fila esta vazia\n");
            }else{
               percurso(inicio); // como essa função é do tipo void, que não ha retorno de dados, não atribuimos ela a alguma variavel, chamamos a função diretamente
            }
            break;

         case 4:
            printf("Fim do programa\n");
            break;

         default: printf("Voce digitou uma opcao invalida\n");
      }
   }while(opcao != 4);

   return 0;
}
