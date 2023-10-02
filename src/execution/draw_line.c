/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acomet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 19:09:47 by acomet            #+#    #+#             */
/*   Updated: 2023/09/29 21:51:17 by acomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_line(mlx_image_t *img, t_coor coor, uint32_t color)
{
	float	x;
	float	y;
	float	dx;
	float	dy;
	float	length;

	if (abs(coor.x2 - coor.x1) >= abs(coor.y2 - coor.y1))
		length = abs(coor.x2 - coor.x1);
	else
		length = abs(coor.y2 - coor.y1);
	dx = (coor.x2 - coor.x1) / length;
	dy = (coor.y2 - coor.y1) / length;
	x = coor.x1;
	y = coor.y1;
	while (length)
	{
		if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
			mlx_put_pixel(img, x + 0.5, y + 0.5, color);
		x += dx;
		y += dy;
		length--;
	}
}
