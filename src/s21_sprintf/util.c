#include "s21_sprintf.h"
#include <stdio.h>
#include <string.h>

void s21_init_struct(t_info* info) {
  info->zero = 0;
  info->width = 0;
  info->minus = 0;
  info->plus = 0;
  info->space = 0;
	info->prec = 6;
  info->sign = 0;
  info->length_h = 0;
  info->length_l = 0;
	info->length_L = 0;
  info->e_size = 0;
  info->dot = 0;
	info->sharp = 0;
	info->number.num_size = 0;
	info->number.dif_prec = 0;
	info->number.dif_width = 0;
	info->number.res_size_num = 0;
	info->number.size_exp = 0;
	info->number.size_man = 0;
	info->number.is_g = 0;
	info->number.need_sign = 0;
}

unsigned long long s21_power_ten(int pow) {
  unsigned long long result = 1;
  while (pow) {
    result *= 10;
    pow--;
  }
  return result;
}

void s21_width_pad(char* str, s21_size_t size, t_info* info) {
	int difference = 0;
	if (info->width && ((s21_size_t) info->prec < size)) {
		difference = info->width - info->prec;
	} else {
		difference = info->width == 0 ? 0 : (int) (info->width - size);
	}

  char symbol = ' ';
  while (difference > 0) {
    str[(info->iterator)++] = symbol;
    difference--;
  }
}

short s21_is_letter(char letter) {
  char* letters = SPECIF;
  short result = 0;
  while (*letters) {
    if (letter == *letters) {
      result = 1;
      break;
    }
    letters++;
  }
  return result;
}

short s21_is_number(char symbol) {
  short result = 0;
  if (symbol >= '0' && symbol <= '9') {
    result = 1;
  }
  return result;
}

short s21_numlen(unsigned long long number, short notation) {
  short size = 0;
	while (number) {
    number /= notation;
    size++;
  }
  return size == 0 ? 1 : size;
}

void s21_left_pad(char* from, char* to, char symb, short size) {
  while (size > 0) {
    *(to++) = symb;
    size--;
  }
  while (*from) {
    *(to++) = *(from++);
  }
  *to = '\0';
}

void s21_right_pad(char* from, char* to, char symb, short size) {
  while (*from) {
    *(to++) = *(from++);
  }
  while (size > 0) {
    *(to++) = symb;
    size--;
  }
  *to = '\0';
}

void s21_num_to_string(unsigned long long number, char* result) {
  short size = s21_numlen(number, 10);

  if (number == 0) {
    result[0] = '0';
  }
	result[size] = '\0';
  while (size) {
    result[--size] = (number % 10) + '0';
    number /= 10;
  }
}
int s21_number_count(char* str) {
	s21_size_t size = strlen(str); //  FIXME заменить на нашу;
	int count = 0;
	for(s21_size_t i = 0; i < size; i++) {
		if (s21_is_number(str[i])) {
			count++;
		}
		if (str[i] == 'e' || str[i] == 'E') {
			break;
		}
	}
	return count;
}

int s21_g_cat_zero(unsigned long long *exponent) {
	int temp = 0;
	int count = 0;
	while (*exponent) {
		temp = *exponent % 10;
		if (temp != 0) {
			break;
		} else {
			*exponent /= 10;
			count++;
		}
	}
	return count;
}
