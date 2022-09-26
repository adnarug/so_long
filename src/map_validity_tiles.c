/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity_tiles.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 12:55:08 by pguranda          #+#    #+#             */
/*   Updated: 2022/09/26 11:22:34 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	check_valid_char(char c)
{
	if (c == '1' || c == '0' || c == 'E' || c == 'P' || \
	c == 'C' || c == 'H' || c == 'V' || c == 'X')
		return ;
	else
		error("Invalid charachter found");
}

static t_map_data	*check_unique_e_p(char c, t_map_data *map_data)
{
	if (c == 'P')
	{
		if ((*map_data).one_p == TRUE)
			error("More than one player on the map");
		else
		{
			(*map_data).one_p = TRUE;
		}
	}
	if (c == 'E')
	{
		if ((*map_data).one_e == TRUE)
			error("More than one exit on the map");
		else
			(*map_data).one_e = TRUE;
	}
	if (c == 'C')
			(*map_data).at_least_one_c = TRUE;
	return (map_data);
}

void	unique_tiles_check(char **map, t_map_data *map_data)
{
	(*map_data).curs.x = 0;
	(*map_data).curs.y = 0;
	(*map_data).player_position.p_is_found = FALSE;
	while ((*map_data).curs.y != (*map_data).size.y)
	{
		while ((*map_data).curs.x != (*map_data).size.x)
		{
			check_valid_char(map[(*map_data).curs.y][(*map_data).curs.x]);
			map_data = check_unique_e_p \
			(map[(*map_data).curs.y][(*map_data).curs.x], map_data);
			if ((*map_data).one_p == TRUE && \
			(*map_data).player_position.p_is_found == FALSE)
			{
				(*map_data).player_position = (*map_data).curs;
				(*map_data).player_position.p_is_found = TRUE;
			}
			(*map_data).curs.x++;
		}
		(*map_data).curs.x = 0;
		(*map_data).curs.y++;
	}
	if ((*map_data).one_e == FALSE || (*map_data).one_p == FALSE)
		error("Not all ements are present on the map - check E and P");
	if ((*map_data).at_least_one_c == FALSE)
		error("Not enough collectables");
}

void	unique_tiles_check_after_flood(char **map, t_map_data *map_data)
{
	(*map_data).curs.x = 0;
	(*map_data).curs.y = 0;
	while ((*map_data).curs.y != (*map_data).size.y)
	{
		while ((*map_data).curs.x != (*map_data).size.x)
		{
			if (map[(*map_data).curs.y][(*map_data).curs.x] == 'E' ||
				map[(*map_data).curs.y][(*map_data).curs.x] == 'C')
				error("There is no valid path on the map");
			(*map_data).curs.x++;
		}
		(*map_data).curs.x = 0;
		(*map_data).curs.y++;
	}
}
