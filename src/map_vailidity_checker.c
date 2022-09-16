/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_vailidity_checker.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 11:56:37 by pguranda          #+#    #+#             */
/*   Updated: 2022/09/16 12:10:42 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

s_map_data_checker init_mapdatachecker(char **map)
{
	s_map_data_checker	map;
	
	map.size.x = ft_strlen(map[0]);
	map.size.y =  line_count;

	
}