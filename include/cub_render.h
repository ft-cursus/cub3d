/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_render.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsarraci <lsarraci@student.42.fr>          +#+#+#+#+#+   +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 17:26:20 by lsarraci          #+#    #+#             */
/*   Updated: 2026/05/05 17:35:46 by lsarraci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_RENDER_H
# define CUB_RENDER_H

/* rendering primitives and frame composition
 * contains image drawing helpers, texture rendering, raycasting, and minimap composition
 */
# include "cub_structs.h"

/* ------------------ custom rendering functions ------------------ */

/* custom function to put a pixel on the screen */
/* writes a single pixel into the image buffer */
void			mlx_put_pixel(t_data *data, int x, int y, int color);

/* custom function to remove a pixel from the screen */
/* clears a single pixel in the image buffer */
void			mlx_remove_pixel(t_data *data, int x, int y);

/* function to clear the image buffer*/
/* fills the full image buffer with a solid color */
void		clear_buffer(t_data *data, int color);

/* function to draw a single line between two points
using Bresenham's line algorithm */
/* draws a line between two points using Bresenham's algorithm */
void		draw_line(t_data *data, t_icoord start, t_icoord end,
						int color);

/* function to draw a filled rectangle given a position,
dimensions, and color */
/* draws a filled rectangle and returns its generated geometry */
t_rectangle		draw_rectangle(t_data *data, t_icoord pos, t_dim dim,
						int color);

/* function to draw a empty circle given a center,
radius, and color */
/* draws a circle outline centered at the given position */
void			draw_circle(t_data *data, t_icoord center, int radius,
						int color);

/* function to draw a empty polygon given an array of points,
number of points, and color */
/* draws a polygon outline from the supplied vertex list */
void			draw_polygon(t_data *data, t_icoord *points,
						int num_points, int color);

/* function to render the current frame by putting the image to the window */
/* presents the prepared image buffer on the MLX window */
void			render_frame(t_data *data, void *mlx_ptr, void *win_ptr);

/* renders the floor and ceiling background for the current frame */
void			render_background(t_data *data, t_game *game);

/* function to free the pixel data and destroy the image */
/* destroys image resources and frees the pixel buffer wrapper */
void			free_pixel_data(t_data *data, void *mlx_ptr);

/* function to allocate and prepare image data */
/* allocates a new off-screen image and returns its pixel buffer */
t_data			*prepare_image_data(void *mlx_ptr, int width, int height);

/* ------------ helper functions for Bresenham's line algorithm --------------*/
/* computes the delta between two points */
t_icoord		calcule_delta(t_icoord start, t_icoord end);
/* computes the step direction for Bresenham traversal */
t_icoord		calcule_step(t_icoord start, t_icoord end);

/* -------- function to calculate the pivot points of a 
rectangle for rotation and scaling -------------------------*/

/* computes the rectangle pivot points used for transformations */
void			calculate_pivot_points(t_rectangle *rect);

/*----------------------- texture management functions ------------------ */

/* loads a texture from disk into an MLX image structure */
t_image			*load_texture(void *mlx_ptr, char *path);
/* draws a texture image at the requested position */
void			render_texture(t_data *data, t_image *texture, t_icoord pos);
/* fills a rectangle by sampling pixels from a texture */
void			draw_textured_rectangle(t_data *data, t_icoord pos, t_dim dim,
									 t_image *texture);
/* destroys a loaded texture and releases its memory */
void			remove_texture(void *mlx_ptr, t_image *texture);
/* selects the correct wall texture based on the ray hit side */
t_image			*get_directional_texture(t_game *game);

/*----------------------- raycasting layer functions ------------------ */

/* returns the normalized camera direction vector */
t_dcoord		camera_dir_unit(const t_camera *camera);
/* applies distance and side shading to a sampled pixel color */
unsigned int	sample_shade_pixel(unsigned int color, float dist,
					int side, const t_game *game);
/* casts rays for every screen column and renders wall slices */
void			cast_ray(t_game *game, t_data *data);

/* draws one tile onto the minimap buffer */
void			draw_tile_at(t_minimap *minimap, t_icoord pos,
						t_dim tile_dim, int color);
/* draws a map grid cell on the minimap */
void			draw_grid_tile(t_minimap *minimap, t_icoord grid_pos);

/* renders the minimap content into its off-screen buffer */
void			render_minimap(t_minimap *minimap, t_game *game);
/* blends the minimap buffer over the main frame buffer */
void			composite_minimap_to_main(t_data *main_buffer, t_minimap *minimap);

#endif