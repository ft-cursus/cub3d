/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_input.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 13:49:45 by lsarraci          #+#    #+#             */
/*   Updated: 2026/05/09 15:38:20 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_INPUT_H
# define CUB_INPUT_H

/* keyboard input definitions and helpers
 * maps keycodes to movement and camera actions handled by the game loop
 */
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_W 119

/* returns whether the keycode belongs to the arrow key set */
int		is_arrow_key(int keycode);
/* rotates the player according to the pressed arrow key */
void	handle_arrow_press(int keycode, t_player *player, t_game *game);
/* returns whether the keycode belongs to the movement keys */
int		is_direction_key(int keycode);
/* applies movement input to the player state */
void	handle_direction_press(int keycode, t_player *player, t_game *game);

#endif