typedef struct // struct dos alunos
{
    int matricula;
    float notas[7];
    char nome[50];
    int codTurma;
    int faltas[7];
} aluno;

typedef struct // struct da turma
{
    aluno *alunos;
    int qtdAlunos;
    int id;
} turma;

int inserir_aluno()
{
}

int listar_aluno()
{
}

int remover_aluno()
{
}

int procurar_aluno()
{
}

int tamanho_aluno()
{
}

int sair()
{
}