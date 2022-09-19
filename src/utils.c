/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 08:46:44 by pguranda          #+#    #+#             */
/*   Updated: 2022/09/19 10:20:39 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_tilemap(t_game *game)
{
	t_tile	**tilemap;

	tilemap = game->tilemap;
	while (*game->tilemap != NULL)
	{
		free(*game->tilemap);
		game->tilemap++;
	}
	free (tilemap);
}

void	free_enemies(t_game *game)
{
	t_enemy	*next;

	if (game->enemy_list == NULL)
		return ;
	while (TRUE)
	{
		next = game->enemy_list->next;
		free (game->enemy_list);
		if (next == NULL)
			break ;
		game->enemy_list = next;
	}
}

/* Frees all allocated memory and makes exit(0) */
int	end_program(t_game *game)
{
	free_tilemap(game);
	game->tilemap = NULL;
	free_enemies(game);
	game->enemy_list = NULL;
	exit(0);
}

/* Returns NULL printing <message> in red */
int	error(char *message)
{
	printf("\033[0;31m" " Error\n %s\n" "\033[0m", message);
	return (0);
}

/* Returns NULL printing <message> in red */
void	*null_error(char *message)
{
	printf("\033[0;31m" " Error\n %s\n" "\033[0m", message);
	return (0);
}

/* Prints <message> in yellow */
void	print_warning(char *message)
{
	printf("\033[0;33m" " Warning\n %s\n" "\033[0m", message);
}

/* Returns the number of lines a 2D string table that ends in NULL
-> *chars*\0
-> *chars*\0
-> NULL 
Retunr value: 2 */
int	ft_chartable_linecount(char **table)
{
	int	count;

	count = 0;
	while (table[count])
		count++;
	return (count);
}

/* Frees a 2D table */
void	ft_free_chartable(char **table)
{
	int	i;

	i = 0;
	while (table[i])
	{
		free(table[i]);
		i++;
	}
	free(table);
}

int	ft_strlen_nl(const char *c)
{
	size_t				i;

	i = 0;
	while (c[i] != '\0' && c[i] != '\n')
		i++;
	return (i);
}