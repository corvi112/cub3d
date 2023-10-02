/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rubikscube.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acomet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 21:04:40 by acomet            #+#    #+#             */
/*   Updated: 2023/10/02 15:59:42 by acomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_rubikscube_algo(t_game *game, t_ray ray, float line_width, int starting_x, float player_angle)
{
	t_coor	coor;
	float	line_h;
	int		end;

	line_h = (SQUARE * HEIGHT) / (cos(player_angle) * ray.length_final);
	if (line_h > HEIGHT)
		line_h = HEIGHT;
	end = starting_x + line_width + 0.5;
	while (starting_x < end)
	{
		coor.x1 = starting_x;
		coor.x2 = starting_x;
		coor.y1 = (HEIGHT / 4) + (line_h / 4);
		coor.y2 = (HEIGHT / 4) - (line_h / 4);
		draw_line(game->mlx->mini_map, coor, RED);
		starting_x++;
	}
}

void	draw_rubikscube(t_game *game, t_player *player)
{
	t_ray	ray;
	float	i;
	float	line_width;
	float	starting_x;

	i = -FOV;
	starting_x = WIDTH / 2;
	while (i <= FOV)
	{
		ray.dir_x = cos(player->pa + (i * PI / 180));
		ray.dir_y = sin(player->pa + (i * PI / 180));
		draw_rays(game, player, &ray);
		line_width = WIDTH / 2 / (FOV * 2 / RAY_STEP_DEGREE);
		draw_rubikscube_algo(game, ray, line_width, starting_x + 0.5, i * PI / 180);
		i += RAY_STEP_DEGREE;
		starting_x += line_width;
	}
}
