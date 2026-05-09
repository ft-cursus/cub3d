/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 15:08:49 by lsarraci          #+#    #+#             */
/*   Updated: 2026/05/09 15:36:38 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

/* umbrella header for the whole project
 * centralizes standard headers, libft, MLX, and all cub3D modules
 */
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <sys/time.h>
# include "../lib/libft/libft.h"
# include "../lib/minilibx-linux/mlx.h"
# include "cub_structs.h"
# include "cub_types.h"
# include "cub_utils.h"
# include "cub_render.h"
# include "cub_input.h"
# include "cub_engine.h"
# include "cub_parser.h"
# include "cub_validation.h"

int			handle_key_press(int keycode, void *param);
int			handle_close(void *param);
int			render(void *param);
/* handles key press events and updates the input state */
int		handle_key_press(int keycode, void *param);
/* handles window close events and shuts the game down cleanly */
int		handle_close(void *param);
/* renders one frame of the game loop */
int		render(void *param);
/* allocates and prepares the main image buffer */
void		initialize_image_data(t_window *window, int width, int height);
/* creates the MLX window and its backing image data */
void		initialize_window_data(t_window *window, int width,
				int height, char *title);
/* allocates a window wrapper and initializes MLX resources */
t_window	*create_window(int width, int height, char *title);
/* destroys the window, image, and MLX context */
void		close_window(void *param);
/* registers input and close-event hooks with MLX */
void		setup_hooks(void *param);
/* releases every resource owned by the game instance */
void		free_game(t_game *game);
/* initializes the game state from the provided scene file */
void		init_game(t_game *game, char **argv);
/* loads textures from the map and creates the player */
void		load_map_textures_and_player(t_game *game);
/* stores the current time as the timer reference point */
void		init_timer(t_timer *timer);
/* updates delta time using the last recorded timestamp */
void		update_timer(t_timer *timer);

/* destroys every loaded texture and clears texture pointers */
void		remove_all_textures(t_game *game);

#endif