/*************************************************/
/*	       ALGORITMO BASE DA ÁRVORE AVL			 */
/*        DISCIPLINA: ESTRUTURA DE DADOS         */
/*           ANO/SEMESTRE: 2022.1                */
/*  FUNÇÕES IMPLEMENTADAS: INSERÇÃO E PERCURSOS  */
/*   O QUE FALTA? REMOÇÃO, ALTURA E QUANTIDADE   */
/*************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <iostream> 

using namespace std;

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

// modelo de struct NO com dado e balanceamento int e ponteiros de subarvores direitas e esquerdas 
struct no {
    int dado, bal;
    struct no* dir, * esq; 
};

// declaração de variaveis globais que são usadas em qualquer luagr do codigo
int h; // para controlar o balanceamento
int contador=0;

// FUNCTION percurso em PRÉ ORDEM//
void pre(struct no* r) {
    cout << r->dado << " ";
    if (r->esq != NULL) //se na esquerda tiver algo
        pre(r->esq); //recursividade com pre ordem
    if (r->dir != NULL)
        pre(r->dir);
}

// FUNCTION percusso em ORDEM SIMETRICA
void sim(struct no* r) { // se for diferente de [NULL] significa que há algo 
    if (r->esq != NULL)//se na esquerda tiver algo
        sim(r->esq);//recursividade com pre ordem
    cout << r->dado << " ";
    if (r->dir != NULL)
        sim(r->dir);
}

// FUNCTION percusso em PÓS ORDEM
void pos(struct no* r) {
    if (r->esq != NULL)//se na esquerda tiver algo
        pos(r->esq);//recursividade com a função pre
    if (r->dir != NULL)
        pos(r->dir);
    cout << r->dado << " ";
}

// se estiver DESBALANCEADO para ESQUERDA
struct no* caso1(struct no* r) {  

    struct no* ptu, * ptv;
    ptu = r->esq; // ptu = valores do lado esquerdo
    if (ptu->bal == -1) // se no balanceamento estiver desbalanceado para o lado esquerdo (que pode ser menor que '0')
    {
        r->esq = ptu->dir; //  o valor do lado direito vai para a esquerda
        ptu->dir = r; // o valor da raiz vai para a direita
        r->bal = 0; // balanceia a raiz
        r = ptu; // a esquerda agora vira raiz
    }
    else // SENÂO
    {
        ptv = ptu->dir; // ptv = direita da esquerda
        ptu->dir = ptv->esq; // o que estava na esquerda da direita agora será o que está na direita da esquerda
        ptv->esq = ptu; // esquerda vai para a esquerda da direita
        r->esq = ptv->dir; //o valor da extrema direita (o maior valor) vai para o lado esquerdo da raiz
        ptv->dir = r; // a raiz vai para a extrema direita
        if (ptv->bal == -1) // se estiver desbalanceado para esquerda
            r->bal = 1; // balanceamento recebe 1 e fica desbalanceado para direita
        else // SENÃO
            r->bal = 0; // balanceado
        if (ptv->bal == 1) // desbalanceado para direita
            ptu->bal = -1; // balanceamento recebe -1 e fica desbalanceado para esquerda
        else // SENÂO
            ptu->bal = 0; // balanceado
        r = ptv; // a raiz será o valor que estava na esquerda
    }
    r->bal = 0; // balanceada
    h = 1; // controle de balanceamento balanceado
    return(r); // retorna o valor da raiz pra ser utilizado em outras funções
}

struct no* caso2(struct no* r) //FUNCTION desbalanceado para direita
{
    struct no* ptu, * ptv;
    ptu = r->dir; // ptv armazena valores do lado direito
    if (ptu->bal == 1) //se no balanceamento dizer que está desbalanceado para o lado direito 
    {
        r->dir = ptu->esq; // esquerda vai para direita
        ptu->esq = r; // raiz vai para a esquerda 
        r->bal = 0; // balanceia
        r = ptu; // direita agora vira raiz
    }
    else // SENÂO
    {
        ptv = ptu->esq; // ptv recebe o que está a esquerda da direita
        ptu->esq = ptv->dir; // o que estava na direita da esquerda agora será o que está na esquerda da direita
        ptv->dir = ptu; // o valor da direita vai para a direita da esquerda
        r->dir = ptv->esq; // o valor da extrema esquerda (o menor valor) vai para o lado direito da raiz
        ptv->esq = r;// o valor da raiz vai para a extrema esquerda
        if (ptv->bal == 1)// se estiver desbalanceado para direita
            r->bal = -1;// balanceamento recebe -1 e fica desbalanceado para esquerda
        else// SENÂO
            r->bal = 0; // balanceado
        if (ptv->bal == -1) // desbalanceado para esquerda
            ptu->bal = 1;// balanceamento recebe 1 e fica desbalanceado para direita
        else // SENÂo
            ptu->bal = 0; // balanceado
        r = ptv; // a raiz será o valor que estava na esquerda
    }
    r->bal = 0; //balanceado
    h = 1; //controle de balanceamento balanceado
    return(r); //retorna um valor da raiz pra ser utilizado por outras funções
}

struct no* inserir(struct no* r, int n) // INSERIR novos ELEMENTOS na arvore
{
    if (r == NULL) // se a raiz for nula
    {

        r = (struct no*)malloc(sizeof(struct no));  //a função malloc aloca espaço memória equivalente ao tamanho da struct e do tipo ponteiro de NO para inserir valores
        r->dado = n; // o valor inserido será o valor da raiz
        r->esq = NULL; //o lado esquerdo da raiz será nulo até ser inserido outro valor menor que a raiz
        r->dir = NULL; //o lado direito da raiz será nulo até ser inserido outro valor maior que a raiz
        r->bal = 0; //balanceia
        h = 0; // controle de balanceiamento 
    }
    else if (n == r->dado)//se o valor novo for igual a um elemento já existente
    {
        cout << "\nELEMENTO JA EXISTE\n";
    }
    else if (n < r->dado)//se o valor novo for menor do que os valores que já existem
    {
        r->esq = inserir(r->esq, n);//inserir o valor no lado esquerdo e realizar demais operações da função através da recursividade
        cout << "\nEsquerdo - Valor: " << r->dado << " - Balanceamento: " << r->bal << " - h: \n" << h;
        if (h == 0) // se o controle de balancemanto quiser testar se necessario o balanceamento, h terá valor 0
        {
            switch (r->bal) // o parametro será o valor do balanceamento
            {
            case 1: r->bal = 0; //caso o valor seja 1, balanceia
                h = 1;//controle de balanceamento balanceado
                break;
            case 0: r->bal = -1;//caso o valor seja 0, colocar desbalanceamento para esquerda
                break;
            case -1: r = caso1(r);//caso o valor seja -1, chama o balanceamento para esquerda
                break;
            }
            cout << "\nEsquerdo - Valor: " << r->dado << "- Balanceamento: " << r->bal << " - h: \n" << h;
        }
    }
    else
    {
        r->dir = inserir(r->dir, n); // inserir o valor no lado direito
        cout << "\nDireito - Valor: " << r->dado << "- Balanceamento: " << r->bal << "- h: \n" << h;
        if (h == 0)//se o controle de balancemanto quiser testar se necessario o balanceamento, h terá valor 0
        {
            switch (r->bal) //o paramqtro será o valor do balanceamento
            {
            case -1: r->bal = 0; // caso o valor seja -1,balanceia
                h = 1; //controle de balanceamento balanceado
                break;
            case 0: r->bal = 1;//caso o valor for 0,colocar desbalanceamento para direita
                break;
            case 1: r = caso2(r);//caso o valor seja 1, chamar o balanceamento para a direita
                break;
            }
            cout << "\nDireito - Valor: " << r->dado << " - Balanceamento: " << r->bal << " - h: \n" << h;
        }
    }
    return (r);//retorna o valor da raiz pra ser utilizado em outras funções
}

no* remover(no* r, int chave) {//função para remover os elementos da arvore
    if (r == NULL) { //se a arvore não tiver nenhum elemento
        cout << "Valor nao encontrado!\n";
        return (NULL); //retornar NULL ou 0
    }
    else {
        if (r->dado == chave) {// se o valor que tiver na árvore for igual ao valor que deseja remover
            if (r->esq == NULL && r->dir == NULL) { // se o valor a ser removido for a raiz
                free(r); // remover o valor da memoria
                return(NULL); // retorna 0
            }
            else {
                if (r->esq != NULL || r->dir != NULL) {
                    no* aux;
                    if (r->esq != NULL)
                        aux = r->esq;
                    else
                        aux = r->dir;
                    free(r);
                    return aux;
                }
                else {
                    no* aux = r->esq;
                    while (aux->dir != NULL)
                        aux = aux->dir;
                    r->dado = aux->dado;
                    aux->dado = chave;
                    r->esq = remover(r->esq, chave);//ele removerá o valor que deseja quando ele terminar de percorre o lado esquerdo através da recursividade
                    return(r);
                }
            }
        }
        else {//caso contrario
            if (chave < r->dado)
                r->esq = remover(r->esq, chave);//ele removerá o valor que deseja quando ele terminar de percorre o lado esquerdo através da recursividade
            else
                r->dir = remover(r->dir, chave);//ele removerá o valor que deseja quando ele terminar de percorre o lado direito através da recursividade
            return(r);
        }
    }
}

int altura(const no* const no_ptr)//função para saber a altura da arvore
{
    //variaveis para alturas
    int altura_esq = 0;
    int altura_dir = 0;

    if (no_ptr->esq)
        altura_esq = altura(no_ptr->esq);

    if (no_ptr->dir)
        altura_dir = altura(no_ptr->dir);

    return max(altura_dir, altura_esq) + 1;//retorna o valor da esquerda e da direita + 1

    cout << altura;
}

void qtde(struct no* r){//função que mostra a quantidade de elementos que existem na arvore
    
	if (r->esq != NULL)//valor reprecisa ser diferente de 0
        qtde(r->esq);
    contador++;//incrementação, aumenta a quantidade de elementos
    if (r->dir != NULL)
        qtde(r->dir);    
}

int main() 
{
    struct no* raiz = NULL;//variável para armazenar valores da árvore
    int novo = 0, opcao = 0; //novo para receber o valor que será inserido ou removido da árvore, opcao para selecionar a operação ou a função desejada
    while (opcao != 8)//laço de repetição das opções de operações
    {
        cout << "\nDigite a opcao:\n1- Inserir\n2- Remover\n3- Percurso em Pre Ordem\n4- Percurso em Ordem Simetrica\n5- Percurso em pos Ordem\n6- Altura da arvore\n7- Quantidade de elementos\n8- Sair\n";
        cin >> opcao;
        switch (opcao) //compara��o de valores, caso o valor seja valido, o caso sera executado//
        {
        case 1: cout << "\nQUAL O ELEMENTO A SER INSERIDO?\n";
            cin >> novo;
            raiz = inserir(raiz, novo);//chamar função de inserir elementos retornando o valor da raiz para a variável raiz
            break;
        case 2:
            cout << "Qual o valor que deseja remover?\n";
            cin >> (novo);
            raiz = remover(raiz, novo);//chamar função de remover elementos retornando o valor da raiz para a vari�vel raiz
            break;
        case 3: if (raiz == NULL) // se a arvore não tiver elementos
            cout << "\nARVORE NAO EXISTE!\n";
              else// SENÂO
            pre(raiz);//chamar a função do percurso em pré-ordem
            cout << endl;
            break;//parar
        case 4: if (raiz == NULL) // se a arvore não tiver elemetos
            cout << "\nARVORE NAO EXISTE!\n";
              else
            sim(raiz); // chamar a função do percurso em ordem simétrica
            cout << endl;
            break;
        case 5: if (raiz == NULL) // se a arvore não tiver elementos
            cout << "\nARVORE NAO EXISTE!\n";
              else// SENÂO
            pos(raiz);//chamar a função do percurso em pós-ordem
            cout << endl;
            break;
        case 6: if (raiz == NULL) // se a arvore não tiver elementos
            cout << "\nARVORE NAO EXISTE!\n";
              else
            cout << altura(raiz) << "\n";//chama a função da altura para atribuir valor a variável altura indicando a altura da árvore
            break;
        case 7: // se a arvor não tiver elementos
        	{
			contador=0;
			qtde(raiz);//chama a função quantidade
			cout << contador << endl;
            break;
        	}
        case 8: cout << "\nSAIR\n"; // irá sair do programa
            break;
        default: cout << "\nOPCAO INVALIDA\n";
        }

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
    return 0;
} // FIM.


