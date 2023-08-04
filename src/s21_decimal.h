#ifndef SRC_S21_DECIMAL_H_
#define SRC_S21_DECIMAL_H_

#include <math.h>
#include <stdlib.h>

typedef struct {
  unsigned int bits[4];
} s21_decimal;

typedef struct {
  unsigned int bits[6];
} s21_long_decimal;

#define S21_INT_MAX 4294967295

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

int s21_is_less(s21_decimal, s21_decimal);
int s21_is_less_or_equal(s21_decimal, s21_decimal);
int s21_is_greater(s21_decimal, s21_decimal);
int s21_is_greater_or_equal(s21_decimal, s21_decimal);
int s21_is_equal(s21_decimal, s21_decimal);
int s21_is_not_equal(s21_decimal, s21_decimal);

int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);

s21_decimal new_decimal(unsigned int bit0, unsigned int bit1, unsigned int bit2,
                        int minus, int multiplier);
int get_bit_status(s21_decimal num, int index);
int get_bit_status_long(s21_long_decimal num, int index);
void set_bit(s21_decimal *num, int index);
void set_bit_long(s21_long_decimal *num, int index);
void reset_bit(s21_decimal *num, int index);
int simple_add(s21_long_decimal num1, s21_long_decimal num2,
               s21_long_decimal *result);
int get_multiplier(s21_decimal number);
void set_multiplier(s21_decimal *number, int multipler);
int left_bit_shift(s21_long_decimal *number, int count);
int right_bit_shift(s21_long_decimal *number, int count);
int decimal_mul_10(s21_long_decimal *number, int count);
void set_minus(s21_decimal *number);
void reset_minus(s21_decimal *number);
int get_minus(s21_decimal number);
int decimal_div_10(s21_long_decimal *number, int count);

int decimal_great(s21_long_decimal num1, s21_long_decimal num2);
int decimal_equal(s21_long_decimal num1, s21_long_decimal num2);
int decimal_lite(s21_long_decimal num1, s21_long_decimal num2);

void reset_decimal(s21_decimal *number);
void reset_decimal_long(s21_long_decimal *number);
s21_decimal copy_decimal(s21_decimal number);
s21_long_decimal copy_decimal_long(s21_long_decimal number);
s21_long_decimal convert_decimal_to_long(s21_decimal number);
s21_decimal convert_long_to_decimal(s21_long_decimal number, int operation,
                                    int *multiplier, int *func_status);
void inverse_decimal(s21_long_decimal *number);
int get_left_index(s21_long_decimal number);
int get_rang(s21_long_decimal number);

int del_nulls(s21_long_decimal *number, int *mult);
void inc_decimal_long(s21_long_decimal *number);
int is_null(s21_decimal num);

int decimal_simple_div(s21_long_decimal dividend, s21_long_decimal divider,
                       s21_long_decimal *result, s21_long_decimal *ostatok);

int get_float_params(float number, int *rank, int *mantissa);

int _pow(int x, int y);
double float_div10(double num, int count);
double float_mul10(double num, int count);

#endif  // SRC_S21_DECIMAL_H_
