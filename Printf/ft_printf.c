/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 10:40:44 by pguranda          #+#    #+#             */
/*   Updated: 2022/09/26 11:16:15 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	find_args(const char *s, va_list ap, int *str_len, t_arg *arg);
static void	struct_default(t_arg *arg);

int	ft_printf(const char *s, ...)
{
	va_list			ap;
	t_arg			*arg;
	int				i;
	int				*str_len;

	str_len = malloc(sizeof(int));
	arg = malloc(sizeof(t_arg));
	struct_default(arg);
	if (arg == NULL)
		return (0);
	*str_len = 0;
	i = 0;
	va_start(ap, s);
	find_args(s, ap, str_len, arg);
	va_end(ap);
	i = *str_len;
	free(arg);
	arg = NULL;
	free(str_len);
	str_len = NULL;
	return (i);
}

/*searching for args, parsing into struct and writing,
while counting the length*/
static void	find_args(const char *s, va_list ap, int *str_len, t_arg *arg)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			ft_parse_args(s, i + 1, arg);
			ft_write_struct(arg, ap, str_len);
			i += arg->length;
			arg->width = 0;
		}
		else
		{
			write(1, &s[i], 1);
			*str_len += 1;
		}
		i++;
	}
}

/*setting the struct elements to the default values*/
static void	struct_default(t_arg *arg)
{
	arg->is_hash = 0;
	arg->is_minus = 0;
	arg->is_zero = 0;
	arg->is_plus = 0;
	arg->is_space = 0;
	arg->width = 0;
	arg->precision = 0;
	arg->length = 0;
	arg->specifier = '0';
}
