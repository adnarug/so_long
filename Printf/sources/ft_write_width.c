/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 13:51:59 by pguranda          #+#    #+#             */
/*   Updated: 2022/05/28 12:13:27 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_write_width(int width, int *sub_counter)
{
	while (width > 0)
	{
		write (1, " ", 1);
		width--;
		*sub_counter += 1;
	}
}
