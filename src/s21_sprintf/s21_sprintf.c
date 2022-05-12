#include "s21_sprintf.h"

int s21_sprintf(char* str, const char* format, ...) {
  char* work_format = (char*)format;
  va_list args;
  t_info info;
  s21_init_struct(&info);
  info.iterator = 0;

  va_start(args, format);

  while (*work_format) {
    work_format = s21_write_to_buff(str, work_format, &info);
    if (*work_format == '%') {
      work_format = s21_parse_spf(work_format, &info, &args);
      s21_write_process(str, &info, &args);
      work_format++;
    }
  }
  va_end(args);
  str[info.iterator] = '\0';

  return info.iterator;
}
