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
    int n, k;
    do
    {
        printf("Введите количество элементов (n): ");
        scanf_s("%d", &n);

        printf("Введите количество элементов (k): ");
        scanf_s("%d", &k);

        if ((n < 1 || n > MAXDIGIT) && (k < 1 || k > MAXDIGIT) && (n < k))
        {
            printf("Слишком большие числа. Введите числа из интервала [1;100], где n > k!\n");
            getchar();
        }
    } while ((n < 1 || n > MAXDIGIT) && (k < 1 || k > MAXDIGIT) && (n < k));
    PlacementsWithRepFunc(n, k);
}

// Размещения без повторений
void PlacementsWithoutRep()
{
    int n, k;
    do
    {
        printf("Введите количество элементов (n): ");
        scanf_s("%d", &n);

        printf("Введите количество элементов (k): ");
        scanf_s("%d", &k);

        if ((n < 1 || n > MAXDIGIT) && (k < 1 || k > MAXDIGIT) && (n < k))
        {
            printf("Слишком большие числа. Введите числа из интервала [1;100], где n > k!\n");
            getchar();
        }
    } while ((n < 1 || n > MAXDIGIT) && (k < 1 || k > MAXDIGIT) && (n < k));
    PlacementsWithoutRepFunc(n, k);
}

// Сочетания с повторениями
void CombinationsWithRep()
{
    int n, k;
    do
    {
        printf("Введите количество элементов (n): ");
        scanf_s("%d", &n);

        printf("Введите количество элементов (k): ");
        scanf_s("%d", &k);

        if ((n < 1 || n > MAXDIGIT) && (k < 1 || k > MAXDIGIT) && (n < k))
        {
            printf("Слишком большие числа. Введите числа из интервала [1;100], где n > k!\n");
            getchar();
        }
    } while ((n < 1 || n > MAXDIGIT) && (k < 1 || k > MAXDIGIT) && (n < k));
    CombinationsWithRepFunc(n, k);
}

// Сочетания без повторений
void CombinationsWithoutRep()
{
    int n, k;
    do
    {
        printf("Введите количество элементов (n): ");
        scanf_s("%d", &n);

        printf("Введите количество элементов (k): ");
        scanf_s("%d", &k);

        if ((n < 1 || n > MAXDIGIT) && (k < 1 || k > MAXDIGIT) && (n < k))
        {
            printf("Слишком большие числа. Введите числа из интервала [1;100], где n > k!\n");
            getchar();
        }
    } while ((n < 1 || n > MAXDIGIT) && (k < 1 || k > MAXDIGIT) && (n < k));
    CombinationsWithoutRepFunc(n, k);
}

// Перестановки
void Permutations()
{
    int n;
    do
    {
        printf("Введите количество элементов (n): ");
        scanf_s("%d", &n);
        if (n < 1 || n > MAXDIGIT)
        {
            printf("Слишком большое число. Введите число из интервала [1;100]!\n");
            getchar();
        }
    } while (n < 1 || n > MAXDIGIT);

    PermutationsFunc(n);
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
                getchar();
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