#include <stdio.h>
#include <locale.h>
#include <malloc.h>
#include "Header1.h";
void calc1() {

	setlocale(LC_ALL, "Rus");

	int choice;

	do {
		printf("�������� ��������:\n1 - �������� ������\n2 - ��������� ������\n3 - ��������� ������\n4 - ��������� ������� �� �����\n5 - �������� � ��������� ������� � ������\n6 - ���������������� �������\n7 - ������������ �������\n8 - �������� �������\n0 - �����\n ");
		scanf_s("%d", &choice);
		getchar();

		switch (choice) {
		case 1:
		{
			printf("�������� ������\n");
			int n, m;
			do {
				printf("������� ���������� ����� ��� ������: "); scanf_s("%d", &n);
				printf("������� ���������� �������� ��� ������: "); scanf_s("%d", &m);
				if ((n < 2) || (m < 2)) printf("������. ���������� ����� � �������� ������� ������ ���� ������ 1\n");
			} while ((n < 2) || (m < 2));

			printf("������� ������ ������� 1\n");
			float* am1 = input(n, m);
			printf("������� ������ ������� 2\n");
			float* am2 = input(n, m);

			printf("-----������� 1-----\n");
			print(am1, n, m);
			printf("-----������� 2-----\n");
			print(am2, n, m);

			float* sum_m = sum(am1, am2, n, m);
			printf("-----���������-----\n");
			print(sum_m, n, m);

			free(am1);
			free(am2);
			free(sum_m);

			break;
		}

		case 2:
		{
			printf("��������� ������\n");
			int n, m;
			do {
				printf("������� ���������� ����� ��� ������: "); scanf_s("%d", &n);
				printf("������� ���������� �������� ��� ������: "); scanf_s("%d", &m);
				if ((n < 2) || (m < 2)) printf("������. ���������� ����� � �������� ������� ������ ���� ������ 1\n");
			} while ((n < 2) || (m < 2));

			printf("������� ������ ������� 1\n");
			float* am1 = input(n, m);
			printf("������� ������ ������� 2\n");
			float* am2 = input(n, m);

			printf("-----������� 1-----\n");
			print(am1, n, m);
			printf("-----������� 2-----\n");
			print(am2, n, m);

			float* sub_m = sub(am1, am2, n, m);
			printf("-----���������-----\n");
			print(sub_m, n, m);

			free(am1);
			free(am2);
			free(sub_m);

			break;
		}

		case 3:
		{
			printf("��������� ������\n");

			int n1, n2, m1, m2;

			do {
				printf("������� ���������� ����� ��� ������� 1: "); scanf_s("%d", &n1);
				printf("������� ���������� �������� ��� ������� 1: "); scanf_s("%d", &m1);
				printf("������� ���������� ����� ��� ������� 2: "); scanf_s("%d", &n2);
				printf("������� ���������� �������� ��� ������� 2: "); scanf_s("%d", &m2);

				if ((m1 != n2) || (n1 < 2) || (m1 < 2) || (n2 < 2) || (m2 < 2)) printf("������. ���������� �������� ������� 1 ������ ���� ����� ���������� ����� ������� 2. ���������� ����� � �������� ������� ������ ���� ������ 1\n");
			} while ((m1 != n2) || (n1 < 2) || (m1 < 2) || (n2 < 2) || (m2 < 2));

			printf("������� ������ ������� 1\n");
			float* amat1 = input(n1, m1);
			printf("������� ������ ������� 2\n");
			float* amat2 = input(n2, m2);

			printf("-----������� 1-----\n");
			print(amat1, n1, m1);
			printf("-----������� 2-----\n");
			print(amat2, n2, m2);

			float* s = multi(amat1, amat2, n1, n2, m1, m2);

			printf("-----���������-----\n");
			print(s, n1, m2);

			free(amat1);
			free(amat2);
			free(s);

			break;
		}
		case 4:
		{
			printf("��������� ������� �� �����\n");
			int n, m;
			float num;

			do {
				printf("������� ���������� ����� ��� ������: "); scanf_s("%d", &n);
				printf("������� ���������� �������� ��� ������: "); scanf_s("%d", &m);
				if ((n < 2) || (m < 2)) printf("������. ���������� ����� � �������� ������� ������ ���� ������ 1\n");
			} while ((n < 2) || (m < 2));

			printf("������� ������ �������\n");
			float* amat = input(n, m);
			printf("������� �����, �� ������� ����� �������� �������: \n"); scanf_s("%f", &num);


			printf("-----�������-----\n");
			print(amat, n, m);

			float* s = multinum(amat, n, m, num);

			printf("-----���������-----\n");
			print(s, n, m);

			free(amat);
			free(s);

			break;
		}

		case 5: {

			printf("��������(���������) ������� � ������\n");
			int n, m;
			float num;
			do {
				printf("������� ���������� ����� ��� ������: "); scanf_s("%d", &n);
				printf("������� ���������� �������� ��� ������: "); scanf_s("%d", &m);
				if ((n < 2) || (m < 2)) printf("������. ���������� ����� � �������� ������� ������ ���� ������ 1\n");
			} while ((n < 2) || (m < 2));

			printf("������� ������ �������\n");
			float* am = input(n, m);
			printf("������� �����, ������� ����� ��������� � �������: \n"); scanf_s("%f", &num);

			printf("-----�������-----\n");
			print(am, n, m);

			float* s = sumnum(am, n, m, num);

			printf("-----���������-----\n");
			print(s, n, m);

			free(am);
			free(s);

			break;
		}
		case 6:
		{
			printf("���������������� �������\n");
			int n, m;
			do {
				printf("������� ���������� ����� ��� ������: "); scanf_s("%d", &n);
				printf("������� ���������� �������� ��� ������: "); scanf_s("%d", &m);
				if ((n < 2) || (m < 2)) printf("������. ���������� ����� � �������� ������� ������ ���� ������ 1\n");
			} while ((n < 2) || (m < 2));

			printf("������� ������ �������\n");
			float* am = input(n, m);

			printf("-----�������-----\n");
			print(am, n, m);

			float* s = transpon(am, n, m);
			printf("-----���������-----\n");
			print(s, m, n);

			free(am);
			free(s);

			break;
		}

		case 7: 
		{
			printf("���������� ������������ �������\n");
			int n, m;
			do {
				printf("������� ���������� ����� ��� �������: "); scanf_s("%d", &n);
				printf("������� ���������� �������� ��� �������: "); scanf_s("%d", &m);
				if ((n != m) || (n < 2) || (m < 2)) printf("������. ������� ������ ���� ����������. ���������� ����� � �������� ������� ������ ���� ������ 1\n ");
			} while ((n != m) || (n < 2) || (m < 2));

			printf("������� ������ �������\n");
			float* am = input(n, m);
			printf("-----�������-----\n");
			print(am, n, m);

			float det = determinant(am, n);
			printf("������������ �������: %.2f\n", det);

			free(am);

			break;
		}

		case 8:
		{
			printf("���������� �������� �������\n");
			int n, m;
			do {
				printf("������� ���������� ����� ��� �������: "); scanf_s("%d", &n);
				printf("������� ���������� �������� ��� �������: "); scanf_s("%d", &m);
				if ((n != m) || (n < 2) || (m < 2)) printf("������. ������� ������ ���� ����������. ���������� ����� � �������� ������� ������ ���� ������ 1\n ");
			} while ((n != m) || (n < 2) || (m < 2));

			printf("������� ������ �������\n");
			float* amat = input(n, m);
			printf("-----�������-----\n");
			print(amat, n, m);

			float* inv = inverse(amat, n);
			if (inv != NULL) {
				printf("-----�������� �������-----\n");
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

//�������� ������
float* sum(float* m1, float* m2, int n, int m) {

	float* s = (float*)malloc(n * m * sizeof(float));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			*(s + i * m + j) = *(m1 + i * m + j) + *(m2 + i * m + j);
		}
	}
	return s;
}

//��������� ������
float* sub(float* m1, float* m2, int n, int m) {

	float* s = (float*)malloc(n * m * sizeof(float));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			*(s + i * m + j) = *(m1 + i * m + j) - *(m2 + i * m + j);
		}
	}
	return s;
}


//��������� ������
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


//��������� ������� �� ����� 
float* multinum(float* mat, int n, int m, float num) {

	float* s = (float*)malloc(n * m * sizeof(float));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			*(s + i * m + j) = *(mat + i * m + j) * num;
		}
	}
	return s;
}


//��������(���������) ������� � ������
float* sumnum(float* am, int n, int m, float num) {

	float* s = (float*)malloc(n * m * sizeof(float));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			*(s + i * m + j) = *(am + i * m + j) + num;
		}
	}
	return s;
}


//���������������� �������
float* transpon(float* am, int n, int m) {
	float* s = (float*)malloc(n * m * sizeof(float));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			*(s + j * n + i) = *(am + i * m + j);
		}
	}
	return s;
}


//������������ �������
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

//�������� �������
float* inverse(float* mat, int n) {

	float det = determinant(mat, n);
	if (det == 0) {
		printf("�������� ������� �� ����������, ������ ��� ������������ ����� ����\n");
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
