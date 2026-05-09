/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_grid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 18:17:38 by bmoreira          #+#    #+#             */
/*   Updated: 2026/05/09 20:18:08 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	flood_fill(char **grid, int height, int y, int x)
{
    int		len;
    char	cell;

    if (y < 0 || y >= height)
        return (0);
    if (!grid[y])
        return (0);
    len = ft_strlen(grid[y]);
    if (x < 0 || x >= len)
        return (0);
    cell = grid[y][x];
    if (cell == ' ' || cell == '\t')
        return (0);
    if (cell == '1' || cell == 'V')
        return (1);
    if (cell != '0' && !is_orientation_char(cell))
        return (0);
    grid[y][x] = 'V';
    if (!flood_fill(grid, height, y - 1, x)
        || !flood_fill(grid, height, y + 1, x)
        || !flood_fill(grid, height, y, x - 1)
        || !flood_fill(grid, height, y, x + 1))
        return (0);
    return (1);
}

static void	validate_allowed_chars(t_map *map)
{
    int	y;
    int	x;
    int	player_count;

    if (!map || !map->grid)
        return ;
    player_count = 0;
    y = 0;
    while (y < map->dim.height)
    {
        if (map->grid[y])
            for (x = 0; map->grid[y][x]; x++)
            {
                if (!is_valid_map_char(map->grid[y][x]))
                    error_handler(map, NULL, INVALID_GRID);
                if (is_orientation_char(map->grid[y][x]))
                    player_count++;
            }
        y++;
    }
    if (player_count != 1)
        error_handler(map, NULL, INVALID_GRID);
}

void	validate_grid(t_map *map)
{
    char	**grid_dup;

    validate_allowed_chars(map);
    if (!map || !map->grid || !map->player)
        return ;
    grid_dup = ft_matrix_dup(map->grid);
    if (!grid_dup)
        error_handler(map, NULL, JOIN_CONTENT);
    if (!flood_fill(grid_dup, map->dim.height,
            map->player->pos.y, map->player->pos.x))
        error_handler(map, grid_dup, INVALID_GRID);
    ft_free_split(grid_dup);
}
