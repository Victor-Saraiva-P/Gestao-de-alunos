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
        while (fscanf(arq, "%d|%f|%s|%d|%i", &alunos[i].matricula, &alunos[i].media, alunos[i].nome, &alunos[i].codTurma, &alunos[i].faltas) != EOF)
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
        while (fscanf(arq, "%d;%f;%[^;];%d;%i\n", &b.matricula, &b.media, b.nome, &b.codTurma, &b.faltas) != EOF)
        {
            if (b.matricula == a.matricula)
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
        char matricula_com_zero[10];
        sprintf(matricula_com_zero, "0%d", a.matricula);

        fprintf(arq, "%s;%.2f;%s;%d;%i\n", matricula_com_zero, a.media, a.nome, a.codTurma, a.faltas);
        fclose(arq);
    }
    else
    {
        printf("ERRO! Nao foi possivel abrir arquivo\n");
    }
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
        while (fscanf(arq, "%d;%f;%[^;];%d;%i\n", &a.matricula, &a.media, a.nome, &a.codTurma, &a.faltas) != EOF)
        {
            printf("Matricula: %d\n", a.matricula);
            printf("Media: %.2f\n", a.media);
            printf("Nome: %s\n", a.nome);
            printf("Codigo da turma: %d\n", a.codTurma);
            printf("Faltas: %i\n", a.faltas);
            printf("\n");
        }
        fclose(arq);
    }
}

void remover_aluno(int matricula)
{
    FILE *arq, *arq_temp;
    aluno a;
    int items, removido = 0;

    arq = fopen("arquivo-alunos.txt", "r");
    arq_temp = fopen("arquivo-alunos-temp.txt", "w");

    if (arq == NULL || arq_temp == NULL)
    {
        printf("ERRO! Nao foi possivel abrir arquivo\n");
        return;
    }

    while ((items = fscanf(arq, "%d;%f;%[^;];%d;%i\n", &a.matricula, &a.media, a.nome, &a.codTurma, &a.faltas)) != EOF)
    {
        if (items != 5)
        {
            printf("ERRO! Formato de linha invalido\n");
            break;
        }

        if (a.matricula != matricula)
        {
            fprintf(arq_temp, "%d;%.2f;%s;%d;%i\n", a.matricula, a.media, a.nome, a.codTurma, a.faltas);
        }
        else
        {
            removido = 1;
        }
    }

    fclose(arq);
    fclose(arq_temp);

    if (removido)
    {
        remove("arquivo-alunos.txt");
        rename("arquivo-alunos-temp.txt", "arquivo-alunos.txt");
        printf("Aluno removido com sucesso.\n");
    }
    else
    {
        remove("arquivo-alunos-temp.txt");
        printf("Aluno nao encontrado.\n");
    }
}

void procurar_aluno()
{
}

void tamanho_aluno()
{
}