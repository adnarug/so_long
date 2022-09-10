/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 13:42:25 by pguranda          #+#    #+#             */
/*   Updated: 2022/09/10 16:19:08 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*Caclucate all animations and render*/

/* Draws the corresponding sprite for the wall at <pos> */
void	draw_wall(t_tile tile, t_game game, t_vector pos)
{
	// if (draw_corner(tile, game, pos))
	// 	return ;
	// else if (draw_sides(tile, game, pos))
	// 	return ;
	mlx_put_image_to_window(game.mlx, game.window,
		game.wall_imgs.block, pos.x, pos.y);
}

/*Drawing the corresponding image to the tile type*/
static void	draw_image(t_tile tile, t_game game, t_vector pos)
{
	if (tile.type == WALL)
		draw_wall(tile, game, pos);
	else if (tile.type == EXIT)
	{
		if (game.collects != 0)
			mlx_put_image_to_window(game.mlx, game.window,
			game.door_open_img, pos.x, pos.y);
		if (game.collects == 0)
			mlx_put_image_to_window(game.mlx, game.window, game.door_close_img, pos.x, pos.y);
	}
	else if (tile.type == COLLECTABLE)
		mlx_put_image_to_window(game.mlx, game.window, game.collects_imgs.current_img, pos.x, pos.y);
	else if (tile.type == PLAYER)
		mlx_put_image_to_window(game.mlx, game.window,
		game.player.current_img, pos.x, pos.y);
	// else if (tile.type == ENEMY)
	// 	mlx_put_image_to_window(game.mlx, game.window, game.enemy_imgs.basic_current, pos.x, pos.y);
	// else if (tile.type == FOLLOWER)
	// 	mlx_put_image_to_window(game.mlx, game.window, game_imgs.follow_current, pos.x, pos.y);
}

void	render(t_game game)
{
	t_tile	tile;
	int		x;
	int		y;

	mlx_clear_window(game.mlx, game.window);
	y = 0;
	while (game.tilemap[y] != NULL)
	{
		x = 0;
		while (game.tilemap[y][x].type != 0)
		{
			tile = game.tilemap[y][x];
			draw_image(tile, game, tile.position);
			// draw_effect(game);
			x++;
		}
		y++;
	}
	// draw_text(game);
}

int	update(t_game *game)
{
	render(*game);
	return(1);
}