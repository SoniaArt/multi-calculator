#pragma once
#define MaxN 100
struct fraction;
void input(char* str, int len, char* str_num, char* str_den);
int check(char* str, int len);
int NOD(int a, int b);
int NOK(int a, int b);
void comparison(fraction fr1, fraction fr2);
void reduction(fraction fr1);
void decimal(fraction fr1);
void choice(fraction res);
void calc2();
