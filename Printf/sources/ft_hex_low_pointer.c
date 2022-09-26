/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_low_pointer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 13:22:54 by pguranda          #+#    #+#             */
/*   Updated: 2022/05/28 12:12:13 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_hex_low_pointer(unsigned long num, int *hex_counter)
{
	if (num >= 16)
	{
		ft_hex_low_pointer(num / 16, hex_counter);
		ft_hex_low_pointer(num % 16, hex_counter);
	}
	else
	{
		if (num <= 9)
		{
			ft_putchar_fd((num + '0'), 1);
			*hex_counter += 1;
		}
		else
		{
			ft_putchar_fd((num - 10 + 'a'), 1);
			*hex_counter += 1;
		}
	}
	return ;
}
