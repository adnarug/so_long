/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_with_zeros_unsigned.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 16:54:37 by pguranda          #+#    #+#             */
/*   Updated: 2022/05/28 12:12:58 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putnbr_with_zeros_unsigned(int precision, int num, int *sub_counter)
{
	int				i;
	unsigned int	num_uns;
	int				counter;

	i = 0;
	num_uns = (unsigned)num;
	counter = 0;
	if (num_uns == 0)
		i = 1;
	while (num_uns != 0)
	{
		num_uns = num_uns / 10;
		i++;
	}
	if (precision != 0 && precision > i)
		ft_write_zeroes(precision - i, sub_counter);
	ft_putnbr_unsigned(num, sub_counter, 0);
	return (*sub_counter);
}
