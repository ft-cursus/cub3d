/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_element.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 17:11:35 by bmoreira          #+#    #+#             */
/*   Updated: 2026/05/04 17:22:02 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

void	    parse_element(t_map *map, char *line);
static void	set_texture(t_map *map, char **element);
static void	set_color(t_map *map, char **element);
static int	get_rgb(int r, int g, int b);

void	parse_element(t_map *map, char *line)
{
	char	**element;

	element = ft_split(line, ' ');
	free(line);
	if (ft_split_size(element) != 2)
		error_handler(map, element, INVALID_ELEMENT);
	if (is_valid_texture(element[0]))
		set_texture(map, element);
	else if (is_valid_color(element[0]))
		set_color(map, element);
	else
		error_handler(map, element, INVALID_ELEMENT);
}

static void	set_texture(t_map *map, char **element)
{
	if (ft_strcmp(element[0], "NO"))
		map->north_texture = ft_strdup(element[1]);
	else if (ft_strcmp(element[0], "SO"))
		map->south_texture = ft_strdup(element[1]);
	else if (ft_strcmp(element[0], "WE"))
		map->west_texture = ft_strdup(element[1]);
	else if (ft_strcmp(element[0], "EA"))
		map->east_texture = ft_strdup(element[1]);
	ft_free_split(element);
}

static void	set_color(t_map *map, char **element)
{
	char	**rgb;

	rgb = ft_split(element[1], ',');
	if (is_valid_rgb(rgb))
	{
		if (ft_strcmp(element[0], "F"))
			map->floor_color =
				get_rgb(ft_atoi(rgb[0]), ft_atoi(rgb[1]), ft_atoi(rgb[2]));
		else if (ft_strcmp(element[0], "C"))
			map->ceiling_color =
				get_rgb(ft_atoi(rgb[0]), ft_atoi(rgb[1]), ft_atoi(rgb[2]));
		ft_free_split(rgb);
		ft_free_split(element);
	}
	else
	{
		ft_free_split(rgb);
		error_handler(map, element, INVALID_COLOR);
	}
}

static int	get_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}
