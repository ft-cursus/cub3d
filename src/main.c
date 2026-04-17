/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsarraci <lsarraci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 15:08:39 by lsarraci          #+#    #+#             */
/*   Updated: 2026/04/17 16:38:47 by lsarraci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

int	main(void)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
	{
		fprintf(stderr, "Failed to initialize game\n");
		return (1);
	}
	game->window = create_window(WINDOW_WIDTH, WINDOW_HEIGHT, "Cub3D");
	if (!game->window)
	{
		free(game);
		return (1);
	}
	setup_hooks(game);
	mlx_loop(game->window->mlx_ptr);
}
