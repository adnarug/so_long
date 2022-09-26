/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minus_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 12:09:09 by pguranda          #+#    #+#             */
/*   Updated: 2022/05/28 12:12:21 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_minus_width(int (*f)(int, int *, int *), \
		t_arg *arg, int integer, int *sub_counter)
{
	int	len;
	int	width;
	int	*sign_flag;

	len = 0;
	width = arg->width;
	sign_flag = malloc(sizeof(size_t));
	*sign_flag = 0;
	if (width > 0 && arg->is_minus == 0)
		ft_write_width(width, sub_counter);
	len = f(integer, sub_counter, sign_flag);
	if (*sign_flag == 1)
		len += 1;
	if (arg->is_minus == 1 && width > len)
	{
		width = width - len;
		ft_write_width(width, sub_counter);
	}
	free(sign_flag);
}
