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

//Definir a estrutura do livro;
typedef struct{
    char titulo[255];
    char autor[100];
    int ano;
} Livros;

int main(){
    system("TITLE       Sistema de Gerência");
    setlocale(LC_ALL, "");

    printf("    ----------SISTEMA DE GERÊNCIA----------\n");
    printf("\n[1] Adicionar Livro;");
    printf("\n[2] Buscar Livro;");
    printf("\n[3] Listar Livros;");
    printf("\n[4] Remover Livro;");
    printf("\n[5] Sair;");
    printf("\nEscolha uma opção: ");
    scanf("%d", &opcao);


    printf("\n");
    system("pause");
    return 0;
}
