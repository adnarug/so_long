/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_hex_low.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 13:32:44 by pguranda          #+#    #+#             */
/*   Updated: 2022/05/28 12:12:26 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_precision_hex_low(int precision, int num, int *sub_counter)
{
	int				i;
	unsigned int	num2;
	int				counter;

	i = 0;
	num2 = (unsigned) num;
	counter = 0;
	if (num2 == 0)
		i = 1;
	ft_hex_counter(num, sub_counter);
	i = *sub_counter;
	*sub_counter = 0;
	precision = precision - i;
	while (precision > 0)
	{
		write (1, "0", 1);
		precision--;
		*sub_counter += 1;
	}
	ft_hex_low(num, sub_counter, 0);
	return (*sub_counter);
}
