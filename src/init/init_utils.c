/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorvisi <ecorvisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 12:16:36 by ecorvisi          #+#    #+#             */
/*   Updated: 2023/10/19 16:51:10 by ecorvisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_if_wall(char *str)
{
	int	i;

	i = 0;
	if (is_texture(str) == 0)
		return (0);
	while (str[i])
	{
		if (str[i] == '1')
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_if_double_texture(t_game *game, char *str)
{
	int	i;

	i = 0;
	while (str[i] && is_white_space(str[i]) == 1)
		i++;
	if (strncmp("NO", &str[i], 2) == 0 && game->north->pathfile != NULL)
		return (1);
	if (strncmp("SO", &str[i], 2) == 0 && game->south->pathfile != NULL)
		return (1);
	if (strncmp("EA", &str[i], 2) == 0 && game->east->pathfile != NULL)
		return (1);
	if (strncmp("WE", &str[i], 2) == 0 && game->west->pathfile != NULL)
		return (1);
	if (strncmp("F", &str[i], 1) == 0 && game->floor->rgb_line != NULL)
		return (1);
	if (strncmp("C", &str[i], 1) == 0 && game->ceiling->rgb_line != NULL)
		return (1);
	return (0);
}

int	ft_check_if_error(t_game *game)
{
	if (game->floor->rgb_line == NULL || game->ceiling->rgb_line == NULL
		|| game->east->pathfile == NULL || game->west->pathfile == NULL
		|| game->north->pathfile == NULL || game->south->pathfile == NULL)
		return (return_error_texture(1, NULL, "Error\nTexture missing\n"));
	return (0);
}
