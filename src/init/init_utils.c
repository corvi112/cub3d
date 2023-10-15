/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorvisi <ecorvisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 12:16:36 by ecorvisi          #+#    #+#             */
/*   Updated: 2023/10/03 15:14:57 by ecorvisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_check_if_error(t_game *game)
{
	if (game->floor->rgb_line == NULL || game->ceiling->rgb_line == NULL
		|| game->east->pathfile == NULL || game->west->pathfile == NULL
		|| game->north->pathfile == NULL || game->south->pathfile == NULL)
		return (1);
	return (0);
}
