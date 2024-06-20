#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*
Descri��o: Um sistema para gerenciar livros de uma biblioteca.
Deve permitir a adi��o de novos livros, remo��o de livros,
pesquisa por t�tulo/autor, empr�stimo e devolu��o de livros.
*/

/*
Etapas do Projeto de Registro de Livros:
    Definir a estrutura do livro;
    Criar fun��es para adicionar, listar e buscar livros;
    Implementar o menu de intera��o com o usu�rio;
    Armazenar e manipular os dados dos livros;
*/

//Definir a estrutura do livro;
typedef struct{
    char titulo[255];
    char autor[100];
    int ano;
} Livros;

int main(){
    system("TITLE       Sistema de Ger�ncia");
    setlocale(LC_ALL, "");

    printf("    ----------SISTEMA DE GER�NCIA----------\n");
    printf("\n[1] Adicionar Livro;");
    printf("\n[2] Buscar Livro;");
    printf("\n[3] Listar Livros;");
    printf("\n[4] Remover Livro;");
    printf("\n[5] Sair;");
    printf("\nEscolha uma op��o: ");
    scanf("%d", &opcao);


    printf("\n");
    system("pause");
    return 0;
}
