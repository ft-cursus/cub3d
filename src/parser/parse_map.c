/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 20:09:00 by bmoreira          #+#    #+#             */
/*   Updated: 2026/04/29 20:16:08 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

void parse_map()
{

}

// ler cada linha do arquivo
// detectar se está no início ou final do arquivo (como?)
// se estiver no início do arquivo, verificar se elementos seguem padrão
// padrão: identificador-espaço-valor
// se identificador for do tipo orientação, verificar se valor é do tipo PATH
// se identificador for do tipo cor, verificar se valor é do tipo RGB
// verificar se cada elemento está separado por um ou mais quebras de linha
// ler todo o mapa para grid
// verificar se mapa está cercado por paredes
// verificar se há pelo menos um caminho válido no mapa
// verificar se não há mais elementos depois do mapa, e se chegou ao final do arquivo
// ao chegar no final do arquivo, checar se todos os elementos foram preenchidos