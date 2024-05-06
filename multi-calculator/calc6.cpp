#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdbool.h>
#include <string.h>
#include <locale.h>
#include "Header6.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <SDL.h>
#include <stdbool.h>



double char_double(const char* input_str) {//проверка на корректность вводимости числа
    char y[20];
    int flag = 0;//обозначение того, что число полностью проверено, и оно соответствует типу double
    double y1;
    do {
        int k_points = 0;//количество точек в строке
        printf("%s", input_str); scanf("%s", y);
        for (int i = 0; i < strlen(y); i++) {
            if (i == 0) {
                if (y[i] != '-' && isdigit(y[i]) == 0)//если символ не является минусом и не является цифрой
                {
                    break;
                }//прерываем программу, чтобы вводить значение заново
            }

            if (i > 0)
            {
                if (y[i] != '.' && isdigit(y[i]) == 0)//если символ не является точкой и не является цифрой
                {
                    break;
                }//прерываем программу, чтобы вводить значение заново
            }
            if (y[i] == '.') {
                k_points++;
                if (k_points > 1) {
                    break;
                }
            }
            if (i == strlen(y) - 1)
            {
                flag = 1;
                y1 = atof(y);
            }
        }
    } while (flag == 0);
    return y1;
}

int char_int(const char* input_str) {//проверка на корректность вводимости числа
    char y[20];
    int flag = 0;//обозначение того, что число полностью проверено, и оно соответствует типу int
    int y1;
    do {
        printf("%s", input_str); scanf("%s", y);
        for (int i = 0; i < strlen(y); i++) {
            if (i == 0) {
                if (y[i] != '-' && isdigit(y[i]) == 0)//если символ не является минусом и не является цифрой
                {
                    break;
                }//прерываем программу, чтобы вводить значение заново
            }

            if (i > 0)
            {
                if (isdigit(y[i]) == 0)//если символ не является цифрой
                {
                    break;
                }//прерываем программу, чтобы вводить значение заново
            }
            if (i == strlen(y) - 1)
            {
                flag = 1;
                y1 = atoi(y);
            }
        }
    } while (flag == 0);
    return y1;
}
//вынести отдельно ввод параметров, чтобы не нужно было их вводить каждый раз
int flag;
int prg = 0;//выбор функции
double A, B;//границы отрезка
double power_function(double x, double a, double b, double c, double d) {//степенная
    double y;

    y = a * pow(x, b) + c;
    //   printf("#%lf %lf\n", y, x);
    return y;
}

double polynomial(double x, double* parameters, double k) {//полином
    double y = 0;
    for (int j45 = 0; j45 < k; j45++) {
        y += parameters[j45] * pow(x, j45);
    }

    return y;
}

double indicative(double x, double a, double b, double c, double d) {//показательная
    double y;

    y = a * pow(b, (c * x)) + d;
    return y;
}

double logarithmic(double x, double a, double b, double c, double d) {//логарифмическая
    //   while ((x*b)<0){
    //      break;
    //   }
    double y;

    y = a * log(b * x) + c;
    return y;
}

double sine(double x, double a, double b, double c, double d) {//синусоида
    double y;

    y = a * sin(b * x + c) + d;
    return y;
}

double cosine(double x, double a, double b, double c, double d) {//косинусоида
    double y;

    y = a * cos(b * x + c) + d;
    return y;
}

double f_choose(double x, double a, double b, double c, double d, int prg) {//выбор ф-ции
    double y;
    switch (prg) {
    case 1: y = power_function(x, a, b, c, d); break;
    case 3: y = indicative(x, a, b, c, d); break;
    case 4: y = logarithmic(x, a, b, c, d); break;
    case 5: y = sine(x, a, b, c, d); break;
    case 6: y = cosine(x, a, b, c, d); break;
    }
    return y;
}

void section(void) {//отрезок работы над функцией
    do {
        A = char_double("Введите первую крайнюю точку отрезка: ");
        B = char_double("Введите вторую крайнюю точку отрезка: ");
        if (A > B) {
            int n;
            n = A; A = B; B = n;
        }
        if (A >= B - 0.01) {
            printf("Слишком близкие значения, попробуйте снова");
        }
    } while (A > B - 0.01);
}

int SDL_powF(void) {
    section();
    //общая часть
    double a = 0, b = 0, c = 0, d = 0;
    if (prg != 2) {//переменные
        a = char_double("Введите a: ");
        b = char_double("Введите b: ");
        c = char_double("Введите c: ");
    }
    if ((((int)b) != b)) {//не целое
        if (B < 0) { printf("невозможно построить график\n"); return -1; }
        if (B > 0 && A <= 0) { A = 0; printf("&&"); }
    }
    //    else{
    //        double parameters[100];
    //        int k1;
    //        k1=char_int("Введите количество слагаемых: ");
    //        for (int j=0; j<k1; j++){
    //            printf("Введите %d параметр: ", j+1); scanf("%lf", &parameters[j]);//не работает ввод с буквами
    //        }
    //    }

    ///////////////////////////////
    int k;

    if (fabs(A) > fabs(B)) k = 200 / fabs(A);
    else k = 200 / fabs(B);

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        printf("Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("Charting", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
    if (!window) {
        printf("Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        printf("Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Event event;

    bool quit = false;

    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
        }

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // устанавливаем цвет на белый
        SDL_RenderClear(renderer); // очищаем экран

        SDL_SetRenderDrawColor(renderer, 190, 210, 247, 255); // устанавливаем цвет на #bed2f7

        //клетка
        for (int i = 400; i < 800; i += k) {
            SDL_RenderDrawLine(renderer, i, 0, i, 600);
        }//ось oy
        for (int i = 400; i > 0; i -= k) {
            SDL_RenderDrawLine(renderer, i, 0, i, 600);
        }//ось oy

        for (int i = 300; i < 600; i += 20) {
            SDL_RenderDrawLine(renderer, 0, i, 800, i);
        }//ось ox
        for (int i = 300; i > 0; i -= 20) {
            SDL_RenderDrawLine(renderer, 0, i, 800, i);
        }//ось ox

//        for (int i=0; i<800; i+=k){
//            SDL_RenderDrawLine(renderer, i, 0, i, 600);}//ось oy
//        for (int i=0; i<600; i+=20){
//            SDL_RenderDrawLine(renderer, 0, i, 800, i);}//ось ox

        SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255); // устанавливаем цвет на серый

        SDL_RenderDrawLine(renderer, 200, 300, 600, 300);//ось ох
        SDL_RenderDrawLine(renderer, 400, 100, 400, 500);//ось оy

        //cтрелка на ось ох
        SDL_RenderDrawLine(renderer, 590, 295, 600, 300);//ось ох
        SDL_RenderDrawLine(renderer, 590, 305, 600, 300);//ось ох

        //стрелка на ось оу
        SDL_RenderDrawLine(renderer, 395, 110, 400, 100);//ось оу
        SDL_RenderDrawLine(renderer, 405, 110, 400, 100);//ось оу


        //косинусоида
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // устанавливаем цвет чёрный
        for (double i = A; i < B; i++) {
            //добавить возможность менять в зависимости от выбора пользователем диапазона. k=20 при диап от -10 до +10
            for (int j = 0; j < k; j++) {

                //                    int x1=k*i+j+400;
                //                    int y1=(-20*(a*sin((k*(b*i)+j)/(double)k)))+300;

                int x1 = k * i + j + 400;
                int y1 = (-20 * (a * pow((k * ((i + j / ((double)k))) / (double)k), b) + c)) + 300;
                SDL_RenderDrawPoint(renderer, x1, y1); //SDL_RenderDrawPoint(renderer,x1,y1);
            }
        }

        SDL_RenderPresent(renderer); // обновляем экран

    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    printf("start\n");

    return 0;
}



int SDL_pol(void) {
    section();
    //общая часть
    double a = 0, b = 0, c = 0, d = 0;


    double parameters[100];
    int k1;
    k1 = char_int("Введите количество слагаемых: ");
    for (int j = 0; j < k1; j++) {
        printf("Введите %d параметр: ", j + 1); scanf("%lf", &parameters[j]);//не работает ввод с буквами
    }


    ///////////////////////////////
    int k;

    if (fabs(A) > fabs(B)) k = 200 / fabs(A);
    else k = 200 / fabs(B);

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        printf("Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("Charting", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
    if (!window) {
        printf("Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        printf("Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Event event;

    bool quit = false;

    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
        }

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // устанавливаем цвет на белый
        SDL_RenderClear(renderer); // очищаем экран

        SDL_SetRenderDrawColor(renderer, 190, 210, 247, 255); // устанавливаем цвет на #bed2f7

        //клетка
        for (int i = 400; i < 800; i += k) {
            SDL_RenderDrawLine(renderer, i, 0, i, 600);
        }//ось oy
        for (int i = 400; i > 0; i -= k) {
            SDL_RenderDrawLine(renderer, i, 0, i, 600);
        }//ось oy

        for (int i = 300; i < 600; i += 20) {
            SDL_RenderDrawLine(renderer, 0, i, 800, i);
        }//ось ox
        for (int i = 300; i > 0; i -= 20) {
            SDL_RenderDrawLine(renderer, 0, i, 800, i);
        }//ось ox

//        for (int i=0; i<800; i+=k){
//            SDL_RenderDrawLine(renderer, i, 0, i, 600);}//ось oy
//        for (int i=0; i<600; i+=20){
//            SDL_RenderDrawLine(renderer, 0, i, 800, i);}//ось ox

        SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255); // устанавливаем цвет на серый

        SDL_RenderDrawLine(renderer, 200, 300, 600, 300);//ось ох
        SDL_RenderDrawLine(renderer, 400, 100, 400, 500);//ось оy

        //cтрелка на ось ох
        SDL_RenderDrawLine(renderer, 590, 295, 600, 300);//ось ох
        SDL_RenderDrawLine(renderer, 590, 305, 600, 300);//ось ох

        //стрелка на ось оу
        SDL_RenderDrawLine(renderer, 395, 110, 400, 100);//ось оу
        SDL_RenderDrawLine(renderer, 405, 110, 400, 100);//ось оу


        //косинусоида
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // устанавливаем цвет чёрный
        for (double i = A; i < B; i++) {
            int schet = 0;

            //добавить возможность менять в зависимости от выбора пользователем диапазона. k=20 при диап от -10 до +10
            for (int j = 0; j < k; j++) {

                int x1 = k * i + j + 400;
                int y1 = 0;
                for (int j45 = 0; j45 < k; j45++) {
                    y1 += -20 * parameters[j45] * pow((k * ((i + j / ((double)k))) / (double)k), j45);
                }
                y1 += 300;
                SDL_RenderDrawPoint(renderer, x1, y1); //SDL_RenderDrawPoint(renderer,x1,y1);

            }
        }

        SDL_RenderPresent(renderer); // обновляем экран

    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    printf("start\n");

    return 0;
}


int SDL_ind(void) {
    section();
    //общая часть
    double a = 0, b = 0, c = 0, d = 0;
    if (prg != 2) {//переменные
        a = char_double("Введите a: ");
        do {
            b = char_double("Введите b: ");
        } while (b <= 0 || b == 1);
        c = char_double("Введите c: ");
        d = char_double("Введите d: ");
    }
    else {
        double parameters[100];
        int k1;
        k1 = char_int("Введите количество слагаемых: ");
        for (int j = 0; j < k1; j++) {
            printf("Введите %d параметр: ", j + 1); scanf("%lf", &parameters[j]);//не работает ввод с буквами
        }
    }

    ///////////////////////////////
    int k;

    if (fabs(A) > fabs(B)) k = 200 / fabs(A);
    else k = 200 / fabs(B);

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        printf("Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("Charting", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
    if (!window) {
        printf("Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        printf("Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Event event;

    bool quit = false;

    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
        }

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // устанавливаем цвет на белый
        SDL_RenderClear(renderer); // очищаем экран

        SDL_SetRenderDrawColor(renderer, 190, 210, 247, 255); // устанавливаем цвет на #bed2f7

        //клетка
        for (int i = 400; i < 800; i += k) {
            SDL_RenderDrawLine(renderer, i, 0, i, 600);
        }//ось oy
        for (int i = 400; i > 0; i -= k) {
            SDL_RenderDrawLine(renderer, i, 0, i, 600);
        }//ось oy

        for (int i = 300; i < 600; i += 20) {
            SDL_RenderDrawLine(renderer, 0, i, 800, i);
        }//ось ox
        for (int i = 300; i > 0; i -= 20) {
            SDL_RenderDrawLine(renderer, 0, i, 800, i);
        }//ось ox

//        for (int i=0; i<800; i+=k){
//            SDL_RenderDrawLine(renderer, i, 0, i, 600);}//ось oy
//        for (int i=0; i<600; i+=20){
//            SDL_RenderDrawLine(renderer, 0, i, 800, i);}//ось ox

        SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255); // устанавливаем цвет на серый

        SDL_RenderDrawLine(renderer, 200, 300, 600, 300);//ось ох
        SDL_RenderDrawLine(renderer, 400, 100, 400, 500);//ось оy

        //cтрелка на ось ох
        SDL_RenderDrawLine(renderer, 590, 295, 600, 300);//ось ох
        SDL_RenderDrawLine(renderer, 590, 305, 600, 300);//ось ох

        //стрелка на ось оу
        SDL_RenderDrawLine(renderer, 395, 110, 400, 100);//ось оу
        SDL_RenderDrawLine(renderer, 405, 110, 400, 100);//ось оу


        //косинусоида
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // устанавливаем цвет чёрный
        for (double i = A; i < B; i++) {
            //добавить возможность менять в зависимости от выбора пользователем диапазона. k=20 при диап от -10 до +10
            for (int j = 0; j < k; j++) {

                //                    int x1=k*i+j+400;
                //                    int y1=(-20*(a*sin((k*(b*i)+j)/(double)k)))+300;

                int x1 = k * i + j + 400;
                int y1 = (-20 * (a * pow(b, (k * (c * (i + j / ((double)k))) / (double)k)) + d)) + 300;
                SDL_RenderDrawPoint(renderer, x1, y1); //SDL_RenderDrawPoint(renderer,x1,y1);
            }
        }

        SDL_RenderPresent(renderer); // обновляем экран

    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    printf("start\n");

    return 0;

}



int SDL_ln(void) {
    section();
    //общая часть
    double a = 0, b = 0, c = 0, d = 0;
    if (prg != 2) {//переменные
        a = char_double("Введите a: ");
        b = char_double("Введите b: ");
        c = char_double("Введите c: ");
    }
    else {
        double parameters[100];
        int k1;
        k1 = char_int("Введите количество слагаемых: ");
        for (int j = 0; j < k1; j++) {
            printf("Введите %d параметр: ", j + 1); scanf("%lf", &parameters[j]);//не работает ввод с буквами
        }
    }
    if (b > 0 && B < 0) { printf("невозможно построить график\n"); return -1; }
    if (b > 0 && A < 0) { A = 0; }
    if (b < 0 && A>0) { printf("невозможно построить график\n"); return -1; }
    if (b < 0 && B>0) { B = 0; }

    ///////////////////////////////
    int k;

    if (fabs(A) > fabs(B)) k = 200 / fabs(A);
    else k = 200 / fabs(B);

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        printf("Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("Charting", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
    if (!window) {
        printf("Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        printf("Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Event event;

    bool quit = false;

    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
        }

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // устанавливаем цвет на белый
        SDL_RenderClear(renderer); // очищаем экран

        SDL_SetRenderDrawColor(renderer, 190, 210, 247, 255); // устанавливаем цвет на #bed2f7

        //клетка
        for (int i = 400; i < 800; i += k) {
            SDL_RenderDrawLine(renderer, i, 0, i, 600);
        }//ось oy
        for (int i = 400; i > 0; i -= k) {
            SDL_RenderDrawLine(renderer, i, 0, i, 600);
        }//ось oy

        for (int i = 300; i < 600; i += 20) {
            SDL_RenderDrawLine(renderer, 0, i, 800, i);
        }//ось ox
        for (int i = 300; i > 0; i -= 20) {
            SDL_RenderDrawLine(renderer, 0, i, 800, i);
        }//ось ox

//        for (int i=0; i<800; i+=k){
//            SDL_RenderDrawLine(renderer, i, 0, i, 600);}//ось oy
//        for (int i=0; i<600; i+=20){
//            SDL_RenderDrawLine(renderer, 0, i, 800, i);}//ось ox

        SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255); // устанавливаем цвет на серый

        SDL_RenderDrawLine(renderer, 200, 300, 600, 300);//ось ох
        SDL_RenderDrawLine(renderer, 400, 100, 400, 500);//ось оy

        //cтрелка на ось ох
        SDL_RenderDrawLine(renderer, 590, 295, 600, 300);//ось ох
        SDL_RenderDrawLine(renderer, 590, 305, 600, 300);//ось ох

        //стрелка на ось оу
        SDL_RenderDrawLine(renderer, 395, 110, 400, 100);//ось оу
        SDL_RenderDrawLine(renderer, 405, 110, 400, 100);//ось оу


        //косинусоида
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // устанавливаем цвет чёрный
        for (double i = A; i < B; i++) {
            //добавить возможность менять в зависимости от выбора пользователем диапазона. k=20 при диап от -10 до +10
            for (int j = 0; j < k; j++) {

                //                    int x1=k*i+j+400;
                //                    int y1=(-20*(a*sin((k*(b*i)+j)/(double)k)))+300;

                int x1 = k * i + j + 400;
                int y1 = (-20 * (a * log(k * (b * (i + j / ((double)k))) / (double)k) + c)) + 300;
                SDL_RenderDrawPoint(renderer, x1, y1); //SDL_RenderDrawPoint(renderer,x1,y1);
            }
        }

        SDL_RenderPresent(renderer); // обновляем экран

    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    printf("start\n");

    return 0;

}

int SDL_sine(void) {
    section();
    //общая часть
    double a = 0, b = 0, c = 0, d = 0;
    if (prg != 2) {//переменные
        a = char_double("Введите a: ");
        b = char_double("Введите b: ");
        c = char_double("Введите c: ");
        d = char_double("Введите d: ");
    }
    else {
        double parameters[100];
        int k1;
        k1 = char_int("Введите количество слагаемых: ");
        for (int j = 0; j < k1; j++) {
            printf("Введите %d параметр: ", j + 1); scanf("%lf", &parameters[j]);//не работает ввод с буквами
        }
    }

    ///////////////////////////////
    int k;

    if (fabs(A) > fabs(B)) k = 200 / fabs(A);
    else k = 200 / fabs(B);

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        printf("Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("Charting", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
    if (!window) {
        printf("Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        printf("Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Event event;

    bool quit = false;

    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
        }

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // устанавливаем цвет на белый
        SDL_RenderClear(renderer); // очищаем экран

        SDL_SetRenderDrawColor(renderer, 190, 210, 247, 255); // устанавливаем цвет на #bed2f7

        //клетка
        for (int i = 400; i < 800; i += k) {
            SDL_RenderDrawLine(renderer, i, 0, i, 600);
        }//ось oy
        for (int i = 400; i > 0; i -= k) {
            SDL_RenderDrawLine(renderer, i, 0, i, 600);
        }//ось oy

        for (int i = 300; i < 600; i += 20) {
            SDL_RenderDrawLine(renderer, 0, i, 800, i);
        }//ось ox
        for (int i = 300; i > 0; i -= 20) {
            SDL_RenderDrawLine(renderer, 0, i, 800, i);
        }//ось ox

//        for (int i=0; i<800; i+=k){
//            SDL_RenderDrawLine(renderer, i, 0, i, 600);}//ось oy
//        for (int i=0; i<600; i+=20){
//            SDL_RenderDrawLine(renderer, 0, i, 800, i);}//ось ox

        SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255); // устанавливаем цвет на серый

        SDL_RenderDrawLine(renderer, 200, 300, 600, 300);//ось ох
        SDL_RenderDrawLine(renderer, 400, 100, 400, 500);//ось оy

        //cтрелка на ось ох
        SDL_RenderDrawLine(renderer, 590, 295, 600, 300);//ось ох
        SDL_RenderDrawLine(renderer, 590, 305, 600, 300);//ось ох

        //стрелка на ось оу
        SDL_RenderDrawLine(renderer, 395, 110, 400, 100);//ось оу
        SDL_RenderDrawLine(renderer, 405, 110, 400, 100);//ось оу


        //косинусоида
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // устанавливаем цвет чёрный
        for (double i = A; i < B; i++) {
            //добавить возможность менять в зависимости от выбора пользователем диапазона. k=20 при диап от -10 до +10
            for (int j = 0; j < k; j++) {

                //                    int x1=k*i+j+400;
                //                    int y1=(-20*(a*sin((k*(b*i)+j)/(double)k)))+300;

                int x1 = k * i + j + 400;
                int y1 = (-20 * (a * sin(k * (b * (i + j / ((double)k)) + c) / (double)k) + d)) + 300;
                SDL_RenderDrawPoint(renderer, x1, y1); //SDL_RenderDrawPoint(renderer,x1,y1);
            }
        }

        SDL_RenderPresent(renderer); // обновляем экран

    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    printf("start\n");

    return 0;

}



int SDL_cosine(void) {
    section();
    //общая часть
    double a = 0, b = 0, c = 0, d = 0;
    if (prg != 2) {//переменные
        a = char_double("Введите a: ");
        b = char_double("Введите b: ");
        c = char_double("Введите c: ");
        d = char_double("Введите d: ");
    }
    else {
        double parameters[100];
        int k1;
        k1 = char_int("Введите количество слагаемых: ");
        for (int j = 0; j < k1; j++) {
            printf("Введите %d параметр: ", j + 1); scanf("%lf", &parameters[j]);//не работает ввод с буквами
        }
    }

    ///////////////////////////////
    int k;

    if (fabs(A) > fabs(B)) k = 200 / fabs(A);
    else k = 200 / fabs(B);

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        printf("Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("Charting", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
    if (!window) {
        printf("Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        printf("Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Event event;

    bool quit = false;

    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
        }

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // устанавливаем цвет на белый
        SDL_RenderClear(renderer); // очищаем экран

        SDL_SetRenderDrawColor(renderer, 190, 210, 247, 255); // устанавливаем цвет на #bed2f7

        //клетка
        for (int i = 400; i < 800; i += k) {
            SDL_RenderDrawLine(renderer, i, 0, i, 600);
        }//ось oy
        for (int i = 400; i > 0; i -= k) {
            SDL_RenderDrawLine(renderer, i, 0, i, 600);
        }//ось oy

        for (int i = 300; i < 600; i += 20) {
            SDL_RenderDrawLine(renderer, 0, i, 800, i);
        }//ось ox
        for (int i = 300; i > 0; i -= 20) {
            SDL_RenderDrawLine(renderer, 0, i, 800, i);
        }//ось ox

//        for (int i=0; i<800; i+=k){
//            SDL_RenderDrawLine(renderer, i, 0, i, 600);}//ось oy
//        for (int i=0; i<600; i+=20){
//            SDL_RenderDrawLine(renderer, 0, i, 800, i);}//ось ox

        SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255); // устанавливаем цвет на серый

        SDL_RenderDrawLine(renderer, 200, 300, 600, 300);//ось ох
        SDL_RenderDrawLine(renderer, 400, 100, 400, 500);//ось оy

        //cтрелка на ось ох
        SDL_RenderDrawLine(renderer, 590, 295, 600, 300);//ось ох
        SDL_RenderDrawLine(renderer, 590, 305, 600, 300);//ось ох

        //стрелка на ось оу
        SDL_RenderDrawLine(renderer, 395, 110, 400, 100);//ось оу
        SDL_RenderDrawLine(renderer, 405, 110, 400, 100);//ось оу


        //косинусоида
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // устанавливаем цвет чёрный
        for (double i = A; i < B; i++) {
            //добавить возможность менять в зависимости от выбора пользователем диапазона. k=20 при диап от -10 до +10
            for (int j = 0; j < k; j++) {

                //                    int x1=k*i+j+400;
                //                    int y1=(-20*(a*sin((k*(b*i)+j)/(double)k)))+300;

                int x1 = k * i + j + 400;
                int y1 = (-20 * (a * cos(k * (b * (i + j / ((double)k)) + c) / (double)k) + d)) + 300;
                SDL_RenderDrawPoint(renderer, x1, y1); //SDL_RenderDrawPoint(renderer,x1,y1);
            }
        }

        SDL_RenderPresent(renderer); // обновляем экран

    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    printf("start\n");

    return 0;

    return 0;
}

void extreme(int prg) {//экстремумы
    section();//отрезок выбран
    int count = 0;
    double a = 0, b = 0, c = 0, d = 0;
    if (prg != 2) {
        a = char_double("Введите а: ");
        b = char_double("Введите b: ");
        c = char_double("Введите c: ");
        if (prg == 3 || prg == 5 || prg == 6) {
            d = char_double("Введите d: ");
        }
        printf("Экстремумы: ");
        for (double i = A + 0.01; i <= B; i += 0.01) {
            if ((f_choose(i - 0.01, a, b, c, d, prg) > f_choose(i, a, b, c, d, prg) && f_choose(i + 0.01, a, b, c, d, prg) > f_choose(i, a, b, c, d, prg)) || (f_choose(i - 0.01, a, b, c, d, prg) < f_choose(i, a, b, c, d, prg) && f_choose(i + 0.01, a, b, c, d, prg) < f_choose(i, a, b, c, d, prg))) { printf("%lf ", f_choose(i, a, b, c, d, prg)); count++; }
        }printf("\n");
        if (count == 0) {
            printf("Эксремумов нет\n");
        }
    }
    else {
        double parameters[100];
        int k;
        k = char_int("Введите количество слагаемых: ");
        for (int j = 0; j < k; j++) {
            printf("Введите %d параметр: ", j + 1); scanf("%lf", &parameters[j]);//j+1=char_double("Введите следующий параметр: ");
        }
        printf("Экстремумы: ");
        for (double i = A + 0.01; i <= B; i += 0.01) {
            if ((polynomial(i - 0.01, parameters, k) > polynomial(i, parameters, k) && polynomial(i + 0.01, parameters, k) > polynomial(i, parameters, k)) || ((polynomial(i - 0.01, parameters, k)) < polynomial(i, parameters, k) && polynomial(i + 0.01, parameters, k) < polynomial(i, parameters, k))) { printf("%lf ", polynomial(i, parameters, k)); count++; }
        }printf("\n");
        if (count == 0) {
            printf("Эксремумов нет\n");
        }

    }
}



void root(int prg) {//корни
    section();//отрезок выбран
    int count = 0;
    double a = 0, b = 0, c = 0, d = 0;
    if (prg != 2) {//переменные
        a = char_double("Введите a: ");
        b = char_double("Введите b: ");
        c = char_double("Введите c: ");
        if (prg == 3 || prg == 5 || prg == 6) {
            d = char_double("Введите d: ");
        }
        printf("Корни: ");
        for (double i = A + 0.01; i <= B; i += 0.01) {
            if (fabs(f_choose(i, a, b, c, d, prg)) <= 0.001) { printf("%lf ", i); count++; }
        }printf("\n");
        if (count == 0) {
            printf("Корней нет\n");
        }
    }
    else {
        double parameters[100];
        int k;
        k = char_int("Введите количество слагаемых: ");
        for (int j = 0; j < k; j++) {
            printf("Введите %d параметр: ", j + 1); scanf("%lf", &parameters[j]);
        }
        printf("Корни: ");
        for (double i = A + 0.01; i <= B; i += 0.01) {
            if (fabs(polynomial(i, parameters, k)) <= 0.0001) { printf("%lf ", polynomial(i, parameters, k)); count++; }
        }printf("\n");
        if (count == 0) {
            printf("Корней нет\n");
        }

    }
}
int integral(int prg) {//интегралы
    section();//отрезок выбран
    int count = 0;
    double s = 0;//gлощадь фигуры
    double a = 0, b = 0, c = 0, d = 0;
    if (prg != 2) {//переменные
        if (prg == 3) {
            do {
                a = char_double("Введите a: ");
            } while (a < 0 || a == 1);
        }
        else {
            a = char_double("Введите a: ");
        }

        b = char_double("Введите b: ");
        c = char_double("Введите c: ");
        if (prg == 3 || prg == 5 || prg == 6) {
            d = char_double("Введите d: ");
        }
        printf("Интеграл: ");
        //проверка логарифма
        if (prg == 4) {
            if (b < 0 && A>0) { printf("Ошибка. Невозможно вычислить интеграл\n"); return 0; }
            if (b < 0 && A < 0 && B>0) { B = 0; }
            if (b > 0 && B < 0) { printf("Ошибка. Невозможно вычислить интеграл\n"); return 0; }
            if (b > 0 && A < 0 && B>0) { A = 0; }

        }
        //проверка степенной
        if (prg == 1) {
            if (b < 0 && A <= 0 && B >= 0) { printf("Ошибка. Невозможно вычислить интеграл\n"); return 0; }
            if ((int)b != b) {
                if (A <= 0 && B >= 0) A = 0;
                if (B <= 0) { printf("Ошибка. Невозможно вычислить интеграл\n"); return 0; }
            }
        }
        //проверка показательной
        if (prg == 3) {

        }
        for (double i = A; i <= B; i += 0.001) {
            //         if (f_choose(i,a,b,c,d, prg)!=0)
            {s += (0.001 * 0.5 * (f_choose(i, a, b, c, d, prg) + f_choose(i + 0.001, a, b, c, d, prg))); count++; }
        }printf("%f\n", s);
    }
    else {
        double parameters[100];
        int k;
        k = char_int("Введите количество слагаемых: ");
        for (int j = 0; j < k; j++) {
            printf("Введите %d параметр: ", j + 1); scanf("%lf", &parameters[j]);//не работает ввод с буквами
        }
        printf("Интергал: ");
        for (double i = A; i <= B; i += 0.001) {
            if (polynomial(i, parameters, k) == 0) { printf("%lf ", polynomial(i, parameters, k)); count++; }
        }printf("\n");
        for (double i = A; i <= B; i += 0.001) {
            //         if (f_choose(i,a,b,c,d, prg)!=0)
            {s += (0.001 * 0.5 * (polynomial(i, parameters, k) + polynomial(i + 0.001, parameters, k))); count++; }
        }printf("%f\n", s);


    }
    return 1;
}



void calc6() {
    //int main(void){
    int circle = 0;
    do {
        int prg = 0;
        do {
            prg = char_int("Выберите вариант функции: \n 1 - Cтепенная вида: a*x^b+c \n 2 - Полином степени вида: a0+a1*x+a2*x^2+...+aN*x^N\n 3 - Показательная вида: a*b^(c*x)+b\n 4 - Логарифмическая вида: a*ln(b*x)+c\n 5 - Cинусоида вида: a*sin(b*x+c)+d\n 6 - Косинусоида вида: a*cos(b*x+c)+d \n");
            switch (prg) {
            case 1: flag = 1; break;
            case 2: flag = 2; break;
            case 3: flag = 3; break;
            case 4: flag = 4; break;
            case 5: flag = 5; break;
            case 6: flag = 6; break;
            default: printf("Неверно введено значение\n"); break;
            }
        } while (prg != 1 && prg != 2 && prg != 3 && prg != 4 && prg != 5 && prg != 6);

        int prg1 = 0;
        do {
            prg1 = char_int("Выберите тип калькулятора: \n 1 - поиск экстремумов на отрезке \n 2 - поиск корня \n 3 - вычисление интеграла 4 - построение графиков\n");
            switch (prg1) {
            case 1: extreme(prg); break;
            case 2: root(prg); break;
            case 3: integral(prg); break;
            case 4:
            {switch (prg) {
            case 1: SDL_powF(); break;
            case 2: SDL_pol(); break;
            case 3: SDL_ind(); break;
            case 4: SDL_ln(); break;
            case 5: SDL_sine(); break;
            case 6: SDL_cosine(); break;
            }
            break;
            }
            default: printf("Неверно введено значение\n"); break;
            }
        } while (prg1 != 1 && prg1 != 2 && prg1 != 3);
        circle = char_int("0 - вернуться в меню;\nлюбое другое целое число - продолжить\n");
    } while (circle != 0);
    //return 0;
}
