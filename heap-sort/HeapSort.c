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

////////////////
// AUXILIARES //
////////////////

// Function to print an array
void printArray(TChave *arr, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to swap the position of two elements
void swap(TChave *a, TChave *b)
{
    TChave temp = *a;
    *a = *b;
    *b = temp;
    couter_movimentacao += 3; // Conta as três operações de movimentação
}

// To heapify a subtree rooted with node i
// which is an index in arr[].
// n is size of heap
void heapify(TChave arr[], int N, int i)
{
    // Find largest among root,
    // left child and right child

    // Initialize largest as root
    int largest = i;

    // left = 2*i + 1
    int left = 2 * i + 1;

    // right = 2*i + 2
    int right = 2 * i + 2;

    // If left child is larger than root
    if (left < N && arr[left] > arr[largest])
    {
        largest = left;
        couter_comparacao++;
    }

    // If right child is larger than largest
    // so far
    if (right < N && arr[right] > arr[largest])
    {
        largest = right;
        couter_comparacao++;
    }

    // Swap and continue heapifying
    // if root is not largest
    // If largest is not root
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        // Recursively heapify the affected
        // sub-tree
        heapify(arr, N, largest);
    }
}

// Main function to do heap sort
void heapSort(TChave arr[], int N)
{
    // Build max heap
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);

    // Heap sort
    for (int i = N - 1; i >= 0; i--)
    {
        swap(&arr[0], &arr[i]);
        // Heapify root element
        // to get highest element at
        // root again
        heapify(arr, i, 0);
    }
}

// Driver's code
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
    // printArray(point, N_array);

    start = clock();
    heapSort(point, N_array);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("TEMPO=%f;", cpu_time_used);
    printf("COMP=%u;", couter_comparacao);
    printf("REGIS=%u", couter_movimentacao);
    fflush(stdout);

    // printArray(point, N_array);

    // free(point);

    return 0;
}
