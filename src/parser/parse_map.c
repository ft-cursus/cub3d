/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 20:09:00 by bmoreira          #+#    #+#             */
/*   Updated: 2026/05/04 15:01:53 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

int		is_texture(char *id)
{
	return (ft_strcmp(id, "NO")
		|| ft_strcmp(id, "SO")
		|| ft_strcmp(id, "WE")
		|| ft_strcmp(id, "EA"));
}

int		is_color(char *id)
{
	return (ft_strcmp(id, "F")
		|| ft_strcmp(id, "C"));
}

void	set_texture()
{

}

void	set_color()
{

}

void	get_map_element(char *line)
{
	char	**splitted;

	splitted = ft_split(line, " ");
	if (ft_split_size(splitted) != 2)
		printf("Invalid element. Must contain two space separated values: "
			"[ID] [PATH/COLOR]");
	if (is_texture(splitted[0]))
		set_texture(splitted[1]);
	else if (is_color(splitted[0]))
		set_color(splitted[1]);
	else
		printf("Invalid element. Please provide a orientation "
			"texture path or RGB color.");
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

char	*read_file(char *file_name)
{
	char	*buffer;
	char	*line;
	int		fd;

	buffer = NULL;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		printf("Error reading file.\n");
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

int main(void)
{
	char *buffer;
	char **split;

	buffer = read_file("assets/maps/valid.cub");
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