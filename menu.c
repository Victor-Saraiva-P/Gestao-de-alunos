#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "biblioteca.h"


int menu;

int main(void) {
    int VarLoop = 1; // Variável responsável por fazer o loop contínuo do menu.
    int c; // Variável para armazenar o caractere lido

    while (VarLoop == 1) { // Menu de opções
        printf("\n>>>>> Gestão de alunos <<<<<");

        printf("\n\n1 - Cadastrar aluno");
        printf("\n4 - Listar aluno");
        printf("\n6 - Remover aluno");
        printf("\n7 - Procurar aluno");
        printf("\n8 - Tamanho aluno");
        printf("\n-1 - Sair do menu\n");

        printf("\nSelecione uma opção: ");
        scanf("%d", &menu);

        // Limpa o buffer de entrada
        while ((c = getchar()) != '\n' && c != EOF);

        switch (menu) {
            case 1:
                // inserir_aluno();
                printf("\nPressione Enter para continuar...");
                getchar(); // Aguarda o usuário pressionar Enter
                break;

            case 4:
                // listar_aluno();
                printf("\nPressione Enter para continuar...");
                getchar(); // Aguarda o usuário pressionar Enter
                break;

            case 6:
                // remover_aluno();
                printf("\nPressione Enter para continuar...");
                getchar(); // Aguarda o usuário pressionar Enter
                break;

            case 7:
                // procurar_aluno();
                printf("\nPressione Enter para continuar...");
                getchar(); // Aguarda o usuário pressionar Enter
                break;

            case 8:
                // tamanho_aluno();
                printf("\nPressione Enter para continuar...");
                getchar(); // Aguarda o usuário pressionar Enter
                break;

            case -1:
                printf("\nSaindo do menu...\n");
                VarLoop = 0; // Encerra o loop principal
                break;

            default:
                printf("\nERRO - Opção inválida.\n");

                printf("\nPressione Enter para continuar...");
                getchar(); // Aguarda o usuário pressionar Enter

                break;
        }
    }

    return 0;
}