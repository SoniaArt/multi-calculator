#include <iostream>
#include <stdbool.h>
#include <string.h>
#include <locale.h>
#include "Header6.h"
#include <stdio.h>
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS
//                                ,                                          
int flag;
int prg=0;//             
double A, B;//               
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

void section(void){//              
    do{
        printf("                             : ");scanf("%lf %lf", &A, &B);
        if (A>B){
            int n;
            n=A; A=B; B=n;
        }
        if (A>=B-0.01){
            printf("                        ,                 ");
        }
    }while (A>B-0.01);
}

void extreme(int prg){
   section();//              
   int count=0;
   double a=0,b=0,c = 0,d=0;
   if (prg!=2){
      printf("         : ");scanf("%lf", &a);
      printf("        b: ");scanf("%lf", &b);
      printf("        c: ");scanf("%lf", &c);
      if (prg==3 || prg==5 || prg==6){
         printf("        d: ");scanf("%lf", &d);
      }
      printf("          : ");
      for (double i=A+0.01; i<=B; i+=0.01){
         if ((f_choose(i-0.01,a,b,c,d, prg)>f_choose(i,a,b,c,d,prg) && f_choose(i+0.01,a,b,c,d,prg)>f_choose(i,a,b,c,d,prg))||(f_choose(i-0.01,a,b,c,d,prg)<f_choose(i,a,b,c,d,prg) && f_choose(i+0.01,a,b,c,d,prg)<f_choose(i,a,b,c,d,prg))){ printf("%lf ",f_choose(i,a,b,c,d,prg)); count++;}
      }printf("\n");
      if (count==0){
         printf("              \n");
      }
   }
   else{
      double parameters[100];
      int k;
      printf("                            : ");scanf("%d", &k);
      for (int j=0; j<k; j++){
         printf("        %d         : ", j+1); scanf("%lf", &parameters[j]);
      }
      printf("          : ");
      for (double i=A+0.01; i<=B; i+=0.01){
         if ((polynomial(i-0.01, parameters,k)>polynomial(i,parameters,k) && polynomial(i+0.01, parameters,k)>polynomial(i, parameters,k))||((polynomial(i-0.01, parameters,k))<polynomial(i, parameters,k) && polynomial(i+0.01, parameters,k)<polynomial(i, parameters,k))){ printf("%lf ",polynomial(i, parameters,k)); count++;}
      }printf("\n");
      if (count==0){
         printf("              \n");
      }
      
   }
}



void root(int prg){
   section();//              
   int count=0;
   double a=0,b=0,c = 0,d=0;
   if (prg!=2){//          
      printf("         : ");scanf("%lf", &a);
      printf("        b: ");scanf("%lf", &b);
      printf("        c: ");scanf("%lf", &c);
      if (prg==3 || prg==5 || prg==6){
         printf("        d: ");scanf("%lf", &d);
      }
      printf("     : ");
      for (double i=A+0.01; i<=B; i+=0.01){
         if (fabs(f_choose(i,a,b,c,d, prg))<=0.001){ printf("%lf ",i); count++;}
      }printf("\n");
      if (count==0){
         printf("          \n");
      }
   }
   else{
      double parameters[100];
      int k;
      printf("                            : ");scanf("%d", &k);
      for (int j=0; j<k; j++){
         printf("        %d         : ", j+1); scanf("%lf", &parameters[j]);
      }
      printf("     : ");
      for (double i=A+0.01; i<=B; i+=0.01){
         if (fabs(polynomial(i, parameters,k))<=0.0001){ printf("%lf ",polynomial(i, parameters,k)); count++;}
      }printf("\n");
      if (count==0){
         printf("          \n");
      }
      
   }
}
void integral(int prg){
   section();//              
   int count=0;
   double s=0;//g             
   double a=0,b=0,c = 0,d=0;
   if (prg!=2){//          
      printf("         : ");scanf("%lf", &a);
      printf("        b: ");scanf("%lf", &b);
      printf("        c: ");scanf("%lf", &c);
      if (prg==3 || prg==5 || prg==6){
         printf("        d: ");scanf("%lf", &d);
      }
      printf("        : ");
      for (double i=A; i<=B; i+=0.001){
//         if (f_choose(i,a,b,c,d, prg)!=0)
         {s+=(0.001*0.5*(f_choose(i,a,b,c,d,prg)+f_choose(i+0.001,a,b,c,d,prg))); count++;}
      }printf("%f\n", s);
   }
   else{
      double parameters[100];
      int k;
      printf("                            : ");scanf("%d", &k);
      for (int j=0; j<k; j++){
         printf("        %d         : ", j+1); scanf("%lf", &parameters[j]);
      }
      printf("     : ");
      for (double i=A; i<=B; i+=0.001){
         if (polynomial(i, parameters,k)==0){ printf("%lf ",polynomial(i, parameters,k)); count++;}
      }printf("\n");
      for (double i=A; i<=B; i+=0.001){
//         if (f_choose(i,a,b,c,d, prg)!=0)
         {s+=(0.001*0.5*(polynomial(i,parameters,k)+polynomial(i+0.001,parameters,k))); count++;}
      }printf("%f\n", s);

      
   }
}



int main (void){
   int circle=0;
   do{
      int prg=0;
      printf("                        : \n 1) C              a*x^b+c \n 2)                     : a0+a1*x+a2*x^2+...+aN*x^N\n 3)                   : a*b^(c*x)+b\n 4)                     : a*ln(b*x)+c\n 5) C             : a*sin(b*x+c)+d\n 6)                 : a*cos(b*x+c)+d \n");
      do{
         scanf("%d", &prg);
         switch (prg){
            case 1: flag=1; break;
            case 2: flag=2; break;
            case 3: flag=3; break;
            case 4: flag=4; break;
            case 5: flag=5; break;
            case 6: flag=6; break;
            default: printf("                        \n"); break;}
      }while (prg!=1 && prg!=2 && prg!=3 && prg!=4 && prg!=5 && prg!=6);
      
      int prg1=0;
      printf("                         : \n 1)                              \n 2)             3)                     \n");
      do{
         scanf("%d", &prg1);
         switch (prg1){
            case 1: extreme(prg); break;
            case 2: root(prg); break;
            case 3: integral(prg); break;
            default: printf("                        \n"); break;}
      }while (prg1!=1 && prg1!=2 && prg1!=3);
      printf("0 -                 ;\n                  -           \n");scanf("%d\n", &circle);
   }while (circle!=0);
}
