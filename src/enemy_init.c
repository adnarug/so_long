/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 15:46:55 by pguranda          #+#    #+#             */
/*   Updated: 2022/09/25 18:16:23 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/* Creates -with malloc- a new enemy with <type> and <tile> */
t_enemy	*new_enemy(t_enemyytpe type, t_tile *tile)
{
	t_enemy	*enemy;

	enemy = malloc(sizeof(t_enemy));
	if (enemy == NULL)
		error("malloc error on new_enemy()");
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

void	enemy_animation(t_enemy_img *img)
{
	static int	basic_count;

	if (basic_count == img->basic_anim)
		img->basic_current = img->basic_low;
	else if (basic_count > img->basic_anim * 2)
	{
		img->basic_current = img->basic_mid;
		basic_count = 0;
	}
	basic_count++;
}
