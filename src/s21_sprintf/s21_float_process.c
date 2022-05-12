#include "s21_sprintf.h"

static void s21_write_e(char* result_f, t_info* info, int last_pos) {
  if (info->symbol == 'e') {
    result_f[last_pos++] = 'e';
  } else if (info->symbol == 'E') {
    result_f[last_pos++] = 'E';
  }
  result_f[last_pos++] = info->e_size > 0 ? '+' : '-';
	if (info->e_size < 0) {
		info->e_size *= -1;
	}
  short size = s21_numlen(info->e_size, 10);
  char e[21];
  s21_num_to_string(info->e_size, e);
  int i = 0;
  if (size == 1) {
    result_f[last_pos++] = '0';
  }
  while (size) {
    result_f[last_pos++] = e[i++];
    size--;
  }
  result_f[last_pos] = '\0';
}

static void s21_write_exponent(unsigned long long exponent, char* result_f,
															 t_info* info, int dot_pos) {
  int index = info->prec + dot_pos;
  int last_pos = index;
  result_f[index + 1] = '\0';
  if (info->prec != 0 || (info->number.is_g && info->sharp)) {
    result_f[dot_pos] = '.';
		last_pos++;
  }

  while (exponent) {
    result_f[index--] = (exponent % 10) + '0';
    exponent /= 10;
  }

  while (index > dot_pos) {
		result_f[index] = '0';
		index--;
  }
  if (info->symbol == 'e' || info->symbol == 'E') {
    s21_write_e(result_f, info, last_pos);
  }
}

static short s21_float_size(short size_mantissa, t_info* info) {
  short float_size = size_mantissa + info->prec + (info->prec ? 1 : 0);
  if (info->symbol == 'e' || info->symbol == 'E') {
    short e = s21_numlen(info->e_size, 10);
    float_size += 2 + (e > 1 ? e : 2);
  }
  return float_size;
}

static int s21_check_extra_zero(unsigned long long *exponent, t_info *info) {
	int extra_zero = info->number.is_g && !info->sharp ? s21_g_cat_zero(exponent) : 0;
	info->prec -= extra_zero;
	return extra_zero;
}

static unsigned long long s21_float_info(double *arg, s21_size_t *mant, t_info* info) {
	unsigned long long exponent = 0;
	long mantis = (long)(*arg);
	info->number.need_sign = s21_need_sign(mantis, info);
	info->sign = *arg < 0 ? 1 : 0;
	if (info->sign) {
		*arg *= -1.0;
		mantis *= -1.0;
	}
	info->number.size_man = s21_numlen(mantis, 10);
	exponent = (*arg - mantis) * s21_power_ten(info->prec + 1);

	if (info->prec == 0) {
		mantis = exponent >= 5 ? mantis + 1 : mantis;
		exponent = 0;
	}
	exponent = (exponent + 5) / 10;
	*mant = mantis;
	return exponent;
}

static char* s21_float_to_string(double arg, t_info* info) {
	s21_size_t mantissa;
	unsigned long long exponent = s21_float_info(&arg, &mantissa, info);
  short arg_size = s21_float_size(info->number.size_man, info);
	info->number.num_size = arg_size + 1;
  short difference = info->width - arg_size;
  difference = difference <= 0 ? arg_size : arg_size + difference;
  char* result_f = (char*)malloc(sizeof(char) * (arg_size + 1));
	ZERO_MEM(result_f, arg_size)
  short sign = info->zero ? 0 : s21_number_flag(&result_f, info);

	difference += s21_check_extra_zero(&exponent, info);
  s21_num_to_string(mantissa, result_f + sign);
  s21_write_exponent(exponent, result_f, info, info->number.size_man + sign);

	char* result_with_pad = (char*)malloc(sizeof(char) * (difference + 2));
	info->number.dif_width = difference;
	ZERO_MEM(result_with_pad, arg_size);
	info->number.num_size = s21_number_count(result_f);
  char symbol = info->zero ? '0' : ' ';
	int pad_size = difference - arg_size - info->number.need_sign -
					(!info->prec && info->number.is_g && info->sharp);

  info->minus ? s21_right_pad(result_f, result_with_pad, symbol, pad_size)
              : s21_left_pad(result_f, result_with_pad, symbol, pad_size);
  free(result_f);

  return result_with_pad;
}

void s21_float_to_result(char *str, char* result_with_pad, t_info *info) {
	for (s21_size_t i = 0; i < s21_strlen(result_with_pad); i++) {
		str[(info->iterator)++] = result_with_pad[i];
	}
}

char *s21_float_process(long double arg, t_info* info) {
  char* result_with_pad = s21_float_to_string(arg, info);
  if (info->zero) {
    s21_number_flag(&result_with_pad, info);
  }
	return result_with_pad;
}

void s21_float_main(char* str, long double arg, t_info* info) {
char* result_with_pad	= s21_float_process(arg, info);
	s21_float_to_result(str, result_with_pad, info);
	free(result_with_pad);
}

static void s21_zero_man_process(double arg, t_info *info) {
	short e_size = 0;
	int temp = (int) arg;
	int edge_accur = info->prec;
	while(temp == 0 && edge_accur) {
		arg *= 10;
		temp = (int) arg;
		e_size++;
		edge_accur--;
	}
	info->e_size = -e_size;
}

char *s21_ex_process(long double arg, t_info* info) {
	long double new_float;
  int mantissa = (int)arg;
	if (mantissa == 0) {
		s21_zero_man_process(arg, info);
		new_float = arg * s21_power_ten(-info->e_size);
	} else {
		mantissa = mantissa < 0 ? -mantissa : mantissa;
		int size = s21_numlen(mantissa, 10);
		info->e_size = size - 1;
		new_float = arg / (s21_power_ten(info->e_size));
	}
	return s21_float_process(new_float, info);
}

void s21_ex_main(char* str, long double arg, t_info* info) {
	char* result_with_pad	= s21_ex_process(arg, info);
	s21_float_to_result(str, result_with_pad, info);
	free(result_with_pad);
}


