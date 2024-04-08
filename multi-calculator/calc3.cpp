#include <iostream>
#include <stdbool.h>
#include <string.h>
#include <locale.h>
#include "Header3.h"

#define MAX 1000
#define MAXDIGIT 100

// ����� �������
void PrintArray(int* arr, int num)
{
    for (int i = num - 1; i >= 0; i--)
    {
        printf("%d", arr[i]);
    }
    printf("\n");
}

// ���������
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

// �������
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

// ���������� � ������������ ����������
void PlacementsWithRepFunc(int n, int k)
{
    int* result = new int[MAX];
    int num = 1;
    result[0] = 1;

    for (int i = 0; i < k; i++)
    {
        Multiply(result, num, n);
    }

    printf("���������� � ������������: ");
    PrintArray(result, num);
    printf("\n");

    delete[] result;
}

// ���������� ��� ���������� ����������
void PlacementsWithoutRepFunc(int n, int k)
{
    int* result = new int[MAX];
    int num = 1;
    result[0] = 1;

    for (int i = n; i > n - k; i--)
    {
        Multiply(result, num, i);
    }

    printf("���������� ��� ����������: ");
    PrintArray(result, num);
    printf("\n");

    delete[] result;
}

// ��������� � ������������ ����������
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

    printf("��������� � ������������: ");
    PrintArray(result, num);
    printf("\n");

    delete[] result;
}

// ��������� ��� ���������� ����������
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

    printf("��������� ��� ����������: ");
    PrintArray(result, num);
    printf("\n");
    delete[] result;
}

// ������������ ����������
void PermutationsFunc(int n)
{
    int* result = new int[MAX];
    int num = 1;
    result[0] = 1;

    for (int i = 2; i <= n; i++)
    {
        Multiply(result, num, i);
    }

    printf("���������� ������������: ");
    PrintArray(result, num);
    printf("\n");
    delete[] result;
}

// ���������� � ������������
void PlacementsWithRep()
{
    int n, k;
    do
    {
        printf("������� ���������� ��������� (n): ");
        scanf_s("%d", &n);

        printf("������� ���������� ��������� (k): ");
        scanf_s("%d", &k);

        if ((n < 1 || n > MAXDIGIT) && (k < 1 || k > MAXDIGIT) && (n < k))
        {
            printf("������� ������� �����. ������� ����� �� ��������� [1;100], ��� n > k!\n");
            getchar();
        }
    } while ((n < 1 || n > MAXDIGIT) && (k < 1 || k > MAXDIGIT) && (n < k));
    PlacementsWithRepFunc(n, k);
}

// ���������� ��� ����������
void PlacementsWithoutRep()
{
    int n, k;
    do
    {
        printf("������� ���������� ��������� (n): ");
        scanf_s("%d", &n);

        printf("������� ���������� ��������� (k): ");
        scanf_s("%d", &k);

        if ((n < 1 || n > MAXDIGIT) && (k < 1 || k > MAXDIGIT) && (n < k))
        {
            printf("������� ������� �����. ������� ����� �� ��������� [1;100], ��� n > k!\n");
            getchar();
        }
    } while ((n < 1 || n > MAXDIGIT) && (k < 1 || k > MAXDIGIT) && (n < k));
    PlacementsWithoutRepFunc(n, k);
}

// ��������� � ������������
void CombinationsWithRep()
{
    int n, k;
    do
    {
        printf("������� ���������� ��������� (n): ");
        scanf_s("%d", &n);

        printf("������� ���������� ��������� (k): ");
        scanf_s("%d", &k);

        if ((n < 1 || n > MAXDIGIT) && (k < 1 || k > MAXDIGIT) && (n < k))
        {
            printf("������� ������� �����. ������� ����� �� ��������� [1;100], ��� n > k!\n");
            getchar();
        }
    } while ((n < 1 || n > MAXDIGIT) && (k < 1 || k > MAXDIGIT) && (n < k));
    CombinationsWithRepFunc(n, k);
}

// ��������� ��� ����������
void CombinationsWithoutRep()
{
    int n, k;
    do
    {
        printf("������� ���������� ��������� (n): ");
        scanf_s("%d", &n);

        printf("������� ���������� ��������� (k): ");
        scanf_s("%d", &k);

        if ((n < 1 || n > MAXDIGIT) && (k < 1 || k > MAXDIGIT) && (n < k))
        {
            printf("������� ������� �����. ������� ����� �� ��������� [1;100], ��� n > k!\n");
            getchar();
        }
    } while ((n < 1 || n > MAXDIGIT) && (k < 1 || k > MAXDIGIT) && (n < k));
    CombinationsWithoutRepFunc(n, k);
}

// ������������
void Permutations()
{
    int n;
    do
    {
        printf("������� ���������� ��������� (n): ");
        scanf_s("%d", &n);
        if (n < 1 || n > MAXDIGIT)
        {
            printf("������� ������� �����. ������� ����� �� ��������� [1;100]!\n");
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
        printf("�������� ������� �������������:\n");
        printf("1.���������� � �����������\n");
        printf("2.���������� ��� ����������\n");
        printf("3.��������� � �����������\n");
        printf("4.��������� ��� ����������\n");
        printf("5.������������\n");
        printf("��� �������� � ������� ���� ������� 0.\n");

        do
        {
            printf("��� �����: ");
            scanf_s(" %c", &selection, 1);
            getchar();
            if (selection < 48 || selection > 54)
            {
                printf("������������ ����. ��������� �������\n");
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
            printf("�����\n\n");
            break;
        }
    } while (selection != 0);
}