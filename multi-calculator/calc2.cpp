#include <iostream>
#include <stdbool.h>
#include <string.h>
#include <locale.h>
#include "Header2.h"
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
	if (b == 0) return a;
	if ((a < 0) || (a > 0 && b > 0)) {
		return NOD(b, a % b);
	}
	else if (b < 0) { return NOD(b, (-1) * abs(a) % abs(b)); }
}
int NOK(int a, int b) {
	return ((a * b) / NOD(a, b));
}
void comparison(fraction fr1, fraction fr2) {
	double d1, d2;
	d1 = fr1.num / (fr1.den * (1.0));
	d2 = fr2.num / (fr2.den * (1.0));
	if (d1 > d2) { printf("Первая дробь больше ('>') второй.\n"); }
	else if (d1 < d2) { printf("Первая дробь меньше ('<') второй.\n"); }
	else { printf("Дроби равны."); }
}
void reduction(fraction fr1) {
	struct fraction res1;
	res1.num = fr1.num / NOD(fr1.num, fr1.den);
	res1.den = fr1.den / NOD(fr1.num, fr1.den);
	if (res1.den != 1) { printf("Сокращённая дробь: %d/%d\n", res1.num, res1.den); }
	else if (res1.den == 1) { printf("Сокращённая дробь - целое число: %d\n", res1.num); }
}
void decimal(fraction fr1) {
	double d;
	d = fr1.num / (fr1.den * (1.0));
	printf("Десятичный вид: %.2lf\n", d);
}
void choice(fraction res) {
	char v;
	printf("Если вы хотите сократить дробь, введите 1, если хотите получить десятичный вид - 2, иначе - любой символ.\n");
	printf("Ваш выбор : "); scanf_s("%c", &v);
	if (v == '1') { reduction(res); }
	else if (v == '2') { decimal(res); }
	getchar();
}
void calc2() {
	setlocale(LC_ALL, "Rus");
	char oper;
	do {
		printf("Выберите операцию над дробями:\n");
		printf("1.Сложение дробей\n2.Вычитание дробей\n3.Умножение дробей\n4.Деление дробей\n5.Сравнение дробей\n6.Сокращение дробей\n7.Представление в виде десятичной дроби\n");
		printf("Для выхода введите 0.\n");
		do {
			printf("Ваш выбор: "); scanf_s("%c", &oper); getchar();
			if (oper < 48 || oper > 55) { printf("Некорректный ввод. Повторите попытку\n"); }
		} while (oper < 48 || oper > 55);

		struct fraction fr1, fr2, res;
		int len1, len2;
		char str1[MaxN], str2[MaxN];
		char str_num1[MaxN], str_den1[MaxN], str_num2[MaxN], str_den2[MaxN];

		if (oper != '0')
		{
			do {
				if (oper > 48 && oper < 54) { printf("Введите 1-ую дробь: "); }
				else { printf("Введите дробь: "); }
				gets_s(str1);
				len1 = strlen(str1);
				input(str1, len1, str_num1, str_den1);
				fr1.num = atoi(str_num1);
				fr1.den = atoi(str_den1);
				if (check(str1, len1) == 1) { printf("Некорректный ввод дроби.\n"); }
				else if (fr1.den == 0) { printf("Знаменатель дроби не может быть равен нулю.\n"); }
				if (fr1.num == 0) { fr1.den = 0; printf("Дробь равна нулю. Повторите ввод.\n"); }
			} while ((fr1.den == 0) || (check(str1, len1) == 1));
			if (oper > 48 && oper < 54) {
				do {
					printf("Введите 2-ую дробь: ");
					gets_s(str2);
					len2 = strlen(str2);
					input(str2, len2, str_num2, str_den2);
					fr2.num = atoi(str_num2);
					fr2.den = atoi(str_den2);
					if (check(str2, len2) == 1) { printf("Некорректный ввод дроби.\n"); }
					else if (fr2.den == 0) { printf("Знаменатель дроби не может быть равен нулю.\n"); }
					if (fr2.num == 0) { fr2.den = 0; printf("Дробь равна нулю. Повторите ввод.\n"); }
				} while ((fr2.den == 0) || (check(str2, len2) == 1));
			}
		}
		
		switch (oper) {
		case '1':
			res.den = NOK(fr1.den, fr2.den);
			res.num = (fr1.num * (NOK(fr1.den, fr2.den) / fr1.den) + fr2.num * (NOK(fr1.den, fr2.den) / fr2.den));
			printf("'+' = %d/%d\n", res.num, res.den);
			choice(res);
			break;
		case '2':
			res.den = NOK(fr1.den, fr2.den);
			res.num = (fr1.num * (NOK(fr1.den, fr2.den) / fr1.den) - fr2.num * (NOK(fr1.den, fr2.den) / fr2.den));
			printf("'-' = %d/%d\n", res.num, res.den);
			choice(res);
			break;
		case '3':
			res.num = fr1.num * fr2.num;
			res.den = fr1.den * fr2.den;
			if (res.den < 0) { res.num *= -1; res.den *= -1; }
			printf("'*' = %d/%d\n", res.num, res.den);
			choice(res);
			break;
		case '4':
			res.num = fr1.num * fr2.den;
			res.den = fr1.den * fr2.num;
			if (res.den < 0) { res.num *= (-1); res.den *= (-1); }
			printf("':' = %d/%d\n", res.num, res.den);
			choice(res);
			break;
		case '5': comparison(fr1, fr2); break;
		case '6': reduction(fr1); break;
		case '7': decimal(fr1); break;
		case '0': printf("Выход\n"); break;
		}
	} while (oper != '0');
}