
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
double char_double (char *input_str){
    char y[20];
    int flag=0;//обозначение того, что число полностью проверено, и оно соответствует типу double
    double y1;
    do{
        int k_points=0;//количество точек в строке
        printf("%s",input_str);scanf("%s", y);
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

int char_int(char *input_str){
    char y[20];
    int flag=0;//обозначение того, что число полностью проверено, и оно соответствует типу int
    int y1;
    do{
        printf("%s",input_str);scanf("%s", y);
        for (int i=0; i<strlen(y);i++){
            if (i==0){
                if (y[i]!='-' && isdigit(y[i])==0)//если символ не является минусом и не является цифрой
                {break;}//прерываем программу, чтобы вводить значение заново
            }

            if (i>0)
            {
                if (isdigit(y[i])==0)//если символ не является цифрой
                {break;}//прерываем программу, чтобы вводить значение заново
            }
            if (i==strlen(y)-1)
            {
                    flag=1;
                    y1=atoi(y);
            }
        }
    }while (flag==0);
    return y1;
}

int main(void){
    double y;
    char input_str1[50]="Введите число типа double: ";//записываем текст, который хотим видеть на прокрутке функции
    y=char_double(input_str1);//аналогично scanf, но с внутренней проверкой на наличие букв
    printf("y=%lf\n", y);
    
    char input_str2[50]="Введите число типа int: ";//записываем текст, который хотим видеть на прокрутке функции
    int x;
    x=char_int(input_str2);
    printf("y=%lf\n", y);
}

