#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct
{
    int matricula;
    float notas[3];

} Aluno;

Aluno leAluno(int matricula, float notas[3])
{
    Aluno al;
    al.matricula = matricula;
    for (int i = 0; i < 3; i++)
    {
        al.notas[i] = notas[i];
    }

    return al;
}

void imprimeTurma(Aluno Turma)
{

    printf("----------\n");
    printf("Matrícula: %d ", Turma.matricula);
    printf("Nota 1: %.2f ", Turma.notas[0]);
    printf("Nota 2: %.2f ", Turma.notas[1]);
    printf("Nota 3: %.2f ", Turma.notas[2]);

    printf("\n");
}

float calculaMediaAluno(float notas[3])
{
    float media = (notas[0] + notas[1] + notas[2]) / 3;
    return media;
}

int main(void)
{
    Aluno Turma[5];
    int matricula = 0;
    float notas[3];
    float media = 0;

    for (int i = 0; i < 5; i++)
    {
        printf("-----------------------\n");
        printf("Informe sua matrícula: ");
        scanf("%d", &matricula);
        for (int j = 0; j < 3; j++)
        {
            printf("Informe sua nota [%d]: ", j + 1);
            scanf("%f", &notas[j]);
        }
        printf("\n");
        Turma[i] = leAluno(matricula, notas);
    }

    for (int i = 0; i < 5; i++)
    {
        imprimeTurma(Turma[i]);
    }

    for(int i=0; i< 5; i++)
    {
        media = calculaMediaAluno(Turma[i].notas);// função que calcula a média das notas de um aluno

        printf("Aluno %d  - Media = %.2f\n", (i+1), media); // imprime os dados do aluno

    }
}
