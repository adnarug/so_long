/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 08:24:18 by pguranda          #+#    #+#             */
/*   Updated: 2022/09/13 11:57:31 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// void	open_wallimgs_down(t_game *game)
// {
// 	game->wall_imgs.down_right = mlx_xpm_file_to_image(game->mlx,
// 			"sprites/wall.xpm",
// 			&game->img_size.x, &game->img_size.y);
// 	game->wall_imgs.down = mlx_xpm_file_to_image(game->mlx,
// 			"sprites/wall.xpm",
// 			&game->img_size.x, &game->img_size.y);
// 	game->wall_imgs.down_left = mlx_xpm_file_to_image(game->mlx,
// 			"sprites/wall.xpm",
// 			&game->img_size.x, &game->img_size.y);
// 	game->wall_imgs.left = mlx_xpm_file_to_image(game->mlx,
// 			"sprites/wall.xpm",
// 			&game->img_size.x, &game->img_size.y);
// }

void	open_walls(t_game *game)
{
	game->wall_imgs.block = mlx_xpm_file_to_image(game->mlx,
			"sprites/wall.xpm",
			&game->img_size.x, &game->img_size.y);
	// game->wall_imgs.up_left = mlx_xpm_file_to_image(game->mlx,
	// 		"/Users/pguranda/Projects/so_long_wip1/sprites/wall1.xpm",
	// 		&game->img_size.x, &game->img_size.y);
	// game->wall_imgs.up = mlx_xpm_file_to_image(game->mlx,
	// 		"/Users/pguranda/Projects/so_long_wip1/sprites/wall1.xpm",
	// 		&game->img_size.x, &game->img_size.y);
	// game->wall_imgs.up_right = mlx_xpm_file_to_image(game->mlx,
	// 		"/Users/pguranda/Projects/so_long_wip1/sprites/wall1.xpm",
	// 		&game->img_size.x, &game->img_size.y);
	// game->wall_imgs.right = mlx_xpm_file_to_image(game->mlx,
	// 		"/Users/pguranda/Projects/so_long_wip1/sprites/wall1.xpm",
	// 		&game->img_size.x, &game->img_size.y);
}

 void	open_player_imgs(t_game *game)
{
	// game->player.idle_img_0 = mlx_xpm_file_to_image(game->mlx,
	// 		"sprites/player.xpm", &game->img_size.x, &game->img_size.y);
	// game->player.idle_img_1 = mlx_xpm_file_to_image(game->mlx,
	// 		"sprites/player.xpm", &game->img_size.x, &game->img_size.y);
	game->player.action_img = mlx_xpm_file_to_image(game->mlx,
			"sprites/player.xpm", &game->img_size.x, &game->img_size.y);
	game->player.current_img = game->player.action_img;
}

void	open_collect_imgs(t_game *game)
{
	game->collects_imgs.img_0 = mlx_xpm_file_to_image(game->mlx,
			"sprites/collect.xpm",
			&game->img_size.x, &game->img_size.y);
	// game->collects_imgs.img_1 = mlx_xpm_file_to_image(game->mlx,
	// 		"sprites/plant_04.xpm",
	// 		&game->img_size.x, &game->img_size.y);
	game->collects_imgs.current_img = game->collects_imgs.img_0;
	// game->effect.img = mlx_xpm_file_to_image(game->mlx,
	// 		"sprites/effect_w.xpm",
	// 		&game->img_size.x, &game->img_size.y);
}

// void	open_enemy_imgs(t_game *game)
// {
// 	game->enemy_imgs.basic_01 = mlx_xpm_file_to_image(game->mlx,
// 			"sprites/enemy_01.xpm",
// 			&game->img_size.x, &game->img_size.y);
// 	game->enemy_imgs.basic_02 = mlx_xpm_file_to_image(game->mlx,
// 			"sprites/enemy_02.xpm",
// 			&game->img_size.x, &game->img_size.y);
// 	game->enemy_imgs.basic_current = game->enemy_imgs.basic_01;
// 	game->enemy_imgs.follow_01 = mlx_xpm_file_to_image(game->mlx,
// 			"sprites/enemy_03.xpm",
// 			&game->img_size.x, &game->img_size.y);
// 	game->enemy_imgs.follow_02 = mlx_xpm_file_to_image(game->mlx,
// 			"sprites/enemy_04.xpm",
// 			&game->img_size.x, &game->img_size.y);
// 	game->enemy_imgs.follow_current = game->enemy_imgs.follow_01;
// }

static void	open_door_imgs(t_game *game)
{
	game->door_open_img = mlx_xpm_file_to_image(game->mlx,
			"sprites/exit_close.xpm",
			&game->img_size.x, &game->img_size.y);
	game->door_close_img = mlx_xpm_file_to_image(game->mlx,
			"sprites/exit_close.xpm",
			&game->img_size.x, &game->img_size.y);
}

/* Opens with the mlx all images needed in the game */
void	open_images(t_game *game)
{
	open_walls(game);
	// open_wallimgs_down (game);
	open_player_imgs(game);
	open_collect_imgs(game);
	// open_enemy_imgs(game);
	open_door_imgs(game);
}

/* Returns a t_color struct */
t_color	new_color(int r, int g, int b, int a)
{
	t_color	color;

	color.r = (char)r;
	color.g = (char)g;
	color.b = (char)b;
	color.a = (char)a;
	return (color);
}

/* Set all pixels in <panel> to <color> */
void	color_panel(t_panel *panel, t_color color)
{
	int	x;
	int	y;

	panel->pixels = mlx_get_data_addr(panel->pointer, &panel->bpp,
			&panel->line_size, &panel->endian);
	y = 0;
	while (y < panel->size.y)
	{
		x = 0;
		while (x < panel->size.x)
		{
			panel->pixels[(x * 4 + panel->line_size * y) + 0] = color.b;
			panel->pixels[(x * 4 + panel->line_size * y) + 1] = color.g;
			panel->pixels[(x * 4 + panel->line_size * y) + 2] = color.r;
			panel->pixels[(x * 4 + panel->line_size * y) + 3] = color.a;
			x += 1;
		}
		y += 1;
	}
}

/* Returns a colored image of the same size as the window */
void	*new_panel(t_game *game, t_color color)
{
	t_panel	panel;

	panel.pointer = mlx_new_image(game->mlx,
			game->wndw_size.x, game->wndw_size.y);
	panel.size.x = game->wndw_size.x;
	panel.size.y = game->wndw_size.y;
	color_panel(&panel, color);
	return (panel.pointer);
}

/* Sets the frames of all animations */
void	game_init(t_game *game)
{
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx,
			game->wndw_size.x /*+ IMG_SIZE/2*/,
			game->wndw_size.y,
			"so_long");
	mlx_hook(game->window, 17, 0, end_program, game);
	open_images(game);
	// game->white_panel = new_panel(game, new_color(254, 15, 254, 0));
	// game->red_panel = new_panel(game, new_color(197, 4, 4, 0));
}