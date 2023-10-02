/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acomet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 18:26:42 by acomet            #+#    #+#             */
/*   Updated: 2023/09/22 23:00:19 by acomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '0')
				draw_square_grid(game->mlx, x * SQUARE, y * SQUARE, BLACK);
			else if (game->map[y][x] == '1')
				draw_square_grid(game->mlx, x * SQUARE, y * SQUARE, WHITE);
			else if (game->map[y][x] == 'N' || game->map[y][x] == 'S'
					|| game->map[y][x] == 'E' || game->map[y][x] == 'W')
				draw_square_grid(game->mlx, x * SQUARE, y * SQUARE, BLACK);
			x++;
		}
		y++;
	}
}
