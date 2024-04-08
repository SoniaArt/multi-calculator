#pragma once
void calc1();
float* input(int n, int m);
void print(float* a, int n, int m);
float* sum(float* m1, float* m2, int n, int m);
float* sub(float* m1, float* m2, int n, int m);
float* multi(float* mat1, float* mat2, int n1, int n2, int m1, int m2);
float* multinum(float* mat, int n, int m, float num);
float* sumnum(float* mat, int n, int m, float num);
float* transpon(float* am, int n, int m);
float determinant(float* mat, int n);
float* inverse(float* mat, int n);

