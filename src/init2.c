/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorvisi <ecorvisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 23:24:43 by ecorvisi          #+#    #+#             */
/*   Updated: 2023/09/12 16:53:36 by ecorvisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	is_texture(char *str)
{
	if (ft_strncmp("NO", str, 2) == 0)
		return (0);
	else if (ft_strncmp("SO", str, 2) == 0)
		return (0);
	else if (ft_strncmp("WE", str, 2) == 0)
		return (0);
	else if (ft_strncmp("EA", str, 2) == 0)
		return (0);
	else if (ft_strncmp("F", str, 1) == 0)
		return (0);
	else if (ft_strncmp("C", str, 1) == 0)
		return (0);
	return (1);
}

void	ft_init_texture(char *str, t_texture *texture)
{
	int	i;

	i = 0;
	while (str[i] && is_white_space(str[i]) == 0)
		i++;
	while (str[i] && is_white_space(str[i]) == 1)
		i++;
	if (ft_strncmp("NO", str, 2) == 0)
		texture->north = ft_strdup_start(str, i);
	else if (ft_strncmp("SO", str, 2) == 0)
		texture->south = ft_strdup_start(str, i);
	else if (ft_strncmp("WE", str, 2) == 0)
		texture->west = ft_strdup_start(str, i);
	else if (ft_strncmp("EA", str, 2) == 0)
		texture->east = ft_strdup_start(str, i);
	else if (ft_strncmp("F", str, 1) == 0)
		texture->floor = ft_strdup_start(str, i);
	else if (ft_strncmp("C", str, 1) == 0)
		texture->ceiling = ft_strdup_start(str, i);
}

int	ft_init_game_2(t_game *game, char **split)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (split[i])
	{
		if (k == 6)
			break ;
		if (is_texture(split[i]) == 0)
		{
			ft_init_texture(split[i], game->texture);
			k++;
		}
		i++;
	}
	if (k < 6)
	{
		printf("error\n");	//msg d'erreur
		ft_free_tab(split);
		return (1);
	}
	while (split[i] && ft_strchr(split[i], '1') == NULL)
		i++;
	game->map = ft_strdup_tab_start(split, i);
	return (0);
}
