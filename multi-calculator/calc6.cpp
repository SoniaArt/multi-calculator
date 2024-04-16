
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdbool.h>
#include <string.h>
#include <locale.h>
#include "Header6.h"
#include <stdio.h>
#include <math.h>

double char_double (const char *input_str){
    char y[20];
    int flag=0;//����������� ����, ��� ����� ��������� ���������, � ��� ������������� ���� double
    double y1;
    do{
        int k_points=0;//���������� ����� � ������
        printf("%s",input_str);scanf("%s", y);
        for (int i=0; i<strlen(y);i++){
            if (i==0){
                if (y[i]!='-' && isdigit(y[i])==0)//���� ������ �� �������� ������� � �� �������� ������
                {break;}//��������� ���������, ����� ������� �������� ������
            }

            if (i>0)
            {
                if (y[i]!='.' && isdigit(y[i])==0)//���� ������ �� �������� ������ � �� �������� ������
                {break;}//��������� ���������, ����� ������� �������� ������
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

int char_int(const char *input_str){
    char y[20];
    int flag=0;//����������� ����, ��� ����� ��������� ���������, � ��� ������������� ���� int
    int y1;
    do{
        printf("%s",input_str);scanf("%s", y);
        for (int i=0; i<strlen(y);i++){
            if (i==0){
                if (y[i]!='-' && isdigit(y[i])==0)//���� ������ �� �������� ������� � �� �������� ������
                {break;}//��������� ���������, ����� ������� �������� ������
            }

            if (i>0)
            {
                if (isdigit(y[i])==0)//���� ������ �� �������� ������
                {break;}//��������� ���������, ����� ������� �������� ������
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
//������� �������� ���� ����������, ����� �� ����� ���� �� ������� ������ ���
int flag;
int prg=0;//����� �������
double A, B;//������� �������
double power_function(double x, double a, double b, double c, double d){
   double y;

   y=a*pow(x,b)+c;
//   printf("#%lf %lf\n", y, x);
   return y;
}

double polynomial(double x, double *parameters, double k){
   double y=0;
   for (int j=0; j<k; j++){
      y+=parameters[j]*pow(x,j);
   }

   return y;
}

double indicative(double x, double a, double b, double c, double d){
    double y;

   y=a*pow(b,(c*x))+d;
   return y;
}

double logarithmic(double x, double a, double b, double c, double d){
//   while ((x*b)<0){
//      break;
//   }
    double y;

   y=a*log(b*x)+c;
   return y;
}

double sine(double x, double a, double b, double c, double d){
   double y;

   y=a*sin(b*x+c)+d;
   return y;
}

double cosine(double x, double a, double b, double c, double d){
   double y;

   y=a*cos(b*x+c)+d;
   return y;
}

double f_choose(double x, double a, double b, double c, double d, int prg){
   double y;
    switch (prg){
        case 1: y=power_function(x,a,b,c,d); break;
        case 3: y=indicative(x,a,b,c,d); break;
        case 4: y=logarithmic(x,a,b,c,d); break;
        case 5: y=sine(x,a,b,c,d); break;
        case 6: y=cosine(x,a,b,c,d); break;
    }
   return y;
}

void section(void){//������� ������
    do{
       A=char_double("������� ������ ������� ����� �������: ");
       B=char_double("������� ������ ������� ����� �������: ");
        if (A>B){
            int n;
            n=A; A=B; B=n;
        }
        if (A>=B-0.01){
            printf("������� ������� ��������, ���������� �����");
        }
    }while (A>B-0.01);
}

void extreme(int prg){
   section();//������� ������
   int count=0;
   double a=0,b=0,c = 0,d=0;
   if (prg!=2){
      a=char_double("������� �: ");
      b=char_double("������� b: ");
      c=char_double("������� c: ");
      if (prg==3 || prg==5 || prg==6){
         d=char_double("������� d: ");
      }
      printf("����������: ");
      for (double i=A+0.01; i<=B; i+=0.01){
         if ((f_choose(i-0.01,a,b,c,d, prg)>f_choose(i,a,b,c,d,prg) && f_choose(i+0.01,a,b,c,d,prg)>f_choose(i,a,b,c,d,prg))||(f_choose(i-0.01,a,b,c,d,prg)<f_choose(i,a,b,c,d,prg) && f_choose(i+0.01,a,b,c,d,prg)<f_choose(i,a,b,c,d,prg))){ printf("%lf ",f_choose(i,a,b,c,d,prg)); count++;}
      }printf("\n");
      if (count==0){
         printf("���������� ���\n");
      }
   }
   else{
      double parameters[100];
      int k;
      k=char_int("������� ���������� ���������: ");
      for (int j=0; j<k; j++){
         printf("������� %d ��������: ", j+1); scanf("%lf", &parameters[j]);//j+1=char_double("������� ��������� ��������: ");
      }
      printf("����������: ");
      for (double i=A+0.01; i<=B; i+=0.01){
         if ((polynomial(i-0.01, parameters,k)>polynomial(i,parameters,k) && polynomial(i+0.01, parameters,k)>polynomial(i, parameters,k))||((polynomial(i-0.01, parameters,k))<polynomial(i, parameters,k) && polynomial(i+0.01, parameters,k)<polynomial(i, parameters,k))){ printf("%lf ",polynomial(i, parameters,k)); count++;}
      }printf("\n");
      if (count==0){
         printf("���������� ���\n");
      }
      
   }
}



void root(int prg){
   section();//������� ������
   int count=0;
   double a=0,b=0,c = 0,d=0;
   if (prg!=2){//����������
      a=char_double("������� a: ");
      b=char_double("������� b: ");
      c=char_double("������� c: ");
      if (prg==3 || prg==5 || prg==6){
         d=char_double("������� d: ");
      }
      printf("�����: ");
      for (double i=A+0.01; i<=B; i+=0.01){
         if (fabs(f_choose(i,a,b,c,d, prg))<=0.001){ printf("%lf ",i); count++;}
      }printf("\n");
      if (count==0){
         printf("������ ���\n");
      }
   }
   else{
      double parameters[100];
      int k;
      k=char_int("������� ���������� ���������: ");
      for (int j=0; j<k; j++){
         printf("������� %d ��������: ", j+1); scanf("%lf", &parameters[j]);
      }
      printf("�����: ");
      for (double i=A+0.01; i<=B; i+=0.01){
         if (fabs(polynomial(i, parameters,k))<=0.0001){ printf("%lf ",polynomial(i, parameters,k)); count++;}
      }printf("\n");
      if (count==0){
         printf("������ ���\n");
      }
      
   }
}
void integral(int prg){
   section();//������� ������
   int count=0;
   double s=0;//g������ ������
   double a=0,b=0,c = 0,d=0;
   if (prg!=2){//����������
      a=char_double("������� a: ");
      b=char_double("������� b: ");
      c=char_double("������� c: ");
      if (prg==3 || prg==5 || prg==6){
         d=char_double("������� d: ");
      }
      printf("��������: ");
      for (double i=A; i<=B; i+=0.001){
//         if (f_choose(i,a,b,c,d, prg)!=0)
         {s+=(0.001*0.5*(f_choose(i,a,b,c,d,prg)+f_choose(i+0.001,a,b,c,d,prg))); count++;}
      }printf("%f\n", s);
   }
   else{
      double parameters[100];
      int k;
      k=char_int("������� ���������� ���������: ");
      for (int j=0; j<k; j++){
         printf("������� %d ��������: ", j+1); scanf("%lf", &parameters[j]);//�� �������� ���� � �������
      }
      printf("�����: ");
      for (double i=A; i<=B; i+=0.001){
         if (polynomial(i, parameters,k)==0){ printf("%lf ",polynomial(i, parameters,k)); count++;}
      }printf("\n");
      for (double i=A; i<=B; i+=0.001){
//         if (f_choose(i,a,b,c,d, prg)!=0)
         {s+=(0.001*0.5*(polynomial(i,parameters,k)+polynomial(i+0.001,parameters,k))); count++;}
      }printf("%f\n", s);

      
   }
}



void calc6(){
   int circle=0;
   do{
      int prg=0;
      do{
         prg=char_int("�������� ������� �������: \n 1 - C�������� ����: a*x^b+c \n 2 - ������� ������� ����: a0+a1*x+a2*x^2+...+aN*x^N\n 3 - ������������� ����: a*b^(c*x)+b\n 4 - ��������������� ����: a*ln(b*x)+c\n 5 - C�������� ����: a*sin(b*x+c)+d\n 6 - ����������� ����: a*cos(b*x+c)+d \n");
         switch (prg){
            case 1: flag=1; break;
            case 2: flag=2; break;
            case 3: flag=3; break;
            case 4: flag=4; break;
            case 5: flag=5; break;
            case 6: flag=6; break;
            default: printf("������� ������� ��������\n"); break;}
      }while (prg!=1 && prg!=2 && prg!=3 && prg!=4 && prg!=5 && prg!=6);
      
      int prg1=0;
      do{
         prg1=char_int("�������� ��� ������������: \n 1 - ����� ����������� �� ������� \n 2 - ����� ����� \n 3 - ���������� ��������� \n");
         switch (prg1){
            case 1: extreme(prg); break;
            case 2: root(prg); break;
            case 3: integral(prg); break;
            default: printf("������� ������� ��������\n"); break;}
      }while (prg1!=1 && prg1!=2 && prg1!=3);
      circle=char_int("0 - ��������� � ����;\n����� ������ ����� ����� - ����������\n");
   }while (circle!=0);
   //return 0;
}
