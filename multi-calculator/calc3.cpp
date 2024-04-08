#include <iostream>
#include <stdbool.h>
#include <string.h>
#include <locale.h>
#include "Header3.h"

#define MAX 1000
#define MAXDIGIT 100

// Вывод массива
void PrintArray(int* arr, int num)
{
    for (int i = num - 1; i >= 0; i--)
    {
        printf("%d", arr[i]);
    }
    printf("\n");
}

// Умножение
void Multiply(int* result, int& num, int n)
{
    int c = 0;
    for (int i = 0; i < num || c != 0; i++)
    {
        int m;
        if (i < num)
        {
            m = result[i] * n;
        }
        else
        {
            m = 0;
        }
        m += c;
        result[i] = m % 10;
        c = m / 10;
        if (i >= num)
        {
            num++;
        }
    }
}

// Деление
void Divide(int* result, int& num, int n)
{
    int c = 0;
    for (int i = num - 1; i >= 0; i--)
    {
        int cur = c * 10 + result[i];
        result[i] = cur / n;
        c = cur % n;
    }
    while (num > 1 && result[num - 1] == 0)
    {
        num--;
    }
}

// Размещения с повторениями реализация
void PlacementsWithRepFunc(int n, int k)
{
    int* result = new int[MAX];
    int num = 1;
    result[0] = 1;

    for (int i = 0; i < k; i++)
    {
        Multiply(result, num, n);
    }

    printf("Размещения с повторениями: ");
    PrintArray(result, num);
    printf("\n");

    delete[] result;
}

// Размещения без повторений реализация
void PlacementsWithoutRepFunc(int n, int k)
{
    int* result = new int[MAX];
    int num = 1;
    result[0] = 1;

    for (int i = n; i > n - k; i--)
    {
        Multiply(result, num, i);
    }

    printf("Размещения без повторений: ");
    PrintArray(result, num);
    printf("\n");

    delete[] result;
}

// Сочетания с повторениями реализация
void CombinationsWithRepFunc(int n, int k)
{
    int* result = new int[MAX];
    int num = 1;
    result[0] = 1;

    for (int i = n + k - 1; i > 1; i--)
    {
        Multiply(result, num, i);
    }

    for (int i = 2; i <= k; i++)
    {
        Divide(result, num, i);
    }

    for (int i = 2; i <= n - 1; i++)
    {
        Divide(result, num, i);
    }

    printf("Сочетания с повторениями: ");
    PrintArray(result, num);
    printf("\n");

    delete[] result;
}

// Сочетания без повторений реализация
void CombinationsWithoutRepFunc(int n, int k)
{
    int* result = new int[MAX];
    int num = 1;
    result[0] = 1;

    for (int i = n; i > n - k; i--)
    {
        Multiply(result, num, i);
    }

    for (int i = 2; i <= k; i++)
    {
        Divide(result, num, i);
    }

    printf("Сочетания без повторений: ");
    PrintArray(result, num);
    printf("\n");
    delete[] result;
}

// Перестановки реализация
void PermutationsFunc(int n)
{
    int* result = new int[MAX];
    int num = 1;
    result[0] = 1;

    for (int i = 2; i <= n; i++)
    {
        Multiply(result, num, i);
    }

    printf("Количество перестановок: ");
    PrintArray(result, num);
    printf("\n");
    delete[] result;
}

// Размещения с повторениями
void PlacementsWithRep()
{
    char n, k;
    do
    {
        printf("Введите количество элементов (число n из интервала [1,100]): ");
        scanf_s(" %c", &n, 1);
        getchar();

        printf("Введите количество элементов (число k из интервала [1,100]): ");
        scanf_s(" %c", &k, 1);
        getchar();

        if (((n - '0') < 1 || (n - '0') > MAXDIGIT) || ((k - '0') < 1 || (k - '0') > MAXDIGIT) || ((n - '0') < (k - '0')) || n < 48 || n > 57 || k < 48 || k > 57)
        {
            printf("Некорректный ввод. Повторите попытку!\n");
        }
    } while (((n - '0') < 1 || (n - '0') > MAXDIGIT) || ((k - '0') < 1 || (k - '0') > MAXDIGIT) || ((n - '0') < (k - '0')) || n < 48 || n > 57 || k < 48 || k > 57);
    int digit1 = n - '0';
    int digit2 = k - '0';
    PlacementsWithRepFunc(digit1, digit2);
}

// Размещения без повторений
void PlacementsWithoutRep()
{
    char n, k;
    do
    {
        printf("Введите количество элементов (число n из интервала [1,100]): ");
        scanf_s(" %c", &n, 1);
        getchar();

        printf("Введите количество элементов (число k из интервала [1,100]): ");
        scanf_s(" %c", &k, 1);
        getchar();

        if (((n - '0') < 1 || (n - '0') > MAXDIGIT) || ((k - '0') < 1 || (k - '0') > MAXDIGIT) || ((n - '0') < (k - '0')) || n < 48 || n > 57 || k < 48 || k > 57)
        {
            printf("Некорректный ввод. Повторите попытку!\n");
        }
    } while (((n - '0') < 1 || (n - '0') > MAXDIGIT) || ((k - '0') < 1 || (k - '0') > MAXDIGIT) || ((n - '0') < (k - '0')) || n < 48 || n > 57 || k < 48 || k > 57);
    int digit1 = n - '0';
    int digit2 = k - '0';
    PlacementsWithoutRepFunc(digit1, digit2);
}

// Сочетания с повторениями
void CombinationsWithRep()
{
    char n, k;
    do
    {
        printf("Введите количество элементов (число n из интервала [1,100]): ");
        scanf_s(" %c", &n, 1);
        getchar();

        printf("Введите количество элементов (число k из интервала [1,100]): ");
        scanf_s(" %c", &k, 1);
        getchar();

        if (((n - '0') < 1 || (n - '0') > MAXDIGIT) || ((k - '0') < 1 || (k - '0') > MAXDIGIT) || ((n - '0') < (k - '0')) || n < 48 || n > 57 || k < 48 || k > 57)
        {
            printf("Некорректный ввод. Повторите попытку!\n");
        }
    } while (((n - '0') < 1 || (n - '0') > MAXDIGIT) || ((k - '0') < 1 || (k - '0') > MAXDIGIT) || ((n - '0') < (k - '0')) || n < 48 || n > 57 || k < 48 || k > 57);
    int digit1 = n - '0';
    int digit2 = k - '0';
    CombinationsWithRepFunc(digit1, digit2);
}

// Сочетания без повторений
void CombinationsWithoutRep()
{
    char n, k;
    do
    {
        printf("Введите количество элементов (число n из интервала [1,100]): ");
        scanf_s(" %c", &n, 1);
        getchar();

        printf("Введите количество элементов (число k из интервала [1,100]): ");
        scanf_s(" %c", &k, 1);
        getchar();

        if (((n - '0') < 1 || (n - '0') > MAXDIGIT) || ((k - '0') < 1 || (k - '0') > MAXDIGIT) || ((n - '0') < (k - '0')) || n < 48 || n > 57 || k < 48 || k > 57)
        {
            printf("Некорректный ввод. Повторите попытку!\n");
        }
    } while (((n - '0') < 1 || (n - '0') > MAXDIGIT) || ((k - '0') < 1 || (k - '0') > MAXDIGIT) || ((n - '0') < (k - '0')) || n < 48 || n > 57 || k < 48 || k > 57);
    int digit1 = n - '0';
    int digit2 = k - '0';
    CombinationsWithoutRepFunc(digit1, digit2);
}

// Перестановки
void Permutations()
{
    char n;
    do
    {
        printf("Введите количество элементов (число n из интервала [1,100]): ");
        scanf_s(" %c", &n, 1);
        getchar();
        if ((n - '0') < 1 || (n - '0') > MAXDIGIT || n < 48 || n > 57)
        {
            printf("Некорректный ввод. Повторите попытку!\n");
        }
    } while ((n - '0') < 1 || (n - '0') > MAXDIGIT || n < 48 || n > 57);
    int digit = n - '0';
    PermutationsFunc(digit);
}

void calc3()
{
    char selection;
    do
    {
        printf("Выберите формулу комбинаторики:\n");
        printf("1.Размещения с повторением\n");
        printf("2.Размещения без повторений\n");
        printf("3.Сочетание с повторением\n");
        printf("4.Сочетание без повторений\n");
        printf("5.Перестановки\n");
        printf("Для возврата в главное меню введите 0.\n");

        do
        {
            printf("Ваш выбор: ");
            scanf_s(" %c", &selection, 1);
            getchar();
            if (selection < 48 || selection > 54)
            {
                printf("Некорректный ввод. Повторите попытку\n");
            }
        } while (selection < 48 || selection > 54);
        selection = selection - '0';

        switch (selection)
        {
        case 1:
            printf("\n");
            PlacementsWithRep();
            break;
        case 2:
            printf("\n");
            PlacementsWithoutRep();
            break;
        case 3:
            printf("\n");
            CombinationsWithRep();
            break;
        case 4:
            printf("\n");
            CombinationsWithoutRep();
            break;
        case 5:
            printf("\n");
            Permutations();
            break;
        case 0:
            printf("Выход\n\n");
            break;
        }
    } while (selection != 0);
}