#include <iostream>
#include <stdbool.h>
#include <string.h>
#include <locale.h>
#include "Header4.h"

int TTrueNum(char GuessNum[])
{
	int i;
	for (i = 0; i < strlen(GuessNum); i++) {
		if (GuessNum[i] == '+' || GuessNum[i] == '-' || GuessNum[i] == '.') {}
		else if (!isdigit(GuessNum[i])) {
			printf("Некорректный ввод.\n\n");
			return 0;
		}
	}
	return 1;
}

int Inputt()
{
	char GuessNum[100];
	scanf_s("%s", &GuessNum, sizeof(GuessNum));
	while (!(TTrueNum(GuessNum)))
	{
		printf("Повторите ввод: ");
		scanf_s("%s", &GuessNum, sizeof(GuessNum));
	}
	return atoi(GuessNum);
}

int TTrueNum1(char GuessNum[])
{
	int i;
	for (i = 0; i < strlen(GuessNum); i++) {
		if (!isdigit(GuessNum[i])) {
			printf("Некорректный ввод.\n\n");
			return 0;
		}
	}
	return 1;
}

int Inputt1()
{
	char GuessNum[100];
	scanf_s("%s", &GuessNum, sizeof(GuessNum));
	while (!(TTrueNum1(GuessNum)))
	{
		printf("Повторите ввод: ");
		scanf_s("%s", &GuessNum, sizeof(GuessNum));
	}
	return atoi(GuessNum);
}


void Print(char coefficients[], int degree)
{
	int i;
	for (i = degree; i >= 0; i--)
	{
		if (coefficients[i] != 0) {
			if (i == degree)
			{
				if (degree == 0) {
					printf("%d", coefficients[i]);
				}
				else if (degree == 1) {
					if (coefficients[i] = 1) {
						printf("x");
					}
					else {
						printf("%dx", coefficients[i]);
					}
				}
				else {
					if (coefficients[i] = 1) {
						printf("x^%d", i);
					}
					else {
						printf("%dx^%d", coefficients[i], i);
					}
				}
			}
			else
			{
				if (coefficients[i] > 0)
				{
					if (i == 0) {
						printf("+%d", coefficients[i]);
					}
					else if (i == 1) {
						if (coefficients[i] = 1) {
							printf("+x");
						}
						else {
							printf("+%dx", coefficients[i]);
						}
					}
					else {
						if (coefficients[i] = 1) {
							printf("+x^%d", i);
						}
						else {
							printf("+%dx^%d", coefficients[i], i);
						}
					}
				}
				else
				{
					if (i == 0) {
						printf("%d", coefficients[i]);
					}
					else if (i == 1) {
						if (coefficients[i] = -1)
						{
							printf("-x");
						}
						else {
							printf("%dx", coefficients[i]);
						}
					}
					else {
						if (coefficients[i] = -1) {
							printf("-x^%d", i);
						}
						else {
							printf("%dx^%d", coefficients[i], i);
						}
					}
				}
			}
		}
	}
	printf("\n\n");
}

void input_coefficients(char* coefficients, int* degree)
{
	printf("Введите степень многочлена:");
	*degree = Inputt1();
	int i;
	for (i = 0; i <= *degree; i++)
	{
		printf("Введите коэффициент x^%d:", i);
		coefficients[i] = Inputt();
	}
	Print(coefficients, *degree);
}

void Sum_coefficients(char coefficients1[], char coefficients2[], int degree1, int degree2, char coefficients_new[], int* degree3)
{
	if (degree1 >= degree2)
	{
		*degree3 = degree1;
	}
	else {
		*degree3 = degree2;
	}
	for (int t = 0; t <= *degree3; t++)
	{
		coefficients_new[t] = 0;
	}
	for (int k = 0; k <= degree1; k++)
	{
		for (int i = 0; i <= degree1; i++)
		{
			if (k == i) {
				coefficients_new[k] += coefficients1[i];
			}
		}
	}
	for (int k = 0; k <= degree2; k++)
	{
		for (int j = 0; j <= degree2; j++)
		{
			if (k == j) {
				coefficients_new[k] += coefficients2[j];
			}
		}
	}
	Print(coefficients_new, *degree3);
}

void Minus_coefficients(char coefficients1[], char coefficients2[], int degree1, int degree2, char coefficients_new[], int* degree3)
{
	if (degree1 >= degree2)
	{
		*degree3 = degree1;
	}
	else {
		*degree3 = degree2;
	}
	for (int t = 0; t <= *degree3; t++)
	{
		coefficients_new[t] = 0;
	}
	for (int k = 0; k <= degree1; k++)
	{
		for (int i = 0; i <= degree1; i++)
		{
			if (k == i) {
				coefficients_new[k] += coefficients1[i];
			}
		}
	}
	for (int k = 0; k <= degree2; k++)
	{
		for (int j = 0; j <= degree2; j++)
		{
			if (k == j) {
				coefficients_new[k] -= coefficients2[j];
			}
		}
	}
	Print(coefficients_new, *degree3);
}

void Umn(char coefficients1[], char coefficients2[], int degree1, int degree2, char coefficients_new[], int* degree3)
{
	*degree3 = degree1 + degree2;
	for (int t = 0; t <= *degree3; t++)
	{
		coefficients_new[t] = 0;
	}

	for (int i = 0; i <= degree1; i++)
	{
		for (int j = 0; j <= degree2; j++)
		{
			coefficients_new[i + j] += (coefficients1[i] * coefficients2[j]);
		}
	}
	Print(coefficients_new, *degree3);
}

void Umn_count(char coefficients1[], int degree1, char coefficients_new[], int a)
{
	for (int i = 0; i <= degree1; i++)
	{
		coefficients_new[i] = a * coefficients1[i];
	}
	Print(coefficients_new, degree1);
}

void Proizv(char coefficients1[], int degree1, char coefficients_new[], int* degree3)
{
	*degree3 = degree1 - 1;
	for (int i = 0; i <= degree1; i++)
	{
		for (int k = 0; k <= *degree3; k++)
		{
			coefficients_new[k] = coefficients1[k + 1] * (k + 1);
		}
	}
	Print(coefficients_new, *degree3);
}

void Del(char coefficients1[], char coefficients2[], char quotient[], char remainder[], int degree1, int degree2)
{
	char temp[100];
	for (int t = 0; t < 100; t++)
	{
		temp[t] = 0;
	}
	for (int i = degree1 - degree2; i >= 0; i--)
	{
		quotient[i] = (coefficients1[i + degree2] / coefficients2[degree2]);
		for (int j = 0; j <= degree2; j++)
		{
			temp[j + i] = coefficients2[j] * quotient[i];
		}
		for (int j = 0; j <= degree2; j++)
		{
			coefficients1[j + i] = coefficients1[j + i] - temp[j + i];
		}
	}
	for (int i = 0; i <= degree1; i++)
	{
		remainder[i] = coefficients1[i];
	}
	printf("Частное: ");
	Print(quotient, (degree1 - degree2));
	printf("Остаток: ");
	Print(remainder, degree1);
}

void calc4()
{
	setlocale(LC_ALL, "Russian");
	int ch, degree = 0, a;
	int degree1, degree2, degree3, degree4;
	char GuessNum[100], coefficients[100], coefficients_new[100];
	char coefficients1[100], coefficients2[100];
	char quotient[100], remainder[100];
	do
	{
		printf("\nВыберите, какую операцию вы хотите совершить\n");
		printf("\n1 - сложение многочленов\n2 - вычитание многочленов\n3 - умножение многочленов\n4 - умножение многочлена на число\n5 - Вычисление производной от многочлена\n6 - деление многочлена в столбик\n\n");
		ch = Inputt();
		switch (ch)
		{
		case 1:
			input_coefficients(coefficients1, &degree1);
			input_coefficients(coefficients2, &degree2);
			Sum_coefficients(coefficients1, coefficients2, degree1, degree2, coefficients_new, &degree3);
			break;
		case 2:
			input_coefficients(coefficients1, &degree1);
			input_coefficients(coefficients2, &degree2);
			Minus_coefficients(coefficients1, coefficients2, degree1, degree2, coefficients_new, &degree3);
			break;
		case 3:
			input_coefficients(coefficients1, &degree1);
			input_coefficients(coefficients2, &degree2);
			Umn(coefficients1, coefficients2, degree1, degree2, coefficients_new, &degree3);
			break;
		case 4:
			input_coefficients(coefficients1, &degree1);
			printf("Введите число: ");
			a = Inputt();
			Umn_count(coefficients1, degree1, coefficients_new, a);
			break;
		case 5:
			input_coefficients(coefficients1, &degree1);
			Proizv(coefficients1, degree1, coefficients_new, &degree3);
			break;
		case 6:
			input_coefficients(coefficients1, &degree1);
			input_coefficients(coefficients2, &degree2);
			Del(coefficients1, coefficients2, quotient, remainder, degree1, degree2);
			break;
		default: printf("error\n");
		}
	} while (0 >= ch || ch > 6);
}