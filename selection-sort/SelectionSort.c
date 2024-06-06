#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "input.h"

// Definição dos tipos
typedef int TChave;
typedef struct
{
    TChave Chave;
    /* outros componentes */
} TItem;

// Variáveis globais para contagem
unsigned int couter_comparacao = 0;
unsigned int couter_movimentacao = 0;

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
// ALGORITMO  //
////////////////
void Selecao(TItem *A, int n)
{
    int i, j, Min;
    TItem aux;
    for (i = 0; i < n-1; i++)
    {
        Min = 1;
        for (j = i + 1; j < n; j++)
        {   
            couter_comparacao++;
            if (A[j].Chave < A[Min].Chave)
            {
                Min = j;
            }
        }

        if (i != Min)
        {
            aux = A[Min];
            A[Min] = A[i];
            A[i] = aux;
            couter_movimentacao += 3; 
        }
    }
}

// Programa principal para testar as funções acima
int main(int argc, char *argv[])
{
    clock_t start, end;
    double cpu_time_used;
    int N_array = 0;
    // TChave *point;
    int *point;

    if (argc < 3)
    {
        return -1;
    }

    int seletor_modo = atoi(argv[1]);
    int seletor_qtde = atoi(argv[2]);
    point = selecionarArray(seletor_modo, seletor_qtde);
    N_array = getTamanhoArray(seletor_qtde);

    start = clock();
    Selecao(point, N_array);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("TEMPO=%f;", cpu_time_used);
    printf("COMP=%u;", couter_comparacao);
    printf("REGIS=%u", couter_movimentacao);
    fflush(stdout);


        return 0;
}
