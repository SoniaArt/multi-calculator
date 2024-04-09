#include <iostream>
#include <stdbool.h>
#include <string.h>
#include <locale.h>
#include "Header2.h"
#include <windows.h>
struct fraction {
	int num;
	int den;
};
void input(char* str, int len, char* str_num, char* str_den) {
	for (int i = 0, n = 0, d = 0, cnt = 0; i < len; i++) {
		if (str[i] != '/' && cnt == 0) {
			str_num[n] = str[i];
			n++;
		}
		if (str[i] == '/') { cnt++; }
		if (str[i] != '/' && cnt != 0) {
			str_den[d] = str[i];
			d++;
		}
	}
}
int check(char* str, int len) {
	int cnt = 0;
	int cnt1 = 0;
	for (int i = 0; i < len; i++) {
		if (str[i] < 45 || str[i] > 57 || str[i] == 46) { cnt = 1; }
		if (str[i] == 47) { cnt1 += 1; }
	}
	if (cnt1 > 1) { cnt = 1; }
	return cnt;
}
int NOD(int a, int b) {
	a = abs(a); b = abs(b);
	if (b == 0) { return a; }
	else { return NOD(b, a % b); }
}
int NOK(int a, int b) {
	return ((a * b) / NOD(a, b));
}
void comparison(fraction fr1, fraction fr2) {
	double d1, d2;
	d1 = fr1.num / (fr1.den * (1.0));
	d2 = fr2.num / (fr2.den * (1.0));
	if (d1 > d2) { printf("������ ����� ������ ('>') ������.\n"); }
	else if (d1 < d2) { printf("������ ����� ������ ('<') ������.\n"); }
	else { printf("����� �����."); }
}
void reduction(fraction fr1) {
	struct fraction res1;
	res1.num = fr1.num / NOD(fr1.num, fr1.den);
	res1.den = fr1.den / NOD(fr1.num, fr1.den);
	if (res1.den != 1) { printf("%d/%d\n", res1.num, res1.den); }
	else if (res1.den == 1) { printf("����������� ����� - ����� �����: %d\n", res1.num); }
}
void decimal(fraction fr1) {
	double d;
	d = fr1.num / (fr1.den * (1.0));
	printf("���������� ���: %.2lf\n", d);
}
void choice(fraction res) {
	char v;
	printf("���� �� ������ ��������� �����, ������� 1, ���� ������ �������� ���������� ��� - 2, ����� - ����� ������.\n");
	printf("��� ����� : "); scanf_s("%c", &v);
	if (v == '1') { reduction(res); }
	else if (v == '2') { decimal(res); }
	getchar();
}
void calc2() {
	setlocale(LC_ALL, "Rus");
	char oper;
	do {
		printf("�������� �������� ��� �������:\n\n");
		printf(" 1 - �������� ������\n 2 - ��������� ������\n 3 - ��������� ������\n 4 - ������� ������\n 5 - ��������� ������\n 6 - ���������� ������\n 7 - ������������� � ���� ���������� �����\n");
		printf("\n��� ������ ������� 0.\n");
		printf("�����! ��� ���������� ������ ���� ������� ������������ ������� ����� ������ � ���������.\n");
		do {
			printf("��� �����: "); scanf_s("%c", &oper);
			if (oper < 48 || oper > 55) { printf("������������ ����. ��������� �������\n"); }
		} while (oper < 48 || oper > 55);
		struct fraction fr1, fr2, res;
		if (oper != '0') {
			system("cls");
			do {
				if (oper > 48 && oper < 54) { printf("������� 1-�� �����: "); }
				else { printf("������� �����: "); }
				scanf_s("%d/%d", &fr1.num, &fr1.den);
				if (fr1.den == 0) { printf("����������� ����� �� ����� ���� ����� ����.\n"); }
				if (fr1.num == 0) { fr1.den = 0; printf("����� ����� ����. ��������� ����.\n"); }
			} while (fr1.den == 0);
			if (oper > 48 && oper < 54) {
				do {
					printf("������� 2-�� �����: ");
					scanf_s("%d/%d", &fr2.num, &fr2.den);
					if (fr2.den == 0) { printf("����������� ����� �� ����� ���� ����� ����.\n"); }
				} while (fr2.den == 0);
			}
		}
		switch (oper) {
		case '1':
			res.den = NOK(fr1.den, fr2.den);
			res.num = (fr1.num * (NOK(fr1.den, fr2.den) / fr1.den) + fr2.num * (NOK(fr1.den, fr2.den) / fr2.den));
			printf("'+' = ");
			reduction(res);
			break;
		case '2':
			res.den = NOK(fr1.den, fr2.den);
			res.num = (fr1.num * (NOK(fr1.den, fr2.den) / fr1.den) - fr2.num * (NOK(fr1.den, fr2.den) / fr2.den));
			printf("'-' = ");
			reduction(res);
			break;
		case '3':
			res.num = fr1.num * fr2.num;
			res.den = fr1.den * fr2.den;
			if (res.den < 0) { res.num *= -1; res.den *= -1; }
			printf("'*' = ");
			reduction(res);
			break;
		case '4':
			res.num = fr1.num * fr2.den;
			res.den = fr1.den * fr2.num;
			if (res.den < 0) { res.num *= (-1); res.den *= (-1); }
			printf("':' = ");
			reduction(res);
			break;
		case '5': comparison(fr1, fr2); break;
		case '6': printf("����������� �����: "); reduction(fr1); break;
		case '7': decimal(fr1); break;
		case '0': printf("�����\n"); system("cls"); break;
		}
	} while (oper != '0'); 
}