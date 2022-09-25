/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 13:25:28 by pguranda          #+#    #+#             */
/*   Updated: 2022/09/25 16:20:36 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/*Driver function to make the map and initialize structs*/
static void	launch(t_game *game, char **argv)
{
	game->collects = 0;
	game->moves = 0;
	game->tilemap = map_init(argv, game);
	if (game->tilemap == NULL)
		error("Map initialization error");
	game->og_collects = game->collects;
	game->player.idle_frames = 20;
	game->enemy_imgs.basic_anim = 17;
	game_init(game);
	return ;
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		error("Wrong input - check the parameters");
		return (0);
	}
	if ((argv[1] == NULL || *argv[1] == '\0') && argc == 2)
	{
		error("Wrong input - empty parameter");
		return (0);
	}
	check_file_extension(argv[1]);
	launch(&game, argv);
	mlx_hook(game.window, 2, 0, input, &game);
	mlx_loop_hook(game.mlx, update, &game);
	mlx_loop(game.mlx);
	return (0);
}
