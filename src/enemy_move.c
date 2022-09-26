/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 11:52:03 by pguranda          #+#    #+#             */
/*   Updated: 2022/09/25 17:12:45 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/* Change the tile of <enemy> */
void	move_enemy_to(t_enemy *enemy, t_tile *tile)
{
	enemy->tile->type = EMPTY;
	tile->type = ENEMY;
	enemy->tile = tile;
}

t_bool	change_dir(t_enemy *enemy)
{
	if (enemy->dir == 0)
		enemy->dir = 1;
	else
		enemy->dir = 0;
	return (FALSE);
}

/* Move <enemy> to the left or right based on his direction */
t_bool	move_hor(t_enemy *enemy, t_game *game)
{
	if (enemy->dir == 0)
	{
		if (enemy->tile->left->type == EMPTY)
			move_enemy_to(enemy, enemy->tile->left);
		else if (enemy->tile->left->type == PLAYER)
		{
			move_enemy_to(enemy, enemy->tile->left);
			kill_player(game);
		}
		else
			return (change_dir(enemy));
	}
	else if (enemy-> dir == 1)
	{
		if (enemy->tile->right->type == EMPTY)
			move_enemy_to(enemy, enemy->tile->right);
		else if (enemy->tile->right->type == PLAYER)
		{
			move_enemy_to(enemy, enemy->tile->right);
			kill_player(game);
		}
		else
			return (change_dir(enemy));
	}
	return (TRUE);
}

/* Move up or down based on his direction */
t_bool	move_ver(t_enemy *enemy, t_game *game)
{
	if (enemy->dir == 0)
	{
		if (enemy->tile->up->type == EMPTY)
			move_enemy_to(enemy, enemy->tile->up);
		else if (enemy->tile->up->type == PLAYER)
		{
			move_enemy_to(enemy, enemy->tile->up);
			kill_player(game);
		}
		else
			return (change_dir(enemy));
	}
	else if (enemy-> dir == 1)
	{
		if (enemy->tile->down->type == EMPTY)
			move_enemy_to(enemy, enemy->tile->down);
		else if (enemy->tile->down->type == PLAYER)
		{
			move_enemy_to(enemy, enemy->tile->down);
			kill_player(game);
		}
		else
			return (change_dir(enemy));
	}
	return (TRUE);
}

/* Go though the enemy list moving all of them according to their type */
void	move_enemies(t_game *game)
{
	t_enemy	*current;

	if (game->enemy_list == NULL)
		return ;
	current = game->enemy_list;
	while (TRUE)
	{
		if (current->type == HORIZONTAL_ENEM)
			move_hor(current, game);
		else if (current->type == VERTICAL_ENEM)
			move_ver(current, game);
		if (current->next == NULL)
			break ;
		current = current->next;
	}
}
