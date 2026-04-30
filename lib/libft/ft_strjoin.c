/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 11:58:56 by lsarraci          #+#    #+#             */
/*   Updated: 2026/04/30 20:18:59 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*s3;
	size_t		count;
	int			i;
	int			j;

	i = 0;
	j = 0;
	count = ft_strlen((char *)s2) + ft_strlen((char *)s1);
	s3 = (char *)malloc(count + 1 * sizeof(char));
	if (!s3)
		return (NULL);
	while (s1 && s1[i] != 0)
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2 && s2[j] != 0)
	{
		s3[i + j] = s2[j];
		j++;
	}
	s3[i + j] = 0;
	return (s3);
}
