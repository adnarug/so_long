/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_up.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 13:22:54 by pguranda          #+#    #+#             */
/*   Updated: 2022/05/28 12:12:18 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_hex_up(int num, int *sub_counter, int *sign_flag)
{
	sign_flag = NULL;
	if ((long)num == 9223372036854775807LL || (unsigned)num == ULONG_MAX)
	{
		write(1, "FFFFFFFF", 8);
		*sub_counter += 8;
		return (8);
	}
	if ((unsigned)num >= 16)
	{
		ft_hex_up((unsigned)num / 16, sub_counter, NULL);
		ft_hex_up((unsigned)num % 16, sub_counter, NULL);
	}
	else
	{
		if ((unsigned)num <= 9)
			ft_putchar_fd(((unsigned)num + '0'), 1);
		else
			ft_putchar_fd((num - 10 + 'A'), 1);
		*sub_counter += 1;
	}
	return (*sub_counter);
}
