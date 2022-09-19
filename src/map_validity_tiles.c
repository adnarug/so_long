/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity_tiles.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 12:55:08 by pguranda          #+#    #+#             */
/*   Updated: 2022/09/19 14:31:40 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"


static void	check_valid_char(char c)
{
	if (c == '1' || c == '0' || c == 'E' || c == 'P' || c == 'C' || c == 'H' || c == 'V')
		return;
	else
	{
		error("Invalid charachter found");
		exit(1);
	}
}

static t_map_data	check_unique_E_P(char c, t_map_data map_data)
{
	if (c == 'P')
	{
		if (map_data.one_P == TRUE)
		{
			error("More than one player on the map");
			exit(1);
		}
		else
			map_data.one_P = TRUE;
	}
	if (c == 'E')
	{
		if (map_data.one_E == TRUE)
		{
			error("More than one exit on the map");
			exit(1);
		}
		else
			map_data.one_E = TRUE;
	}
	if (c == 'C')
			map_data.at_least_one_C = TRUE;
	return (map_data);
}

void	unique_tiles_check(char **map, t_map_data map_data)
{
	map_data.curs.x = 0;
	map_data.curs.y = 0;
	while (map_data.curs.y != map_data.size.y)
	{
		while(map_data.curs.x != map_data.size.x)
		{
			check_valid_char(map[map_data.curs.y][map_data.curs.x]);
			map_data = check_unique_E_P(map[map_data.curs.y][map_data.curs.x], map_data);
			map_data.curs.x++;
		}
		map_data.curs.x = 0;
		map_data.curs.y++;
	}
	if (map_data.one_E == FALSE || map_data.one_P == FALSE)
	{
		error("Not all ements are present on the map - check E and P");
		exit(1);
	}
	if (map_data.at_least_one_C == FALSE)
	{
		error("Not enough collectables");
		exit(1);
	}
}