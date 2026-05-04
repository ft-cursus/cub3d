/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_elements.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 17:38:30 by bmoreira          #+#    #+#             */
/*   Updated: 2026/05/04 17:45:19 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

int	is_valid_elements(t_map *map)
{
	return (map->north_texture
			&& map->south_texture
			&& map->west_texture
			&& map->east_texture
			&& map->grid
			&& map->floor_color >= 0
			&& map->ceiling_color >= 0);
}
