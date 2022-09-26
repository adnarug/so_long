/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_unsigned.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 11:45:26 by pguranda          #+#    #+#             */
/*   Updated: 2022/05/28 12:12:38 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_precision_unsigned(int precision, int num, int *sub_counter)
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
	precision = precision - i;
	while (precision > 0)
	{
		write (1, "0", 1);
		precision--;
		*sub_counter += 1;
	}
	ft_putnbr_unsigned(num, sub_counter, 0);
	return (*sub_counter);
}
