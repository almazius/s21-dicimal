#include "s21_decimal.h"

int s21_floor(s21_decimal value, s21_decimal *result) {
  int res = 0;
  int mult = get_multiplier(value);
  int minus = get_minus(value);
  s21_long_decimal num = convert_decimal_to_long(value);
  int res_div = decimal_div_10(&num, mult);
  if (minus && (res_div || !is_null(value))) inc_decimal_long(&num);

  *result = convert_long_to_decimal(num, 0, &mult, &res);
  if (minus) set_minus(result);
  return res;
}

int s21_round(s21_decimal value, s21_decimal *result) {
  int res = 0;
  int mult = get_multiplier(value);
  int minus = get_minus(value);
  s21_long_decimal num = convert_decimal_to_long(value);
  int res_div = decimal_div_10(&num, mult);
  if (res_div == 1) inc_decimal_long(&num);

  *result = convert_long_to_decimal(num, 0, &mult, &res);
  if (minus) set_minus(result);
  return res;
}

int s21_truncate(s21_decimal value, s21_decimal *result) {
  int res = 0;
  int mult = get_multiplier(value);
  int minus = get_minus(value);
  s21_long_decimal num = convert_decimal_to_long(value);
  decimal_div_10(&num, mult);

  *result = convert_long_to_decimal(num, 0, &mult, &res);
  if (minus) set_minus(result);
  return res;
}

int s21_negate(s21_decimal value, s21_decimal *result) {
  int res = 0;
  int minus = get_minus(value);
  *result = copy_decimal(value);
  if (minus) reset_minus(result);
  if (!minus) set_minus(result);
  return res;
}
