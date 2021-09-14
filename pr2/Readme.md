# Введение

Цель: Написать две программы на языке программирования C. Сделать блок-схемы для этих задач. Отредактировать pipeline для данной работы. Составить отчёт, используя язык разметки Markdown.

## Задание

1) Cумма последовательности. На вход подаётся число 𝑛 ∈ N : 𝑛 ≤ 2147483647,  а также 𝑛 чисел 𝑥𝑖 ∈ Z : |𝑥𝑖| ≤ 2147483647 для любого целого 𝑖 от 1 до 𝑛. Вывести значение ∑︁𝑥𝑖 для 𝑖 от 1 до n.
2)  Сумма квадратов. На вход подаётся число 𝑛 ∈ N : 𝑛 ≤2147483647,  а также 𝑛 чисел 𝑥𝑖 ∈ Z : |𝑥𝑖| ≤ 2147483647 для любого целого 𝑖 от 1 до 𝑛. Вывести значение ∑︁𝑥^2 для i от 1 до n.
***

# Ход работы

## Код 08_cnt_not_positive.c

```
#include <stdio.h>

int main(){
    double n, x, i, count;
    count = 0;
    int tempValue = scanf("%lf", &n);
    if(tempValue == 1){
        for(i = 1; i <= n; i++){
            tempValue = scanf("%lf", &x);
            if(tempValue == 1){
                if(x <= 0)
                {
		            count++;
                }
            }
        }

        printf("%lf\n", count);
    }

    return 0;
}
```

На рисунке снизу представленна блок-схема данного алгоритма


## Код 18_sum_of_list.c

```
#include <stdio.h>

int main(){
    double n, x, i, sum = 0;
    int temp = scanf("%lf", &n);
    if(temp == 1){
        for(i = 1; i <= n; i++){
            temp = scanf("%lf", &x);
            if(temp == 1){
                sum += x - i;
            }
        }

        printf("%lf\n", sum);
    }
    else
    {
        return 1;
    }
    return 0;
}

```

На рисунке ниже представленна блок-схема данного алгоритма


***
Загружаем программы на gitlab, проверяем их на pipeline. На рисунке, показанно, что все программы успешно прошли проверки.

[![](https://gitlab.com/Tukhvatulina/practices-729-1-tka/-/raw/master/pr2/pr2_pipeline.png)](https://gitlab.com/Tukhvatulina/practices-729-1-tka/-/blob/master/pr2/pr2_pipeline.png)

# Вывод

В ходе выполения практической работы были написаны 2 программы на языке C, составлены блок-схемы. Составлен отчёт в Markdown.
