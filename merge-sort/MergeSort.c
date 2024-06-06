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
} TItem;

// Variáveis globais para contagem
unsigned int couter_comparacao = 0;
unsigned int couter_movimentacao = 0;

// Function to print an array
void printArray(TItem *arr, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


void mergeSort_intercala(TItem *A, TItem *B, int p, int q, int r)
{
    int i, j, k;
    i = p;
    j = q + 1;
    k = p;

    while (i <= q && j <= r)
    {
        couter_comparacao++;
        if (A[i].Chave <= A[j].Chave)
        {
            B[k] = A[i];
            i = i + 1;
        }
        else
        {
            B[k] = A[j];
            j = j + 1;
        }
        k = k + 1;
        couter_movimentacao++;
    }

    while (i <= q)
    {
        B[k] = A[i];
        i = i + 1;
        k = k + 1;
        couter_movimentacao++;
    }

    while (j <= r)
    {
        B[k] = A[j];
        j = j + 1;
        k = k + 1;
        couter_movimentacao++;
    }

    for (i = p; i <= r; i++)
    {
        A[i] = B[i];
        couter_movimentacao++;
    }
}

void mergeSort_ordena(TItem *A, TItem *B, int p, int r)
{
    int q;
    if (p < r)
    {
        q = (p + r) / 2;
        mergeSort_ordena(B, A, p, q);
        mergeSort_ordena(B, A, q + 1, r);
        mergeSort_intercala(A, B, p, q, r);
    }
}

void mergeSort(TItem *A, int n)
{
    TItem *B;
    B = (TItem *)malloc(n * sizeof(TItem));
    if (B == NULL)
    {
        fprintf(stderr, "Memória insuficiente\n");
        exit(1);
    }
    memcpy(B, A, n * sizeof(TItem));
    mergeSort_ordena(B, A, 0, n - 1);
    free(B);
}

int main(int argc, char *argv[])
{
    clock_t start, end;
    double cpu_time_used;
    int N_array = 0;
    TItem *point;

    if (argc < 3)
    {
        return -1;
    }

    int seletor_modo = atoi(argv[1]);
    int seletor_qtde = atoi(argv[2]);
    point = selecionarArray(seletor_modo, seletor_qtde);
    N_array = getTamanhoArray(seletor_qtde);

    start = clock();
    mergeSort(point, N_array);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("TEMPO=%f;", cpu_time_used);
    printf("COMP=%u;", couter_comparacao);
    printf("REGIS=%u", couter_movimentacao);
    fflush(stdout);

    // printArray(point, N_array);

    return 0;
}
