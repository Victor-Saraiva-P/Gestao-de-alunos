#include <stdio.h>
#include <string.h>

typedef struct // struct dos alunos
{
    char matricula[50];
    float media;
    char nome[50];
    int codTurma;
    int faltas;
} aluno;

typedef struct // struct da turma
{
    aluno *alunos;
    int qtdAlunos;
    int id;
} turma;

void ler_alunos(int *qtde, aluno alunos[])
{
    FILE *arq;
    int i = 0;
    arq = fopen("Database-Alunos.txt", "r");

    if (arq == NULL)
        printf("ERRO! Nao foi possivel abrir arquivo\n");
    else
    {
        while (fscanf(arq, "%s|%f|%s|%d|%i", alunos[i].matricula, &alunos[i].media, alunos[i].nome, &alunos[i].codTurma, &alunos[i].faltas) != EOF)
            i++;

        fclose(arq);
    }

    *qtde = i;
}

void inserir_aluno(aluno a)
{
    // Verificando se os valores são válidos
    if (a.media > 10)
    {
        printf("ERRO! Media nao pode ser maior que 10\n");
        return;
    }
    if (a.faltas > 7)
    {
        printf("ERRO! Faltas nao podem ser mais que 7\n");
        return;
    }
    if (strlen(a.nome) == 0)
    {
        printf("ERRO! Nome nao pode ser vazio\n");
        return;
    }

    FILE *arq;
    arq = fopen("arquivo-alunos.txt", "r");

    if (arq != NULL)
    {
        aluno b;
        while (fscanf(arq, "%s;%f;%[^;];%d;%i\n", b.matricula, &b.media, b.nome, &b.codTurma, &b.faltas) != EOF)
        {
            if (strcmp(b.matricula, a.matricula) == 0)
            {
                printf("ERRO! Aluno com a mesma matricula ja existe\n");
                fclose(arq);
                return;
            }
        }
        fclose(arq);
    }

    arq = fopen("arquivo-alunos.txt", "a");
    if (arq != NULL)
    {
        fprintf(arq, "%s;%.2f;%s;%d;%i\n", a.matricula, a.media, a.nome, a.codTurma, a.faltas);
        fclose(arq);
    }
    else
    {
        printf("ERRO! Nao foi possivel abrir arquivo\n");
    }

    // printar mensagem de sucesso
    printf("\nAluno inserido com sucesso!\n");
}

void listar_alunos()
{
    FILE *arq;
    arq = fopen("arquivo-alunos.txt", "r");

    if (arq == NULL)
        printf("ERRO! Nao foi possivel abrir arquivo\n");
    else
    {
        aluno a;
        while (fscanf(arq, "%[^;];%f;%[^;];%d;%i\n", a.matricula, &a.media, a.nome, &a.codTurma, &a.faltas) != EOF)
        {
            printf("Matricula: %s\n", a.matricula);
            printf("Media: %.2f\n", a.media);
            printf("Nome: %s\n", a.nome);
            printf("Codigo da turma: %d\n", a.codTurma);
            printf("Faltas: %i\n", a.faltas);
            printf("\n");
        }
        fclose(arq);
    }
}

// criar uma função para remover aluno
void remover_aluno(char matricula[])
{
    FILE *arq;
    FILE *arq2;
    arq = fopen("arquivo-alunos.txt", "r");
    arq2 = fopen("arquivo-alunos2.txt", "w");

    if (arq == NULL)
        printf("ERRO! Nao foi possivel abrir arquivo\n");
    else
    {
        aluno a;
        int found = 0; // flag para verificar se o aluno foi encontrado

        while (fscanf(arq, "%[^;];%f;%[^;];%d;%i\n", a.matricula, &a.media, a.nome, &a.codTurma, &a.faltas) != EOF)
        {
            if (strcmp(a.matricula, matricula) == 0)
            {
                found = 1; // aluno encontrado
            }
            else
            {
                fprintf(arq2, "%s;%.2f;%s;%d;%i\n", a.matricula, a.media, a.nome, a.codTurma, a.faltas);
            }
        }

        fclose(arq);
        fclose(arq2);

        if (!found)
        {
            printf("Erro: matricula não encontrada.\n");
            return; // se o aluno não foi encontrado, não precisamos renomear os arquivos
        }

        if (remove("arquivo-alunos.txt") != 0)
        {
            printf("Erro: Sistema sem registros cadastrados.\n");
            return;
        }

        if (rename("arquivo-alunos2.txt", "arquivo-alunos.txt") != 0)
        {
            printf("Erro: Não foi possível renomear o arquivo, tente novamente.\n");
        }
    }
    printf("\nAluno removido com sucesso!\n");
}

void alunos_aprovados(float media, int faltas)
{
    FILE *arq;
    arq = fopen("arquivo-alunos.txt", "r");

    if (arq == NULL)
        printf("ERRO! Nao foi possivel abrir arquivo\n");
    else
    {
        aluno a;
        while (fscanf(arq, "%[^;];%f;%[^;];%d;%i\n", a.matricula, &a.media, a.nome, &a.codTurma, &a.faltas) != EOF)
        {
            if (a.media >= media && a.faltas <= faltas)
            {
                printf("Matricula: %s\n", a.matricula);
                printf("Media: %.2f\n", a.media);
                printf("Nome: %s\n", a.nome);
                printf("Codigo da turma: %d\n", a.codTurma);
                printf("Faltas: %i\n", a.faltas);
                printf("\n");
            }
        }
        fclose(arq);
    }
}

// criar uma função paa listar os alunos reprovados
void alunos_reprovados(float media, int faltas)
{
    FILE *arq;
    arq = fopen("arquivo-alunos.txt", "r");

    if (arq == NULL)
        printf("ERRO! Nao foi possivel abrir arquivo\n");
    else
    {
        aluno a;
        while (fscanf(arq, "%[^;];%f;%[^;];%d;%i\n", a.matricula, &a.media, a.nome, &a.codTurma, &a.faltas) != EOF)
        {
            if (a.media < media || a.faltas > faltas)
            {
                printf("Matricula: %s\n", a.matricula);
                printf("Media: %.2f\n", a.media);
                printf("Nome: %s\n", a.nome);
                printf("Codigo da turma: %d\n", a.codTurma);
                printf("Faltas: %i\n", a.faltas);
                printf("\n");
            }
        }
        fclose(arq);
    }
}