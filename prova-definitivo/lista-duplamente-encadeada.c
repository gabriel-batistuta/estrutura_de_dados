
//            Lista Duplamente Encadeada

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

// definindo struct NO[<-anterior,valor,->proximo]
typedef struct no{
    int valor;
    struct no *proximo;
    struct no *anterior;
}No;

// Função para inserir no início da Lista
void inserir_no_inicio(No **lista, int num){
    No *novo = malloc(sizeof(No)); // ponteiro NOVO do NO = alocamento de memoria do tamanho da struct

    if(novo) { // se houver uma var 'novo'
        // código pra criar o novo elemento no inicio da lista
        novo->valor = num; 
        novo->proximo = *lista; // valor de proximo = ponteiro de lista
        novo->anterior = NULL; 
        if(*lista) { 
            (*lista)->anterior = novo; // anterior de ponteiro de lista = novo
        }
        *lista = novo; // ponteiro de lista = novo
    } else { // senão, mostre uma mensagem de ERRO
        printf("Erro ao alocar memoria!\n");
    }
}

// função para INSERIR NO FIM DA LISTA
void inserir_no_fim(No **lista, int num){
    No *aux, *novo = malloc(sizeof(No));

    if(novo) { // se houver uma var 'novo'
        novo->valor = num;
        novo->proximo = NULL;

        // é o primeiro elemento? se for, o ponteiro da lista aponta pra ele e seu anteriror recebe NULO ['VALOR', 'anterior' -> NULL]
        if(*lista == NULL){
            *lista = novo;
            novo->anterior = NULL;
        }
        else{
            // senão for o primeiro elemento, aux varre a lista até que chegue ao fim e faça o novo elemento no final da lista
            aux = *lista;
            while(aux->proximo != NULL) {
                aux = aux->proximo;
            }
            aux->proximo = novo;
            novo->anterior = aux;
        }
    } else { // senão houver um novo elemento imprima ERRO
        printf("Erro ao alocar memoria!\n");
    }
}


// função para REMOVER UM ELEMENTO ESCOLHIDO DA LISTA
No* remover(No **lista, int num){
    No *aux, *remover = NULL;

    if(*lista){ // se houver um ponteiro de topo 
        if((*lista)->valor == num){
            remover = *lista;
            *lista = remover->proximo; 
            if(*lista) {
                (*lista)->anterior = NULL; // anterior de lista = NULL
            }
        }
        else{
            aux = *lista;
            while(aux->proximo && aux->proximo->valor != num) {
                // varrendo a lista se o NO do proximo for diferente de num 
                aux = aux->proximo;
            }
            
            if(aux->proximo){
                // definindo que elemento será removido
                remover = aux->proximo;
                aux->proximo = remover->proximo;
                if(aux->proximo) {
                    aux->proximo->anterior = aux;
                }
            }
        }
    }
    return remover;
}

// função para BUSCAR E INFORMAR SE HÁ um elemento na lista
No* buscar(No **lista, int num){
    No *aux, *no = NULL;

    aux = *lista;
    while(aux && aux->valor != num) {
        // enquanto o auxiliar e seu valor forem diferentes de num:
        // receba o proximo ELEMENTO
        aux = aux->proximo;
    }

    if(aux) {
        // se houver um auxiliar no = auxiliar
        no = aux;
    }
    return no;
}

// função para IMPRIMIR elementos da lista
void imprimir(No *no){
    printf("\nESTRUTURA: ['1', '2', '3', ..., '33']\n");
    printf("\n\tLista: [");
    // enquanto o elemento 'NO' for diferente de NULO imprima o valor do 'NO'
    // e dps pra incrementar o laço de repetição do 'NO' ele recebe o próximo 'NO'
    while(no != NULL /* NULL or ['\0'] */){
        printf("'%d', ", no->valor);
        no = no->proximo;
    }
    printf("\b\b]\n\n"); // formatação para imprimir elementos mais bonito
}

// retorna ponteiro para o último nó da lista
No* ultimo(No **lista){
    No *aux = *lista;
    while(aux->proximo) {
        // loop pro ponteiro retornar pro ultimo NO
        aux = aux->proximo;
    }
    return aux;
}

int main(){

    int opcao, valor, anterior;
    No *removido, *lista = NULL;

    do{
        // IMPRIME AS OPÇÕES QUE O USUARIO QUER FAZER E PEDE A QUE ELE QUER
        printf("\n0 - Sair\n1 - Inserir no Inicio\n2 - inserir no Fim\n3 - Remover\n4 - Imprimir\n5 - Buscar\n");
        scanf("%d", &opcao);
        switch(opcao) {
        case 1: // INSERIR NO INICIO
            printf("Digite um valor: ");
            scanf("%d", &valor);
            inserir_no_inicio(&lista, valor);
            if(PAUSE=="Windows") {
                // PAUSE para sistema [Windows]
                system("pause");
            } else {
                // PAUSE para sistema [Linux]
                system("read -p \"\n(Pressione enter para sair...)\" saindo");
            }
            if(LimpaTela=="Windows") {
			// LimparTela para sistema [Windows]
			system("Windows");
            } else {
                // LimparTela para sistema [Linux]
                system("clear");
            }
            break;
        case 2: // INSERIR NO FIM
            printf("Digite um valor: ");
            scanf("%d", &valor);
            inserir_no_fim(&lista, valor);
            if(PAUSE=="Windows") {
                // PAUSE para sistema [Windows]
                system("pause");
            } else {
                // PAUSE para sistema [Linux]
                system("read -p \"\n(Pressione enter para sair...)\" saindo");
            }
            if(LimpaTela=="Windows") {
			// LimparTela para sistema [Windows]
			system("Windows");
            } else {
                // LimparTela para sistema [Linux]
                system("clear");
            }
            break;
        case 3: // REMOVER ELEMENTO
            printf("Digite um valor a ser removido: ");
            scanf("%d", &valor);
            removido = remover(&lista, valor);
            if(removido) {
                // imprime elemento e o libera da memoria
                printf("Elemento a ser removido: %d\n", removido->valor);
                free(removido);
                if(PAUSE=="Windows") {
                    // PAUSE para sistema [Windows]
                    system("pause");
                } else {
                    // PAUSE para sistema [Linux]
                    system("read -p \"\n(Pressione enter para sair...)\" saindo");
                }
                if(LimpaTela=="Windows") {
                // LimparTela para sistema [Windows]
                system("Windows");
                } else {
                    // LimparTela para sistema [Linux]
                    system("clear");
                }
            }
            else {
                // elemento não encontrado na lista
                printf("Elemento inexistente!\n");
                if(PAUSE=="Windows") {
                    // PAUSE para sistema [Windows]
                    system("pause");
                } else {
                    // PAUSE para sistema [Linux]
                    system("read -p \"\n(Pressione enter para sair...)\" saindo");
                }
                if(LimpaTela=="Windows") {
                // LimparTela para sistema [Windows]
                system("Windows");
                } else {
                    // LimparTela para sistema [Linux]
                    system("clear");
                }
            }
            break;
        case 4: // IMPRIME A LISTA
            imprimir(lista);
            if(PAUSE=="Windows") {
                // PAUSE para sistema [Windows]
                system("pause");
            } else {
                // PAUSE para sistema [Linux]
                system("read -p \"\n(Pressione enter para sair...)\" saindo");
            }
            if(LimpaTela=="Windows") {
			// LimparTela para sistema [Windows]
			system("Windows");
            } else {
                // LimparTela para sistema [Linux]
                system("clear");
            }
            break;
        case 5: // BUSCA E INFORMA SE HÁ ESSE VALOR NA LISTA, SENÃO HOUVER IMPRIMA QUE NÃO FOI ENCONTRADO
            printf("Digite um valor a ser buscado: ");
            scanf("%d", &valor);
            removido = buscar(&lista, valor);
            if(removido) {
                printf("Elemento encontrado: %d\n", removido->valor);
                if(LimpaTela=="Windows") {
                // LimparTela para sistema [Windows]
                system("Windows");
                } else {
                    // LimparTela para sistema [Linux]
                    system("clear");
                }
            } else {
                printf("Elemento nao encontrado!\n");
                if(PAUSE=="Windows") {
                    // PAUSE para sistema [Windows]
                    system("pause");
                } else {
                    // PAUSE para sistema [Linux]
                    system("read -p \"\n(Pressione enter para sair...)\" saindo");
                }
                if(LimpaTela=="Windows") {
                // LimparTela para sistema [Windows]
                system("Windows");
                } else {
                    // LimparTela para sistema [Linux]
                    system("clear");
                }
            }
            break;
        default: // mensagem de erro pra quando for inserido uma opção invalida
            if(opcao != 0) {
                printf("Opcao invalida!\n");
            }
        }

    } while(opcao != 0); // condição pra sair do programa é ser != 0, senão for sair do loop do programa

    return 0;
}