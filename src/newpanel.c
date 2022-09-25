/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newpanel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 09:10:54 by pguranda          #+#    #+#             */
/*   Updated: 2022/09/23 10:26:36 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


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
