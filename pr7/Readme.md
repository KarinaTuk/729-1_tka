# Введение

Цель работы - изучение базовых команд терминала ОС Linux, получение навыков работы с алгоритмами сортировки в языке программирования C.

## Задание

Необходимо реализовать программу на языке C, реализующую быструю и пирамидальную сортировки.

1.  Программа принимает на вход количество элементов и на отдельной строке массив элементов;
2. Программа выводит в stdout отсортированный по возрастанию массив;
3. В файл quicksort.log записывается порядок преобразования массива с помощью алгоритма быстрой сортировки.
4. В heapsort.log записывается порядок преобразования массива алгоритмом пирамидальной сортировки.

## Ход работы

Для выполнения работы, были разработы функции для алгоритма быстрой и пирамидальной сортировок.

Код, реализующий сортировку с помощью двух алгоримтов, представлен ниже.

```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printQuickSort(int *arr, int n)
{
  FILE *fout;
  fout = fopen("quicksort.log", "a+");
  for (int i = 0; i < n; ++i)
    fprintf(fout, "%d ", arr[i]);
  fprintf(fout, "\n");
  fclose(fout);
}

void printHeapSort(int *arr, int n)
{
  FILE *fout;
  fout = fopen("heapsort.log", "a+");
  for (int i = 0; i < n; ++i)
    fprintf(fout, "%d ", arr[i]);
  fprintf(fout, "\n");
  fclose(fout);
}

void quicksort(int *arr, int first, int last, int n)
{
    if (first < last)
    {
        int left = first; 
        int right = last;
        int middle = arr[(left + right) / 2];
        do
        {
            while (arr[left] < middle) 
                left++;
            while (arr[right] > middle) 
                right--;
            if (left <= right)
            {
                int tmp = arr[left];
                arr[left] = arr[right];
                arr[right] = tmp;
                left++;
                right--;
	            printQuickSort(arr, n);
            }
        } while (left <= right);
        quicksort(arr, first, right, n);
        quicksort(arr, left, last, n);
    }
}

void heapify(int *arr, int n, int i)
{
    int largest = i;
    // Инициализируем наибольший элемент как корень
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
    // Если левый дочерний элемент больше корня
    if (l < n && arr[l] > arr[largest])
        largest = l;
       // Если правый дочерний элемент больше, чем самый большой элемент на данный момент
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        
        heapify(arr, n, largest);
    }
}

// Пирамидальная сортировка
void heapSort(int *arr, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    // Один за другим извлекаем элементы из кучи
    for (int i = n - 1; i >= 0; i--)
    {
        // Перемещаем текущий корень в конец
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        printHeapSort(arr, n);
        heapify(arr, i, 0);
    }
}

int main()
{
  int *arrForQuickSort = NULL;
  int *arrForHeapSort = NULL;
  int size;
  scanf("%d", &size);
  arrForQuickSort = (int *)realloc(arrForQuickSort, size * sizeof(int));
  arrForHeapSort = (int *)realloc(arrForHeapSort, size * sizeof(int));
  for (int i = 0; i < size; i++)
  {
    scanf("%d", &arrForQuickSort[i]);
    arrForHeapSort[i] = arrForQuickSort[i];
  }
  quickSort(arrForQuickSort, 0, size - 1);
  heapSort(arrForHeapSort, size);
  for (int i = 0; i < size; i++)
  {
    printf("%d ", arrForHeapSort[i]);
  }
  printf("\n");
  return 0;
}
```

### Таблица в входными и выходными данными

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
