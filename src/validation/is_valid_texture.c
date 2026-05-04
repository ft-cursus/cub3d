/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 16:54:39 by bmoreira          #+#    #+#             */
/*   Updated: 2026/05/04 16:58:33 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

int	is_valid_texture(char *id)
{
	return (ft_strcmp(id, "NO")
		|| ft_strcmp(id, "SO")
		|| ft_strcmp(id, "WE")
		|| ft_strcmp(id, "EA"));
}
