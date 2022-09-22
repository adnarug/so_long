/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity_checker.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 11:56:37 by pguranda          #+#    #+#             */
/*   Updated: 2022/09/22 17:45:20 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static t_map_data	init_mapdatachecker(char **map, int line_count)
{
	t_map_data	map_data;

	map_data.size.x = ft_strlen(map[0]) - 1;
	map_data.size.y = line_count - 1;
	if ((map_data.size.x * IMG_SIZE) > IMAC_RES_X)
	{
		error("The map will not fit in the screen");
		exit (1);
	}
	if ((map_data.size.y * IMG_SIZE) > IMAC_RES_Y)
	{
		error("The map will not fit in the screen");
		exit (1);
	}
	map_data.one_P = FALSE;
	map_data.one_E = FALSE;
	map_data.at_least_one_C = FALSE;
	map_data.curs.x = 0;
	map_data.curs.y = 0;
	return(map_data);
}

/*Checks the validity of the map*/
static void borders_integrity(char **map, t_map_data map_data)
{
	//top border
	while (map_data.curs.x != map_data.size.x)
	{
		if (map[map_data.curs.y][map_data.curs.x] != '1')
		{
			error("The map is not valid - hole in the wall top");
			exit(1);
		}
		map_data.curs.x++;
	}
	//right border
	map_data.curs.x--;
	while (map_data.curs.y != map_data.size.y)
	{
		if (map[map_data.curs.y][map_data.curs.x] != '1')
		{
			error("The map is not valid - hole in the right wall");
			exit(1);
		}
		map_data.curs.y++;
	}
	//bottom border
	while (map_data.curs.x != 0)
	{
		if (map[map_data.curs.y][map_data.curs.x] != '1')
		{
			error("The map is not valid - whole in the wall bottom");
			exit(1);
		}
		map_data.curs.x--;
	}
	// left border
	while (map_data.curs.y != 0)
	{
		if (map[map_data.curs.y][map_data.curs.x] != '1')
		{
			error("The map is not valid - whole in the wall left");
			exit(1);
		}
		map_data.curs.y--;
	}
}

static int rectang_check(char **map, t_map_data map_data)
{
	t_bool	valid;
	
	valid = 1;
	while (map_data.curs.y != map_data.size.y)
	{
		if (ft_strlen(map[map_data.curs.y]) - 1 != map_data.size.x)
		{
			error("The map is not rectangular");
			exit(1);
		}
		map_data.curs.y++;
	}
	return (valid);
}

int		map_validity_check(char **map, int line_count, t_game *game)
{
	t_map_data	map_data;
	t_bool		valid;
	char		**map_duplicate;

	map_data = init_mapdatachecker(map, line_count);
	borders_integrity(map, map_data);
	valid = rectang_check(map, map_data);
	unique_tiles_check(map, &map_data);
	map_duplicate = map_dup(map, map_data);
	check_valid_path(map_duplicate, &map_data, game);
	ft_free_chartable(map_duplicate);
	return (valid);
}
