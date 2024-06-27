#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
/*
Descri��o simples do Projeto:
        Um sistema para gerenciar livros de uma biblioteca. Deve
    permitir a adi��o e remo��o de livros, pesquisa por ano e
    listagem dos livros.
*/

//==========================SUB-PROGRAMAS==========================

//Definindo a struct Livro:
typedef struct{
    char titulo[100];
    char autor[100];
    int ano;
}Livro;

// Fun��o para limpar a tela:
void limpaTela() {
    system("cls");
}

// Fun��o para inserir linha-tra�o:
void linhaTraco(){
    int c;
    for (c=0; c<=30; c++){
        printf("==");
    }
    printf("\n");
}

// Fun��o para limpar o buffer do teclado
void limpaTeclado() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Fun��o para adicionar um livro
Livro adLivro() {
    //Definindo vari�vel do tipo Livro:
    Livro livro;

    limpaTela();

    //Lendo dados do livro:
    linhaTraco();
    printf("Nome do livro: ");
    fgets(livro.titulo, 100, stdin);

    // Removendo o caractere de nova linha:
    livro.titulo[strcspn(livro.titulo, "\n")] = '\0';

    linhaTraco();
    printf("Nome do autor: ");
    fgets(livro.autor, 100, stdin);

    // Remove o caractere de nova linha
    livro.autor[strcspn(livro.autor, "\n")] = '\0';

    linhaTraco();
    printf("Ano do livro: ");
    scanf("%d", &livro.ano);
    limpaTeclado();

    return livro;
}

// Fun��o para listar os livros
void listaLivros(Livro livros[], int quantidade) {

    //Definindo vari�vel:
    int i;

    limpaTela();

    //La�o de Repeti��o para listagem de livros:
    for (i = 0; i < quantidade; i++) {
        linhaTraco();
        printf("Livro %d:\n", i + 1);
        printf("T�tulo: %s\n", livros[i].titulo);
        printf("Autor: %s\n", livros[i].autor);
        printf("Ano: %d\n\n", livros[i].ano);
        linhaTraco();
    }

    printf("Pressione Enter para continuar...");
    limpaTeclado();
    getchar();
}

// Fun��o para buscar livros (por ano):
void buscaPorAno(Livro livros[], int quantidade, int ano) {
    //Definindo vari�vel:
    int encontrado = 0;

    limpaTela();

    //La�o de repeti��o para listar os dados dos livros encontrados:
    for (int i = 0; i < quantidade; i++) {
        if (livros[i].ano == ano) {
            linhaTraco();
            printf("Livro %d:\n", i + 1);
            printf("T�tulo: %s\n", livros[i].titulo);
            printf("Autor: %s\n", livros[i].autor);
            printf("Ano: %d\n\n", livros[i].ano);

            encontrado = 1; //Assume esse valor para invalidar a condicional seguinte:
            linhaTraco();
        }
    }

    //Condicional para caso nenehum livro seja encontrado:
    if (encontrado==0) {
        printf("Nenhum livro encontrado para o ano %d.\n", ano);
        linhaTraco();
    }

    printf("Pressione Enter para continuar...");
    limpaTeclado();
    getchar();
}

// Fun��o para remover um livro:
void removeLivro(Livro livros[], int *quantidade, int indice) {
    //Condicional para caso o indice n�o seja v�lido
    if (indice < 0 || indice >= *quantidade) {
        linhaTraco();
        printf("�ndice inv�lido!\n");
        linhaTraco();

        return; //Encerra a fun��o sem nenhum retorno;
    }

    //La�o de repeti��o para Trocar os livros de posi��o:
    for (int i = indice; i < *quantidade - 1; i++) {
        livros[i] = livros[i + 1];
    }

    //Decremento para remover o �ltimo espa�o ocupado:
    (*quantidade)--;

    linhaTraco();
    printf("Livro removido com sucesso.\n");
    linhaTraco();

    printf("Pressione Enter para continuar...");
    limpaTeclado();
    getchar();
}

//==========================ALGORITMO PRINCIPAL==========================:
int main() {
    //T�tulo para o prompt aberto:
    system("TITLE Sistema de Gerenciamento de Biblioteca");
    //C�digo para permiss�o de caracteres especiais:
    setlocale(LC_ALL, "");

    //Definindo vari�veis:
    Livro livros[100];
    int opcao;
    int quantidade = 0;
    int ano, indice;

    //La�o de repeti��o "eterno" para que o programa s� se encerre caso o usu�rio deseje:
    while(1){
        limpaTela();
        linhaTraco();
        printf("        Sistema de Gerenciamento de Biblioteca\n");
        linhaTraco();

        printf("1. Adicionar livro\n");
        printf("2. Listar livros\n");
        printf("3. Buscar livro por ano\n");
        printf("4. Remover livro\n");
        printf("5. Sair\n");
        linhaTraco();

        //Lendo op��o do usu�rio:
        printf("Escolha uma op��o: ");
        scanf("%d", &opcao);
        limpaTeclado();

        //Condicional mediante escolha do usu�rio:
        switch(opcao){
            case 1: //Adicionar livros:

                //Condicional para verificar se a "biblioteca" est� cheia:
                if (quantidade < 100) {
                    livros[quantidade] = adLivro();
                    quantidade++;
                }
                else{
                    linhaTraco();
                    printf("Capacidade m�xima de livros atingida.\n");
                    linhaTraco();
                    printf("Pressione Enter para continuar...");
                    limpaTeclado();
                    getchar();
                }
                break;

            case 2: //Listar livros:
                listaLivros(livros, quantidade);
                break;

            case 3: //Buscar livro por ano:
                linhaTraco();
                printf("Digite o ano do livro: ");
                scanf("%d", &ano);

                linhaTraco();
                limpaTeclado();

                buscaPorAno(livros, quantidade, ano);
                break;

            case 4: //Remover Livro:
                //Listando os livros para o usu�rio:
                listaLivros(livros, quantidade);
                linhaTraco();

                printf("Digite o �ndice do livro para remover (1 a %d): ", quantidade);
                scanf("%d", &indice);
                linhaTraco();
                limpaTeclado();

                removeLivro(livros, &quantidade, indice - 1);
                break;

            case 5: //Sair do programa:
                limpaTela();
                linhaTraco();
                printf("                SISTEMA ENCERRADO\n");
                linhaTraco();
                return 0; //Retornando 0, o la�o de repeti��o se encerra;

            default: //Caso nenhum caso seja atendido:
                linhaTraco();
                printf("Op��o inv�lida! Tente novamente.\n");
                linhaTraco();

                printf("Pressione Enter para continuar...");
                limpaTeclado();
                getchar();
                break;
        }
    }

    return 0;
}
