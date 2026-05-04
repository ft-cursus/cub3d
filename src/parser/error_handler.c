/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 15:36:36 by bmoreira          #+#    #+#             */
/*   Updated: 2026/05/04 16:47:12 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

void	free_map(t_map *map)
{
	free(map->north_texture);
	free(map->south_texture);
	free(map->west_texture);
	free(map->east_texture);
	if (map->grid)
		ft_free_split(map->grid);
	free(map);
}

void	error_handler(t_map *map, char **split, int exit_code)
{
	if (split)
		ft_split_free(split);
	free_map(map);
	if (exit_code == READ_FILE)
		printf("Error reading file.\n");
	else if (exit_code == INVALID_COLOR)
		printf("Invalid color. Please provide a valid RGB value: "
			"[0-255],[0-255],[0-255]\n");
	else if (exit_code == INVALID_ELEMENT)
		printf("Invalid element. Please provide a valid texture path or RGB."
			"It must contain two space separated values: [ID] [PATH/COLOR]\n");
	exit (1);
}
