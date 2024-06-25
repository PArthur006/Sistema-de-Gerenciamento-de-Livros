#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*
Descrição: Um sistema para gerenciar livros de uma biblioteca.
Deve permitir a adição de novos livros, remoção de livros,
pesquisa por título/autor, empréstimo e devolução de livros.
*/

/*
Etapas do Projeto de Registro de Livros:
    Definir a estrutura do livro;
    Criar funções para adicionar, listar e buscar livros;
    Implementar o menu de interação com o usuário;
    Armazenar e manipular os dados dos livros;
*/

//SUB-PROGRAMAS SIMPLES
void limpaTela(){
    system("cls");
}

void limpaTeclado(){
    fflush(stdin);
}

void quebraLinha(){
    printf("\n");
}

void linhaTraco(int i){
    int c;
    quebraLinha();
    for(c=i;c>=0;c--){
        printf("==");
    }
    quebraLinha();
}

//ALGORITMO PRINCIPAL:

//CRIAÇÃO DE STRUCT
typedef struct{
    char nome_livro[50];
    char autor[50];
    int ano_livro;
} Livros;

int main(){
    system("TITLE       Sistema de Gerência");
    setlocale(LC_ALL, "");

    Livros livro;
    int opcao, cont=0;
    do{
        printf("    ----------SISTEMA DE GERÊNCIA----------\n");
        printf("\n[1] Adicionar Livro;");
        printf("\n[2] Buscar Livro;");
        printf("\n[3] Listar Livros;");
        printf("\n[4] Remover Livro;");
        printf("\n[5] Sair;");
        linhaTraco(10);
        printf("\nEscolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                cont+=1
                limpaTela();
                printf("Título: ");
                fgets(livro.nome_livro, 50, stdin);

                printf("Autor: ");
                fgets(livro.autor, 50, stdin);

                printf("Ano de lançamento: ");
                scanf("%d", &livro.ano_livro);

                break;
            case 2:
                break;
            case 3:
                printf("Livro %d\n", cont);
                printf("Título: %s\n")
                break;
            case 4:
                break;
            case 5:
                break;
            default:
                limpaTela();
                puts("Opção inválida. Tente novamente:");
        }
    }while(opcao < 1 && opcao > 5);

    quebraLinha();
    system("pause");
    return 0;
}

//SUB-PROGRAMAS COMPLEXOS

/*PROBLEMA*
void adLivro(Livros livro) {

}


void buscaLivro(){
    limpaTela();

    int opcao;

    do{
        printf("[1]Buscar por ano:\n");
        printf("[2]Buscar por autor:\n");
        printf("Escolha: ");
        switch(opcao){
            case 1:

                break;
            case 2:

                break;
            default:
                limpaTela();
                printf("    Valor Inválido! Escolha novamente!");
                linhaTraco(20);
        }
    }while(opcao<1 && opcao>2);
}
*/
