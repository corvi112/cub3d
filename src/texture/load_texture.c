/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorvisi <ecorvisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 19:25:13 by ecorvisi          #+#    #+#             */
/*   Updated: 2023/10/15 17:55:55 by ecorvisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	load_texture_png(t_game *game)
{
	game->north->png = mlx_load_png(game->north->pathfile);
	game->south->png = mlx_load_png(game->south->pathfile);
	game->east->png = mlx_load_png(game->east->pathfile);
	game->west->png = mlx_load_png(game->west->pathfile);
	return (0);
}

int	load_texture(t_game *game)
{
	if (check_png(game->north) == 1 || check_png(game->south) == 1
		|| check_png(game->east) == 1 || check_png(game->west) == 1
		|| check_if_exist(game) == 1)
			return (1);
	load_texture_png(game);
	if (check_size(game->north) == 1 || check_size(game->south) == 1
		|| check_size(game->east) == 1 || check_size(game->west) == 1)
			return (1);
	//check la taille de l'image
	return (0);
}
