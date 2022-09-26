/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_on.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 15:20:44 by pguranda          #+#    #+#             */
/*   Updated: 2022/09/25 15:24:09 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	step_on_empty(t_game *game, t_tile *tile)
{
	tile->type = PLAYER;
	if (game->player.tile->type != EXIT)
		game->player.tile->type = EMPTY;
	if (game->player.tile->was_exit == TRUE)
		game->player.tile->type = EXIT;
	game->player.tile = tile;
}

void	step_on_collect(t_game *game, t_tile *tile)
{
	tile->type = PLAYER;
	game->collects--;
	if (game->player.tile->type != EXIT)
		game->player.tile->type = EMPTY;
	if (game->player.tile->was_exit == TRUE)
		game->player.tile->type = EXIT;
	game->player.tile = tile;
}

void	step_through_exit(t_game *game, t_tile *tile)
{
	tile->type = PLAYER;
	if (game->player.tile->type != EXIT)
		game->player.tile->type = EMPTY;
	ft_printf("Not all collectables are gathered!\n");
	game->player.tile = tile;
}

void	step_on_exit(t_game *game)
{
	remove_player(game);
	game->collects = -1;
	ft_printf("You won!");
	end_program(game);
}

void	step_on_enemy(t_game *game)
{
	remove_player(game);
	ft_printf("You lost!");
	end_program(game);
}
