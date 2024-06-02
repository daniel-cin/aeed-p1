#include <stdio.h>
#define TAMANHO_LISTA 1000000

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
            if (A[j].Chave < A[j - 1].Chave)
            {
                aux = A[j];
                A[j] = A[j - 1];
                A[j - 1] = aux;
                troca = 1;
            }
        }
        if (troca == 0)
        {
            break;
        }
    }
}

// Function to print an array
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
}

void carregar_lista_csv(int *lista)
{
    printf("\nRead File");
    FILE *fp;
    int value;
    int i = -1;

    if ((fp = fopen("../lista_1000000_aleatoria.csv", "r")) == NULL)
        return 1;
    while (!feof(fp) && fscanf(fp, "%d", &value) && i++ < TAMANHO_LISTA)
        lista[i] = value;

    fclose(fp);
}

int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};

    printArray(arr, 7);
    Bolha(arr, 7);
    printf("\n");
    printArray(arr, 7);

    // LISTA ENORME
    static int integers[TAMANHO_LISTA];
    printf("\nRead File");
    FILE *fp;
    int value;
    int i = -1;

    if ((fp = fopen("../lista_1000000_aleatoria.csv", "r")) == NULL)
        return 1;
    while (!feof(fp) && fscanf(fp, "%d", &value) && i++ < TAMANHO_LISTA)
        integers[i] = value;

    fclose(fp);

    printf("\nOrdenar...");
    fflush(stdout) ;
    Bolha(integers, TAMANHO_LISTA);
    printf("Protno!");
    printArray(integers, TAMANHO_LISTA);
}