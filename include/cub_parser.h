/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 20:17:59 by bmoreira          #+#    #+#             */
/*   Updated: 2026/05/09 15:38:32 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_PARSER_H
# define CUB_PARSER_H

/* map parsing and validation helpers
 * responsible for reading the .cub file, loading scene data, and reporting errors
 */
# include "cub_structs.h"
# include "cub_validation.h"
# include <fcntl.h>

typedef enum e_exit_code
{
	READ_FILE,
	INVALID_ELEMENT,
	INVALID_COLOR,
    JOIN_CONTENT,
}	t_exit_code;

/* reports a parsing failure and frees partial allocations */
void	error_handler(t_map *map, char **split, int exit_code);
/* releases every allocation owned by the map structure */
void	free_map(t_map *map);
/* parses one texture or color declaration from the scene file */
void	parse_element(t_map *map, char *line);
/* reads and validates the .cub file contents */
int		parse_map(t_map *map, char *file_name);
/* allocates and initializes an empty map structure */
t_map	*init_map(void);

/* checks whether a character is a valid player orientation */
int		is_orientation_char(char c);
/* converts a spawn orientation to its initial angle */
float	set_start_angle(char orientation);
/* counts the number of rows in the parsed map grid */
int		count_map_rows(char **grid);
/* computes the widest row in the map grid */
int		count_map_columns(char **grid);

#endif