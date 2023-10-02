/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_available.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acomet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 19:10:23 by acomet            #+#    #+#             */
/*   Updated: 2023/10/01 20:50:11 by acomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/* for the moment it doesn't handle the slide on walls */
int	movement_x_possible(char **map, t_player *player, t_coor coor)
{
	// /* we can remove the check WIDTH and HEIGHT because it's handle by the following one */
	if (coor.x2 < 0 || coor.y2 < 0)
		return (1);
	if (coor.y2 / SQUARE >= player->y_max || coor.x2 / SQUARE >= player->x_max[coor.y2 / SQUARE])
		return (1);
	if (map[coor.y2 / SQUARE][coor.x2 / SQUARE] == '0' || map[coor.y2 / SQUARE][coor.x2 / SQUARE] == 'N' || map[coor.y2 / SQUARE][coor.x2 / SQUARE] == 'E')
		return (0);
	return (1);
}

// int	movement_y_possible(char **map, t_player *player, t_coor coor)
// {
// 
// }
