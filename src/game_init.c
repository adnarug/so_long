/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 08:24:18 by pguranda          #+#    #+#             */
/*   Updated: 2022/09/25 17:21:59 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	open_player_imgs(t_game *game)
{
	game->player.idle_img_0 = mlx_xpm_file_to_image(game->mlx,
			"sprites/player_idle_1.xpm", &game->img_size.x, &game->img_size.y);
	game->player.idle_img_1 = mlx_xpm_file_to_image(game->mlx,
			"sprites/player_idle_2.xpm", &game->img_size.x, &game->img_size.y);
	game->player.current_img = game->player.idle_img_0;
}

void	open_collect_imgs(t_game *game)
{
	game->collects_imgs = mlx_xpm_file_to_image(game->mlx,
			"sprites/collect.xpm",
			&game->img_size.x, &game->img_size.y);
}

void	open_enemy_imgs(t_game *game)
{
	game->enemy_imgs.basic_mid = mlx_xpm_file_to_image(game->mlx,
			"sprites/enemy_wings_mid.xpm",
			&game->img_size.x, &game->img_size.y);
	game->enemy_imgs.basic_low = mlx_xpm_file_to_image(game->mlx,
			"sprites/enemy_wings_low.xpm",
			&game->img_size.x, &game->img_size.y);
	game->enemy_imgs.basic_current = game->enemy_imgs.basic_mid;
}

/* Opens with the mlx all images needed in the game */
void	open_images(t_game *game)
{
	game->wall_img = mlx_xpm_file_to_image(game->mlx,
			"sprites/wall.xpm", &game->img_size.x, &game->img_size.y);
	game->door_close_img = mlx_xpm_file_to_image(game->mlx,
			"sprites/exit_close.xpm", &game->img_size.x, &game->img_size.y);
	open_player_imgs(game);
	open_collect_imgs(game);
	open_enemy_imgs(game);
}

/* Sets the frames of all animations */
void	game_init(t_game *game)
{
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx,
			game->wndw_size.x,
			game->wndw_size.y,
			"so_long");
	mlx_hook(game->window, 17, 0, end_program, game);
	open_images(game);
}
