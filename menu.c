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

    // verifica se existe um arquivo-alunos.txt, senão existia cria ele atraves de uma função que esta nas opcoes
    verifica_arquivo();

    while (VarLoop == 1)
    { // Menu de opções
        printf("\n>>>>> Gestão de alunos <<<<<");

        printf("\n\n1 - Cadastrar aluno");
        printf("\n2 - Remover aluno");
        printf("\n3 - Listar aluno");
        printf("\n4 - Ver alunos aprovados");
        printf("\n5 - Ver alunos reprovados");
        printf("\n6 - Procurar aluno");
        printf("\n7 - Quantidade de alunos por turma\n");
        printf("\n0 - Sair do menu\n");

        printf("\nSelecione uma opção: ");
        scanf("%d", &menu);

        // declaraç]ao de variaveis que possivelmente serão usadas nas opções
        int media_pra_passar;
        int faltas_pra_passar;
        char matricula_pra_manipular[50];
        aluno aluno_novo;

        // Limpa o buffer de entrada
        while ((c = getchar()) != '\n' && c != EOF)
            ;

        switch (menu)
        {
        case 1:
            // perguntar ao usuário os dados do aluno
            printf("\nDigite a matrícula do aluno: ");
            scanf("%[^\n]s", aluno_novo.matricula);
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

            getchar();
            printf("\nPressione Enter para continuar...");
            getchar(); // Aguarda o usuário pressionar Enter
            break;

        case 2:
            // receber a matricula do aluno a ser removido
            printf("\nDigite a matrícula do aluno a ser removido: ");
            scanf("%[^\n]s", matricula_pra_manipular);

            remover_aluno(matricula_pra_manipular);

            getchar();
            printf("\nPressione Enter para continuar...");
            getchar(); // Aguarda o usuário pressionar Enter
            break;

        case 3:
            listar_alunos();
            printf("\nPressione Enter para continuar...");
            getchar(); // Aguarda o usuário pressionar Enter
            break;

        case 4:
            printf("\nDigite a media para passar: ");
            scanf("%d", &media_pra_passar);

            printf("\nDigite o numero máximo de faltas para passar: ");
            scanf("%d", &faltas_pra_passar);

            alunos_aprovados(media_pra_passar, faltas_pra_passar);

            getchar();
            printf("\nPressione Enter para continuar...");
            getchar(); // Aguarda o usuário pressionar Enter
            break;
        case 5:
            printf("\nDigite a media para passar: ");
            scanf("%d", &media_pra_passar);

            printf("\nDigite o numero máximo de faltas para passar: ");
            scanf("%d", &faltas_pra_passar);

            alunos_reprovados(media_pra_passar, faltas_pra_passar);

            getchar();
            printf("\nPressione Enter para continuar...");
            getchar(); // Aguarda o usuário pressionar Enter
            break;

        case 6:
            printf("\nDigite a matrícula do aluno a ser procurado: ");
            scanf("%[^\n]s", matricula_pra_manipular);

            procurar_aluno(matricula_pra_manipular);

            getchar();
            printf("\nPressione Enter para continuar...");
            getchar(); // Aguarda o usuário pressionar Enter
            break;

        case 7:
            quantidade_alunos_turma();
            printf("\nPressione Enter para continuar...");
            getchar(); // Aguarda o usuário pressionar Enter
            break;
        case 0:
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