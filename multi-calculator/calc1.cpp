#include <stdio.h>
#include <locale.h>
#include <malloc.h>
#include "Header1.h"

float* input(int n, int m);
void print(float* a, int n, int m);
float* sum(float* m1, float* m2, int n, int m);
float* sub(float* m1, float* m2, int n, int m);
float* multi(float* mat1, float* mat2, int n1, int n2, int m1, int m2);

int main() {

	setlocale(LC_ALL, "Rus");

	int choice;

	do {
		printf("Выберете действие:\n1 - Сложение матриц\n2 - Вычитание матриц\n3 - Умножение матриц\n0 - Выход\n ");
		scanf_s("%d", &choice);

		switch (choice) {
		case 1:
		{
			printf("Сложение матриц\n");
			int n, m;
			printf("Введите количество строк для матриц: "); scanf_s("%d", &n);
			printf("Введите количество столбцов для матриц: "); scanf_s("%d", &m);
			printf("Введите данные матрицы 1\n");
			float* am1 = input(n, m);
			printf("Введите данные матрицы 2\n");
			float* am2 = input(n, m);

			printf("-----Матрица 1-----\n");
			print(am1, n, m);
			printf("-----Матрица 2-----\n");
			print(am2, n, m);

			float* sum_m = sum(am1, am2, n, m);
			printf("-----Результат-----\n");
			print(sum_m, n, m);

			free(am1);
			free(am2);
			free(sum_m);

			break;
		}

		case 2:
		{
			printf("Вычитание матриц\n");
			int n, m;
			printf("Введите количество строк для матриц: "); scanf_s("%d", &n);
			printf("Введите количество столбцов для матриц: "); scanf_s("%d", &m);
			printf("Введите данные матрицы 1\n");
			float* am1 = input(n, m);
			printf("Введите данные матрицы 2\n");
			float* am2 = input(n, m);

			printf("-----Матрица 1-----\n");
			print(am1, n, m);
			printf("-----Матрица 2-----\n");
			print(am2, n, m);

			float* sub_m = sub(am1, am2, n, m);
			printf("-----Результат-----\n");
			print(sub_m, n, m);

			free(am1);
			free(am2);
			free(sub_m);

			break;
		}

		case 3:
		{
			printf("Умножение матриц\n");

			int n1, n2, m1, m2;

			do {
				printf("Введите количество строк для матрицы 1: "); scanf_s("%d", &n1);
				printf("Введите количество столбцов для матрицы 1: "); scanf_s("%d", &m1);
				printf("Введите количество строк для матрицы 2: "); scanf_s("%d", &n2);
				printf("Введите количество столбцов для матрицы 2: "); scanf_s("%d", &m2);

				if (m1 != n2) printf("Ошибка: количество столбцов матрицы 1 не равно количеству строк матрицы 2\n");
			} while (m1 != n2);

			printf("Введите данные матрицы 1\n");
			float* amat1 = input(n1, m1);
			printf("Введите данные матрицы 2\n");
			float* amat2 = input(n2, m2);

			printf("-----Матрица 1-----\n");
			print(amat1, n1, m1);
			printf("-----Матрица 2-----\n");
			print(amat2, n2, m2);

			float* s = multi(amat1, amat2, n1, n2, m1, m2);

			printf("-----Результат-----\n");
			print(s, n1, m2);

			free(amat1);
			free(amat2);
			free(s);

			break;
		}
		}
	} while (choice);

	return 0;
}


float* input(int n, int m) {

	float* a;
	a = (float*)malloc(n * m * sizeof(float));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("a[%d][%d] = ", i, j);
			scanf_s("%f", (a + i * m + j));
		}
	}

	return a;
}

void print(float* a, int n, int m) {

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%.2f ", *(a + i * m + j));
		}
		printf("\n");
	}
}

//сложение матриц
float* sum(float* m1, float* m2, int n, int m) {

	float* s = (float*)malloc(n * m * sizeof(float));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			*(s + i * m + j) = *(m1 + i * m + j) + *(m2 + i * m + j);
		}
	}
	return s;
}

//вычитание матриц
float* sub(float* m1, float* m2, int n, int m) {

	float* s = (float*)malloc(n * m * sizeof(float));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			*(s + i * m + j) = *(m1 + i * m + j) - *(m2 + i * m + j);
		}
	}
	return s;
}


//умножение матриц
float* multi(float* mat1, float* mat2, int n1, int n2, int m1, int m2) {

	float* s = (float*)malloc(n1 * m2 * sizeof(float));

	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < m2; j++) {
			*(s + i * m2 + j) = 0;
			for (int k = 0; k < n2; k++) {
				*(s + i * m2 + j) += *(mat1 + i * m1 + k) * *(mat2 + k * m2 + j);
			}
		}
	}

	return s;
}
