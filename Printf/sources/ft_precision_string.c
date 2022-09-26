/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_string.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:55:54 by pguranda          #+#    #+#             */
/*   Updated: 2022/05/28 12:12:30 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_precision_string(char *str, int i)
{
	int	counter;

	counter = 0;
	if (i == -1)
		return (0);
	while (i != 0 && str[counter] != '\0')
	{
		write(1, &str[counter], 1);
		counter++;
		i--;
	}
	return (counter);
}
