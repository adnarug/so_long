/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 12:01:58 by pguranda          #+#    #+#             */
/*   Updated: 2022/09/16 10:51:44 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	kill_player(t_game *game, t_vector pos)
{
	game->player.tile = NULL;
	printf("You lost!");
	end_program(game);
	// effect_anim(&game->effect, pos);
	// mlx_put_image_to_window(game->mlx, game->window, game->red_panel, 0, 0);
}

void	remove_player(t_game *game)
{
	game->player.tile->type = EMPTY;
	game->player.tile = NULL;
}


void	move_to_empty(t_game *game, t_tile *tile)
{
	tile->type = PLAYER;
	if (game->player.tile->type != EXIT)
		game->player.tile->type = EMPTY;
	game->player.tile = tile;
}

void	pick_collect(t_game *game, t_tile *tile)
{
	tile->type = PLAYER;
	game->collects--;
	if (game->player.tile->type != EXIT)
		game->player.tile->type = EMPTY;
	game->player.tile = tile;
}

void	move_to_exit(t_game *game, t_tile *tile)
{
	remove_player(game);
	game->collects = -1;
	printf("You won!");//printf here and everywhere
	end_program(game);
}

void	move_to_enemy(t_game *game, t_tile *tile)
{
	remove_player(game);
	printf("You lost!");
	end_program(game);
}

t_bool	move_to(t_game *game, t_tile *tile)
{
	if(tile->type == EMPTY)
		move_to_empty(game, tile);
	else if(tile->type == COLLECTABLE)
		pick_collect(game, tile);
	else if (tile->type == EXIT && game->collects <= 0)
		move_to_exit(game, tile);
	else if (tile->type == ENEMY)
		move_to_enemy(game, tile);
	else
		return (FALSE);
	move_enemies(game);
	return (TRUE);
}

int	input(int key, t_game *game)
{
	t_bool	moved;
	
	if (key == ESC)
		end_program(game);
	if (game->player.tile == NULL)
		return (0);
	if (key == KEY_UP)
		moved = move_to(game, game->player.tile->up);
	else if (key == KEY_DOWN)
		moved = move_to(game, game->player.tile->down);
	else if (key == KEY_LEFT)
		moved = move_to(game, game->player.tile->left);
	else if (key == KEY_RIGHT)
		moved = move_to(game, game->player.tile->right);
	else
		return (0);
	if  (moved != FALSE )
		ft_printf("Moves -> %02d\n", game->moves++);
	return (1);
}