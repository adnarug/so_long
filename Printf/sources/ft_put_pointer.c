/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 16:52:45 by pguranda          #+#    #+#             */
/*   Updated: 2022/05/28 12:12:41 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_put_pointer(void *pointer, t_arg *out, int *sub_counter)
{
	int				counter;
	unsigned long	address;
	int				width;

	counter = 0;
	address = (unsigned long)pointer;
	width = out->width;
	if (out->is_minus == 0 && width > 14)
		ft_write_width(width - 14, sub_counter);
	write(1, "0x", 2);
	*sub_counter += 2;
	ft_hex_low_pointer(address, sub_counter);
	if (out->is_minus == 1 && width > *sub_counter)
		ft_write_width(width - *sub_counter, sub_counter);
	return (*sub_counter);
}
