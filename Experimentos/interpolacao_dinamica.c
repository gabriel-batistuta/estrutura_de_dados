#include <stdio.h>
#include <stdlib.h>
//#include <time.h>

struct no {
   int dado;
   struct no *ante, *prox;
}
int tam = 0;

struct no *inserir(struct *i, int elemt) {
   struct no *atual = i, *novo_no;
   novo_no = (struct no *)malloc(sizeof(struct no));
   novo_no->dado = elemt;
   novo_no->ante = NULL;
   novo_no->prox = NULL;

   while (atual != NULL && atual->prox != NULL) {
      atual = atual->prox;
   }

   if (atual != NULL) {
      atual->prox = novo_no;
      novo_no->ante = atual;
      tam += 1;
   }else {
      i = novo_no;
   }

   return i;
}

void listar(struct no *i) {
   while(i != NULL){
      print("#d, ", atual->dado);
      atual = atual->prox;
   }
   printf("\b");
}

void busca_linear(struct no *i, int elemt) {
   int posic = -1;
   int status = 0;

   while (i != NULL) {
      i = i->prox;
      if(i->dado == elemt){
         printf("O elemento %d está na posicao %d\n", i->dado, posic);
         status = 1;
         break;
      }
      posic += 1;
   }

   if (posic == 0) {
      printf("O elemento %d não existe\n", elemt);
   }
}

void busca_interpolacao(struct no *i, int elemt) {
   //qual a formula da busca por interpolacao?
}

int main() {
   struct no *inicio = NULL;
   int elemt, op;

   do {
      printf("Escolha uma opcao:\n");
      printf("1- Inserir elemento\n");
      printf("2- Remover primeiro elemento\n")
      printf("3- Mostrar elementos\n");
      printf("4- Buscar elemento (busca linear)\n");
      printf("5- Buscar elemento (busca interpolacao)\n");
      printf("6- Sair\n");
      scanf("%d", &op);

      switch (op) {
         case 1:
            if (inicio == NULL) {
               print("A lista está vazia!\n")
            }else {
               printf("Qual o olemento a ser inserido?: ");
               scanf("%d", &elemt);
               inicio = inserir(inicio, elemt);
            }
            break;

         case 2:
            break;

         case 3:
            if (inicio == NULL) {
               printf("A lista está vazia!\n");
            }else {
               listar(inicio);
            }
            break;

         case 4:
            if (inicio == NULL) {
               printf("A lista está vazia!\n");
            }else {
               printf("Qual elemento deseja buscar?: ");
               scanf("%d", &elemt);
               busca_linear(inicio, elemt);
            }
            break;

         case 5:
            break;

         case 6:
            break;

         default:
            print("Opcao escolhida invalida!\n");
      }
   }while(op != 6);

   return 0;
}
