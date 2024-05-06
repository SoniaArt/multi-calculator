#pragma once
void calc6();
double power_function(double x, double a, double b, double c, double d);
double polynomial(double x, double* parameters, double k);
double indicative(double x, double a, double b, double c, double d);
double logarithmic(double x, double a, double b, double c, double d);
double sine(double x, double a, double b, double c, double d);
double cosine(double x, double a, double b, double c, double d);
double f_choose(double x, double a, double b, double c, double d, int prg);
void section(void);
void extreme(int prg);
void root(int prg);
int integral(int prg);
//double char_double (char *input_str);
//int char_int(char *input_str);
int char_int(const char* input_str);
double char_double(const char* input_str);
int SDL_powF(void);
int SDL_pol(void);
int SDL_ind(void);
int SDL_ln(void);
int SDL_sine(void);
int SDL_cosine(void);
