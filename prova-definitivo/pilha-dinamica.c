#include <stdio.h>
#include <stdlib.h>

struct no{
	int dado;
	struct no *prox;
};

struct no *inserir(struct no *t, int novo)
{
	struct no *aux;
	aux = (struct no *) malloc(sizeof(struct no));
	aux->dado = novo;
	aux->prox = t;
	t = aux;
	return(t);
}

struct no *remover(struct no *t)
{
	struct no *aux;
	aux = t;
	t = t->prox;
	free(aux);
	return(t);
}

void percurso(struct no *t)
{
	while (t != NULL)
	  {
	  	printf("\n%x - %d - %x\n",t,t->dado,t->prox);
	  	t = t->prox;
	  }
}

main()
{
	struct no *topo = NULL;
	int opcao = 0, novo;
	while(opcao != 4)
	{
		system("cls");
		printf("DIGITE A SUA OPCAO:\n1- INSERIR\n2- REMOVER\n3- PERCURSO\n4- SAIR\n");
		scanf("%d",&opcao);
		switch(opcao)
		{
			case 1: printf("\nQUAL O NOVO ELEMENTO DA PILHA? ");
			        scanf("%d",&novo);
			        topo = inserir(topo,novo);
					break;
			case 2: if (topo == NULL)
			           printf("\nA PILHA ESTA VAZIA!!!");
			        else
			        {
			        	topo = remover(topo);
					}
			        break;
			case 3: if (topo == NULL)
			           printf("\nA PILHA ESTA VAZIA!!!");
			        else
			        {
			        	percurso(topo);
			        	system("pause");
					}
			        break;
			case 4: printf("FIM DO PROGRAMA!!!");
			        break;
			default: printf("\nVOCE DIGITOU UMA OPCAO INVALIDA!!!");
		}
	}
}
