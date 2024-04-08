#include <iostream>
#include <locale.h>
#include "Header5.h"
using namespace std;


void probabilityMN() {
    long long int m, n;
    while (1) {
        cout << "������� ���������� �������� �����������: "; cin >> m;
        if (m < 0) { cout << "������������ ��������, ���������� �����\n"; continue; }
        break;
    }
    while (1) {
        cout << "������� ����� ���������� �������: "; cin >> n;
        if (n <= 0) { cout << "������������ ��������, ���������� �����\n"; continue; }
        if (n < m) { cout << "����� ���������� ������� �� ����� ��������� ���������� �������� �������, ���������� �����\n"; continue; }
        break;
    }
    double prob = (m * 1.0 / (n * 1.0)) * 100.0;
    cout << "����������� �������� �������: " << prob << "%\n";
}

void dispersion() {
    double mathexp = 0, mathexp_square = 0;
    double disp;
    double sum_probab = 0;
    int amount;
    while (1) {
        cout << "������� ���������� ��������� � ���������� �������������: "; cin >> amount;
        if (amount <= 0) { cout << "���������� ��������� �� ����� ���� 0 ��� �������������, ��������� ����\n"; continue; }
        break;
    }

    double* x, * p;
    x = (double*)malloc(amount * sizeof(double));
    p = (double*)malloc(amount * sizeof(double));
    // �������� �������� ������� � ����� ���������� ���������������, � ������ ������ ��� �������������

    cout << "����������� ����������� ������� ������ (p > 0 p <= 1).\n";
    for (int i = 0; i < amount; i++) {
        cout << "������� �������� " << i + 1 << "-�� ��������: "; cin >> x[i];
        while (1) {
            cout << "������� ����������� ��� " << i + 1 << "-�� ��������: "; cin >> p[i];
            if (p[i] <= 0.0 or p[i] > 1.0) { cout << "������������ ��������\n"; continue; }
            break;
        }
        mathexp += x[i] * p[i];
        mathexp_square += x[i]*x[i] * p[i];
        sum_probab += p[i];
    }
    if (sum_probab != 1.0) {
        cout << "����� ������������ �� ��������� 1, ���������� ��������� ���������.\n";
        return;
    }
    disp = mathexp_square - mathexp * mathexp;

    cout << "��������� ��� ������� �������������: " << disp << ".\n";

    free(x);
    free(p);
}

void expectedVal() {
    double expval = 0;
    double sum_probab = 0;
    int amount;
    while (1) {
        cout << "������� ���������� ��������� � ���������� �������������: "; cin >> amount; getchar();
        if (amount <= 0) { cout << "���������� ��������� �� ����� ���� 0 ��� �������������, ��������� ����\n"; continue; }
        break;
    }

    double* x, * p;
    x = (double*)malloc(amount * sizeof(double));
    p = (double*)malloc(amount * sizeof(double));
    // �������� �������� ������� � ����� ���������� ���������������, � ������ ������ ��� �������������

    cout << "����������� ����������� ������� ������ (p > 0 p <= 1).\n";
    for (int i = 0; i < amount; i++) {
        cout << "������� �������� " << i + 1 << "-�� ��������: "; cin >> x[i];
        while (1) {
            cout << "������� ����������� ��� " << i + 1 << "-�� ��������: "; cin >> p[i];
            if (p[i] <= 0.0 or p[i] >= 1.0) { cout << "������������ ��������\n"; continue; }
            break;
        }
        expval += x[i] * p[i];
        sum_probab += p[i];
    }
    if (sum_probab != 1.0) {
        cout << "����� ������������ �� ��������� 1, ���������� ��������� �������������� ��������.\n";
        return;
    }
    cout << "�������������� �������� ��� ������� ����������� �������������: " << expval << ".\n";
    free(x);
    free(p);
}


void calc5() {
    {
        setlocale(LC_ALL, "Rus");
        int choice = 0;
        do {
            cout << "�������� ����������� ������:\n1. ����������� m/n\n2. ��������� ��� ����������� ������������� �������\n"
                << "3. ���. �������� ��� ����������� ������������� �������\n0. ��������� � ���������� ����\n";
            cin >> choice;
            switch (choice) {
                case 1: system("cls"); probabilityMN(); cout << "\n\n"; break;
                case 2: system("cls"); dispersion(); cout << "\n\n"; break;
                case 3: system("cls");  expectedVal(); cout << "\n\n"; break;
                case 0: system("cls"); break;
                default: cout << "������������ ��������. ���������� �����.\n";
            }
        } while (choice != 0);
    }
}
