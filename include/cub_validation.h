/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_validation.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 16:56:05 by bmoreira          #+#    #+#             */
/*   Updated: 2026/05/09 19:58:01 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_VALIDATION_H
# define CUB_VALIDATION_H

/* ----------validation functions---------- */

/*verify if the elements present in the map are valid*/
int	is_valid_elements(t_map *map);

/*verify if the color identifier is valid (F or C)*/
int	is_valid_color(char *id);

/*verify if the RGB values are valid (3 values between 0 and 255)*/
int	is_valid_rgb(char **rgb);

/*verify if the texture identifier is valid (NO, SO, WE, EA)*/
int	is_valid_texture(char *id);

/*verify if the character is allowed inside grid (N, S, W, E, 1, 0)*/
int	is_valid_map_char(char c);

#endif