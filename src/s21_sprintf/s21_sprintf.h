#ifndef SRC_S21_SPRINTF_S21_SPRINTF_H_
#define SRC_S21_SPRINTF_S21_SPRINTF_H_
#include <stdarg.h>
#include <stdlib.h>
#include "../s21_string.h"

typedef unsigned short s21_wchar_t;

typedef struct s_number {
	int need_sign;
  int num_size;
  int res_size_num;
  int dif_width;
	int dif_prec;
	int size_double_num;
  int size_exp;
  int size_man;
	int is_g;
} t_number;

typedef struct s_info {
  short zero;
  int width;
  short length_l;
  short length_h;
	short length_L;
  char symbol;
  int iterator;
	int e_size;
  short sign;
  short minus;
  short plus;
  short space;
  int prec;
  int dot;
	int sharp;
  t_number number;
} t_info;

#define SPECIF "cdifsueEnoxXpgG%"
#define ZERO_MEM(x, y) s21_memset(x, 0, y);

//  util.c
void s21_width_pad(char* str, s21_size_t size, t_info* info);
short s21_is_letter(char letter);
short s21_is_number(char symbol);
unsigned long long s21_power_ten(int pow);
short s21_number_flag(char** str, t_info* info);
short s21_numlen(unsigned long long number, short notation);
void s21_init_struct(t_info* info);
int s21_number_count(char* str);
int s21_g_cat_zero(unsigned long long *exponent);
void s21_left_pad(char* from, char* to, char symb, short size);
void s21_right_pad(char* from, char* to, char symb, short size);
void s21_num_to_string(unsigned long long number, char* result);

//  parse.c
char* s21_write_to_buff(char* str, char* format, t_info* info);
char* s21_parse_spf(char* format, t_info* info, va_list *args);
char* s21_parse_accuracy(char* format, t_info* info, va_list *args);
char* s21_check_length(char* format, t_info* info);
long long s21_parse_num_arg(t_info* info, va_list* arg);
long double s21_parse_double_arg(t_info *info, va_list* arg);


//  s21_process.c
void s21_write_process(char* str, t_info* info, va_list* args);
void s21_number_process(char* str, long long number, t_info* info);
void s21_str_process(char* str, char* arg, t_info* info);
void s21_char_process(char* str, s21_wchar_t arg, t_info* info);
void s21_float_main(char* str, long double arg, t_info* info);
void s21_ex_main(char* str, long double arg, t_info* info);
char *s21_float_process(long double arg, t_info* info);
char *s21_ex_process(long double arg, t_info* info);
void s21_dec_to_oct_process(char* str, unsigned long long number, t_info* info);
void s21_hex_process(char* str, unsigned long long number, t_info* info);
void s21_g_process(char* str, long double number, t_info* info);
void s21_float_to_result(char *str, char* result_with_pad, t_info *info);
short s21_need_sign(long long number, t_info *info);

#endif  //  SRC_S21_SPRINTF_S21_SPRINTF_H_
