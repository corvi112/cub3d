/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acomet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 22:39:52 by acomet            #+#    #+#             */
/*   Updated: 2023/09/23 19:00:05 by acomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	cub_hook(void *param)
{
	t_game		*game;
	t_mlx		*mlx;
	t_player	*player;

	game = param;
	mlx = game->mlx;
	player = game->player;
	if (mlx_is_key_down(mlx->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx->mlx);
	player_directions(game, mlx, player);
	player_view_angle(mlx, player);
	draw_cub(game);
}
