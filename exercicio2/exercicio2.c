#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

/*
2. Crie um programa que permita armazenar o nome, a altura e da data de nascimento de até 10 pessoas.
Cada pessoa deve ser representada por uma struct dentro de um vetor.

A data de nascimento também deve ser uma struct.

O nome e a altura de cada pessoa devem ser informados pelo teclado.

A geração da data de nascimento deve ser feita aleatoriamente através da função abaixo
*/

typedef struct
{
    int dia, mes, ano;
} DataNascimento;

typedef struct
{
    char nome[30];
    float altura;
    DataNascimento data;
} Pessoa;

DataNascimento CriaData(DataNascimento d)
{
    d.mes = 1 + (rand() % 12);
    d.ano = 1950 + (rand() % 49);
    d.dia = 1 + (rand() % 30);

    return d;
}

Pessoa setPessoa(char nome[], float altura, DataNascimento data, int length)
{
    Pessoa p;
    strncpy(p.nome, nome, 30); // Copia o nome para a estrutura Pessoa
    p.nome[29] = '\0';

    p.altura = altura;
    p.data = data;

    return p;
}

void listPessoa(Pessoa p)
{

    printf("-----------------------------------\n");
    printf("Nome: %s\n", p.nome);
    printf("Altura: %f\n", p.altura);
    printf("Data: %d/%d/%d\n", p.data.dia, p.data.mes, p.data.ano);
}

int comparaDataNascimento(const void *a, const void *b)
{
    Pessoa *p1 = (Pessoa *)a;
    Pessoa *p2 = (Pessoa *)b;

    if (p1->data.ano != p2->data.ano)
        return p1->data.ano - p2->data.ano;
    if (p1->data.mes != p2->data.mes)
        return p1->data.mes - p2->data.mes;
    return p1->data.dia - p2->data.dia;
}

void listPerNascimento(Pessoa pessoas[3])
{
    qsort(pessoas, 3, sizeof(Pessoa), comparaDataNascimento);
    for (int i = 0; i < 3; i++)
    {

        listPessoa(pessoas[i]);
    }
}

void criarPessoa(Pessoa pessoas[3], char nome[30], float altura, DataNascimento data)
{

    for (int i = 0; i < 3; i++)
    {
        /* code */
        printf("------------------\n");
        printf("[%d]\n", (i + 1));
        printf("Informe seu nome: ");
        scanf("%s", nome);
        printf("Informe sua altura: ");
        scanf("%f", &altura);
        int length = strlen(nome);
        pessoas[i] = setPessoa(nome, altura, CriaData(data), length);
    }
}

void menu(Pessoa pessoas[3], char nome[30], float altura, DataNascimento data)
{
    int escolha = 0;

    do
    {
        printf("Escolha sua operação: \n");
        printf("[0] - Sair\n");
        printf("[1] - Cadastrar Pessoa\n");
        printf("[2] - Listar Nomes\n");
        printf("[3] - Listar Nome em ordem da data de nascimento\n");
        scanf("%d", &escolha);

        switch (escolha)
        {
        case 1:
            criarPessoa(pessoas, nome, altura, data);
            break;
        case 2:
            for (int i = 0; i < 3; i++)
            {
                listPessoa(pessoas[i]);
            }
            break;
        case 3:
            listPerNascimento(pessoas);
            break;
        default:
            break;
        }

    } while (escolha != 0);
}

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    Pessoa pessoas[3];
    char nome[30];
    float altura;
    DataNascimento data;

    menu(pessoas, nome, altura, data);
}
