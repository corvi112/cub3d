/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acomet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 20:05:28 by acomet            #+#    #+#             */
/*   Updated: 2023/10/19 17:31:29 by acomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	initialize_window_begining(t_game *game)
{
	game->mlx = malloc(sizeof(t_mlx));
	if (!game->mlx)
		return (1);
	game->mlx->mlx = mlx_init(WIDTH, HEIGHT, "Rubikscube3D", false);
	if (!game->mlx->mlx)
	{
		ft_putstr_fd("mlx error init\n", 2);
		return (1);
	}
	game->mlx->mini_map = mlx_new_image(game->mlx->mlx, WIDTH, HEIGHT);
	if (!game->mlx->mini_map)
		return (1);
	if (mlx_image_to_window(game->mlx->mlx, game->mlx->mini_map, 0, 0) < 0)
	{
		ft_putstr_fd("mlx image window error\n", 2);
		return (1);
	}
	game->player = init_player(game);
	if (!game->player)
	{
		ft_putstr_fd("game player init error\n", 2);
		return (1);
	}
	return (0);
}

int	execution(t_game *game)
{
	if (initialize_window_begining(game))
		return (1);
	draw_cub(game);
	mlx_loop_hook(game->mlx->mlx, cub_hook, game);
	mlx_loop(game->mlx->mlx);
	return (0);
}
