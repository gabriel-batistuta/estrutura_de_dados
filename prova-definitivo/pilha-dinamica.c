#include <stdio.h> // biblioteca da linguagem C para entrada e saida de dados.
#include <stdlib.h> // biblioteca da linguagem C que possui funções envolvendo alocação de memória, controle de processos, conversões e outras.

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

// definindo o tipo de variavel que será utilizada como dado da pilha
struct no {
	// ELEMENTO: [INT - dado, ponteiro - NEXT]
	int dado;
	struct no *prox;
};

// definindo a função que INSERE elementos na pilha
struct no *inserir(struct no *t, int novo) {
	struct no *aux; // definindo um ponteiro auxiliar para ajudar no script
	aux = (struct no *) malloc(sizeof(struct no)); // alocando um espaço de memória do tamanho do tipo NO e definindo como ponteiro do tipo NO
	aux->dado = novo; // [dado] do auxiliar recebe o novo elemento
	aux->prox = t; // [next] do auxiliar recebe TOPO
	t = aux; // TOPO = auxiliar 
	return(t); // retornando TOPO que será utilizada por mais funções
}

// definindo a função que REMOVE elementos da pilha
struct no *remover(struct no *t) {
	struct no *aux; // definindo um ponteiro auxiliar para ajudar no script
	aux = t; // auxiliar recebe TOPO
	t = t->prox; // TOPO = o valor do next(que é a variavel que é o proximo valor da pilha)
	free(aux); // liberando do espaço de memória a variavel [aux]
	return(t); // retornando TOPO que será utilizada por mais funções
}

// definindo a função que IMPRIME e PERCORRE a pilha
void percurso(struct no *t) {
	while (t != NULL) {
		// Enquanto o TOPO for DIFERENTE de NULO continua imprimindo o endereço do topo, dado do topo e endereço do proximo topo 
	  	printf("\n%x - %d - %x\n",t,t->dado,t->prox);
	  	t = t->prox; // Mundando o valor do topo para proximo valor da pilha

		// o topo só muda aqui nessa função pra percorrer e mostrar ao usuario
	}
}

main() {
	struct no *topo = NULL; // definindo topo da pilha como nulo no inicio do programa pois não tem nenhum ainda
	int opcao = 0, novo; // declaração de variaveis novo pra armazenar o valor digitado pelo usuario e opcao para definir que função fazer
	while(opcao != 4) {
		if(LimpaTela=="Windows") {
			// LimparTela para sistema [Windows]
			system("Windows");
		} else {
			// LimparTela para sistema [Linux]
			system("clear");
		}
		// opções do programa
		printf("DIGITE A SUA OPCAO:\n1- INSERIR\n2- REMOVER\n3- PERCURSO\n4- SAIR\n");
		scanf("%d",&opcao);
		switch(opcao) {
			// case 1 - INSERIR ELEMENTO

			/*
				insere um novo elemento TOPO digitado pelo usuario
			*/
			case 1: printf("\nQUAL O NOVO ELEMENTO DA PILHA? ");
			        scanf("%d",&novo);
			        topo = inserir(topo,novo);
					break;
			// case 2 - REMOVER

			/*
				se o topo for NULO é retornado que a pilha não tem elementos
			*/
			case 2: if (topo == NULL)
			           printf("\n[A PILHA VAZIA!!!]\n");
			        else
			        {
			        	topo = remover(topo);
					}
			        break;
			/* case 3 - MOSTRAR PERCURSO
			
				se o topo for nulo, informa que a pilha esta vazia.
				senão, mostra o percurso de elementos e espera o usuario apertar ENTER pra voltar a pedir comandos
			*/
			case 3: if (topo == NULL)
			           printf("\nA PILHA ESTA VAZIA!!!");
			        else {
			        	percurso(topo);
			        	if(PAUSE=="Windows") {
							// PAUSE para sistema [Windows]
							system("pause");
						} else {
							// PAUSE para sistema [Linux]
							system("read -p \"\n[Pressione enter para sair...]\" saindo");
						}
					}
			        break;
			/*
				case 4 - SAIR DO PROGRAMA

				sai do switch, terminando o programa
			*/
			case 4: printf("\n[FIM DO PROGRAMA]!!!\n");
			        break;
			/*
				case 5 - OPÇÂO SOLICITADA BÉ INVALIDA

				informa pro usuario que a opção é invalida e solicita novamente uma opção
			*/
			default: printf("\n[VOCE DIGITOU UMA OPCAO INVALIDA!!!]\n");
		}
	}
}
