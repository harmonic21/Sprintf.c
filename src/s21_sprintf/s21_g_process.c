#include "s21_sprintf.h"

static void s21_check_accuracy(t_info *info) {
	info->prec = info->prec < 0 ? 0 : info->prec;
}

static void s21_check_zero_case(long double number, t_info *info) {
	int temp_accur = info->prec;
	int check = 0;
	unsigned long long exp_value = (number - (long) number) * s21_power_ten(info->prec + 1);
	while (temp_accur) {
		check = exp_value % 10;
		if (check) {
			break;
		} else {
			exp_value /= 10;
		}
		temp_accur--;
	}
	if (temp_accur == 0) {
		info->prec = 0;
	}
}

void s21_g_process(char* str, long double number, t_info* info) {
	s21_check_zero_case(number, info);
	int accr = info->prec;
	info->number.is_g = 1;
	info->symbol = info->symbol == 'g' ? 'e' : 'E';
	info->prec = accr - 1;
	s21_check_accuracy(info);
	char *e_case = s21_ex_process(number, info);
	int e_size = info->number.num_size;

	info->symbol = 'f';
	int mantissa = (int)number;
	int size_mantissa = s21_numlen(mantissa < 0 ? -mantissa : mantissa, 10);
	info->prec = accr - size_mantissa;
	s21_check_accuracy(info);
	char *f_case = s21_float_process(number, info);

	int f_size = info->number.num_size;

	e_size < f_size ? s21_float_to_result(str, e_case, info)
									: s21_float_to_result(str, f_case, info);
	free(e_case);
	free(f_case);
}