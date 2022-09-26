/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 11:29:00 by pguranda          #+#    #+#             */
/*   Updated: 2022/05/28 12:13:02 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void static	putstr_null(t_arg *arg, int width, int *sub_counter);

int	ft_putstr_printf(char *s, t_arg *arg, int *sub_counter)
{
	int		len;
	int		width;

	width = arg->width;
	if (s == NULL)
	{
		putstr_null(arg, width, sub_counter);
		return (*sub_counter);
	}
	len = ft_strlen(s);
	if (arg->is_minus == 0 && width > len)
		ft_write_width(width - len, sub_counter);
	*sub_counter += ft_putstr_fd(s, 1);
	if (arg->is_minus == 1 && width > len)
		ft_write_width(width - len, sub_counter);
	return (*sub_counter);
}

/*in case it is a null string with width*/
void static	putstr_null(t_arg *arg, int width, int *sub_counter)
{
	char	*s;
	int		len;

	s = malloc(sizeof(char) * 7);
	if (s == NULL)
		return ;
	ft_strlcpy(s, "(null)", 7);
	len = ft_strlen(s);
	if (arg->is_minus == 0 && width > len)
		ft_write_width(width - len, sub_counter);
	*sub_counter += ft_putstr_fd(s, 1);
	if (arg->is_minus == 1 && width > len)
		ft_write_width(width - len, sub_counter);
	free(s);
	s = NULL;
	return ;
}
