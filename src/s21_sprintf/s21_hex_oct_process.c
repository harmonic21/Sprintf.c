#include "s21_sprintf.h"

static void s21_prefix_process(char** hex, t_info* info) {
	int pos = 0;
	int hex_size = s21_strlen(*hex);
	char* pref_hex = (char *)malloc(sizeof(char) * (hex_size + 3));
	switch (info->symbol) {
		case 'x':
		case 'X':
		case 'p':
			if (info->sharp || info->symbol == 'p') {
				pref_hex[pos++] = '0';
				pref_hex[pos++] = info->symbol == 'X' ? 'X' : 'x';
				pref_hex[pos] = '\0';
				s21_strcat(pref_hex, *hex);
			}
			break;
		case 'o':
			if (info->sharp) {
				pref_hex[pos++] = '0';
				pref_hex[pos] = '\0';
				s21_strcat(pref_hex, *hex);
			}
			break;
	}
	free(*hex);
	*hex = pref_hex;
}
static void s21_to_hex_str(unsigned long  number, char* hex, t_info *info) {
	const char low_case[] = "0123456789abcdef";
	const char upper_case[] = "0123456789ABCDEF";
	int index;
	hex[info->number.num_size] = '\0';
	int size = info->number.num_size;
	while (size) {
		index = number % 16;
		hex[--size] = info->symbol == 'X' ? upper_case[index] : low_case[index];
		number /= 16;
	}
}

void s21_hex_process(char* str, unsigned long long number, t_info* info) {
	info->number.num_size = s21_numlen(number, 16);
	int pref = (info->sharp || info->symbol == 'p') && number != 0;
	char* hex = (char*)malloc(sizeof(char) * info->number.num_size + 1);
  s21_to_hex_str(number, hex, info);
	if (pref && !info->zero ) {
		s21_prefix_process(&hex, info);
	}

	info->number.dif_width = info->width > info->number.num_size ?
					info->width - info->number.num_size - pref * 2 : 0;

	int res_size = info->number.dif_width + info->number.num_size + pref * 2 + 1;
	char *result = (char *)malloc (sizeof(char) * res_size);

	char symbol = info->zero ? '0' : ' ';
	info->minus ? s21_right_pad(hex, result, symbol, info->number.dif_width)
							: s21_left_pad(hex, result, symbol, info->number.dif_width);
	if (pref && info->zero ) {
		s21_prefix_process(&result, info);
	}
  for (int i = 0; result[i] != '\0'; i++) {
    str[(info->iterator)++] = result[i];
  }

  free(hex);
	free(result);
}

static char* s21_oct_info(unsigned long long number, t_info* info) {
	info->number.num_size = s21_numlen(number, 8);
	char* oct_res = (char*)malloc(sizeof(char) * (info->number.num_size + 1));
	int j = 0;
	unsigned long long octal = 0;
	while (number != 0) {
		octal = octal + (number % 8) * s21_power_ten(j);
		number /= 8;
		j++;
	}
	s21_num_to_string(octal, oct_res);
	return oct_res;
}

void s21_dec_to_oct_process(char* str, unsigned long long number, t_info* info) {
	int need_pref = info->sharp && number != 0;
	char* octal_result = s21_oct_info(number, info);
  int size = info->number.num_size;

	if (need_pref && !info->zero ) {
		s21_prefix_process(&octal_result, info);
	}

	info->number.dif_width = info->width > size ? info->width - size - need_pref : 0;
	char *result = (char *)malloc (sizeof(char) * (info->number.dif_width + size + need_pref + 1));

	char symbol = info->zero ? '0' : ' ';
	info->minus ? s21_right_pad(octal_result, result, symbol, info->number.dif_width)
							: s21_left_pad(octal_result, result, symbol, info->number.dif_width);

	if (need_pref && info->zero ) {
		s21_prefix_process(&result, info);
	}

  for (int i = 0; result[i] != '\0'; i++) {
    str[(info->iterator)++] = result[i];
  }
  free(octal_result);
	free(result);
}

