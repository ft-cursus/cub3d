/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 20:09:00 by bmoreira          #+#    #+#             */
/*   Updated: 2026/05/04 17:54:46 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

t_map	*init_map(void)
{
	t_map	*map;

	map = ft_calloc(1, sizeof(t_map));
	map->north_texture = NULL;
	map->south_texture = NULL;
	map->west_texture = NULL;
	map->east_texture = NULL;
	map->grid = NULL;
	map->floor_color = -1;
	map->ceiling_color = -1;
	return (map);
}

void    parse_grid(t_map *map, int fd, char *line)
{
	char	*buffer;
	while (line)
	{
		buffer = ft_strjoin(buffer, line);
		if (!buffer)
			error_handler(map, NULL, JOIN_CONTENT);
		line = get_next_line(fd);
	}
	map->grid = ft_split(buffer, '\n');
	// missing:
	// check if there is any empty \n line inside grid
	// check if grid is surrounded by walls
	// pathfinder/floodfill
}

void	parse_map(t_map *map, char *file_name)
{
	char	*line;
	int		fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		error_handler(map, NULL, READ_FILE);
	line = get_next_line(fd);
	while (line)
	{
		if (is_valid_elements(map))
			parse_grid(map, fd, line);
		else
			parse_element(map, line);
		line = get_next_line(fd);
	}
}

int main(void)
{
	t_map *map;
	char *buffer;
	char **split;
	char *path;

	map = init_map();
	path = "assets/maps/valid.cub";
	parse_map(map, path);
}

// ler cada linha do arquivo
// detectar se está no início ou final do arquivo (como?)
// se estiver no início do arquivo, verificar se elementos seguem padrão
// padrão: identificador-espaço-valor
// se identificador for do tipo orientação, verificar se valor é do tipo PATH
// se identificador for do tipo cor, verificar se valor é do tipo RGB
// verificar se cada elemento está separado por um ou mais quebras de linha
// ler todo o mapa para grid
// verificar se mapa está cercado por paredes
// verificar se há pelo menos um caminho válido no mapa
// verificar se não há mais elementos depois do mapa, e se chegou ao final do arquivo
// ao chegar no final do arquivo, checar se todos os elementos foram preenchidos