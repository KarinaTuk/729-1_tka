# Введение

Цель работы - изучение базовых команд терминала ОС Linux, получение навыков работы с двусвязными списками в языке программирования C.

## Задание

Необходимо реализовать программу на языке C с заданными функциями, которая:

1. считывает количество элементов n, 0 < n <= 2147483647;
2. создает пустой список, считывает n элементов a, |a| <= 2147483647 и заносит их в список;
3. выводит содержимое списка, используя функцию print;
4. считывает k1, k2, k3 (|k| <= 2147483647) и выводит "1", если в списке существует элемент с таким значением и "0" если нет (выводить через пробел, например "1 0 1");
5. считывает m, |m| <= 2147483647 и вставляет его в конец списка;
6. выводит содержимое списка, используя функцию print_invers;
7. считывает t, |t| <= 2147483647 и вставляет его в начало списка;
8. выводит содержимое списка, используя функцию print;
9. считывает j и x (0 < j <= 2147483647, |x| <= 2147483647) и вставляет значение x после j-ого элемента списка;
10. выводит содержимое списка, используя функцию print_invers;
11. считывает u и y (0 < u <= 2147483647, |y| <= 2147483647) и вставляет значение y перед u-ым элементом списка;
12. выводит содержимое списка, используя функцию print;
13. считывает z, |z| <= 2147483647 и удаляет первый элемент (при его наличии), хранящий значение z из списка;
14. выводит содержимое списка, используя функцию print_invers;
15. считывает r, |r| <= 2147483647 и удаляет последний элемент (при его наличии), хранящий значение r из списка;
16. выводит содержимое списка, используя функцию print;
17. очищает список.

## Ход работы

Для выполнения работы были реализованы функции: инициализация пустого списка, удаление всех элементов из списка, проверка на пустоту списка, поиск элемента по значению, вставка элемента в конец/начало списка, вставка значение перед/после указанного узла, удалить первый/последний элемент из списка, вывести все элементы списка в прямом/обратном порядке через пробел.

Код программы реализующей эти функции представлен ниже.

```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
int value; // значение узла
struct node* next; // следующий узел
struct node* prev; // предыдущий узел
} node; // структура узла

typedef struct list {
struct node* head; // начальный элемент
struct node* tail; // конечный элемент
} list; // структура списка

/// <summary>
/// Инициализация списка
/// </summary>
/// <param name="l">список</param>
void init(list* l)
{
list* tmp = (list*)malloc(sizeof(list));
tmp->head = tmp->tail = NULL;
*l = *tmp;
}

/// <summary>
/// Удалить все элементы списка
/// </summary>
/// <param name="l">список</param>
void clean(list* l)
{
node* tempNode = l->head; // передали адрес начального узла списка
node* removeNode = (node*)malloc(sizeof(node)); // узел для удаления
while (tempNode) // пока есть элементы
{
removeNode = tempNode;
tempNode = tempNode->next;
free(removeNode);
}
l->head = NULL;
l->tail = NULL;
}

/// <summary>
/// Проверка списка на пустоту
/// </summary>
/// <param name="l">список</param>
/// <returns>True - пустой список, False - в списке есть значения</returns>
bool is_empty(list* l)
{
if (l->head == NULL)
return 1;
else return 0;
}

/// <summary>
/// Поиск узла по значению
/// </summary>
/// <param name="l">Список</param>
/// <param name="value">Значение для поиска узла</param>
/// <returns>(node*) - узел найден, NULL - указанного значение в списке нет</returns>
node* find(list* l, int value)
{
node* tempNode = l->head; // адрес первого узла
while (tempNode) // пока есть элементы в списке
{
if (tempNode->value == value) // нашли значение
{
return tempNode; // вернули узел
}
tempNode = tempNode->next; // смотрим следующий элемент
}
return NULL;
}

/// <summary>
/// Добавление значение в конец списка
/// </summary>
/// <param name="l">список</param>
/// <param name="value">значение для добавления</param>
/// <returns>0 - успешное добавление</returns>
int push_back(list* l, int value)
{
node* tempNode = (node*)malloc(sizeof(node)); // выделение памяти под узел
if (tempNode == NULL)
{
return 0;
}
// инициализируем узел, кладем значение, следующий узел NULL, предыдущий - последний узел списка
tempNode->value = value;
tempNode->next = NULL;
tempNode->prev = l->tail;
if (l->tail) // последний элемент списка есть
{
l->tail->next = tempNode; // после последнего элемента новый узел
}
l->tail = tempNode; // новый узел - новый конец списка

if (l->head == NULL) // если голова пустая
{
l->head = tempNode; // голова - последний элемент списка
}
return 0;
}

/// <summary>
/// Добавление элемента в начало списка
/// </summary>
/// <param name="l">список</param>
/// <param name="value">значение для добавления</param>
/// <returns>0 - успешное добавление</returns>
int push_front(list* l, int value)
{
node* tempNode = (node*)malloc(sizeof(node)); // выделение памяти под узел
tempNode->value = value; // положили значение в узел
if (l->head == NULL) // если голова пустая
{
// значит список пустой
// голова и хвост -> новый узел
l->head = tempNode;
l->tail = tempNode;
}
else
{
// узел теперь головной
tempNode->next = l->head;
tempNode->next->prev = tempNode;
l->head = tempNode;
}
if (tempNode)
{
return 0;
}
}

/// <summary>
/// Добавление элемента после указанного узла
/// </summary>
/// <param name="l">список</param>
/// <param name="n">узел</param>
/// <param name="value">значение для добавления</param>
/// <returns>0 - успешная вставка</returns>
int insert_after(list* l, node* n, int value) {
node* tempNode = (node*)malloc(sizeof(node)); // выделение памяти под узел
if (n->next == NULL) // если нет следующего узла
{
tempNode->prev = n;
n->next = tempNode;
l->tail = tempNode;
tempNode->value = value;
return 0;
}
tempNode->value = value;
tempNode->prev = n;
tempNode->next = n->next;
n->next->prev = tempNode;
n->next = tempNode;
return 0;
}

/// <summary>
/// Добавление элемента перед указанным узлом
/// </summary>
/// <param name="l">список</param>
/// <param name="n">узел</param>
/// <param name="value">значение для добавления</param>
/// <returns>0 - успешная вставка</returns>
int insert_before(list* l, node* n, int value)
{
node* tempNode = (node*)malloc(sizeof(node)); // выделение памяти под узел
if (n->prev == NULL) // если предыдущего элемента нет
{
tempNode->next = n;
n->prev = tempNode;
l->head = tempNode;
tempNode->value = value;
return 0;
}
tempNode->value = value;
tempNode->prev = n->prev;
n->prev->next = tempNode;
tempNode->next = n;
n->prev = tempNode;
return 0;
}

/// <summary>
/// Удаление указанного значения из списка
/// </summary>
/// <param name="l">список</param>
/// <param name="value">значение для удаления</param>
/// <returns>0 - успешное удаление</returns>
int remove_node(list* l, int value)
{
node* tempNode = l->head;
while (tempNode != NULL) { // пока есть узлы
if (tempNode->value == value) { // нашли узел с заданным значением
if (tempNode->prev) { // если есть предыдущий элемент
tempNode->prev->next = tempNode->next; // скрепляем предыдущий и следующий узлы от указанного узла
}
if (tempNode->next) { // если есть следующий элемент
tempNode->next->prev = tempNode->prev; // скрепляем предыдущий и следующий узлы от указанного узла
}
if (!tempNode->prev) { // если предыдущиего элемента нет, значит головной узел
l->head = tempNode->next;
}
if (!tempNode->next) { // если следующего элемента нет, значит хвост
l->tail = tempNode->prev;
}
free(tempNode);
return 0;
}
else {
tempNode = tempNode->next;
}
}
return 1;
}

/// <summary>
/// Поиск последнего элемента в списке с заданным значением
/// </summary>
/// <param name="l">список</param>
/// <param name="value">значение для поиска</param>
/// <returns>(node*) - нашли элемент, NULL - такого элемента нет</returns>
node* findlast(list* l, int value) {
node* tempNode = l->tail;
if (!l->head) {
return NULL;
}
while (tempNode) {
if (tempNode->value == value)
return tempNode;
tempNode = tempNode->prev;
}
return NULL;
}

/// <summary>
/// Удаление посдледнего элемента с указанным значением
/// </summary>
/// <param name="l"></param>
/// <param name="value">значение для поиска</param>
/// <returns>0 - успешное удаление</returns>
int remove_last(list* l, int value) {
if (l->head == NULL) {
return 1;
}
node* tempNode = findlast(l, value);
if (tempNode != NULL) {
node* prevNode = tempNode->prev;
node* nextNode = tempNode->next;
if (prevNode != NULL) {
prevNode->next = nextNode;
}
if (nextNode != NULL) {
nextNode->prev = prevNode;
}
if (tempNode == l->head) {
l->head = tempNode->next;
}
if (tempNode == l->tail) {
l->tail = tempNode->prev;
}
free(tempNode);
}
return 0;
}

/// <summary>
/// Вывод элементов в прямом порядке
/// </summary>
/// <param name="l">список</param>
void print(list* l)
{
node* tempNode = l->head;
if (tempNode == NULL) {
return;
}
while (tempNode != NULL) {
printf("%d ", tempNode->value);
tempNode = tempNode->next;
}
printf("\n");
}

/// <summary>
/// Вывод элементов списка в обратном порядке
/// </summary>
/// <param name="l">список</param>
void print_invers(list* l)
{
node* tempNode = l->tail;
if (tempNode == NULL) {
return;
}
while (tempNode != NULL) {
printf("%d ", tempNode->value);
tempNode = tempNode->prev;
}
printf("\n");
}

int main() {
list* l; // объявление списка
init(l); // инициализация списка
int n, values, i;
scanf("%d", &n); // считывание значения
for (int i = 0; i < n; i++) // ввод n элементов в список
{
scanf("%d", &values);
push_back(l, values);
}
print(l); // вывод списка
for (int i = 0; i < 3; i++) // поиск 3 элементов в списке 1 - есть, 0 - нет
{
scanf("%d", &values);
if (find(l, values) == NULL)
{
printf("%d ", 0);
}
else
{
printf("%d ", 1);
}

}
printf("\n");
scanf("%d", &values);
push_back(l, values); // добавление элемента в конец
print_invers(l);
scanf("%d", &values);
push_front(l, values); // добавление элемента в начало
print(l);
int j, x;
scanf("%d", &j);
scanf("%d", &x);
node* temp = l->head;
for (i = 1; i < j; i++)
{
temp = temp->next;
}
insert_after(l, temp, x); // добавление элемента после указанного узла
print_invers(l);
int u, y;
scanf("%d", &u);
scanf("%d", &y);
temp = l->head;
for (i = 1; i < u; i++)
{
temp = temp->next;
}
insert_before(l, temp, y); // доабвление элемента перед указанным узлом
print(l);
scanf("%d", &values);
remove_node(l, values); // удаление узла по значению
print_invers(l);
scanf("%d", &values);
remove_last(l, values); // удаление последнего найденного значения
print(l);
clean(l); // очистка списка
return 0;
}

```

### Таблица с входными и выходными данными

***
|input | output |
|-----------------:|:-------------------:|
|5 | |
|1 2 3 2 4  | 1 2 3 2 4 |
|2 5 1| 1 0 1 |
|1 | 1 4 2 3 2 1 |
|7 | 7 1 2 3 2 4 1|
|3 0 | 1 4 2 3 0 2 1 7 |
|5 8 | 7 1 2 0 8 3 2 4 1 |
|2 | 1 4 2 3 8 0 1 7 |
|1 | 7 1 0 8 3 2 4|
***

Написанная программа успешно проходит pipeline.

[![](https://gitlab.com/Tukhvatulina/practices-729-1-tka/-/raw/master/pr4/pr4_pipeline.png)](https://gitlab.com/Tukhvatulina/practices-729-1-tka/-/blob/master/pr4/pr4_pipeline.png)

## Заключение

Были получены навыки работы с двусвязными списками в C.
Был составлен отчёт с помощью языка разметки Markdown.
