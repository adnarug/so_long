/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zero.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 13:47:15 by pguranda          #+#    #+#             */
/*   Updated: 2022/05/28 12:13:41 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_zero(size_t width)
{
	int	counter;

	counter = 0;
	while (width > 0)
	{
		write (1, "0", 1);
		width--;
		counter++;
	}
	return (counter);
}
