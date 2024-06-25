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

//CRIA��O DE STRUCT
typedef struct{
    char nome_livro[50];
    char autor[50];
    int ano_livro;
} Livros;

int main(){
    system("TITLE       Sistema de Ger�ncia");
    setlocale(LC_ALL, "");

    Livros livro;
    int opcao, cont=0;
    do{
        printf("    ----------SISTEMA DE GER�NCIA----------\n");
        printf("\n[1] Adicionar Livro;");
        printf("\n[2] Buscar Livro;");
        printf("\n[3] Listar Livros;");
        printf("\n[4] Remover Livro;");
        printf("\n[5] Sair;");
        linhaTraco(10);
        printf("\nEscolha uma op��o: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                cont+=1
                limpaTela();
                printf("T�tulo: ");
                fgets(livro.nome_livro, 50, stdin);

                printf("Autor: ");
                fgets(livro.autor, 50, stdin);

                printf("Ano de lan�amento: ");
                scanf("%d", &livro.ano_livro);

                break;
            case 2:
                break;
            case 3:
                printf("Livro %d\n", cont);
                printf("T�tulo: %s\n")
                break;
            case 4:
                break;
            case 5:
                break;
            default:
                limpaTela();
                puts("Op��o inv�lida. Tente novamente:");
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
                printf("    Valor Inv�lido! Escolha novamente!");
                linhaTraco(20);
        }
    }while(opcao<1 && opcao>2);
}
*/
