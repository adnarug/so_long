/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 13:25:28 by pguranda          #+#    #+#             */
/*   Updated: 2022/09/13 13:47:12 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <math.h>
#include <memory.h>
#include "get_next_line.h"
#include "../so_long.h"

/* Return how many '\n' are in <file> */
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
	while (TRUE)
	{
		readcount = read(fd, &c, 1);
		if (readcount == 0)
			break ;
		if (readcount < 0)
			return (-1);
		if (c == '\n')
			linecount++;
	}
	close(fd);
	return (linecount);
}

/* Allocates memory for a string array with the same lines as the file */
static char	**alloc_columns(char *file, int *line_count)
{
	char	**map;

	*line_count = file_linecount(file);
	if (*line_count <= 0)
		return (null_error("open or reading error, the file may not exist"));
	map = malloc(sizeof(char *) * *line_count + 1);
	if (map == NULL)
		return (null_error("malloc error on alloc_map()"));
	return (map);
}

/* Creates -with malloc- a 2D char map as found in file */
char	**read_map(char *file)
{
	char	**map;
	int		fd;
	int		line_count;
	int		i;

	i = 0;
	line_count = 0;
	map = alloc_columns(file, &line_count);
	// printf("Line count: %d", line_count);
	if (map == NULL)
		return (NULL);
	fd = open(file, O_RDONLY);
	while (line_count > 0)
	{
		map[i] = get_next_line(fd);
		// printf("%s", map[i]);
		line_count--;
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

/* Creates -with malloc- a tilemap acording to the
first file of argv. Returns NULL if an error occurs. */
t_tile	**map_init(int argc, char **argv, t_game *game)
{
	char	**map;
	t_tile	**tilemap;

	// if (!valid_file(argc, argv[1]))
	// 	return (NULL);
	map = read_map(argv[1]);
	if (map == NULL)
		return (NULL);
	//checking the validity of the map
	tilemap = generate_tilemap(map, game);
	ft_free_chartable(map);
	if (tilemap == NULL)
		return (NULL);
	return (tilemap);
}

void	anim_setup(t_game *game)
{
	game->player.idle_frames = 17;
	game->player.action_frames = 10;
	game->collects_imgs.anim_frames = 25;
	game->effect.frames = 7;
	game->enemy_imgs.basic_anim = 16;
	game->enemy_imgs.follow_anim = 6;
}

int	start(t_game *game, int argc, char **argv)
{
	game->collects = 0;
	game->moves = 0;
	game->tilemap = map_init(argc, argv, game);
	if (game->tilemap == NULL)
		return (0);
	game->og_collects = game->collects;
	// anim_setup(game);
	game_init(game);
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 1)
		printf("Error");
	if (argc > 2)
		printf("Too many args");
	if (start(&game, argc, argv) == 0)
		return (0);
	mlx_hook(game.window, 2, 0, input, (void*)&game);
	mlx_loop_hook(game.mlx, update, (void*)&game);
	mlx_loop(game.mlx);
	return (0);
}
