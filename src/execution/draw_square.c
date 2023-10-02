/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acomet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 16:49:36 by acomet            #+#    #+#             */
/*   Updated: 2023/09/19 20:51:02 by acomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_square_grid(t_mlx *mlx, int x, int y, uint32_t color)
{
	int	x_max;
	int	y_max;

	x_max = x + SQUARE;
	y_max = y + SQUARE;
	x++;
	while (x < x_max)
	{
		y = y_max - SQUARE + 1;
		while (y < y_max)
		{
			mlx_put_pixel(mlx->mini_map, x, y, color);
			y++;
		}
		x++;
	}
}
