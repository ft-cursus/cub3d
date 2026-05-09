/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_validation.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 16:56:05 by bmoreira          #+#    #+#             */
/*   Updated: 2026/05/09 15:36:45 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_VALIDATION_H
# define CUB_VALIDATION_H

/* validation helpers for parsed scene data
 * used to verify identifiers, colors, textures, and overall map readiness
 */
/* checks whether all mandatory map elements were parsed */
int	is_valid_elements(t_map *map);
/* checks whether a token is a valid color identifier */
int	is_valid_color(char *id);
/* checks whether three RGB components are within range */
int	is_valid_rgb(char **rgb);
/* checks whether a token is a valid texture identifier */
int	is_valid_texture(char *id);

#endif