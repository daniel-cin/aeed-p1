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


// Utility function to swap two integers
void swap(TChave *p1, TChave *p2)
{
    TChave temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int partition(TChave arr[], int low, int high)
{
    // choose the pivot
    TChave pivot = arr[high];

    // Index of smaller element and indicate
    // the right position of pivot found so far
    int i = (low - 1);

    for (int j = low; j <= high; j++)
    {
        // If current element is smaller than the pivot
        couter_comparacao++;
        if (arr[j] < pivot)
        {
            // Increment index of smaller element
            i++;
            swap(&arr[i], &arr[j]);
            couter_movimentacao++;
        }
    }
    swap(&arr[i + 1], &arr[high]);
    couter_movimentacao++;
    return (i + 1);
}

// The Quicksort function Implement
void quickSort(TChave arr[], int low, int high)
{
    // when low is less than high
    if (low < high)
    {
        // pi is the partition return index of pivot

        int pi = partition(arr, low, high);

        // Recursion Call
        // smaller element than pivot goes left and
        // higher element goes right
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

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
    quickSort(point, 0, N_array - 1);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("TEMPO=%f;", cpu_time_used);
    printf("COMP=%u;", couter_comparacao);
    printf("REGIS=%u", couter_movimentacao);
    fflush(stdout);

    // printArray(point, N_array);


    return 0;
}
