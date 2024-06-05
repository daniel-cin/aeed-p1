#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "input.h"

// Definição dos tipos
typedef int TChave;

// Variáveis globais para contagem
unsigned int couter_comparacao = 0;
unsigned int couter_movimentacao = 0;

// Função para trocar dois elementos
void swap(TChave *xp, TChave *yp)
{
    TChave temp = *xp;
    *xp = *yp;
    *yp = temp;
    couter_movimentacao += 3; // Conta as três operações de movimentação
}

// Função de ordenação por seleção
void selectionSort(TChave arr[], int n)
{
    int i, j, min_idx;

    // Um por um, move a fronteira do subarray não ordenado
    for (i = 0; i < n - 1; i++)
    {
        // Encontra o elemento mínimo no array não ordenado
        min_idx = i;
        for (j = i + 1; j < n; j++)
        {
            couter_comparacao++; // Conta a comparação
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }

        // Troca o elemento mínimo encontrado com o primeiro elemento
        if (min_idx != i)
            swap(&arr[min_idx], &arr[i]);
    }
}

// Programa principal para testar as funções acima
int main(int argc, char *argv[])
{
    clock_t start, end;
    double cpu_time_used;
    int N_array = 0;
    TChave *point;

    if (argc < 3)
    {
        return -1;
    }

    int seletor_modo = atoi(argv[1]);
    int seletor_qtde = atoi(argv[2]);
    point = selecionarArray(seletor_modo, seletor_qtde);
    N_array = getTamanhoArray(seletor_qtde);

    start = clock();
    selectionSort(point, N_array);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("TEMPO=%f;", cpu_time_used);
    printf("COMP=%u;", couter_comparacao);
    printf("REGIS=%u", couter_movimentacao);
    fflush(stdout);

    free(point);

    return 0;
}
