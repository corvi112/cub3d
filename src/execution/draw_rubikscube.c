/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rubikscube.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acomet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 21:04:40 by acomet            #+#    #+#             */
/*   Updated: 2023/10/15 21:33:25 by acomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	draw_rubikscube_algo(t_game *game, t_ray ray, int starting_x,
		float player_angle)
{
	t_coor	coor;
	float	line_h;

	line_h = (SQUARE_MAP * HEIGHT) / (cos(player_angle) * ray.length_final);
	if (line_h > HEIGHT)
		line_h = HEIGHT;
	coor.x1 = starting_x;
	coor.x2 = starting_x;
	coor.y1 = (HEIGHT + line_h) / 2;
	coor.y2 = (HEIGHT - line_h) / 2;
	draw_line(game->mlx->mini_map, coor, RED);
}

static void	draw_rubikscube_recursive(t_game *game, t_player *player,
		float angle_incr, int i)
{
	t_ray	ray;

	ray.dir_x = cos(player->pa + (i * angle_incr));
	ray.dir_y = sin(player->pa + (i * angle_incr));
	draw_rays(game, player, &ray);
	draw_rubikscube_algo(game, ray, i + (WIDTH / 2), i * angle_incr);
	if (i <= WIDTH / 2)
		draw_rubikscube_recursive(game, player, angle_incr, ++i);
	if (i == WIDTH / 2)
	{
		draw_map(game, game->player);
		draw_player(game->mlx->mini_map);
	}
	if (i % 20 == 0)
		assign_coor_draw_line(game, ray);
}

void	draw_rubikscube(t_game *game, t_player *player)
{
	int		i;
	float	angle_incr;

	i = (-WIDTH) / 2;
	angle_incr = FOV * 2;
	angle_incr = angle_incr / WIDTH * PI / 180;
	draw_rubikscube_recursive(game, player, angle_incr, i);
}
