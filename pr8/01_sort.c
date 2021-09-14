#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printArrayShell(int *arr, int n)
{
    FILE *fout;
    fout = fopen("shellSort.log", "a+");
    for (int i = 0; i < n; ++i)
        fprintf(fout, "%d ", arr[i]);
    fprintf(fout, "\n");
    fclose(fout);
}

void printArrayComb(int *arr, int n)
{
    FILE *fout;
    fout = fopen("combSort.log", "a+");
    for (int i = 0; i < n; ++i)
        fprintf(fout, "%d ", arr[i]);
    fprintf(fout, "\n");
    fclose(fout);
}

void shellSort(int *array, int size)
{
    int cnt = 0;
    for (int s = size / 2; s > 0; s /= 2)
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = i + s; j < size; j += s)
            {
                if (array[i] > array[j])
                {
                    int temp = array[j];
                    array[j] = array[i];
                    array[i] = temp;
                    cnt++;
                }
            }
        }
        printArrayShell(array, size);
    }
}

void combSort(int *array, int size)
{
    int cnt = 0;
    double factor = 1.2473309;
    int step = size - 1;
    while (step >= 1)
    {
        for (int i = 0; i + step < size; i++)
        {
            if (array[i] > array[i + step])
            {
                int temp = array[i];
                array[i] = array[i + step];
                array[i + step] = temp;
                ++cnt;
            }
        }
        printArrayComb(array, size);
        step /= factor;
    }
}

int main()
{
    int size;
    scanf("%d", &size);
    int *arr = (int *)malloc(size * sizeof(int));
    int *arr2 = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
        arr2[i] = arr[i];
    }
    shellSort(arr, size);
    combSort(arr2, size);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
