//#include <\\wsl$\Ubuntu-20.04\usr\include\check.h>
#include <check.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "s21_string.h"

START_TEST(s21_to_upper_normal) {
  char* test_str0 = "hello world";
  char* test_str1 = "h1e2l3l4o5";

  char* func_result0 = s21_to_upper(test_str0);
  char* func_result1 = s21_to_upper(test_str1);

  ck_assert_str_eq(func_result0, "HELLO WORLD");
  ck_assert_str_eq(func_result1, "H1E2L3L4O5");
  free(func_result0);
  free(func_result1);
} END_TEST

//  s21_to_upper
START_TEST(s21_to_upper_whith_sign) {
  char* test_str = "h!e1l/l&o.";

  char* func_result = s21_to_upper(test_str);
  ck_assert_str_eq(func_result, "H!E1L/L&O.");
  free(func_result);
} END_TEST

START_TEST(s21_to_upper_whith_upper) {
  char* test_str = "HELLO";

  char* func_result = s21_to_upper(test_str);
  ck_assert_str_eq(func_result, test_str);
  free(func_result);
} END_TEST

START_TEST(s21_to_upper_empty_string) {
  char* test_str0 = "";

  char* func_result = s21_to_upper(test_str0);
  ck_assert_ptr_eq(func_result, s21_NULL);
  free(func_result);
} END_TEST

//  s21_strtok
START_TEST(s21_strtok_normal) {
  char s21_test_str[30] = "one/two.three?four";
  char lib_test_str[30] = "one/two.three?four";
  char* step = "./?";
  char* s21_result = s21_strtok(s21_test_str, step);
  char* lib_result = strtok(lib_test_str, step);

  while (s21_result != s21_NULL && lib_result != s21_NULL) {
    ck_assert_str_eq(s21_result, lib_result);
    s21_result = s21_strtok(s21_NULL, step);
    lib_result = strtok(s21_NULL, step);
  }
  ck_assert_ptr_eq(s21_result, lib_result);
} END_TEST

START_TEST(s21_strtok_no_delimetr) {
  char s21_test_str[30] = "one/two.three?four";
  char lib_test_str[30] = "one/two.three?four";
  char* step = "$()-";
  char* s21_result = s21_strtok(s21_test_str, step);
  char* lib_result = strtok(lib_test_str, step);

  while (s21_result != s21_NULL && lib_result != s21_NULL) {
    ck_assert_str_eq(s21_result, lib_result);
    s21_result = s21_strtok(s21_NULL, step);
    lib_result = strtok(s21_NULL, step);
  }
  ck_assert_ptr_eq(s21_result, lib_result);
} END_TEST

START_TEST(s21_strtok_empty) {
  char s21_test_str[30] = "";
  char lib_test_str[30] = "";
  char* step = "$()-";
  char* s21_result = s21_strtok(s21_test_str, step);
  char* lib_result = strtok(lib_test_str, step);

  ck_assert_ptr_eq(s21_result, lib_result);
} END_TEST

//  s21_strpbrk
START_TEST(s21_strpbrk_normal) {
  char test_str[11] = "0123456789";
  char symb[3] = "345";

  char* s21_result = s21_strpbrk(test_str, symb);
  char* lib_result = strpbrk(test_str, symb);

  ck_assert_str_eq(s21_result, lib_result);
} END_TEST

START_TEST(s21_strpbrk_no_symb) {
  char test_str[11] = "0123456789";
  char symb[1] = "a";

  char* s21_result = s21_strpbrk(test_str, symb);
  char* lib_result = strpbrk(test_str, symb);

  ck_assert_ptr_eq(s21_result, lib_result);
} END_TEST

START_TEST(s21_strpbrk_empty_symb) {
  char test_str[11] = "0123456789";
  char* symb = "";

  char* s21_result = s21_strpbrk(test_str, symb);
  char* lib_result = strpbrk(test_str, symb);

  ck_assert_ptr_eq(s21_result, lib_result);
} END_TEST

START_TEST(s21_strpbrk_empty_str) {
  char* test_str = "";
  char symb[3] = "123";

  char* s21_result = s21_strpbrk(test_str, symb);
  char* lib_result = strpbrk(test_str, symb);

  ck_assert_ptr_eq(s21_result, lib_result);
} END_TEST

//  memset
START_TEST(s21_memset_normal) {
  char s21_test_str[] = "Hello";
	s21_memset(s21_test_str, 'c', 3);
	char lib_test_str[] = "Hello";
  memset(lib_test_str, 'c', 3);

  ck_assert_str_eq(s21_test_str, lib_test_str);
} END_TEST

START_TEST(s21_memset_null) {
	char s21_test_str[] = "Hello";
	char lib_test_str[] = "Hello";

	s21_memset(s21_test_str, '\0', 3);
	memset(lib_test_str, '\0', 3);

	ck_assert_str_eq(s21_test_str, lib_test_str);
} END_TEST

START_TEST(s21_memset_sign) {
	char s21_test_str[] = "Hello";
	char lib_test_str[] = "Hello";

	s21_memset(s21_test_str, '-', 3);
	memset(lib_test_str, '-', 3);

	ck_assert_str_eq(s21_test_str, lib_test_str);

} END_TEST

//  strerror
START_TEST(s21_strerror_normal) {
  char* s21_test_str = s21_strerror(S21_E2BIG);
  char* lib_test_str = strerror(E2BIG);

  ck_assert_str_eq(s21_test_str, lib_test_str);
} END_TEST

//  sprintf
START_TEST(s21_sprintf_d) {
  char* s21_test_str = (char*)malloc(sizeof(char) * 256);
  char* lib_test_str = (char*)malloc(sizeof(char) * 256);
  int min = -2147483648;
  int max = 2147483647;

  int lib_res = sprintf(lib_test_str, "|%d| |%d| |% d| |%+d| |%d| |%-5d| |%05d| |%+05d| |%05d| |%20.15d| |%+.0d| |%5.15d|\n", 12, 0, 12, max, min, 12, 12, 12, -12, 12, 12, -12);
  int s21_res = s21_sprintf(s21_test_str, "|%d| |%d| |% d| |%+d| |%d| |%-5d| |%05d| |%+05d| |%05d| |%20.15d| |%+.0d| |%5.15d|\n", 12, 0, 12, max, min, 12, 12, 12, -12, 12, 12, -12);

  ck_assert_str_eq(s21_test_str, lib_test_str);
  ck_assert_int_eq(s21_res, lib_res);

  free(s21_test_str);
  free(lib_test_str);
} END_TEST

START_TEST(s21_sprintf_i) {
  char* s21_test_str = (char*)malloc(sizeof(char) * 256);
  char* lib_test_str = (char*)malloc(sizeof(char) * 256);

  int lib_res = sprintf(lib_test_str, "|%i| |% i| |%+i| |%i| |%-5i| |%05i| |%+05i| |%05i|\n", 12, 12, 12, -12, 12, 12, 12, -12);
  int s21_res = s21_sprintf(s21_test_str, "|%i| |% i| |%+i| |%i| |%-5i| |%05i| |%+05i| |%05i|\n", 12, 12, 12, -12, 12, 12, 12, -12);

  ck_assert_str_eq(s21_test_str, lib_test_str);
  ck_assert_int_eq(s21_res, lib_res);

  free(s21_test_str);
  free(lib_test_str);
} END_TEST

START_TEST(s21_sprintf_star) {
	char* s21_test_str = (char*)malloc(sizeof(char) * 256);
	char* lib_test_str = (char*)malloc(sizeof(char) * 256);

	int lib_res = sprintf(lib_test_str, "%*.*d\n", 5, 3, 5);
	int s21_res = s21_sprintf(s21_test_str, "%*.*d\n", 5, 3, 5);

	ck_assert_str_eq(s21_test_str, lib_test_str);
	ck_assert_int_eq(s21_res, lib_res);

	free(s21_test_str);
	free(lib_test_str);
} END_TEST

START_TEST(s21_sprintf_u) {
  char* s21_test_str = (char*)malloc(sizeof(char) * 256);
  char* lib_test_str = (char*)malloc(sizeof(char) * 256);
	unsigned int u = 2147483647;
	unsigned int a = 0;
	unsigned int b = 102;
	unsigned int c = 12;
	unsigned int d = 120;
	unsigned int e = 1200;
	unsigned int f = 14895085;

	int lib_res = sprintf(lib_test_str, "|%u| |%u| |%u| |%-20u| |%u| |%07u| |%05u| |%.20u| |%-20.15u| |%u|\n",
												u, a, b, c, f, c, c, c, d, e);
  int s21_res = s21_sprintf(s21_test_str, "|%u| |%u| |%u| |%-20u| |%u| |%07u| |%05u| |%.20u| |%-20.15u| |%u|\n",
														u, a, b, c, f, c, c, c, d, e);

  ck_assert_str_eq(s21_test_str, lib_test_str);
  ck_assert_int_eq(s21_res, lib_res);

  free(s21_test_str);
  free(lib_test_str);
} END_TEST

START_TEST(s21_sprintf_f) {
  char* s21_test_str = (char*)malloc(sizeof(char) * 256);
  char* lib_test_str = (char*)malloc(sizeof(char) * 256);

  int lib_res = sprintf(lib_test_str, "|%f| |% f| |%+f| |%f| |%-8f| |%08f| |%+08f| |%08f|\n", 0.020, 0.020, 0.020, -0.020, 0.020, 0.020, 0.020, -0.020);
  int s21_res = s21_sprintf(s21_test_str, "|%f| |% f| |%+f| |%f| |%-8f| |%08f| |%+08f| |%08f|\n", 0.020, 0.020, 0.020, -0.020, 0.020, 0.020, 0.020, -0.020);

  ck_assert_str_eq(s21_test_str, lib_test_str);
  ck_assert_int_eq(s21_res, lib_res);

  free(s21_test_str);
  free(lib_test_str);
} END_TEST

START_TEST(s21_sprintf_eE) {
  char* s21_test_str = (char*)malloc(sizeof(char) * 256);
  char* lib_test_str = (char*)malloc(sizeof(char) * 256);

  int lib_res = sprintf(lib_test_str, "|%e| |% E| |%+e| |%E| |%-8e| |%08E| |%+08E| |%08e|\n", 0.020, 0.020, 0.020, -344.020, 344.020, 344.020, 344.020, -344.020);
  int s21_res = s21_sprintf(s21_test_str, "|%e| |% E| |%+e| |%E| |%-8e| |%08E| |%+08E| |%08e|\n", 0.020, 0.020, 0.020, -344.020, 344.020, 344.020, 344.020, -344.020);

  ck_assert_str_eq(s21_test_str, lib_test_str);
  ck_assert_int_eq(s21_res, lib_res);

  free(s21_test_str);
  free(lib_test_str);
} END_TEST

START_TEST(s21_sprintf_o) {
  char* s21_test_str = (char*)malloc(sizeof(char) * 256);
  char* lib_test_str = (char*)malloc(sizeof(char) * 256);
  int i = 2147483647;

  int lib_res = sprintf(lib_test_str, "|%o| |%#o| |%#o| |%o| |%8o| |%#015o| |%-15o| |%#-15o|\n", 286546, 0, i, 286546, 286546, 286546, 286546, 286546);
  int s21_res = s21_sprintf(s21_test_str, "|%o| |%#o| |%#o| |%o| |%8o| |%#015o| |%-15o| |%#-15o|\n", 286546, 0, i, 286546, 286546, 286546, 286546, 286546);

  ck_assert_str_eq(s21_test_str, lib_test_str);
  ck_assert_int_eq(s21_res, lib_res);

  free(s21_test_str);
  free(lib_test_str);
} END_TEST


START_TEST(s21_sprintf_xX) {
  char* s21_test_str = (char*)malloc(sizeof(char) * 256);
  char* lib_test_str = (char*)malloc(sizeof(char) * 256);
  int i = 2147483647;

  int lib_res = sprintf(lib_test_str, "|%x| |%#x| |%012x| |%x| |%-8X| |%08X| |%#08X| |%#20X|\n", 286546, 0, i, 286546, 286546, 286546, 286546, 286546);
  int s21_res = s21_sprintf(s21_test_str, "|%x| |%#x| |%012x| |%x| |%-8X| |%08X| |%#08X| |%#20X|\n", 286546, 0, i, 286546, 286546, 286546, 286546, 286546);

  ck_assert_str_eq(s21_test_str, lib_test_str);
  ck_assert_int_eq(s21_res, lib_res);

  free(s21_test_str);
  free(lib_test_str);
} END_TEST

START_TEST(s21_sprintf_gG) {
	char* s21_test_str = (char*)malloc(sizeof(char) * 256);
	char* lib_test_str = (char*)malloc(sizeof(char) * 256);
	int lib_res = sprintf(lib_test_str, "|%.2g| |%12.4G| |%-15.5g| |%+5.15g| |%015.13g| |%#15.3g| |%+#10.3G| |%10.0G| |%10.0G|",
					45333.200000, 123245.21324, 1.21324, 0.0, -123245.21324, 453.205, 453.205, 453.205, 453.205);
	int s21_res = s21_sprintf(s21_test_str, "|%.2g| |%12.4G| |%-15.5g| |%+5.15g| |%015.13g| |%#15.3g| |%+#10.3G| |%10.0G| |%10.0G|",
							45333.200000, 123245.21324, 1.21324, 0.0, -123245.21324, 453.205, 453.205, 453.205, 453.205);

	ck_assert_str_eq(s21_test_str, lib_test_str);
	ck_assert_int_eq(s21_res, lib_res);

	free(s21_test_str);
	free(lib_test_str);
} END_TEST

START_TEST(s21_sprintf_p) {
  char* s21_test_str = (char*)malloc(sizeof(char) * 256);
  char* lib_test_str = (char*)malloc(sizeof(char) * 256);
  int i = 2147483647;
  int a;
  int b;
  char c;

  int lib_res = sprintf(lib_test_str, "|%p| |%20p| |%p| |%-15p| |%p|\n", &i, &a, &b, &c, &i);
  int s21_res = s21_sprintf(s21_test_str, "|%p| |%20p| |%p| |%-15p| |%p|\n", &i, &a, &b, &c, &i);

  ck_assert_str_eq(s21_test_str, lib_test_str);
  ck_assert_int_eq(s21_res, lib_res);

  free(s21_test_str);
  free(lib_test_str);
} END_TEST

START_TEST(s21_sprintf_s) {
  char* s21_test_str = (char*)malloc(sizeof(char) * 256);
  char* lib_test_str = (char*)malloc(sizeof(char) * 256);

  int lib_res = sprintf(lib_test_str, "|%20s| |%-20s| |%5.0s| |%.1s|\n", "Hi", "My", "Hi", "My");
  int s21_res = s21_sprintf(s21_test_str, "|%20s| |%-20s| |%5.0s| |%.1s|\n", "Hi", "My", "Hi", "My");

  ck_assert_str_eq(s21_test_str, lib_test_str);
  ck_assert_int_eq(s21_res, lib_res);

  free(s21_test_str);
  free(lib_test_str);
} END_TEST

START_TEST(s21_sprintf_h) {
	char* s21_test_str = (char*)malloc(sizeof(char) * 256);
	char* lib_test_str = (char*)malloc(sizeof(char) * 256);

	short i = 0;
	short a = 32767;
	unsigned short b = 65535;
	unsigned long c = 4294967295;
	int lib_res = sprintf(lib_test_str, "|%hi| |%hd| |%ho| |%hu| |%hx| |%hX| |%lX|",i, a, b, i, a, b, c);
	int s21_res = s21_sprintf(s21_test_str, "|%hi| |%hd| |%ho| |%hu| |%hx| |%hX| |%lX|",i, a, b, i, a, b, c);

	ck_assert_str_eq(s21_test_str, lib_test_str);
	ck_assert_int_eq(s21_res, lib_res);

	free(s21_test_str);
	free(lib_test_str);
} END_TEST

START_TEST(s21_sprintf_l) {
	char* s21_test_str = (char*)malloc(sizeof(char) * 256);
	char* lib_test_str = (char*)malloc(sizeof(char) * 256);
	long i = LONG_MAX;
	long a = LONG_MIN;
	unsigned long b = 4294967295;
	int lib_res = sprintf(lib_test_str, "|%li| |%ld| |%lo| |%lu| |%lx| |%lX|",i, a, b, b, b, b);
	int s21_res = s21_sprintf(s21_test_str, "|%li| |%ld| |%lo| |%lu| |%lx| |%lX|",i, a, b, b, b, b);

	ck_assert_str_eq(s21_test_str, lib_test_str);
	ck_assert_int_eq(s21_res, lib_res);

	free(s21_test_str);
	free(lib_test_str);
} END_TEST

START_TEST(s21_sprintf_L) {
	char* s21_test_str = (char*)malloc(sizeof(char) * 256);
	char* lib_test_str = (char*)malloc(sizeof(char) * 256);

	long double i = 12345675.12345678;

	int lib_res = sprintf(lib_test_str, "|%Le| |%LE| |%Lf| |%Lg| |%LG| ",i, i, i, i, i);
	int s21_res = s21_sprintf(s21_test_str, "|%Le| |%LE| |%Lf| |%Lg| |%LG| ",i, i, i, i, i);

	ck_assert_str_eq(s21_test_str, lib_test_str);
	ck_assert_int_eq(s21_res, lib_res);

	free(s21_test_str);
	free(lib_test_str);
} END_TEST

START_TEST(s21_sprintf_n) {
  char* s21_test_str = (char*)malloc(sizeof(char) * 256);
  char* lib_test_str = (char*)malloc(sizeof(char) * 256);
  int size_s211;
  int size_lib1;
	int size_s212;
	int size_lib2;
	int size_s213;
	int size_lib3;

  int s21_res = s21_sprintf(s21_test_str, "%nHel%%lo%n world%n\n", &size_s211, &size_s212, &size_s213);
	int lib_res = sprintf(lib_test_str, "%nHel%%lo%n world%n\n", &size_lib1, &size_lib2, &size_lib3);

  ck_assert_int_eq(size_s211, size_lib1);
  ck_assert_int_eq(size_s212, size_lib2);
  ck_assert_int_eq(size_s213, size_lib3);
  ck_assert_str_eq(s21_test_str, lib_test_str);
   ck_assert_int_eq(s21_res, lib_res);
  free(s21_test_str);
  free(lib_test_str);
} END_TEST

START_TEST(s21_sprintf_diu_whith_str) {
  char* s21_test_str = (char*)malloc(sizeof(char) * 256);
  char* lib_test_str = (char*)malloc(sizeof(char) * 256);

  long number = 100000000;
	short number1 = 5;
  int lib_res = sprintf(lib_test_str,
    "%d Hello, %010u it's a great % hd, %-10i, %d, %+10d, %ld\n", 0, 1, number1, 3, -4, 5, number);
  int s21_res = s21_sprintf(s21_test_str,
    "%d Hello, %010u it's a great % hd, %-10i, %d, %+10d, %ld\n", 0, 1, number1, 3, -4, 5, number);

  ck_assert_str_eq(s21_test_str, lib_test_str);
  ck_assert_int_eq(s21_res, lib_res);

  free(s21_test_str);
  free(lib_test_str);
} END_TEST

START_TEST(s21_sprintf_cs) {
  char* s21_test_str = (char*)malloc(sizeof(char) * 256);
  char* lib_test_str = (char*)malloc(sizeof(char) * 256);

  char* str0 = "User";
  char* str1 = "";
  int lib_res = sprintf(lib_test_str, "Hello, %-13s, i%c, %s a great day!", str0, 't', str1);
  int s21_res = s21_sprintf(s21_test_str, "Hello, %-13s, i%c, %s a great day!", str0, 't', str1);

  ck_assert_str_eq(s21_test_str, lib_test_str);
  ck_assert_int_eq(s21_res, lib_res);

  free(s21_test_str);
  free(lib_test_str);
} END_TEST

START_TEST(s21_sprintf_f_with_str) {
  char* s21_test_str = (char*)malloc(sizeof(char) * 512);
  char* lib_test_str = (char*)malloc(sizeof(char) * 512);

  int lib_res = sprintf(lib_test_str, "Hello%0.10f, my %0.2f, beautiful %+10.f,world %-5.3f", 0.2, 0.12345, 0.3, -0.23246);
  int s21_res = s21_sprintf(s21_test_str, "Hello%0.10f, my %0.2f, beautiful %+10.f,world %-5.3f", 0.2, 0.12345, 0.3, -0.23246);

  ck_assert_str_eq(s21_test_str, lib_test_str);
  ck_assert_int_eq(s21_res, lib_res);

  free(s21_test_str);
  free(lib_test_str);
} END_TEST

START_TEST(s21_sprintf_empty) {
  char* s21_test_str = (char*)malloc(sizeof(char) * 512);
  char* lib_test_str = (char*)malloc(sizeof(char) * 512);

  int lib_res = sprintf(lib_test_str, "%c", '\0');
  int s21_res = s21_sprintf(s21_test_str, "%c", '\0');

  ck_assert_str_eq(s21_test_str, lib_test_str);
  ck_assert_int_eq(s21_res, lib_res);

  free(s21_test_str);
  free(lib_test_str);
} END_TEST

Suite* s21_string_suite() {
  Suite* s;
  TCase* tc_to_upper, * tc_strtok, * tc_strpbrk, * tc_memset, * tc_strerror, * tc_sprintf;

  s = suite_create("s21_string");
  tc_to_upper = tcase_create("s21_to_upper");
  tcase_add_test(tc_to_upper, s21_to_upper_normal);
  tcase_add_test(tc_to_upper, s21_to_upper_whith_sign);
  tcase_add_test(tc_to_upper, s21_to_upper_whith_upper);
  tcase_add_test(tc_to_upper, s21_to_upper_empty_string);
  suite_add_tcase(s, tc_to_upper);

  tc_strtok = tcase_create("s21_strtok");
  tcase_add_test(tc_strtok, s21_strtok_normal);
  tcase_add_test(tc_strtok, s21_strtok_no_delimetr);
  tcase_add_test(tc_strtok, s21_strtok_empty);
  suite_add_tcase(s, tc_strtok);

  tc_strpbrk = tcase_create("s21_strpbrk");
  tcase_add_test(tc_strpbrk, s21_strpbrk_normal);
  tcase_add_test(tc_strpbrk, s21_strpbrk_no_symb);
  tcase_add_test(tc_strpbrk, s21_strpbrk_empty_symb);
  tcase_add_test(tc_strpbrk, s21_strpbrk_empty_str);
  suite_add_tcase(s, tc_strpbrk);

  tc_memset = tcase_create("s21_memset");
  tcase_add_test(tc_memset, s21_memset_normal);
  tcase_add_test(tc_memset, s21_memset_null);
  tcase_add_test(tc_memset, s21_memset_sign);
  suite_add_tcase(s, tc_memset);

  tc_strerror = tcase_create("s21_strerror");
  tcase_add_test(tc_strerror, s21_strerror_normal);
  suite_add_tcase(s, tc_strerror);

  tc_sprintf = tcase_create("s21_sprintf");
  tcase_add_test(tc_sprintf, s21_sprintf_d);
  tcase_add_test(tc_sprintf, s21_sprintf_u);
  tcase_add_test(tc_sprintf, s21_sprintf_cs);
  tcase_add_test(tc_sprintf, s21_sprintf_f);
  tcase_add_test(tc_sprintf, s21_sprintf_eE);
  tcase_add_test(tc_sprintf, s21_sprintf_xX);
  tcase_add_test(tc_sprintf, s21_sprintf_o);
  tcase_add_test(tc_sprintf, s21_sprintf_i);
  tcase_add_test(tc_sprintf, s21_sprintf_p);
  tcase_add_test(tc_sprintf, s21_sprintf_n);
  tcase_add_test(tc_sprintf, s21_sprintf_s);
	tcase_add_test(tc_sprintf, s21_sprintf_h);
	tcase_add_test(tc_sprintf, s21_sprintf_l);
	tcase_add_test(tc_sprintf, s21_sprintf_L);
	tcase_add_test(tc_sprintf, s21_sprintf_gG);
	tcase_add_test(tc_sprintf, s21_sprintf_star);
  tcase_add_test(tc_sprintf, s21_sprintf_empty);
  tcase_add_test(tc_sprintf, s21_sprintf_diu_whith_str);
  tcase_add_test(tc_sprintf, s21_sprintf_f_with_str);
  suite_add_tcase(s, tc_sprintf);

  return s;
}

int main() {
  int no_failed = 0;
  Suite* s;
  SRunner* runner;

  s = s21_string_suite();
  runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  no_failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
