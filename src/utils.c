/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 08:46:44 by pguranda          #+#    #+#             */
/*   Updated: 2022/09/25 16:09:24 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/* Returns NULL printing <message> in red */
void	error(char *message)
{
	ft_printf("Error\n%s\n", message);
	exit (1);
}

int	ft_chartable_linecount(char **table)
{
	int	count;

	count = 0;
	while (table[count])
		count++;
	return (count);
}

int	ft_strlen_nl(const char *c)
{
	size_t				i;

	i = 0;
	while (c[i] != '\0' && c[i] != '\n')
		i++;
	return (i);
}

void	check_file_extension(char *s)
{
	while (*s != '\0')
		s++;
	s = s - 4;
	if (ft_strncmp(s, ".ber", 4) != 0)
	{
		error("Wrong file extension");
		exit(1);
	}
	else
		return ;
}
