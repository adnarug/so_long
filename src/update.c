/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 13:42:25 by pguranda          #+#    #+#             */
/*   Updated: 2022/09/22 18:19:39 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*Caclucate all animations and render*/
static void	player_animation(t_player *player)
{
	if (player->current_img == player->action_img
		&& player->framecount >= player->action_frames)
	{
		player->current_img = player->idle_img_1;
	}
	else if (player->framecount == player->idle_frames)
	{
		player->current_img = player->idle_img_0;
	}
	else if (player->framecount >= player->idle_frames * 2)
	{
		player->current_img = player->idle_img_1;
		player->framecount = 0;
	}
	player->framecount += 1;
}

/* Draws the corresponding sprite for the wall at <pos> */
void	draw_wall(t_tile tile, t_game game, t_vector pos)
{
	mlx_put_image_to_window(game.mlx, game.window,
		game.wall_imgs.block, pos.x, pos.y);
}

/*Drawing the corresponding image to the tile type*/
void	draw_image(t_tile tile, t_game game, t_vector pos, int *frame)
{
	// printf("%d ", *frame);
	if (tile.type == WALL)
		draw_wall(tile, game, pos);
	else if (tile.type == EXIT)
			mlx_put_image_to_window(game.mlx, game.window, \
			game.door_open_img, pos.x, pos.y);
	else if (tile.type == COLLECTABLE)
		mlx_put_image_to_window(game.mlx, game.window, game.collects_imgs.current_img, pos.x, pos.y);
	else if (tile.type == PLAYER)
		mlx_put_image_to_window(game.mlx, game.window,
		game.player.current_img, pos.x, pos.y);
	else if (tile.type == ENEMY)
			mlx_put_image_to_window(game.mlx, game.window, game.enemy_imgs.basic_current, pos.x, pos.y);
}

void	draw_text(t_game game)
{
	char *count;
	count = ft_itoa(game.moves);
	mlx_string_put(game.mlx, game.window,
			game.wndw_size.x - IMG_SIZE / 2.3,
			IMG_SIZE - IMG_SIZE / 1.5,
			15921152, count);
	free(count);
	count = NULL;
}

void	render(t_game game)
{
	t_tile	tile;
	int		x;
	int		y;
	int		frame;

	mlx_clear_window(game.mlx, game.window);
	y = 0;
	frame = 0;
	while (game.tilemap[y] != NULL)
	{
		x = 0;
		while (game.tilemap[y][x].type != 0)
		{
			tile = game.tilemap[y][x];
			draw_image(tile, game, tile.position, &frame);
			x++;
		}
		y++;
	}
	draw_text(game);
}

int	update(t_game *game)
{
	player_animation(&game->player);
	enemy_animation(&game->enemy_imgs);
	render(*game);
	return(1);
}