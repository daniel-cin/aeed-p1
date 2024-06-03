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

void Bolha(TItem *A, int n)
{
    int i, j;
    int troca;
    TItem aux;

    for (i = 0; i < n - 1; i++)
    {
        troca = 0;
        for (j = 1; j < n - 1; j++)
        {   
            couter_comparacao ++;
            if (A[j].Chave < A[j - 1].Chave)
            {
                aux = A[j];
                A[j] = A[j - 1];
                A[j - 1] = aux;
                couter_movimentacao++;
                troca = 1;
            }
        }
        if (troca == 0)
        {
            break;
        }
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
    int N_array=0;
    int *point;

    //-- RECEBER INPUT
    if (argc < 3)
    {
        return -1;
    }

    //-- SELECIONAR LISTA
    int seletor_modo = atoi(argv[1]);
    int seletor_qtde = atoi(argv[2]);
    point   = selecionarArray( seletor_modo, seletor_qtde);
    N_array = getTamanhoArray(seletor_qtde);
    // printArray(point, N_array);
    

    //-- RODAR ALGORITMO DE ORDENACAO
    start = clock();
    Bolha(point, N_array);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    // printArray(point, N_array);

    //-- PLOTAR RESULTADOS
    printf("\n TEMPO = %f\n", cpu_time_used);
    printf("\n COMP = %u\n", couter_comparacao);
    printf("\n REGIS = %u\n", couter_movimentacao);
    fflush(stdout);
}