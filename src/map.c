/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 09:32:19 by pguranda          #+#    #+#             */
/*   Updated: 2022/09/26 18:37:23 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../include/get_next_line.h"

/* Counting the newlines */
static int	file_linecount(char *file)
{
	int		linecount;
	int		fd;
	int		readcount;
	char	c;	

	fd = open(file, O_RDONLY);
	if (!fd)
		return (-1);
	linecount = 1;
	while (1)
	{
		readcount = read(fd, &c, 1);
		if (readcount == 0)
			break ;
		if (readcount < 0)
			return (-1);
		if (c == '\n')
			linecount++;
	}
	close (fd);
	return (linecount);
}

/* Allocates memory for a string array with the same lines as the file */
static char	**malloc_columns(char *file, int *line_count)
{
	char	**map;

	*line_count = file_linecount(file);
	if (*line_count <= 0)
		error("could not read the file, it may not exist or the path is wrong");
	map = malloc(sizeof(char *) * *line_count + 1);
	if (map == NULL)
		error("malloc error, when creating the map");
	return (map);
}

/* Creating with malloc 2d array based on the map */
static char	**read_map(char *file, int *line_count)
{
	char	**map;
	int		fd;
	int		i;
	int		num_lines;

	i = 0;
	map = malloc_columns(file, line_count);
	num_lines = *line_count;
	if (map == NULL)
		return (NULL);
	fd = open(file, O_RDONLY);
	while (num_lines > 0)
	{
		map[i] = get_next_line(fd);
		if (map[i] == NULL || **map == ' ')
			error("Invalid map - extra newline");
		num_lines--;
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

/* Creating the map of the tiles and checking the map for the validity. */
t_tile	**map_init(char **argv, t_game *game)
{
	char	**map;
	t_tile	**tilemap;
	int		line_count;

	line_count = 0;
	map = read_map(argv[1], &line_count);
	map_validity_check(map, line_count);
	tilemap = generate_tilemap(map, game);
	if (tilemap == NULL)
		return (NULL);
	ft_free_chartable(map);
	return (tilemap);
}
