/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_engine.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsarraci <lsarraci@student.42.fr>          +#+  +#+#+#+#+#+   +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 17:56:15 by lsarraci          #+#    #+#             */
/*   Updated: 2026/05/04 17:11:46 by lsarraci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_ENGINE_H
# define CUB_ENGINE_H

/* gameplay, collision, and raycasting engine helpers
 * covers player movement, DDA, ray tracing, and wall shading logic
 */
# include "cub_structs.h"

/* --------------------- directional movement functions ------------------- */

/* checks whether a world position is free of wall collisions */
int			is_position_walkable(t_map *map, float x, float y);
/* moves the player forward or backward while checking collisions */
void			move_player(t_player *player, t_map *map, float move_step);
/* moves the player sideways while checking collisions */
void			strafe_player(t_player *player, t_map *map, float move_step);
/* dispatches movement input to the correct motion handler */
void			set_directional_movement(int keycode, t_player *player,
					t_game *game);

/* ------------------- collision detection functions ------------------- */

/* converts a circular hitbox into a floating rectangle approximation */
void			player_to_frect(t_dcoord pos, float radius, t_frect *out);
/* samples a point inside a floating rectangle */
void			frect_sample_point(const t_frect *r, int i, int j,
						t_dcoord *out);
/* checks whether the sampled hitbox intersects a wall tile */
int			frect_collides_map(t_map *map, const t_frect *r, int i);
/* tests whether a player-sized hitbox collides with the map */
int			rect_collides(t_map *map, t_dcoord pos, float radius);

/* ----------------------- raycasting related functions ------------------ */

/* traces a ray through the grid and stores the hit point */
void			trace_ray(t_ray *ray, t_minimap *map, t_dcoord *hit_point);
/* draws the traced ray on the minimap */
void			draw_ray_on_minimap(t_ray *ray, t_minimap *map,
						t_dcoord *hit_point);
/* computes and renders a single minimap ray */
void			render_ray(t_ray *ray, t_minimap *map);
/* renders the player-facing ray used as the minimap center reference */
void			render_first_ray(t_player *player, t_minimap *map, t_ray *ray);

/* draws the player field-of-view rays to the target buffer */
void			draw_fov_rays(t_player *player, t_minimap *map, t_data *target);

/* ------------------- DDA related functions ------------------- */

/* initializes the DDA stepping values for a ray */
void			init_dda_variables(t_ray *ray, t_dcoord *rd, t_icoord *rmap,
						t_dcoord *delta_dist);
/* computes the initial side distances for DDA traversal */
void			calc_side_dist(t_dda *dda, t_dcoord ray_pos);
/* verifies whether the DDA walk is still inside the map */
int			check_bounds(t_dda *dda, t_minimap *map);
/* stores the final hit information for a traced ray */
void			update_ray_hit_data(t_ray *ray, t_dda *dda,
						t_dcoord *hit_point);
/* advances the DDA step along the next grid boundary */
void			update_ray_step(t_dda *dda);

/* ------------------- ray initialization functions ------------------- */

/* allocates the depth buffer used for wall rendering */
float			*init_zbuffer(t_game *game);
/* prepares the rendering data for one screen column */
void			init_column(t_column *col, int x, float perp, int screen_h);
/* initializes a ray from the player and the given angle */
void			init_ray(t_ray *ray, t_player *player, float ray_angle,
						t_data *target);
/* sets up the camera basis from the player state */
void			init_camera(t_camera *camera, t_player *player);

/* ----------------------- camera related functions ----------------------- */

/* rotates the camera direction and plane by the given angle */
void			rotate_camera(t_camera *camera, float angle);
/* moves the camera forward or backward with collision checks */
void			move_camera(t_camera *camera, t_map *map, float move_step);
/* computes the ray direction for a given screen column */
void			get_camera_ray(t_camera *camera, int x, t_ray *ray);
/* synchronizes the camera with the player position and angle */
void			update_camera(t_camera *camera, t_player *player);

/* ------------------- ray casting utilities ------------------- */

/* validates the input pointers before tracing a ray */
int			validate_trace_inputs(t_ray *ray, t_minimap *map,
						t_dcoord *hit_point);
/* computes the perpendicular distance used for projection */
float			perp_dist_from_proj(const t_ray *ray,
					const t_dcoord cam_dir_u);
/* converts distance into the visible wall slice height */
int			compute_line_height(int screen_h, float perp_dist);
/* clamps wall drawing limits to the screen bounds */
void			clamp_draw_bounds(int line_h, int screen_h,
					int *draw_start, int *draw_end);
/* returns the wall texture matching the ray hit direction */
t_image			*get_directional_texture(t_game *game);

/* ------------------- column related functions ------------------- */

/* casts and renders a single vertical wall slice */
void			cast_single_column(t_game *game, t_data *data,
						t_camera *camera, int x);
/* samples the final color for one pixel in the wall column */
unsigned int	get_column_color(t_game *game, t_column *col,
					 t_image *tex, int y);
/* paints the pixels for one raycasted wall column */
void			draw_column_pixels(t_game *game, t_data *data, t_column *col,
								 t_image *tex);
/* renders a wall slice for the current screen x coordinate */
void			render_wall_column(t_game *game, t_data *data, int x,
						float perp);

/* ------------------- color related functions ------------------- */

/* converts an RGB color structure to a packed integer */
unsigned int	color_to_hex(t_color color);
/* converts a packed integer into an RGB color structure */
t_color		hex_to_color(unsigned int hex);
/* darkens a color according to a shading factor */
t_color		apply_shade(t_color color, float shade);
/* darkens wall colors depending on the hit side */
t_color		apply_side_darkening(t_color color, int side);
/* computes a shading coefficient from distance and lighting settings */
float		calculate_shade_factor(float distance, float shadow_k,
					float light_intensity);

#endif