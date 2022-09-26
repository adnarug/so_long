/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 12:01:58 by pguranda          #+#    #+#             */
/*   Updated: 2022/09/25 15:27:03 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	kill_player(t_game *game)
{
	game->player.tile = NULL;
	ft_printf("You lost!");
	end_program(game);
}

void	remove_player(t_game *game)
{
	game->player.tile->type = EMPTY;
	game->player.tile = NULL;
}

t_bool	move_to(t_game *game, t_tile *tile)
{
	if (tile->type == EMPTY)
		step_on_empty(game, tile);
	else if (tile->type == COLLECTABLE)
		step_on_collect(game, tile);
	else if (tile->type == EXIT && game->collects <= 0)
		step_on_exit(game);
	else if (tile->type == EXIT && game->collects > 0)
		step_through_exit(game, tile);
	else if (tile->type == ENEMY)
		step_on_enemy(game);
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
	if (moved != FALSE)
		ft_printf("Moves -> %02d\n", game->moves++);
	return (1);
}
