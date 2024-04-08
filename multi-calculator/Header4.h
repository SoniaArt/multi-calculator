#pragma once
void calc4();

int TTrueNum(char GuessNum[]);
int Inputt();
int TTrueNum1(char GuessNum[]);
int Inputt1();
void Print(char coefficients[], int degree);
void input_coefficients(char* coefficients, int* degree);
void Sum_coefficients(char coefficients1[], char coefficients2[], int degree1, int degree2, char coefficients_new[], int* degree3);
void Minus_coefficients(char coefficients1[], char coefficients2[], int degree1, int degree2, char coefficients_new[], int* degree3);
void Umn(char coefficients1[], char coefficients2[], int degree1, int degree2, char coefficients_new[], int* degree3);
void Umn_count(char coefficients1[], int degree1, char coefficients_new[], int a);
void Proizv(char coefficients1[], int degree1, char coefficients_new[], int* degree3);