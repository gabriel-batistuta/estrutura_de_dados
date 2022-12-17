/*************************************************/
/*	       ALGORITMO BASE DA �RVORE AVL			     */
/*        DISCIPLINA: ESTRUTURA DE DADOS         */
/*           ANO/SEMESTRE: 2022.1                */
/*  FUN��ES IMPLEMENTADAS: INSER��O E PERCURSOS  */
/*   O QUE FALTA? REMO��O, ALTURA E QUANTIDADE   */
/*************************************************/

#include <stdio.h>
#include <stdlib.h>

// definindo que comando usar para PAUSAR a tela a depender do sistema operacional do usuario
#ifdef WIN32 || WIN64
#define PAUSE "Windows" /* Se for Windows retorne [Windows] como uma variavel pra ser usada posteriormente */
#else
#define PAUSE "Linux" /* Se for != de Windows retorne [Linux] como uma variavel pra ser usada posteriormente */
#endif

// definindo que comando usar para LIMPAR a tela a depender do sistema operacional do usuario
#ifdef WIN32 || WIN64
#define LimpaTela "Windows" /* Se for Windows retorne [Windows] como uma variavel pra ser usada posteriormente */
#else
#define LimpaTela "Linux" /* Se for != de Windows retorne [Linux] como uma variavel pra ser usada posteriormente */
#endif

struct no{
   int dado, bal;
   struct no *dir, *esq;
}; int h;

void pre(struct no *r){
   printf("%d ", r->dado);
   if(r->esq != NULL){
      pre(r->esq);
   }
   if(r->dir != NULL){
      pre(r->dir);
   }
}

void sim(struct no *r){
   if(r->esq != NULL){
      sim(r->esq);
   }
   printf("%d ", r->dado);
   if(r->dir != NULL){
      sim(r->dir);
   }
}

void pos(struct no *r){
   if(r->esq != NULL){
      pos(r->esq);
   }
   if(r->dir != NULL){
      pos(r->dir);
   }
   printf("%d ", r->dado);
}

struct no *caso1(struct no *r){
   struct no *ptu, *ptv;
   ptu = r->esq;

   if(ptu->bal == -1){
      r->esq = ptu->dir;
      ptu->dir = r;
      r->bal = 0;
      r = ptu;

   }else{
      ptv = ptu->dir;
      ptu->dir = ptv->esq;
      ptv->esq = ptu;
      r->esq = ptv->dir;
      ptv->dir = r;

      if(ptv->bal == -1){
         r->bal = 1;
      }else{
         r->bal = 0;
      }

      if(ptv->bal == 1){
         ptu->bal = -1;
      }else{
         ptu->bal = 0;
      }

      r = ptv;
   }
   r->bal = 0;
   h = 1;
   return r;
}

struct no *caso2(struct no *r){
   struct no *ptu, *ptv;
   ptu = r->dir;

   if(ptu->bal == 1){
      r->dir = ptu->esq;
      ptu->esq = r;
      r->bal = 0;
      r = ptu;
   }else{
      ptv = ptu->esq;
      ptu->esq = ptv->dir;
      ptv->dir = ptu;
      r->dir = ptv->esq;
      ptv->esq = r;

      if(ptv->bal == 1){
         r->bal = -1;
      }else{
         r->bal = 0;
      }

      if(ptv->bal == -1){
         ptu->bal = 1;
      }else{
         ptu->bal = 0;
      }

      r = ptv;
   }
   r->bal = 0;
   h = 1;
   return r;
}

struct no *inserir(struct no *r, int n){
   if(r == NULL){
      r = (struct no *)malloc(sizeof(struct no));
      r->dado = n;
      r->esq = NULL;
      r->dir = NULL;
      r->bal = 0;
      h = 0;

   }else if(r->dado == n){
      printf("O elemento já existe\n");

   }else if(n < r->dado){
      r->esq = inserir(r->esq, n);
      printf("Esquerdo - valor: %d - Balanceamento: %d - h: %d\n", r->dado, r->bal, h);
      if(h == 0){
         switch(r->bal){
            case 1:
               r->bal = 0;
               h = 1;
               break;
            case 0:
               r->bal = -1;
               break;
            case -1:
               r = caso1(r);
               break;
         }
         printf("Esquerdo - valor: %d - Balanceamento: %d - h: %d\n", r->dado, r->bal, h);
      }

   }else{
      r->dir = inserir(r->dir, n);
      printf("Direito - valor: %d - Balanceamento: %d - h: %d\n", r->dado, r->bal, h);
      if(h == 0){
         switch(r->bal){
            case -1:
               r->bal = 0;
               h = 1;
               break;
            case 0:
               r->bal = 1;
               break;
            case 1:
               r = caso2(r);
               break;
         }
         printf("Direito - valor: %d - Balanceamento: %d - h: %d\n", r->dado, r->bal, h);
      }
   }
   return r;
}

int existencia(struct no *r, int n){
   int bool = 0;

   if(r->dado == n){
      bool = 1;
   }else{
      if(r->dir != NULL){
         bool = existencia(r->dir, n);
      }
      if(r->esq != NULL){
         bool = existencia(r->esq, n);
      }
   }

   return bool;
}

struct no *remover(struct no *r, int n){
   struct no *p1, *p2;

   if(r->dado == n){
      if(r->esq == r->dir){
         free(r);
         return NULL;

      }else if(r->esq == NULL){
         p1 = r->dir;
         free(r);
         return p1;

      }else if(r->dir == NULL){
         p1 = r->esq;
         free(r);
         return p1;

      }else{
         p2 = r->dir;
         p1 = r->dir;

         while(p1->esq != NULL){
            p1 = p1->esq;
         }

         p1->esq = r->esq;
         free(r);
         return p2;
      }

   }else if(r->dado < n){
      r->dir = remover(r->dir, n);
   }else{
      r->esq = remover(r->esq, n);
   }

   return r;
}

void desenho(struct no *r, int alt, int n){
   int n_dir = 0, n_esq = 0, quant = 1;

   if(r->esq != NULL){
      desenho(r->esq, alt-1, n);
   }
   if(r->dir != NULL){
      desenho(r->dir, alt-1, n);
   }

   if(n_dir >= n_esq){
      quant += n_dir;
   }else{
      quant += n_esq;
   }

   if(quant == alt){
      for(int x = 0; x < n; x++){
         printf(" ");
      }

      printf("(%d)", r->dado);
      if(PAUSE=="Windows") {
         // PAUSE para sistema [Windows]
         system("pause");
      } else {
         // PAUSE para sistema [Linux]
         system("read -p \"\n(Pressione enter para sair...)\" saindo");
      }
   }
}

int altura(struct no *r){
   int n_esq = 0, n_dir = 0, num;

   if(r->esq != NULL){
      n_esq = altura(r->esq);
   }
   if(r->dir != NULL){
      n_dir = altura(r->dir);
   }

   if(n_esq >= n_dir){
      num = n_esq;
   }else{
      num = n_dir;
   }

   return num + 1;
}

int qtde(struct no *r){
   int n_esq = 0, n_dir = 0, quant = 1;

   if(r->esq != NULL){
      n_esq = qtde(r->esq);
   }
   if(r->dir != NULL){
      n_dir = qtde(r->dir);
   }

   quant += n_esq + n_dir;
   return quant;
}

int main(){
   struct no *raiz = NULL;
   int novo, opcao;

   do{
      printf("Digite a opcao\n");
      printf("1- Inserir\n");
      printf("2- Remover\n");
      printf("3- Percurso em pre ordem\n");
      printf("4- Percurso em ordem simetrica\n");
      printf("5- Percurso em pos ordem\n");
      printf("6- Percuso desenhado\n");
      printf("7- Altura da arvore\n");
      printf("8- Quantidade de elementos\n");
      printf("9- Sair\n");
      scanf("%d", &opcao);

      switch(opcao){
         case 1:
            printf("Qual elemento a ser inserido?: ");
            scanf("%d", &novo);
            raiz = inserir(raiz, novo);
            break;
         case 2:
         if(raiz == NULL){
            printf("Não é possivel remover, a arvore não existe!\n");
         }else{
            printf("Qual elemento deseja remover?: ");
            scanf("%d", &novo);

            if(existencia(raiz, novo) == 1){
               raiz = remover(raiz, novo);
            }else{
               printf("O elemento não existe!\n");
            }

         }

         break;
         case 3:
            if(raiz == NULL){
               printf("Arvore não existe!\n");
            }else{
               pre(raiz);
               printf("\n");
            }
            break;
         case 4:
            if(raiz == NULL){
               printf("Arvore não existe!\n");
            }else{
               sim(raiz);
               printf("\n");
            }
            break;
         case 5:
            if(raiz == NULL){
               printf("Arvore não existe!\n");
            }else{
               pos(raiz);
               printf("\n");
            }
            break;
         case 6:
            if(raiz == NULL){
               printf("Arvore não existe\n");
            }else{
               novo = altura(raiz);

               //falta descobrir um padrão de decremento adequando para y
               for(int x = 1, y = novo * 2; x <= novo && y > 0; x++, y/= 2){
                  desenho(raiz, x, y);
                  printf("\n");
               }
            }
            break;
         case 7:
            if(raiz == NULL){
               printf("Arvore não existe\n");
            }else{
               novo = altura(raiz);
               //reutilização da variavel novo
               printf("A altura da arvore é: %d\n", novo);
               //elaborar uma mensagem melhor pra altura da arvore
            }
            break;
         case 8:
            if(raiz == NULL){
               printf("Arvore não existe\n");
            }else{
               novo = qtde(raiz);
               printf("A arvore tem %d elemento(s)\n", novo);
            }
            break;
         case 9:
            printf("Saindo do programa\n");
            break;
         default: printf("Opcao invalida!\n");
      }
      if(opcao != 9){
         if(LimpaTela == "Linux"){
            system("read -p \"Precione a tecla Enter para continuar\"\n");
            system("clear");
         }else{
            system("pause");
            // system(SYS);
         }
      }

   }while(opcao != 9);

   return 0;
}
