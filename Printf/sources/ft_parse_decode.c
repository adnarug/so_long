/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_decode.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 10:58:09 by pguranda          #+#    #+#             */
/*   Updated: 2022/05/28 12:12:23 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	ft_flags_parse(char *str_arg, size_t i, t_arg *out);
static void	ft_precision_parse(char *str_arg, size_t i, \
			size_t counter, t_arg *out);

void	ft_parse_args(const char *s, size_t z, t_arg *out)
{
	size_t	arg_len;
	char	*str_arg;

	str_arg = NULL;
	arg_len = ft_find_len(s, z);
	out->length = arg_len;
	str_arg = ft_substr(s, z, arg_len);
	if (str_arg == NULL)
		return ;
	ft_flags_parse(str_arg, arg_len, out);
	free(str_arg);
	str_arg = NULL;
	return ;
}

static void	ft_flags_parse(char *str_arg, size_t i, t_arg *out)
{
	size_t	counter;
	int		flag_or_zero;

	counter = 0;
	flag_or_zero = 0;
	out->specifier = str_arg[i - 1];
	out->length = i;
	while (counter != i)
	{
		if (ft_digit(str_arg[counter]) == 1 && flag_or_zero == 0)
			flag_or_zero = 1;
		if (str_arg[counter] == '#')
			out->is_hash = 1;
		if (str_arg[counter] == '-')
			out->is_minus = 1;
		if (str_arg[counter] == '0' && flag_or_zero == 0)
			out->is_zero = 1;
		if (str_arg[counter] == '+')
			out->is_plus = 1;
		if (str_arg[counter] == ' ')
			out->is_space = 1;
		ft_precision_parse(str_arg, i, counter, out);
		counter++;
	}
}

static void	ft_precision_parse(char *str_arg, size_t i, \
			size_t counter, t_arg *out)
{
	char	*address_dot;

	address_dot = NULL;
	while (counter != i)
	{
		if (str_arg[counter] == '.')
		{
			if (str_arg[counter + 1] == out->specifier)
				out->precision = -1;
			else
				out->precision = ft_atoi(str_arg + counter + 1);
			address_dot = &str_arg[counter];
		}
		if ((ft_digit(str_arg[counter]) == 1) && (out->width == 0) && \
		((&str_arg[counter] < address_dot) || (address_dot == NULL)))
			out->width = ft_atoi(str_arg + counter);
		counter++;
	}
	if (address_dot != NULL)
		address_dot = NULL;
}
