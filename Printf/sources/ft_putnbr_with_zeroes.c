/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_with_zeroes.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 16:54:37 by pguranda          #+#    #+#             */
/*   Updated: 2022/05/28 12:12:55 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putnbr_with_zeroes_pr(int precision, int num, int *sub_counter)
{
	int	i;
	int	num2;

	i = 0;
	num2 = num;
	if (num < 0)
	{
		num *= -1;
	}
	if (num == 0)
		i = 1;
	while (num != 0)
	{
		num = num / 10;
		i++;
	}
	if (precision > 0 && precision >= i)
		ft_write_zeroes(precision - i, sub_counter);
	*sub_counter += ft_putnbr_fd(num2, 1, 0);
	return (*sub_counter);
}

int	ft_putnbr_with_zeroes_zr(int precision, int num, int *sub_counter)
{
	int	i;
	int	num2;

	i = 0;
	num2 = num;
	if (num < 0)
	{
		num *= -1;
		i++;
	}
	if (num == 0)
		i = 1;
	while (num != 0)
	{
		num = num / 10;
		i++;
	}
	if (precision > 0 && precision >= i)
		ft_write_zeroes(precision - i, sub_counter);
	*sub_counter += ft_putnbr_fd(num2, 1, 0);
	return (*sub_counter);
}
