/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:03:03 by pguranda          #+#    #+#             */
/*   Updated: 2022/09/20 18:20:13 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	check_valid_char_after_flood(char c);

static void	fill(char **tab, t_vector size, t_vector cur)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| check_valid_char_after_flood(tab[cur.y][cur.x]) != 1)
		return;
	tab[cur.y][cur.x] = 'X';
	fill(tab, size, (t_vector){cur.x - 1, cur.y});
	fill(tab, size, (t_vector){cur.x + 1, cur.y});
	fill(tab, size, (t_vector){cur.x, cur.y - 1});
	fill(tab, size, (t_vector){cur.x, cur.y + 1});
}

static void	flood_fill(char **tab, t_map_data *map_data, t_vector begin)
{
	fill(tab, (*map_data).size, begin);
}

void	check_valid_path(char **map, t_map_data *map_data, t_game *game)
{
	(*map_data).player_position.x--;
	(*map_data).player_position.y--;
	flood_fill(map, map_data, (*map_data).player_position);
	unique_tiles_check_after_flood(map, map_data);
}

static int	check_valid_char_after_flood(char c)
{
	if (c == '0' || c == 'E' || c == 'P' || c == 'C' || c == 'H' || c == 'V')
		return (1);
	else
		return (0);
}

char **map_dup(char **map, t_map_data map_data)
{
	char **map_dup;
	int		i;
	
	map_dup = malloc(sizeof(map));
	i = 0;
	while (i != map_data.size.y)
	{
		map_dup[i] = ft_strdup(map[i]);
		printf("%s", map_dup[i]);
		i++;
	}
	// printf("%s", map_dup[i]);
	return (map_dup);
}