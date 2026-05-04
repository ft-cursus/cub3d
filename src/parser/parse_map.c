/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 20:09:00 by bmoreira          #+#    #+#             */
/*   Updated: 2026/05/04 16:46:59 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

int		is_valid_texture(char *id)
{
	return (ft_strcmp(id, "NO")
		|| ft_strcmp(id, "SO")
		|| ft_strcmp(id, "WE")
		|| ft_strcmp(id, "EA"));
}

int		is_valid_color(char *id)
{
	return (ft_strcmp(id, "F")
		|| ft_strcmp(id, "C"));
}

void	set_texture(t_map *map, char *id, char *path)
{
	if (ft_strcmp(id, "NO"))
		map->north_texture = path;
	else if (ft_strcmp(id, "SO"))
		map->south_texture = path;
	else if (ft_strcmp(id, "WE"))
		map->west_texture = path;
	else if (ft_strcmp(id, "EA"))
		map->east_texture = path;
}

int	is_valid_rgb(char **rgb)
{
	int	num;
	int	i;

	i = 0;
	num = 0;
	if (ft_split_size(rgb) != 3)
		return (0);
	while (rgb[i])
	{
		num = ft_atoi(rgb[i]);
		if (num < 0 || num > 255)
			return (0);
		i++;
	}
	return (1);
}

int	get_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	set_color(t_map *map, char *id, char *color)
{
	char	**rgb;

	rgb = ft_split(color, ',');
	if (is_valid_rgb(rgb))
	{
		if (ft_strcmp(id, "F"))
			map->floor_color =
				get_rgb(ft_atoi(rgb[0]), ft_atoi(rgb[1]), ft_atoi(rgb[2]));
		else if (ft_strcmp(id, "C"))
			map->ceiling_color =
				get_rgb(ft_atoi(rgb[0]), ft_atoi(rgb[1]), ft_atoi(rgb[2]));
		free(id);
		free(color);
	}
	else
		error_handler(map, rgb, INVALID_COLOR);
}

void	get_map_element(t_map *map, char *line)
{
	char	**element;

	element = ft_split(line, ' ');
	free(line);
	if (ft_split_size(element) != 2)
		error_handler(map, element, INVALID_ELEMENT);
	if (is_valid_texture(element[0]))
		set_texture(map, element[0], element[1]);
	else if (is_valid_color(element[0]))
		set_color(map, element[0], element[1]);
	else
		error_handler(map, element, INVALID_ELEMENT);
}
// receber linha
// splitar por espaço
// checar se tem 2 itens
// checar se item 1 é igual aos ids possíveis (NO, SO, WE, EA, F, C)
// checar item 2 para F e C:
// splitar por vírgula
// checar se tem 3 itens
// fazer atoi nos itens
// checar se valores vao de 0 a 255

char	*read_file(t_map *map, char *file_name)
{
	char	*buffer;
	char	*line;
	int		fd;

	buffer = NULL;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		error_handler(map, NULL, READ_FILE);
	line = get_next_line(fd);
	while (line)
	{
		// get_map_element(line)
		// check_elements_filled(map)
		// get_map()
		buffer = ft_strjoin(buffer, line);
		if (!buffer)
			printf("Error joining line.\n");
		line = get_next_line(fd);
	}
	return (buffer);
}

void    parse_map()
{
	
}

t_map	*init_map(void)
{
	t_map	*map;

	map = ft_calloc(1, sizeof(t_map));
	map->north_texture = NULL;
	map->south_texture = NULL;
	map->west_texture = NULL;
	map->east_texture = NULL;
	map->floor_color = -1;
	map->ceiling_color = -1;
	map->grid = NULL;
	return (map);
}

int main(void)
{
	t_map *map;
	char *buffer;
	char **split;
	char *path;

	map = init_map();
	path = "assets/maps/valid.cub";
	buffer = read_file(map, path);
	printf("%s", buffer);
	split = ft_split(buffer, '\n');
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