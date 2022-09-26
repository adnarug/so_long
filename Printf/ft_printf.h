/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 20:17:35 by pguranda          #+#    #+#             */
/*   Updated: 2022/05/28 12:14:00 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft/libft.h"
# define SPECIFIERS "cspdiuxX%%"
# define FLAGS ".0123456789+-# "
# define LONG_MIN	-2147483648
# define LONG_MAX	2147483647
# define ULONG_MAX	4294967295

typedef struct s_arg
{
	int				is_hash;
	int				is_minus;
	int				is_zero;
	int				is_plus;
	int				is_space;
	int				width;
	int				precision;
	size_t			length;
	char			specifier;
}	t_arg;

size_t		ft_find_len(const char *s, size_t arg_start);
void		ft_decode_to_struct(const char *str_arg, size_t i, t_arg *out);
void		ft_parse_args(const char *s, size_t z, t_arg *out);
void		ft_write_struct(t_arg *first_arg, va_list ap, int *counter);
int			ft_hex_up(int i, int *sub_counter, int *sign_flag);
int			ft_hex_low(int num, int *sub_counter, int *sign_flag);
void		ft_hex_low_pointer(unsigned long num, int *hex_counter);
int			ft_putnbr_unsigned(int n, int *sub_counter, int *sign_flag);
int			ft_zero(size_t width);
int			ft_precision_string(char *str, int i);
int			ft_put_pointer(void *pointer, t_arg *out, int *sub_counter);
int			ft_putnbr_with_zeroes(int precision, int num, int *sub_counter);
int			ft_sign(int i);
int			ft_space_sign(int i);
int			ft_digit(int c);
int			ft_putstr_printf(char *s, t_arg *arg, int *sub_counter);
int			ft_putchar_printf(char s, t_arg *arg, int *sub_counter);
void		ft_minus_width(int (*f)(int, int*, int*), t_arg *arg, \
			int integer, int *sub_counter);
int			ft_putnbr_printf(int n, int *sub_counter, int *sign_flag);
int			ft_precision_unsigned(int precision, int num, int *sub_counter);
int			ft_printf(const char *s, ...);
int			ft_precision_hex_low(int precision, int num, int *sub_counter);
int			ft_precision_hex_up(int precision, int num, int *sub_counter);
int			ft_hex_counter(int num, int *sub_counter);
void		ft_write_width(int width, int *sub_counter);
void		ft_write_zeroes(int width, int *sub_counter);
int			ft_putnbr_with_zeros_unsigned(int precision, \
			int num, int *sub_counter);
int			ft_putnbr_with_zeroes_pr(int precision, int num, int *sub_counter);
int			ft_putnbr_with_zeroes_zr(int precision, int num, int *sub_counter);
void		ft_write_hex(int long num, t_arg *arg, \
			int *counter, int *sub_counter);

#endif