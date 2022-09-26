/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 17:04:25 by pguranda          #+#    #+#             */
/*   Updated: 2022/05/28 12:13:24 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/* Checking up or low hex and then writing*/
static void	write_hex_up(int long num, t_arg *arg, \
			int *counter, int *sub_counter);
static void	write_hex_low(int long num, t_arg *arg, \
			int *counter, int *sub_counter);

void	ft_write_hex(int long num, t_arg *arg, \
			int *counter, int *sub_counter)
{
	if (arg->specifier == 'x')
		write_hex_low(num, arg, counter, sub_counter);
	if (arg->specifier == 'X')
		write_hex_up(num, arg, counter, sub_counter);
}

static void	write_hex_up(int long num, t_arg *arg, \
			int *counter, int *sub_counter)
{
	if (arg->is_hash == 1 && (int)num != 0)
	{
		write (1, "0X", 2);
		*counter += 2;
	}
	if (arg->precision != 0)
		ft_precision_hex_up(arg->precision, num, sub_counter);
	else if (arg->is_zero == 1 && arg->precision == 0 && arg->is_minus == 0)
		ft_precision_hex_up(arg->width, num, sub_counter);
	else
		ft_minus_width(ft_hex_up, arg, num, sub_counter);
	*counter += *sub_counter;
}

static void	write_hex_low(int long num, t_arg *arg, \
			int *counter, int *sub_counter)
{
	if (arg->is_hash == 1 && (int)num != 0)
	{
		write (1, "0x", 2);
		*counter += 2;
	}
	if (arg->precision != 0)
		ft_precision_hex_low(arg->precision, num, sub_counter);
	else if (arg->is_zero == 1 && arg->precision == 0 && arg->is_minus == 0)
		ft_precision_hex_low(arg->width, num, sub_counter);
	else
		ft_minus_width(ft_hex_low, arg, num, sub_counter);
	*counter += *sub_counter;
}
