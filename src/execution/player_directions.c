/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_directions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acomet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 19:09:47 by acomet            #+#    #+#             */
/*   Updated: 2023/10/01 20:47:59 by acomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	player_direction_forward(char **map, t_player *player)
{
	t_coor	coor;

	coor.x1 = player->px;
	coor.y1 = player->py;
	coor.x2 = player->px + (player->pdx * SPEED);
	coor.y2 = player->py + (player->pdy * SPEED);
	if (!movement_x_possible(map, player, coor))
	{
		player->px += player->pdx * SPEED;
		player->py += player->pdy * SPEED;
	}
	// if (movement_y_possible(map, player, coor))
		// player->py += player->pdy;
	return (0);
}

static int	player_direction_backward(char **map, t_player *player)
{
	t_coor	coor;

	coor.x1 = player->px;
	coor.y1 = player->py;
	coor.x2 = player->px - (player->pdx * SPEED);
	coor.y2 = player->py - (player->pdy * SPEED);
	if (!movement_x_possible(map, player, coor))
	{
		player->px -= player->pdx * SPEED;
		player->py -= player->pdy * SPEED;
	}
	return (0);
}

static int	player_direction_left(char **map, t_player *player)
{
	t_coor	coor;

	coor.x1 = player->px;
	coor.y1 = player->py;
	coor.x2 = player->px + cos(player->pa - (PI / 2)) * SPEED;
	coor.y2 = player->py + sin(player->pa - (PI / 2)) * SPEED;
	if (!movement_x_possible(map, player, coor))
	{
		player->px += cos(player->pa - (PI / 2)) * SPEED;
		player->py += sin(player->pa - (PI / 2)) * SPEED;
	}
	return (0);
}

static int	player_direction_right(char **map, t_player *player)
{
	t_coor	coor;

	coor.x1 = player->px;
	coor.y1 = player->py;
	coor.x2 = player->px + cos(player->pa + (PI / 2)) * SPEED;
	coor.y2 = player->py + sin(player->pa + (PI / 2)) * SPEED;
	if (!movement_x_possible(map, player, coor))
	{
		player->px += cos(player->pa + (PI / 2)) * SPEED;
		player->py += sin(player->pa + (PI / 2)) * SPEED;
	}
	return (0);
}

int	player_directions(t_game *game, t_mlx *mlx, t_player *player)
{
	if (mlx_is_key_down(mlx->mlx, MLX_KEY_W))
		player_direction_forward(game->map, player);
	if (mlx_is_key_down(mlx->mlx, MLX_KEY_S))
		player_direction_backward(game->map, player);
	if (mlx_is_key_down(mlx->mlx, MLX_KEY_A))
		player_direction_left(game->map, player);
	if (mlx_is_key_down(mlx->mlx, MLX_KEY_D))
		player_direction_right(game->map, player);
	return (0);
}
