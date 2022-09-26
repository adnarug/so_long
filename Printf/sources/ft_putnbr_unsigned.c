/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 11:45:26 by pguranda          #+#    #+#             */
/*   Updated: 2022/05/28 12:12:53 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putnbr_unsigned(int n, int *sub_counter, int *sign_flag)
{
	sign_flag = 0;
	if ((long)n > LONG_MAX || (long)n < LONG_MIN)
		return (0);
	if ((unsigned)n < 10)
	{
		ft_putchar_fd((unsigned)n + '0', 1);
		*sub_counter += 1;
		return (1);
	}
	*sub_counter += 1;
	ft_putnbr_unsigned((unsigned)n / 10, sub_counter, sign_flag);
	ft_putchar_fd(((unsigned)n % 10) + '0', 1);
	return (*sub_counter);
}
