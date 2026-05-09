/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_structs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 15:35:12 by lsarraci          #+#    #+#             */
/*   Updated: 2026/05/09 15:41:36 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_STRUCTS_H
# define CUB_STRUCTS_H

/* project-wide data structures
 * groups the runtime state used by parsing, rendering, input, minimap, and raycasting
 */
# include "cub_types.h"

typedef struct s_render_cfg	t_render_cfg;
typedef struct s_window		t_window;
typedef struct s_game		t_game;
typedef struct s_map		t_map;
typedef struct s_minimap	t_minimap;
typedef struct s_player		t_player;
typedef struct s_camera		t_camera;
typedef struct s_column		t_column;
typedef struct s_wall_ctx	t_wall_ctx;
typedef struct s_ray		t_ray;
typedef struct s_dda		t_dda;
typedef struct s_wall		t_wall;
typedef struct s_illum		t_illum;
typedef struct s_data		t_data;
typedef struct s_line		t_line;
typedef struct s_frect		t_frect;
typedef struct s_rectangle	t_rectangle;
typedef struct s_sprite		t_sprite;
typedef struct s_image		t_image;
typedef struct s_timer		t_timer;
typedef struct s_input		t_input;

/*
img: pointer to the image created by mlx_new_image
tmp_img: pointer to a temporary image used for
off-screen rendering
addr: pointer to the memory area where the image data
can be accessed
bits_per_pixel: number of bits used to represent
each pixel in the image
line_length: number of bytes in a single row of the image
endian: indicates the endianness of the image data
(0 for little-endian, 1 for big-endian)
width: width of the image in pixels
height: height of the image in pixels
*/
struct s_data
{
	void	*img;
	void	*tmp_img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
};

/*
start: line start coordinate
end: line end coordinate
color: line color in packed hex
*/
struct s_line
{
	t_icoord	start;
	t_icoord	end;
	int			color;
};

/*
timeval: structure that holds the last recorded time
and the delta time between frames
last_time: the last recorded time, used to calculate
the time difference between frames
delta_time: the time difference between the current
frame and the last recorded time,
used for timing and animation purposes
*/
struct s_timer
{
	struct timeval	last_time;
	float			delta_time;
};

/*
left: arrow left pressed
right: arrow right pressed
up: arrow up pressed
down: arrow down pressed
w: move forward pressed
a: strafe left pressed
s: move backward pressed
d: strafe right pressed
*/
struct s_input
{
	int	left;
	int	right;
	int	up;
	int	down;
	int	w;
	int	a;
	int	s;
	int	d;
};

/*
img_ptr: MLX image handle
path: texture file path
addr: pointer to raw pixel data
data: cached image metadata
dim: image dimensions in pixels
*/
struct s_image
{
	void	*img_ptr;
	char	*path;
	char	*addr;
	t_data	data;
	t_dim	dim;
};

/*
fog_distance: max distance before fog fully applies
ray_distance: max ray distance for rendering
light_intensity: global light strength
shadow_factor: shadow contribution factor
shade: current shade multiplier
shadow_k: shadow curve coefficient
max_render_distance: render cutoff distance
render_quality: quality level for rendering
base_color: base RGB color for shading
shade_color: shaded RGB color
tex_color: texture RGB color
shaded_hex: final shaded color packed as hex
*/
struct s_render_cfg
{
	float			fog_distance;
	float			ray_distance;
	float			light_intensity;
	float			shadow_factor;
	float			shade;
	float			shadow_k;
	int				max_render_distance;
	int				render_quality;
	t_color			base_color;
	t_color			shade_color;
	t_color			tex_color;
	unsigned int	shaded_hex;
};

/*
x: screen column index
line_h: projected wall slice height
perp: perpendicular distance to wall
tex_x: texture column index
screen_h: screen height used for projection
*/
struct s_column
{
	int			x;
	int			line_h;
	float		perp;
	int			tex_x;
	int			screen_h;
};

/*
wall_x: horizontal hit position on the wall
texture: texture selected for the hit side
tex_x: texture column index
hit_side: which side of the wall was hit
*/
struct s_wall_ctx
{
	double	wall_x;
	t_image	*texture;
	int		tex_x;
	int		hit_side;
};

/*
north_texture: loaded north wall texture
south_texture: loaded south wall texture
west_texture: loaded west wall texture
east_texture: loaded east wall texture
north_path: north texture file path
south_path: south texture file path
west_path: west texture file path
east_path: east texture file path
grid: map grid rows
dim: map dimensions in tiles
floor_color: floor color in packed hex
ceiling_color: ceiling color in packed hex
*/
struct s_map
{
	t_image			*north_texture;
	t_image			*south_texture;
	t_image			*west_texture;
	t_image			*east_texture;
	char			*north_path;
	char			*south_path;
	char			*west_path;
	char			*east_path;
	char			**grid;
	t_dim			dim;
	unsigned int	floor_color;
	unsigned int	ceiling_color;
};

/*
data: target image buffer
player: player state reference
pos: ray position in grid coords
dir: ray direction in grid coords
fpos: ray position in world coords
fdir: ray direction in world coords
hit: hit point in world coords
length: total ray length
hit_wall: wall hit flag
hit_sprite: sprite hit flag
hit_side: wall side hit
color: final hit color
*/
struct s_ray
{
	t_data		*data;
	t_player	*player;
	t_icoord	pos;
	t_icoord	dir;
	t_dcoord	fpos;
	t_dcoord	fdir;
	t_dcoord	hit;
	float		length;
	int			hit_wall;
	int			hit_sprite;
	int			hit_side;
	int			color;
};

/*
rmap: current grid position
rd: ray direction
delta_dist: distance to next side in each axis
side_dist: accumulated side distance
step: grid step direction
hit: hit flag
side: hit side index
*/
struct s_dda
{
	t_icoord	rmap;
	t_dcoord	rd;
	t_dcoord	delta_dist;
	t_dcoord	side_dist;
	t_icoord	step;
	int			hit;
	int			side;
};

/*
pos: camera position
dir: camera direction
plane: camera projection plane
screen_dim: screen dimensions
inv_screen_width: inverse of screen width
*/
struct s_camera
{
	t_dcoord	pos;
	t_dcoord	dir;
	t_dcoord	plane;
	t_icoord	screen_dim;
	float		inv_screen_width;
};

/*
pos: player position in world coords
dim: player dimensions
color: player color
ray: player-facing ray data
angle: player viewing angle
collision_radius: player collision radius
orientation: spawn orientation
*/
struct s_player
{
	t_dcoord	pos;
	t_dim		dim;
	int			color;
	t_ray		ray;
	float		angle;
	float		collision_radius;
	char		orientation;
};

/*
buffer: structure that holds the minimap's image data and dimensions
mlx_ptr: pointer to the MLX instance, used for all MLX operations
dim: dimensions of the minimap
ref_map: reference to the main game map, used to determine what to render
pos: position of the minimap on the screen
offset: offset to center the minimap around the player
player_pos: current position of the player, used to calculate
the player's position on the minimap
scale: scaling factor to adjust the size of the minimap
*/
struct s_minimap
{
	t_data		*buffer;
	void		*mlx_ptr;
	t_dim		dim;
	t_map		*ref_map;
	t_icoord	pos;
	t_icoord	offset;
	t_icoord	player_pos;
	float		scale;
};

/*
pos: rectangle position
dim: rectangle dimensions
color: rectangle color
points: rectangle corner and pivot points
*/
struct s_rectangle
{
	t_icoord	pos;
	t_dim		dim;
	int			color;
	t_icoord	points[9];
};

/*
x: rectangle x position
y: rectangle y position
pos: rectangle position in world coords
dim: rectangle dimensions
width: rectangle width
height: rectangle height
points: sampled points for collision checks
*/
struct s_frect
{
	float		x;
	float		y;
	t_dcoord	pos;
	t_dim		dim;
	float		width;
	float		height;
	int			points[9];
};

/*
pos: sprite position
dim: sprite dimensions
texture: sprite texture
color: sprite color
rotation: sprite rotation
*/
struct s_sprite
{
	t_icoord	pos;
	t_dim		dim;
	t_image		*texture;
	int			color;
	int			rotation;
};

/*
mlx_ptr: pointer to the MLX instance,
used for all MLX operations
win_ptr: pointer to the window created by MLX,
used for rendering and event handling
img_ptr: main image buffer wrapper
*/
struct s_window
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_data	*img_ptr;
};

/*
window: MLX window wrapper
timer: frame timing data
input: current input state
player: player state
player_rect: collision rect for player
map: parsed map data
ray: shared ray state
config: render configuration
minimap: minimap state
map_file: path to the loaded map
z_buffer: depth buffer for wall rendering
*/
struct s_game
{
	t_window		*window;
	t_timer			timer;
	t_input			input;
	t_player		*player;
	t_frect			player_rect;
	t_map			*map;
	t_ray			ray;
	t_render_cfg	config;
	t_minimap		*minimap;
	char			*map_file;
	float			*z_buffer;
};

#endif