/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   border_checks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 10:05:27 by pguranda          #+#    #+#             */
/*   Updated: 2022/09/25 12:56:18 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	top_border_check(t_map_data map_data, char **map)
{
	while (map_data.curs.x != map_data.size.x)
	{
		if (map[map_data.curs.y][map_data.curs.x] != '1')
			error("The map is not valid - hole in the wall top");
		map_data.curs.x++;
	}
}

static void	right_border_check(t_map_data map_data, char **map)
{
	map_data.curs.x = map_data.size.x - 1;
	while (map_data.curs.y != map_data.size.y)
	{
		if (map[map_data.curs.y][map_data.curs.x] != '1')
			error("The map is not valid - hole in the right wall");
		map_data.curs.y++;
	}
}

static void	bottom_border_check(t_map_data map_data, char **map)
{
	map_data.curs.x = map_data.size.x - 1;
	map_data.curs.y = map_data.size.y;
	while (map_data.curs.x != 0)
	{
		if (map[map_data.curs.y][map_data.curs.x] != '1')
			error("The map is not valid - whole in the wall bottom");
		map_data.curs.x--;
	}
}

static void	left_border_check(t_map_data map_data, char **map)
{
	map_data.curs.y = map_data.size.y;
	while (map_data.curs.y != 0)
	{
		if (map[map_data.curs.y][map_data.curs.x] != '1')
			error("The map is not valid - whole in the wall left");
		map_data.curs.y--;
	}
}

void	check_border_integrity(t_map_data *map_data, char **map)
{
	top_border_check(*map_data, map);
	right_border_check(*map_data, map);
	bottom_border_check(*map_data, map);
	left_border_check(*map_data, map);
}
