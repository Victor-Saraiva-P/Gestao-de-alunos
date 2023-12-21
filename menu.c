#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "opcoes.h"

int menu;

int qtdtotal = 0;

int main(void)
{
    int VarLoop = 1; // Variável responsável por fazer o loop contínuo do menu.
    int c;           // Variável para armazenar o caractere lido

    while (VarLoop == 1)
    { // Menu de opções
        printf("\n>>>>> Gestão de alunos <<<<<");

        printf("\n\n1 - Cadastrar aluno");
        printf("\n4 - Listar aluno");
        printf("\n6 - Remover aluno");
        printf("\n7 - Procurar aluno");
        printf("\n8 - Tamanho aluno");
        printf("\n-1 - Sair do menu\n");

        printf("\nSelecione uma opção: ");
        scanf("%d", &menu);

        // declaraç]ao de variaveis que possivelmente serão usadas nas opções
        int matricula_remover;
        aluno aluno_novo;

        // Limpa o buffer de entrada
        while ((c = getchar()) != '\n' && c != EOF)
            ;

        switch (menu)
        {
        case 1:
            // perguntar ao usuário os dados do aluno
            printf("\nDigite a matrícula do aluno: ");
            scanf("%d", &aluno_novo.matricula);
            // pegar o nome do aluno mesmo com ESPAÇOS
            // Limpar o buffer de entrada
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF)
                ;

            printf("\nDigite o nome do aluno: ");
            scanf("%[^\n]s", aluno_novo.nome);

            // receber o resto dos dados
            printf("\nDigite o código da turma do aluno: ");
            scanf("%d", &aluno_novo.codTurma);
            printf("\nDigite a media do aluno: ");
            scanf("%f", &aluno_novo.media);
            printf("\nDigite o numero de faltas do aluno: ");
            scanf("%d", &aluno_novo.faltas);
            inserir_aluno(aluno_novo);

            printf("\nPressione Enter para continuar...");
            getchar(); // Aguarda o usuário pressionar Enter
            break;

        case 4:
            listar_alunos();
            printf("\nPressione Enter para continuar...");
            getchar(); // Aguarda o usuário pressionar Enter
            break;

        case 6:
            // receber a matricula do aluno a ser removido
            printf("\nDigite a matrícula do aluno a ser removido: ");
            scanf("%i", &matricula_remover);

            remover_aluno(matricula_remover);

            getchar();
            printf("\nPressione Enter para continuar...");
            getchar(); // Aguarda o usuário pressionar Enter
            break;

        case 7:
            procurar_aluno();
            printf("\nPressione Enter para continuar...");
            getchar(); // Aguarda o usuário pressionar Enter
            break;

        case 8:
            tamanho_aluno();
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