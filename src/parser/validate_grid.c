/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_grid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 18:17:38 by bmoreira          #+#    #+#             */
/*   Updated: 2026/05/09 19:08:31 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int flood_fill(char **grid, int y, int x)
{
    
}

void validate_grid(t_game *game)
{
    char **grid_dup;

    grid_dup = ft_matrix_dup(game->map->grid);
    flood_fill(grid_dup, game->player->pos.x, game->player->pos.x);
}