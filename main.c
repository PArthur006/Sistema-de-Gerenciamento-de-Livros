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

int main(){
    system("TITLE       Sistema de Ger�ncia");
    setlocale(LC_ALL, "");

    int opcao;
    while(true){
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
                caso 1:
                    break;
                caso 2:
                    break;
                caso 3:
                    break;
                caso 4:
                    break;
                case 5:
                    break;
                default:
                    limpaTela();
                    printf("Op��o inv�lida. Tente novamente:")
            }
        }while(opcao < 1 && opcao > 5);
    }

    quebraLinha();
    system("pause");
    return 0;
}
