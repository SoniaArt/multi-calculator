#include <stdio.h>
#include <locale.h>
#include <malloc.h>
#include "Header1.h";
void calc1() {

	setlocale(LC_ALL, "Rus");

	int choice;

	do {
		printf("Выберете действие:\n1 - Сложение матриц\n2 - Вычитание матриц\n3 - Умножение матриц\n4 - Умножение матрицы на число\n5 - Сложение и вычитание матрицы с числом\n6 - Транспонирование матрицы\n7 - Определитель матрицы\n8 - Обратная матрица\n0 - Выход\n ");
		scanf_s("%d", &choice);
		getchar();

		switch (choice) {
		case 1:
		{
			printf("Сложение матриц\n");
			int n, m;
			do {
				printf("Введите количество строк для матриц: "); scanf_s("%d", &n);
				printf("Введите количество столбцов для матриц: "); scanf_s("%d", &m);
				if ((n < 2) || (m < 2)) printf("Ошибка. Количество строк и столбцов матрицы должно быть больше 1\n");
			} while ((n < 2) || (m < 2));

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
			do {
				printf("Введите количество строк для матриц: "); scanf_s("%d", &n);
				printf("Введите количество столбцов для матриц: "); scanf_s("%d", &m);
				if ((n < 2) || (m < 2)) printf("Ошибка. Количество строк и столбцов матрицы должно быть больше 1\n");
			} while ((n < 2) || (m < 2));

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

				if ((m1 != n2) || (n1 < 2) || (m1 < 2) || (n2 < 2) || (m2 < 2)) printf("Ошибка. Количество столбцов матрицы 1 должно быть равно количеству строк матрицы 2. Количество строк и столбцов матрицы должно быть больше 1\n");
			} while ((m1 != n2) || (n1 < 2) || (m1 < 2) || (n2 < 2) || (m2 < 2));

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
		case 4:
		{
			printf("Умножение матрицы на число\n");
			int n, m;
			float num;

			do {
				printf("Введите количество строк для матриц: "); scanf_s("%d", &n);
				printf("Введите количество столбцов для матриц: "); scanf_s("%d", &m);
				if ((n < 2) || (m < 2)) printf("Ошибка. Количество строк и столбцов матрицы должно быть больше 1\n");
			} while ((n < 2) || (m < 2));

			printf("Введите данные матрицы\n");
			float* amat = input(n, m);
			printf("Введите число, на которое нужно умножить матрицу: \n"); scanf_s("%f", &num);


			printf("-----Матрица-----\n");
			print(amat, n, m);

			float* s = multinum(amat, n, m, num);

			printf("-----Результат-----\n");
			print(s, n, m);

			free(amat);
			free(s);

			break;
		}

		case 5: {

			printf("Сложение(вычитание) матрицы с числом\n");
			int n, m;
			float num;
			do {
				printf("Введите количество строк для матриц: "); scanf_s("%d", &n);
				printf("Введите количество столбцов для матриц: "); scanf_s("%d", &m);
				if ((n < 2) || (m < 2)) printf("Ошибка. Количество строк и столбцов матрицы должно быть больше 1\n");
			} while ((n < 2) || (m < 2));

			printf("Введите данные матрицы\n");
			float* am = input(n, m);
			printf("Введите число, которое нужно прибавить к матрице: \n"); scanf_s("%f", &num);

			printf("-----Матрица-----\n");
			print(am, n, m);

			float* s = sumnum(am, n, m, num);

			printf("-----Результат-----\n");
			print(s, n, m);

			free(am);
			free(s);

			break;
		}
		case 6:
		{
			printf("Транспонирование матрицы\n");
			int n, m;
			do {
				printf("Введите количество строк для матриц: "); scanf_s("%d", &n);
				printf("Введите количество столбцов для матриц: "); scanf_s("%d", &m);
				if ((n < 2) || (m < 2)) printf("Ошибка. Количество строк и столбцов матрицы должно быть больше 1\n");
			} while ((n < 2) || (m < 2));

			printf("Введите данные матрицы\n");
			float* am = input(n, m);

			printf("-----Матрица-----\n");
			print(am, n, m);

			float* s = transpon(am, n, m);
			printf("-----Результат-----\n");
			print(s, m, n);

			free(am);
			free(s);

			break;
		}

		case 7: 
		{
			printf("Нахождение определителя матрицы\n");
			int n, m;
			do {
				printf("Введите количество строк для матрицы: "); scanf_s("%d", &n);
				printf("Введите количество столбцов для матрицы: "); scanf_s("%d", &m);
				if ((n != m) || (n < 2) || (m < 2)) printf("Ошибка. Матрица должна быть квадратной. Количество строк и столбцов матрицы должно быть больше 1\n ");
			} while ((n != m) || (n < 2) || (m < 2));

			printf("Введите данные матрицы\n");
			float* am = input(n, m);
			printf("-----Матрица-----\n");
			print(am, n, m);

			float det = determinant(am, n);
			printf("Определитель матрицы: %.2f\n", det);

			free(am);

			break;
		}

		case 8:
		{
			printf("Нахождение обратной матрицы\n");
			int n, m;
			do {
				printf("Введите количество строк для матрицы: "); scanf_s("%d", &n);
				printf("Введите количество столбцов для матрицы: "); scanf_s("%d", &m);
				if ((n != m) || (n < 2) || (m < 2)) printf("Ошибка. Матрица должна быть квадратной. Количество строк и столбцов матрицы должно быть больше 1\n ");
			} while ((n != m) || (n < 2) || (m < 2));

			printf("Введите данные матрицы\n");
			float* amat = input(n, m);
			printf("-----Матрица-----\n");
			print(amat, n, m);

			float* inv = inverse(amat, n);
			if (inv != NULL) {
				printf("-----Обратная матрица-----\n");
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < n; j++) {
						printf("%.2f ", inv[i * n + j]);
					}
					printf("\n");
				}
				free(inv);
			}

			free(amat);
			break;
		}
		}
	} while (choice);

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


//умножение матрицы на число 
float* multinum(float* mat, int n, int m, float num) {

	float* s = (float*)malloc(n * m * sizeof(float));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			*(s + i * m + j) = *(mat + i * m + j) * num;
		}
	}
	return s;
}


//сложение(вычитание) матрицы с числом
float* sumnum(float* am, int n, int m, float num) {

	float* s = (float*)malloc(n * m * sizeof(float));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			*(s + i * m + j) = *(am + i * m + j) + num;
		}
	}
	return s;
}


//транспонирование матрицы
float* transpon(float* am, int n, int m) {
	float* s = (float*)malloc(n * m * sizeof(float));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			*(s + j * n + i) = *(am + i * m + j);
		}
	}
	return s;
}


//определитель матрицы
float determinant(float* mat, int n) {
	if (n == 1) {
		return *mat;
	}

	float det = 0;
	float* submat = (float*)malloc((n - 1) * (n - 1) * sizeof(float));

	for (int k = 0; k < n; k++) {
		int subi = 0;
		for (int i = 1; i < n; i++) {
			int subj = 0;
			for (int j = 0; j < n; j++) {
				if (j == k) {
					continue;
				}
				submat[subi * (n - 1) + subj] = *(mat + i * n + j);
				subj++;
			}
			subi++;
		}
		det += (k % 2 == 0 ? 1 : -1) * *(mat + k) * determinant(submat, n - 1);
	}

	free(submat);
	return det;
}

//обратная матрица
float* inverse(float* mat, int n) {

	float det = determinant(mat, n);
	if (det == 0) {
		printf("Обратной матрицы не существует, потому что определитель равен нулю\n");
		return NULL;
	}

	float* inv = (float*)malloc(n * n * sizeof(float));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {

			float* submat = (float*)malloc((n - 1) * (n - 1) * sizeof(float));

			int subi = 0;

			for (int k = 0; k < n; k++) {
				if (k == i) continue;

				int subj = 0;

				for (int l = 0; l < n; l++) {
					if (l == j) continue;
					submat[subi * (n - 1) + subj] = mat[k * n + l];
					subj++;
				}
				subi++;
			}

			float sign = ((i + j) % 2 == 0) ? 1 : -1;

			inv[j * n + i] = sign * determinant(submat, n - 1) / det;
			free(submat);
		}
	}

	return inv;
}
