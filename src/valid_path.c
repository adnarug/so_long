/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:03:03 by pguranda          #+#    #+#             */
/*   Updated: 2022/09/25 18:21:49 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	check_invalid_to_fill(char c)
{
	if (c == '0' || c == 'E' || c == 'P' || c == 'C' || c == 'V' || c == 'H')
		return (0);
	else
		return (1);
}

static void	flood_fill(char **tab, t_vector size, t_vector cur)
{
	char	c;

	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x \
		|| check_invalid_to_fill(tab[cur.y][cur.x]) == 1)
		return ;
	c = tab[cur.y][cur.x];
	tab[cur.y][cur.x] = 'X';
	flood_fill(tab, size, (t_vector){cur.x - 1, cur.y, .p_is_found = FALSE});
	flood_fill(tab, size, (t_vector){cur.x + 1, cur.y, .p_is_found = FALSE});
	flood_fill(tab, size, (t_vector){cur.x, cur.y - 1, .p_is_found = FALSE});
	flood_fill(tab, size, (t_vector){cur.x, cur.y + 1, .p_is_found = FALSE});
}

void	check_valid_path(char **map, t_map_data *map_data)
{
	flood_fill(map, (*map_data).size, (*map_data).player_position);
	unique_tiles_check_after_flood(map, map_data);
}

char	**map_dup(char **map, t_map_data map_data)
{
	char	**map_dup;
	int		i;

	map_dup = malloc(sizeof(char *) * (map_data.size.y + 1));
	i = 0;
	while (map[i] != NULL)
	{
		map_dup[i] = ft_strdup(map[i]);
		i++;
	}
	map_dup[i] = NULL;
	return (map_dup);
}
