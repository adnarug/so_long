/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 17:16:24 by pguranda          #+#    #+#             */
/*   Updated: 2022/05/28 12:12:08 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

size_t	ft_find_len(const char *s, size_t arg_start)
{
	size_t	len;

	len = 0;
	while (ft_strchr(SPECIFIERS, s[arg_start + len]) == NULL)
		len++;
	return (len + 1);
}
