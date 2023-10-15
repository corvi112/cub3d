/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorvisi <ecorvisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 19:30:48 by ecorvisi          #+#    #+#             */
/*   Updated: 2023/10/03 15:18:55 by ecorvisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_rgb_texture(char *str)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (str[i])
	{
		if (str[i] == ',')
		{
			if (str[i + 1] != '\0' && str[i + 1] == ',')
				return (1);
			k++;
		}
		else if (ft_isdigit(str[i]) == 1)
			return (1);
		i++;
	}
	if (k > 2)
		return (1);
	return (0);
}

int	check_texture(t_game *game)
{
	if (check_rgb_texture(game->floor->rgb_line) == 1
		|| check_rgb_texture(game->ceiling->rgb_line) == 1)
	{
		ft_putstr_fd("Error\nNot valid RGB format\n", 2);
		return (1);
	}
	return (0);
}
