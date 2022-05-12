#ifndef SRC_S21_STRING_H__
#define SRC_S21_STRING_H__
#include "s21_errno.h"

typedef unsigned int s21_size_t;
#define s21_NULL ((void *) 0)

void* s21_memset(void* str, int c, s21_size_t n);
char* s21_strerror(int errnum);
char* s21_strpbrk(const char* str1, const char* str2);
char* s21_strtok(char* str, const char* delim);
s21_size_t s21_strlen(const char *str);
char *s21_strcat(char *dest, const char *src);
char *s21_strcpy(char *dest, const char *src);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);

int s21_sprintf(char* str, const char* format, ...);

void* s21_to_upper(const char* str);

#endif  //  SRC_S21_STRING_H__
