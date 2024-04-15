#pragma once
void calc4();

int TTrueNum(char GuessNum[]);
int Inputt();
int TTrueNum1(char GuessNum[]);
int Inputt1();
void Print(char coefficients[], int degree);
void input_coefficients(char* coefficients, int* degree);
void Sum(char coefficients1[], char coefficients2[], int degree1, int degree2, char coefficients_new[], int* degree3);
void Minus(char coefficients1[], char coefficients2[], int degree1, int degree2, char coefficients_new[], int* degree3);
void Multiplication(char coefficients1[], char coefficients2[], int degree1, int degree2, char coefficients_new[], int* degree3);
void Multiplication_count(char coefficients1[], int degree1, char coefficients_new[], int a);
void Composition(char coefficients1[], int degree1, char coefficients_new[], int* degree3);
void Division(char coefficients1[], char coefficients2[], char quotient[], char remainder[], int degree1, int degree2);