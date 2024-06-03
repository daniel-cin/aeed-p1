#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "input.h"

typedef int TChave;

typedef struct
{
    TChave Chave;
    /* outros componentes */
} TItem;

unsigned int couter_comparacao = 0;
unsigned int couter_movimentacao = 0;

// Função auxiliar para busca binária
int librarySort_lower_bound(TItem *A, int n, TChave value)
{
    int low = 0, high = n;
    while (low < high)
    {
        int mid = (low + high) / 2;
        couter_comparacao++;
        if (A[mid].Chave < value)
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }
    return low;
}

void librarySort(TItem *A, int n)
{
    int lib_size, index_pos;
    int *numbered;
    TItem *gaps, *library[2];
    int target_lib;

    for (int i = 0; i < 2; i++)
        library[i] = (TItem *)malloc(n * sizeof(TItem));

    gaps = (TItem *)malloc((n + 1) * sizeof(TItem));
    numbered = (int *)malloc((n + 1) * sizeof(int));

    lib_size = 1;
    index_pos = 1;
    target_lib = 0;
    library[target_lib][0] = A[0];
    couter_movimentacao++; // Incrementa o contador de movimentações

    for (int i = 0; i <= n; i++)
        numbered[i] = 0;

    while (index_pos < n)
    {
        int insert = librarySort_lower_bound(library[target_lib], lib_size, A[index_pos].Chave);

        if (numbered[insert] == 1)
        {
            int prov_size = 0, next_target_lib = !target_lib;

            for (int i = 0; i <= n; i++)
            {
                if (numbered[i] == 1)
                {
                    library[next_target_lib][prov_size] = gaps[i];
                    prov_size++;
                    numbered[i] = 0;
                    couter_movimentacao++; // Incrementa o contador de movimentações
                }

                if (i < lib_size)
                {
                    library[next_target_lib][prov_size] = library[target_lib][i];
                    prov_size++;
                    couter_movimentacao++; // Incrementa o contador de movimentações
                }
            }

            target_lib = next_target_lib;
            lib_size = prov_size;
        }
        else
        {
            numbered[insert] = 1;
            gaps[insert] = A[index_pos];
            index_pos++;
            couter_movimentacao++;
        }
    }

    int index_pos_for_output = 0;
    for (int i = 0; index_pos_for_output < n; i++)
    {
        if (numbered[i] == 1)
        {
            A[index_pos_for_output] = gaps[i];
            index_pos_for_output++;
            couter_movimentacao++;
        }

        if (i < lib_size)
        {
            A[index_pos_for_output] = library[target_lib][i];
            index_pos_for_output++;
            couter_movimentacao++;
        }
    }

    for (int i = 0; i < 2; i++)
        free(library[i]);
    free(gaps);
    free(numbered);
}

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
    librarySort(point, N_array);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nNumero de comparacoes: %d\n", couter_comparacao);
    printf("Numero de movimentacoes: %d\n", couter_movimentacao);
    printf("Tempo total gasto: %.9f segundos\n", cpu_time_used);

    return 0;
}
