#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
/*
Descrição: Um sistema para gerenciar livros de uma biblioteca.
Deve permitir a adição e remoção de livros, pesquisa por ano
e listagem dos livros.
*/

/*
Etapas do Projeto de Registro de Livros:
    Definir a estrutura do livro;
    Criar funções para adicionar e listar;
    Implementar o menu de interação com o usuário;
    Armazenar e manipular os dados dos livros;
*/

//==========================SUB-PROGRAMAS==========================

//Definição da struct Livro:
struct Livro {
    char titulo[100];
    char autor[100];
    int ano;
};

// Função para limpar a tela:
void limpaTela() {
    system("cls");
}

// Função para inserir linha-traço:
void linhaTraco(){
    int c;
    for (c=0; c<=30; c++){
        printf("==");
    }
    printf("\n");
}

// Função para limpar o buffer do teclado
void limpaTeclado() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função para adicionar um livro
struct Livro adLivro() {
    struct Livro livro;

    limpaTela();

    linhaTraco();
    printf("Nome do livro: ");
    fgets(livro.titulo, 100, stdin);

    livro.titulo[strcspn(livro.titulo, "\n")] = '\0';  // Remove o caractere de nova linha

    linhaTraco();
    printf("Nome do autor: ");
    fgets(livro.autor, 100, stdin);

    livro.autor[strcspn(livro.autor, "\n")] = '\0';  // Remove o caractere de nova linha

    linhaTraco();
    printf("Ano do livro: ");
    scanf("%d", &livro.ano);
    limpaTeclado();

    return livro;
}

// Função para listar os livros
void listaLivros(struct Livro livros[], int quantidade) {

    limpaTela();
    int i;

    for (i = 0; i < quantidade; i++) {
        linhaTraco();
        printf("Livro %d:\n", i + 1);
        printf("Título: %s\n", livros[i].titulo);
        printf("Autor: %s\n", livros[i].autor);
        printf("Ano: %d\n\n", livros[i].ano);
        linhaTraco();
    }

    printf("Pressione Enter para continuar...");
    limpaTeclado();
    getchar();
}

// Função para buscar livros (por ano):
void buscaPorAno(struct Livro livros[], int quantidade, int ano) {
    limpaTela();

    int encontrado = 0;

    for (int i = 0; i < quantidade; i++) {
        if (livros[i].ano == ano) {
            linhaTraco();
            printf("Livro %d:\n", i + 1);
            printf("Título: %s\n", livros[i].titulo);
            printf("Autor: %s\n", livros[i].autor);
            printf("Ano: %d\n\n", livros[i].ano);
            encontrado = 1;
            linhaTraco();
        }
    }

    if (encontrado==0) {
        printf("Nenhum livro encontrado para o ano %d.\n", ano);
        linhaTraco();
    }

    printf("Pressione Enter para continuar...");
    limpaTeclado();
    getchar();
}

// Função para remover um livro:
void removeLivro(struct Livro livros[], int *quantidade, int indice) {
    if (indice < 0 || indice >= *quantidade) {
        linhaTraco();
        printf("Índice inválido!\n");
        linhaTraco();
        return;
    }

    for (int i = indice; i < *quantidade - 1; i++) {
        livros[i] = livros[i + 1];
    }

    (*quantidade)--;
    linhaTraco();
    printf("Livro removido com sucesso.\n");
    linhaTraco();

    printf("Pressione Enter para continuar...");
    limpaTeclado();
    getchar();
}

//ALGORITMO PRINCIPAL:
int main() {
    setlocale(LC_ALL, "");

    struct Livro livros[100];
    int opcao;
    int quantidade = 0;
    int ano, indice;

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
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        limpaTeclado();

        switch(opcao){
            case 1:
                if (quantidade < 100) {
                    livros[quantidade] = adLivro();
                    quantidade++;
                }
                else{
                    linhaTraco();
                    printf("Capacidade máxima de livros atingida.\n");
                    linhaTraco();
                    printf("Pressione Enter para continuar...");
                    limpaTeclado();
                    getchar();
                }
                break;
            case 2:
                listaLivros(livros, quantidade);
                break;
            case 3:
                linhaTraco();
                printf("Digite o ano do livro: ");
                scanf("%d", &ano);
                linhaTraco();
                limpaTeclado();
                buscaPorAno(livros, quantidade, ano);
                break;
            case 4:
                listaLivros(livros, quantidade);
                linhaTraco();
                printf("Digite o índice do livro para remover (1 a %d): ", quantidade);
                scanf("%d", &indice);
                linhaTraco();
                limpaTeclado();
                removeLivro(livros, &quantidade, indice - 1);
                break;
            case 5:
                return 0;
            default:
                linhaTraco();
                printf("Opção inválida! Tente novamente.\n");
                linhaTraco();
                printf("Pressione Enter para continuar...");
                limpaTeclado();
                getchar();
                break;
        }
    }

    return 0;
}
