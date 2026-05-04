/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_rgb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 16:55:39 by bmoreira          #+#    #+#             */
/*   Updated: 2026/05/04 17:16:04 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

int	is_valid_rgb(char **rgb)
{
	int	num;
	int	i;

	i = 0;
	num = 0;
	if (ft_split_size(rgb) != 3)
		return (0);
	while (rgb[i])
	{
		num = ft_atoi(rgb[i]);
		if (num < 0 || num > 255)
			return (0);
		i++;
	}
	return (1);
}
