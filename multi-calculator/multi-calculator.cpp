﻿#include <iostream>
#include <stdbool.h>
#include <string.h>
#include <locale.h>
#include "Header1.h"
#include "Header2.h"
#include "Header3.h"
#include "Header4.h"
#include "Header5.h"
#include "Header6.h"
#define MaxN 100
int main() {
    setlocale(LC_ALL, "Rus");
    char t;
    do {
        printf("Каким видом калькулятора вы хотите пользоваться?\n\n");
        printf(" 1 - Матричный калькулятор\n 2 - Калькулятор обыкновенных дробей\n 3 - Калькулятор формул комбинаторики\n 4 - Калькулятор многочленов\n 5 - Теор.вер. и мат.статистика\n 6 - Работа с функциями\n\n");
        printf("Для выхода введите 0.\n");
        do {
            printf("Ваш выбор: "); scanf_s("%c", &t); getchar(); printf("\n");
            if (t < 48 || t > 54) { printf("Некорректный ввод. Повторите попытку\n"); getchar(); }
        } while (t < 48 || t > 54);
        t = t - '0';
        switch (t) {
        case 1: calc1(); break;
        case 2: calc2(); break;
        case 3: calc3(); break;
        case 4: calc4(); break;
        case 5: calc5(); break;
        case 6: calc6(); break;
        case 0: system("cls"); printf("Программа завершена!\n"); break;
        }
    } while (t != 0);
    return 0;
}
	
