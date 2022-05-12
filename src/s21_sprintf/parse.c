#include "s21_sprintf.h"

char* s21_write_to_buff(char* str, char* format, t_info* info) {
  while (*format != '%' && *format != '\0') {
    str[(info->iterator)++] = *(format++);
  }
  return format;
}

long long s21_parse_num_arg(t_info* info, va_list* arg) {
	long long result = 0;
	if (info->symbol == 'd' || info->symbol == 'i') {
		if (info->length_h) {
			result = (short) va_arg(*arg, int);
		} else if (info->length_l) {
			result = va_arg(*arg, long);
		} else {
			result = va_arg(*arg, int);
		}
	} else if (info->symbol == 'u' || info->symbol == 'o'
						|| info->symbol == 'x' || info->symbol == 'X') {
		if(info->length_h) {
			result = (unsigned short) va_arg(*arg, unsigned int);
		}
		else if (info->length_l) {
			result = (unsigned long) va_arg(*arg, unsigned long);
	} else {
			result = va_arg(*arg, unsigned int);
	}
	}
  return result;
}

long double s21_parse_double_arg(t_info *info, va_list* arg) {
	long double result;
	if (info->length_L) {
		result = va_arg(*arg, long double);
	} else {
		result = va_arg(*arg, double);
	}
	return result;
}

static char* s21_check_flags(char* format, t_info* info) {
  s21_init_struct(info);
  while (*format == '+' || *format == '-' || *format == ' '
				|| *format == '0' || *format == '#') {
    switch (*format) {
    case '+':
      info->plus = 1;
      break;
    case '-':
      info->minus = 1;
      break;
    case ' ':
      info->space = 1;
      break;
    case '0':
      info->zero = 1;
      break;
		case '#':
			info->sharp = 1;
			break;
    }
    format++;
  }
  return format;
}

char* s21_check_length(char* format, t_info* info) {
  switch (*format) {
  case 'h':
    info->length_h = 1;
    format++;
    break;
  case 'l':
    info->length_l = 1;
    format++;
    break;
	case 'L':
		info->length_L = 1;
		format++;
		break;
  }
  return format;
}

char* s21_parse_spf(char* format, t_info* info, va_list *args) {
  format++;
  format = s21_check_flags(format, info);
  int number = 0;

  while (s21_is_number(*format)) {
    number = number * 10 + (*format - '0');
    format++;
  }
	if (*format == '*') {
		number = va_arg(*args, int );
		format++;
	}
  info->width = number;

  format = s21_parse_accuracy(format, info, args);
  format = s21_check_length(format, info);

  while (!s21_is_letter(*format)) {
    format++;
  }

  info->symbol = *format;
  return format;
}

char* s21_parse_accuracy(char* format, t_info* info, va_list *args) {
  if (*format == '.') {
    info->dot = 1;
    int number = 0;
    format++;
    while (s21_is_number(*format)) {
      number = number * 10 + (*format - '0');
      format++;
    }
		if (*format == '*') {
			number = va_arg(*args, int );
			format++;
		}
    info->prec = number;
  }
  return format;
}
