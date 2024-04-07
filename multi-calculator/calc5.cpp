#include <iostream>
#include <locale.h>
#include "Header5.h"
using namespace std;


void probabilityMN() {
    long long int m, n;
    while (1) {
        cout << "Введите количество успешных результатов: "; cin >> m;
        if (m < 0) { cout << "Некорректное значение, попробуйте снова\n"; continue; }
        break;
    }
    while (1) {
        cout << "Введите общее количество попыток: "; cin >> n;
        if (n <= 0) { cout << "Некорректное значение, попробуйте снова\n"; continue; }
        if (n < m) { cout << "Общее количество попыток не может превышать количество успешных попыток, попробуйте снова\n"; continue; }
        break;
    }
    double prob = (m * 1.0 / (n * 1.0)) * 100.0;
    cout << "Вероятность успешной попытки: " << prob << "%\n";
}

void dispersion() {
    double mathexp = 0, mathexp_square = 0;
    double disp;
    double sum_probab = 0;
    int amount;
    while (1) {
        cout << "Введите количество элементов в дискретном распределении: "; cin >> amount;
        if (amount <= 0) { cout << "Количество элементов не может быть 0 или отрицательным, повторите ввод\n"; continue; }
        break;
    }

    double* x, * p;
    x = (double*)malloc(amount * sizeof(double));
    p = (double*)malloc(amount * sizeof(double));
    // Введение массивов сделано с целью возможного масштабирования, в данном случае оно необязательно

    cout << "Вероятность указывается дробным числом (p > 0 p <= 1).\n";
    for (int i = 0; i < amount; i++) {
        cout << "Введите значение " << i + 1 << "-го элемента: "; cin >> x[i];
        while (1) {
            cout << "Введите вероятность для " << i + 1 << "-го элемента: "; cin >> p[i];
            if (p[i] <= 0.0 or p[i] > 1.0) { cout << "Некорректное значение\n"; continue; }
            break;
        }
        mathexp += x[i] * p[i];
        mathexp_square += x[i]*x[i] * p[i];
        sum_probab += p[i];
    }
    if (sum_probab != 1.0) {
        cout << "Сумма вероятностей не равняется 1, невозможно вычислить дисперсию.\n";
        return;
    }
    disp = mathexp_square - mathexp * mathexp;

    cout << "Дисперсия для данного распределения: " << disp << ".\n";

    free(x);
    free(p);
}

void expectedVal() {
    double expval = 0;
    double sum_probab = 0;
    int amount;
    while (1) {
        cout << "Введите количество элементов в дискретном распределении: "; cin >> amount; getchar();
        if (amount <= 0) { cout << "Количество элементов не может быть 0 или отрицательным, повторите ввод\n"; continue; }
        break;
    }

    double* x, * p;
    x = (double*)malloc(amount * sizeof(double));
    p = (double*)malloc(amount * sizeof(double));
    // Введение массивов сделано с целью возможного масштабирования, в данном случае оно необязательно

    cout << "Вероятность указывается дробным числом (p > 0 p <= 1).\n";
    for (int i = 0; i < amount; i++) {
        cout << "Введите значение " << i + 1 << "-го элемента: "; cin >> x[i];
        while (1) {
            cout << "Введите вероятность для " << i + 1 << "-го элемента: "; cin >> p[i];
            if (p[i] <= 0.0 or p[i] >= 1.0) { cout << "Некорректное значение\n"; continue; }
            break;
        }
        expval += x[i] * p[i];
        sum_probab += p[i];
    }
    if (sum_probab != 1.0) {
        cout << "Сумма вероятностей не равняется 1, невозможно вычислить математическое ожидание.\n";
        return;
    }
    cout << "Математическое ожидание для данного дискретного распределения: " << expval << ".\n";
    free(x);
    free(p);
}


int calc5() {
    {
        setlocale(LC_ALL, "rus");
        int choice = 0;
        do {
            cout << "Выберите необходимую задачу:\n1. Вероятность m/n\n2. Дисперсия для дискретного распределения величин\n"
                << "3. Мат. ожидание для дискретного распределения величин\n0. Вернуться в предыдущее меню\n";
            cin >> choice;
            switch (choice) {
                case 1: system("cls"); probabilityMN(); break;
                case 2: system("cls"); dispersion(); break;
                case 3: system("cls");  expectedVal(); break;
                case 0: system("cls"); break;
                default: cout << "Некорректное значение. Попробуйте снова.\n";
            }
            cout << "\n\n";
        } while (choice != 0);
    }
}
