/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 15:44:58 by lsarraci          #+#    #+#             */
/*   Updated: 2026/05/09 15:36:44 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_UTILS_H
# define CUB_UTILS_H

/* gameplay and utility helpers
 * covers timers, minimap setup, player creation, and cleanup helpers
 */
# include "cub_structs.h"

/* stores the current timestamp in the timer */
void		init_timer(t_timer *timer);
/* updates the timer delta with the elapsed time since last frame */
void		update_timer(t_timer *timer);
/* scales movement speed by delta time */
float		set_step(float delta_time, float base_speed);

/* allocates and initializes the player structure */
t_player	*create_player(void);
/* frees the player structure */
void		destroy_player(t_player *player);

/* releases the minimap buffer and related allocations */
void		remove_minimap_data(t_minimap *minimap);
/* allocates and initializes the minimap structure */
t_minimap	*create_minimap(t_game *game);
/* frees the minimap structure */
void		destroy_minimap(t_minimap *minimap);

/* computes the minimap scroll offset around the player */
void		calculate_minimap_offset(t_minimap *minimap, t_game *game);
/* maps minimap pixels into the destination buffer */
void		set_minimap_addresses(t_data *main_buffer, t_minimap *mmap,
				t_icoord *pos, t_icoord *dst);
/* draws the player marker and facing ray on the minimap */
void		render_player_and_ray(t_game *game, t_minimap *minimap);
/* renders the player icon inside the minimap buffer */
void		draw_player_on_minimap(t_minimap *minimap, t_game *game);

#endif