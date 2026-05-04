/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 20:17:59 by bmoreira          #+#    #+#             */
/*   Updated: 2026/05/04 16:34:39 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_PARSER_H
# define CUB_PARSER_H

# include "cub_structs.h"
# include <fcntl.h>

typedef enum e_exit_code
{
	READ_FILE,
	INVALID_ELEMENT,
	INVALID_COLOR,
}	t_exit_code;

#endif