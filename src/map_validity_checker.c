/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity_checker.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 11:56:37 by pguranda          #+#    #+#             */
/*   Updated: 2022/09/25 18:22:46 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static t_map_data	init_mapdatachecker(char **map, int line_count)
{
	t_map_data	map_data;

	map_data.size.x = ft_strlen(map[0]) - 1;
	map_data.size.y = line_count ;
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
	map_data.one_p = FALSE;
	map_data.one_e = FALSE;
	map_data.at_least_one_c = FALSE;
	map_data.curs.x = 0;
	map_data.curs.y = 0;
	return (map_data);
}

static int	rectang_check(char **map, t_map_data map_data)
{
	t_bool	valid;

	valid = 1;
	while (map_data.curs.y < map_data.size.y - 1)
	{
		if (ft_strlen(map[map_data.curs.y]) - 1 != map_data.size.x)
		{
			error("The map is not rectangular");
			exit(1);
		}
		map_data.curs.y++;
	}
	if (ft_strlen(map[map_data.curs.y]) != map_data.size.x)
	{
		error("The map is not rectangular");
		exit(1);
	}
	return (valid);
}

int	map_validity_check(char **map, int line_count)
{
	t_map_data	map_data;
	t_bool		valid;
	char		**map_duplicate;

	map_data = init_mapdatachecker(map, line_count);
	check_border_integrity(&map_data, map);
	valid = rectang_check(map, map_data);
	unique_tiles_check(map, &map_data);
	map_duplicate = map_dup(map, map_data);
	check_valid_path(map_duplicate, &map_data);
	ft_free_chartable(map_duplicate);
	return (valid);
}
