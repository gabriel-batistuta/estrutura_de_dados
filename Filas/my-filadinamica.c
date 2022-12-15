#include <stdio.h>
#include <stdlib.h>

struct no{
   int dado;
   struct no *prox;
};

struct no *inserir(struct no *i, int novo){
   struct no *atual = i, *novo_no;
   novo_no = (struct no *)malloc(sizeof(struct no));
   novo_no->dado = novo;
   novo_no->prox = NULL;

   while(atual != NULL && atual->prox != NULL){
      atual = atual->prox;
   }

   if(atual != NULL){
      atual->prox = novo_no;
   }else{
      i = novo_no;
   }

   return i;
}

struct no *remover(struct no *i){
   struct no *aux;
	aux = i;
	i = i->prox;
	free(aux);
	return i;
}

void percurso(struct no *i){
   printf("Fila atual: ");

   while(i != NULL){
      printf("%d - ", i->dado);
      i = i->prox;
   }
   printf("fim");
}

int main(){
   struct no *inicio = NULL;
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
            if(inicio == NULL){
               printf("A fila esta vazia\n");
            }else{
               inicio = remover(inicio);
            }
            break;

         case 3:
            if(inicio == NULL){
               printf("A fila esta vazia\n");
            }else{
               percurso(inicio);
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
