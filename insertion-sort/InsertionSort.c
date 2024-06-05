#include <stdio.h>
#include <time.h>

#include "input.h"

///////////////
// GLOBAL    //
///////////////
unsigned int couter_comparacao = 0;
unsigned int couter_movimentacao = 0;

///////////////
// ALGORITMO //
///////////////

typedef int TChave;
typedef struct
{
    TChave Chave;
    /* outros componentes */
} TItem;

void Insercao(TItem *A, int n)
{
    int i, j;
    TItem aux;
    for (i = 2; i <= n; i++)
    {
        aux = A[i];
        A[0] = aux;
        couter_movimentacao++;
        j = i - 1;
        while (aux.Chave < A[j].Chave)
        {
            couter_comparacao++;
            A[j + 1] = A[j];
            couter_movimentacao++;
            j--;
        }
        A[j + 1] = aux;
        couter_movimentacao++;
    }
}

////////////////
// AUXILIARES //
////////////////

// Function to print an array
void printArray(int *arr, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

////////////////
//    MAIN    //
////////////////
int main(int argc, char *argv[])
{
    clock_t start, end;
    double cpu_time_used;
    int N_array = 0;
    int *point;

    //-- RECEBER INPUT
    if (argc < 3)
    {
        return -1;
    }

    //-- SELECIONAR LISTA
    int seletor_modo = atoi(argv[1]);
    int seletor_qtde = atoi(argv[2]);
    point = selecionarArray(seletor_modo, seletor_qtde);
    N_array = getTamanhoArray(seletor_qtde);

    //-- RODAR ALGORITMO DE ORDENACAO
    start = clock();
    Insercao(point, N_array);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    //-- PLOTAR RESULTADOS
    printf("TEMPO=%f;", cpu_time_used);
    printf("COMP=%u;", couter_comparacao);
    printf("REGIS=%u", couter_movimentacao);
    fflush(stdout);
}