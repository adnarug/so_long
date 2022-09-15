/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 11:52:03 by pguranda          #+#    #+#             */
/*   Updated: 2022/09/15 17:22:48 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"


// void	enemy_animation(t_enemy_img *img)
// {
// 	static int	basic_count;

// 	if (basic_count == img->basic_anim)
// 		img->basic_current = img->basic_up;
// 	else if (basic_count > img->basic_anim * 2)
// 	{
// 		img->basic_current = img->basic_low;
// 		basic_count = 0;
// 	}
// 	basic_count++;
// }

/* Change the tile of <enemy> */
void	move_enemy_to(t_enemy *enemy, t_tile *tile)
{
	enemy->tile->type = EMPTY;
	tile->type = ENEMY;
	enemy->tile = tile;
}

/* If <enemy> dir is 0, set it to 1.
* If it is 1, set it to 0. */
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
			kill_player(game, enemy->tile->position);
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
			kill_player(game, enemy->tile->position);
		}
		else
			return (change_dir(enemy));
	}
	return (TRUE);
}

/* Move <enemy> up or down based on his direction */
t_bool	move_ver(t_enemy *enemy, t_game *game)
{
	if (enemy->dir == 0)
	{
		if (enemy->tile->up->type == EMPTY)
			move_enemy_to(enemy, enemy->tile->up);
		else if (enemy->tile->up->type == PLAYER)
		{
			move_enemy_to(enemy, enemy->tile->up);
			kill_player(game, enemy->tile->position);
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
			kill_player(game, enemy->tile->position);
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


/* Creates -with malloc- a new enemy with <type> and <tile> */
t_enemy	*new_enemy(t_enemyytpe type, t_tile *tile)
{
	t_enemy	*enemy;

	enemy = malloc(sizeof(t_enemy));
	if (enemy == NULL)
		return (null_error("malloc error on new_enemy()"));
	enemy->type = type;
	enemy->dir = 0;
	enemy->tile = tile;
	enemy->og_tile = enemy->tile;
	enemy->next = NULL;
	return (enemy);
}

/* Returs a pointer to the last element of <lst> */
t_enemy	*last_enemy(t_enemy *list)
{
	if (list == NULL)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

/* Adds -using malloc- an enemy at the end of the list */
void	add_enemy(t_game *game, t_enemyytpe type, t_tile *tile)
{
	t_enemy	*new;

	new = new_enemy(type, tile);
	if (new == NULL)
		return ;
	if (game->enemy_list == NULL)
		game->enemy_list = new;
	else
		last_enemy(game->enemy_list)->next = new;
}
