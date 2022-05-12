#include "s21_sprintf.h"

static void s21_n_process(int* n, t_info* info) {
  *n = info->iterator;
}

void s21_write_process(char* str, t_info* info, va_list* args) {
	switch (info->symbol) {
		case 's':
			s21_str_process(str, va_arg(*args,char*), info);
			break;
		case 'c':
			s21_char_process(str, (s21_wchar_t)va_arg(*args, int), info);
			break;
		case 'i':
		case 'd':
		case 'u':
			s21_number_process(str, s21_parse_num_arg(info, args), info);
			break;
		case 'f':
			s21_float_main(str, s21_parse_double_arg(info, args), info);
			break;
		case '%':
			str[(info->iterator)++] = '%';
			break;
		case 'g':
		case 'G':
			s21_g_process(str, s21_parse_double_arg(info, args), info);
			break;
		case 'e':
		case 'E':
			s21_ex_main(str, s21_parse_double_arg(info, args), info);
			break;
		case 'n':
			s21_n_process(va_arg(*args, int*), info);
			break;
		case 'p':
		case 'x':
		case 'X':
			s21_hex_process(str, va_arg(*args, unsigned long), info);
			break;
		case 'o':
			s21_dec_to_oct_process(str, va_arg(*args, unsigned int), info);
			break;
	}
}

void s21_str_process(char* str, char* arg, t_info* info) {
  s21_size_t str_size = s21_strlen(arg);
  if (!info->minus) {
    s21_width_pad(str, str_size, info);
  }
  if (info->dot == 0) {
    while (*arg) {
      str[(info->iterator)++] = *(arg++);
    }
  } else {
    while (*arg && info->prec)  {
      str[(info->iterator)++] = *(arg++);
      info->prec--;
    }
  }
  if (info->minus) {
    s21_width_pad(str, str_size, info);
  }
}

short s21_number_flag(char** str, t_info* info) {
	int str_size = info->number.num_size + info->number.dif_width + 2;
	char *str_with_sign = (char *) malloc(sizeof(char) * str_size);
	short pos = 0;
  if (info->sign) {
    str_with_sign[pos++] = '-';
  } else if (info->plus) {
		str_with_sign[pos++] = '+';
  } else if (info->space) {
		str_with_sign[pos++] = ' ';
  }
	str_with_sign[pos] = '\0';
	s21_strcat(str_with_sign, *str);
	free(*str);
	*str = str_with_sign;
	return pos;
}

void s21_char_process(char* str, s21_wchar_t arg, t_info* info) {
  if (!info->minus) {
    s21_width_pad(str, 1, info);
  }
  str[(info->iterator)++] = arg;

  if (info->minus) {
    s21_width_pad(str, 1, info);
  }
}
