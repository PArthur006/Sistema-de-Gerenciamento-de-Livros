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

int main(){
    system("TITLE       Sistema de Ger�ncia");
    setlocale(LC_ALL, "");

    int  biblioteca[10], qLivros=0, opcao;

    while(1){
        do{
            printf("    ----------SISTEMA DE GER�NCIA----------\n");
            quebraLinha();
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
                    adLivro();
                    qLivros += 1;
                    break;
                case 2:
                    buscaLivro();
                    break;
                /*case 3:
                    break;
                case 4:
                    break;*/
                case 5:
                    break;
                default:
                    limpaTela();
                    printf("Op��o inv�lida. Tente novamente:");
                    linhaTraco(10);
            }
            break;
        }while(opcao != 5);
        break;
    }

    quebraLinha();
    system("pause");
    return 0;
}

//SUB-PROGRAMAS COMPLEXOS

void adLivro(char nome[], char autor[], int ano) {
    limpaTela();

    limpaTeclado();
    printf("Nome do livro: ");
    fgets(nome, 50, stdin);

    printf("Nome do autor: ");
    fgets(autor, 50, stdin);

    printf("Ano do livro: ");
    scanf("%d", &ano);

    limpaTela();
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