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

int main(){
    system("TITLE       Sistema de Gerência");
    setlocale(LC_ALL, "");

    int opcao;
    while(true){
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
                    printf("Opção inválida. Tente novamente:")
            }
        }while(opcao < 1 && opcao > 5);
    }

    quebraLinha();
    system("pause");
    return 0;
}
