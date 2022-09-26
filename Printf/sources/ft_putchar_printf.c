/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_printf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 11:19:59 by pguranda          #+#    #+#             */
/*   Updated: 2022/05/28 12:12:45 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putchar_printf(char c, t_arg *arg, int *sub_counter)
{
	int		width;

	width = arg->width;
	if (arg->is_minus == 0 && width != 0)
		ft_write_width(width - 1, sub_counter);
	write (1, &c, 1);
	if (arg->is_minus == 1 && width != 0)
		ft_write_width(width - 1, sub_counter);
	return (*sub_counter + 1);
}
