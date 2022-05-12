#include "s21_sprintf.h"

 short s21_need_sign(long long number, t_info *info) {
	info->sign = number < 0 ? 1 : 0;
	return info->plus || info->space || info->sign;
}

static unsigned long long s21_num_info(long long number, t_info *info) {
	info->number.need_sign = s21_need_sign(number, info);
	unsigned long long uns_num = info->sign ? -number : number;
	info->number.num_size = s21_numlen(uns_num, 10);
	if (!info->dot) {
		info->prec = 0;
	}
	info->number.dif_prec = info->prec <= info->number.num_size ?
					0 : info->prec - info->number.num_size ;
	info->number.num_size = info->number.dif_prec <= 0 ?
					info->number.num_size : info->number.num_size + info->number.dif_prec;
	info->number.dif_width = info->width > info->number.num_size ?
					info->width - info->number.num_size : 0;
	return uns_num;
}

static char* s21_number_to_string(long long number, t_info* info) {
	unsigned long long uns_num = s21_num_info(number, info);
	int length = info->number.num_size + info->number.dif_width + 2;
  char* result = (char*)malloc(sizeof(char) * length);
	char* prec_num = (char*)malloc(sizeof(char) * (info->number.num_size + 1));
  char* pad_str = (char*)malloc(sizeof(char) * length);
	ZERO_MEM(pad_str, length)

  short sign = info->zero || info->number.dif_prec > 0 ?
					0 : s21_number_flag(&pad_str, info);

	if (info->number.dif_prec > 0) {
		int prec_pad_size = info->number.dif_prec - sign;
		s21_num_to_string(uns_num, prec_num + sign);
		s21_left_pad(prec_num, pad_str, '0', prec_pad_size);
	} else {
		s21_num_to_string(uns_num, pad_str  + sign);
	}

  char symbol = info->zero ? '0' : ' ';
	int pad_size = info->number.dif_width - info->number.need_sign;
  info->minus ? s21_right_pad(pad_str, result, symbol, pad_size)
							: s21_left_pad(pad_str, result, symbol, pad_size);

  free(pad_str);
	free(prec_num);
  return result;
}

void s21_number_process(char* str, long long number, t_info* info) {
  char* result = s21_number_to_string(number, info);
  if (info->zero || info->number.dif_prec) {
    s21_number_flag(&result, info);
  }
  for (size_t i = 0; i < s21_strlen(result); i++) {
    str[(info->iterator)++] = result[i];
  }
  free(result);
}
