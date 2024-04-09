//
//  функция проверки на вводимость числа.c
//  Function
//
//  Created by Александра on 09.04.2024.
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
double char_double (void){
    char y[20];
    int flag=0;//обозначение того, что число полностью проверено, и оно соответствует типу double
    double y1;
    do{
        int k_points=0;//количество точек в строке
        printf("Введите число типа double: ");scanf("%s", y);
        for (int i=0; i<strlen(y);i++){
            if (i==0){
                if (y[i]!='-' && isdigit(y[i])==0)//если символ не является минусом и не является цифрой
                {break;}//прерываем программу, чтобы вводить значение заново
            }

            if (i>0)
            {
                if (y[i]!='.' && isdigit(y[i])==0)//если символ не является точкой и не является цифрой
                {break;}//прерываем программу, чтобы вводить значение заново
            }
            if (y[i]=='.'){
                k_points++;
                if (k_points>1){
                    break;
                }
            }
            if (i==strlen(y)-1)
            {
                    flag=1;
                    y1=atof(y);
            }
        }
    }while (flag==0);
    return y1;
}

int char_int (char *n){
    int n1;
    return n1;
}

int main(void){
    char n[10]={0};//число в строковом виде
    int n1;//число в инт
    double y;
    y=char_double();//аналогично scanf, но с внутренней проверкой на наличие букв
    printf("y=%lf\n", y);
}
