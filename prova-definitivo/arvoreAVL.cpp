#include <stdio.h>//biblioteca ou arquivo de cabe�alho com as principais fun��es da linguagem C
#include <conio.h>//biblioteca para usar fun��es
#include <stdlib.h>//biblioteca ou arquivo de cabe�alho utilizado para fun��es de limpar tela e pausar at� ser inserido alguma tecla
#include <iostream>//biblioteca respons�vel pela manipula��o de fluxo de dados 

//para usar os recursos de entrada e sa�da da biblioteca iostream//
using namespace std;

// dentro da struct temos ponteiros que � um tipo de dado cujo valor se refere// 
//diretamente a um outro valor alocado em outra �rea da mem�ria//
struct no {
    int dado, bal;//dado = recebe o valor, bal para balanceamento
    struct no* dir, * esq; //dir para valores a direita e esq para valores a esquerda
};//final da declara��o de struct

int h;//vari�veis globais, h para controle de balanceamento
int contador=0;
//fun�ao que mostra percurso em pr� ordem//
void pre(struct no* r)
{
    cout << r->dado << " ";
    if (r->esq != NULL)//se na esquerda tiver algo
        pre(r->esq);//recursividade com a fun��o pre
    if (r->dir != NULL)
        pre(r->dir);
}//fim da condi��o
//fun��o que mostra percusso em ordem sim�trica//
void sim(struct no* r)
{ //''NULL'' define o valor de ponteiros nulos, que equivalem a zero// 
    if (r->esq != NULL)//se na esquerda tiver algo
        sim(r->esq);//recursividade com a fun��o pre
    cout << r->dado << " ";
    if (r->dir != NULL)
        sim(r->dir);
}//fim da condi��o
//fun��o que mostra percusso em p�s ordem//
void pos(struct no* r)
{
    if (r->esq != NULL)//se na esquerda tiver algo
        pos(r->esq);//recursividade com a fun��o pre
    if (r->dir != NULL)
        pos(r->dir);
    cout << r->dado << " ";
}//fim da condi��o

struct no* caso1(struct no* r)//Fun��o caso esteja desbalanceado para esquerda
{
    struct no* ptu, * ptv;//declara��o de vari�veis auxiliares
    ptu = r->esq;//ptu vai armazenar os valores do lado esquerdo
    if (ptu->bal == -1)//se no balanceamento dizer que est� desbalanceado para o lado esquerdo representado por -1
    {
        r->esq = ptu->dir;// o valor do lado direito vai para a esquerda
        ptu->dir = r;// o valor da raiz vai para a direita
        r->bal = 0;//deixa balanceado
        r = ptu;//o que estava na esquerda agora vira raiz
    }
    else //caso contrario
    {
        ptv = ptu->dir;//ptv recebe o que est� a direita da esquerda
        ptu->dir = ptv->esq;//o que estava na esquerda da direita agora ser� o que est� na direita da esquerda
        ptv->esq = ptu;//o valor da esquerda vai para a esquerda da direita
        r->esq = ptv->dir;//o valor da extrema direita ou seja o maior valor vai para o lado esquerdo da raiz
        ptv->dir = r;//a valor da raiz vai para a extrema direita
        if (ptv->bal == -1)//se estiver desbalanceado para esquerda
            r->bal = 1;//balanceamento recebe 1 e fica desbalanceado para direita
        else//caso contrario
            r->bal = 0;//balanceado
        if (ptv->bal == 1)//se estiver desbalanceado para direita
            ptu->bal = -1;//balanceamento recebe -1 e fica desbalanceado para esquerda
        else//caso contrario
            ptu->bal = 0;//balanceado
        r = ptv;// a raiz ser� o valor que estava na esquerda
    }
    r->bal = 0;//balanceada
    h = 1;//controle de balanceamento balanceado
    return(r);//retorna o valor novo da raiz
}

struct no* caso2(struct no* r)//Fun��o caso esteja desbalanceado para direita
{
    struct no* ptu, * ptv;//declara��o de vari�veis auxiliares
    ptu = r->dir;//ptv vai armazenar os valores do lado direito
    if (ptu->bal == 1)//se no balanceamento dizer que est� desbalanceado para o lado direito representado por 1
    {
        r->dir = ptu->esq;//o valor da esquerda vai para direita
        ptu->esq = r;// o valor da raiz vai para a esquerda 
        r->bal = 0;//balanceia
        r = ptu;//o que estava na direita agora vira raiz
    }
    else//caso contrario
    {
        ptv = ptu->esq;//ptv recebe o que est� a esquerda da direita
        ptu->esq = ptv->dir;//o que estava na direita da esquerda agora ser� o que est� na esquerda da direita
        ptv->dir = ptu;//o valor da direita vai para a direita da esquerda
        r->dir = ptv->esq;//o valor da extrema esquerda ou seja o menor valor vai para o lado direito da raiz
        ptv->esq = r;//a valor da raiz vai para a extrema esquerda
        if (ptv->bal == 1)//se estiver desbalanceado para direita
            r->bal = -1;//balanceamento recebe -1 e fica desbalanceado para esquerda
        else//caso contrario
            r->bal = 0;//balanceado
        if (ptv->bal == -1)//se estiver desbalanceado para esquerda
            ptu->bal = 1;//balanceamento recebe 1 e fica desbalanceado para direita
        else//caso contrario
            ptu->bal = 0;//balanceado
        r = ptv;// a raiz ser� o valor que estava na esquerda
    }
    r->bal = 0;//balanceado
    h = 1;//controle de balanceamento balanceado
    return(r);//retorna um novo valor da raiz
}

struct no* inserir(struct no* r, int n)//inserir novos elementos na arvore//
{
    if (r == NULL)//se a raiz for nulo
    {

        r = (struct no*)malloc(sizeof(struct no));  //a fun��o malloc aloca espa�o mem�ria para inserir valores
        r->dado = n;//o valor inserido ser� o valor da raiz
        r->esq = NULL;//o lado esquerdo da raiz ser� nulo at� ser inserido outro valor menor que a raiz
        r->dir = NULL;//o lado direito da raiz ser� nulo at� ser inserido outro valor maior que a raiz
        r->bal = 0;//balanceia
        h = 0;//controle de balanceiamento indica que seja feito balanceamento caso necessario
    }
    else if (n == r->dado)//se o valor novo for igual a um elemento j� existente
    {
        cout << "\nELEMENTO JA EXISTE\n";
    }
    else if (n < r->dado)//se o valor novo for menor do que os valores que j� existem
    {
        r->esq = inserir(r->esq, n);//inserir o valor no lado esquerdo e realizar demais opera��es da fun��o atrav�s da recursividade
        cout << "\nEsquerdo - Valor: " << r->dado << " - Balanceamento: " << r->bal << " - h: \n" << h;
        if (h == 0)//se o controle de balancemanto quiser testar se necessario o balanceamento, h ter� valor 0
        {
            switch (r->bal)//o param�tro ser� o valor do balanceamento
            {
            case 1: r->bal = 0;//caso o valor seja 1, balanceia
                h = 1;//controle de balanceamento balanceado
                break;//parar
            case 0: r->bal = -1;//caso o valor seja 0, colocar desbalanceamento para esquerda
                break;//parar
            case -1: r = caso1(r);//caso o valor seja -1, chama o balanceamento para esquerda
                break;//parar
            }//final do switch case para selecionar opera��es
            cout << "\nEsquerdo - Valor: " << r->dado << "- Balanceamento: " << r->bal << " - h: \n" << h;
        }
    }
    else
    {
        r->dir = inserir(r->dir, n);//inserir o valor no lado direito e realizar demais opera��es da fun��o atrav�s da recursividade
        cout << "\nDireito - Valor: " << r->dado << "- Balanceamento: " << r->bal << "- h: \n" << h;
        if (h == 0)//se o controle de balancemanto quiser testar se necessario o balanceamento, h ter� valor 0
        {
            switch (r->bal)//o param�tro ser� o valor do balanceamento
            {
            case -1: r->bal = 0;//caso o valor seja -1,balanceia
                h = 1;//controle de balanceamento balanceado
                break;//parar
            case 0: r->bal = 1;//caso o valor for 0,colocar desbalanceamento para direita
                break;//parar
            case 1: r = caso2(r);//caso o valor seja 1, chamar o balanceamento para a direita
                break;//parar
            }//final do switch case para selecionar opera��es e final das condi��es
            cout << "\nDireito - Valor: " << r->dado << " - Balanceamento: " << r->bal << " - h: \n" << h;
        }
    }
    return (r);//retorna o novo valor da raiz
}//fim da fun��o

no* remover(no* r, int chave) {//fun��o para remover os elementos da arvore
    if (r == NULL) {//se a arvore n�o existir
        cout << "Valor nao encontrado!\n";
        return (NULL);//retornar NULL ou 0
    }
    else {
        if (r->dado == chave) {// se o valor que tiver na �rvore for igual a valor que deseja remover
            if (r->esq == NULL && r->dir == NULL) {//se o valor a ser removido for a raiz
                free(r);//remover o valor da memoria
                return(NULL);//retorna 0
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
                    r->esq = remover(r->esq, chave);//ele remover� o valor que deseja quando ele terminar de percorre o lado esquerdo atrav�s da recursividade
                    return(r);
                }
            }
        }
        else {//caso contrario
            if (chave < r->dado)
                r->esq = remover(r->esq, chave);//ele remover� o valor que deseja quando ele terminar de percorre o lado esquerdo atrav�s da recursividade
            else
                r->dir = remover(r->dir, chave);//ele remover� o valor que deseja quando ele terminar de percorre o lado direito atrav�s da recursividade
            return(r);
        }//final da condi��o
    }
}

int altura(const no* const no_ptr)//fun��o para saber a altura da arvore
{
    int altura_esq = 0;//variaveis inteiras para altura
    int altura_dir = 0;

    if (no_ptr->esq)
        altura_esq = altura(no_ptr->esq);

    if (no_ptr->dir)
        altura_dir = altura(no_ptr->dir);

    return max(altura_dir, altura_esq) + 1;//retorna o valor da esquerda e da direita + 1

    cout << altura;
}

void qtde(struct no* r){//fun��o que mostra a quantidade de elementos que existem na arvore
    
	if (r->esq != NULL)//valor reprecisa ser diferente de 0
        qtde(r->esq);
    contador++;//incrementa��o, aumenta a quantidade de elementos
    if (r->dir != NULL)
        qtde(r->dir);    
}//fim da condi��o

int main()//fun�a� principal
{
    struct no* raiz = NULL;//vari�vel para armazenar valores da �rvore
    int novo = 0, opcao = 0; //novo para receber o valor que ser� inserido ou removido da �rvore, opcao para selecionar a opera��o ou a fun��o desejada
    while (opcao != 8)//la�o de repeti��o das op��es de opera��es
    {
        cout << "\nDigite a opcao:\n1- Inserir\n2- Remover\n3- Percurso em Pre Ordem\n4- Percurso em Ordem Simetrica\n5- Percurso em pos Ordem\n6- Altura da arvore\n7- Quantidade de elementos\n8- Sair\n";
        cin >> opcao;
        switch (opcao) //compara��o de valores, caso o valor seja valido, o caso sera executado//
        {
        case 1: cout << "\nQUAL O ELEMENTO A SER INSERIDO?\n";//caso o valor seja 1
            cin >> novo;
            raiz = inserir(raiz, novo);//chamar fun��o de inserir elementos retornando o valor da raiz para a vari�vel raiz
            break;//parar
        case 2://caso o valor seja 2
            cout << "Qual o valor que deseja remover?\n";
            cin >> (novo);
            raiz = remover(raiz, novo);//chamar fun��o de remover elementos retornando o valor da raiz para a vari�vel raiz
            break;//parar
        case 3: if (raiz == NULL)//caso o valor seja 3, e se a arvore n�o tiver elementos
            cout << "\nARVORE NAO EXISTE!\n";
              else//caso contrario
            pre(raiz);//chamar a fun��o do percurso em pr�-ordem
            cout << endl;
            break;//parar
        case 4: if (raiz == NULL)//caso o valor seja 4 e se a arvore n�o tiver elemetos
            cout << "\nARVORE NAO EXISTE!\n";
              else
            sim(raiz);//chamar a fun��o do percurso em ordem sim�trica
            cout << endl;
            break;//parar
        case 5: if (raiz == NULL)//caso o valor seja 5 e se a arvore n�o tiver elementos
            cout << "\nARVORE NAO EXISTE!\n";
              else//caso contrario
            pos(raiz);//chamar a fun��o do percurso em p�s-ordem
            cout << endl;
            break;//parar
        case 6: if (raiz == NULL)//caso o valor seja 6, e a arvore n�o tiver elementos
            cout << "\nARVORE NAO EXISTE!\n";
              else
            cout << altura(raiz) << "\n";//chama a fun��o da altura para atribuir valor a vari�vel altura indicando a altura da �rvore
            break;//parar
        case 7://caso o valor seja 7 e se a arvor n�o tiver elementos
        	{
			contador=0;
			qtde(raiz);//chama a fun��o quantidade
			cout << contador << endl;
            break;//parar
        	}
        case 8: cout << "\nSAIR\n";//caso o valor seja 8, ele ir� sair do programa
            break;//parar
        default: cout << "\nOPCAO INVALIDA\n";
        }
        system("pause");//esperar apertar algo
        system("cls");//limpar a tela
    }
    return 0;
}//fim da fun��o principal e do programa


