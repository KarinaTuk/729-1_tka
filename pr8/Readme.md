# Введение

Цель работы - изучение базовых команд терминала ОС Linux, получение навыков работы с алгоритмами сортировки в языке программирования C.

## Задание

Необходимо реализовать программу на языке C, реализующую сортировки: Шелла и "Расческа".

1.  Программа принимает на вход количество элементов и на отдельной строке массив элементов;
2. Программа выводит в stdout отсортированный по возрастанию массив;
3. В файл shellSort.log записывается порядок преобразования массива с помощью алгоритма сортировки Шелла.
4. В combSort.log записывается порядок преобразования массива алгоритмом сортировки "Расческа".

## Ход работы

Для выполнения работы, были разработаны программы для реализации двух алгоритмов сортировки.

Код, реализующий сортировки Шелла и Расческа, представлен ниже

```c
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
```

### Таблица с входными и выходными данными

Таблица с результатами.

***
|input | output |
|-----------------:|:-------------------:|
|8 | |
|-74 70 -23 -68 -62 -53 41 44  | -74 -68 -62 -53 -23 41 44 70 |
***

## Заключение

Были получены навыки работы с алгоритмами сортировки в C.
Был составлен отчёт с помощью языка разметки Markdown.
