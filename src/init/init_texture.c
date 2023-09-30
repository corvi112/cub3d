/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorvisi <ecorvisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:40:21 by ecorvisi          #+#    #+#             */
/*   Updated: 2023/09/29 16:25:23 by ecorvisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	is_texture(char *str)
{
	int	i;

	i = 0;
	while (str[i] && is_white_space(str[i]) == 1)
		i++;
	if (str[i] == 'N' && str[i + 1] != '\0' && str[i + 1] == 'O')
		return (0);
	else if (str[i] == 'S' && str[i + 1] != '\0' && str[i + 1] == 'O')
		return (0);
	else if (str[i] == 'W' && str[i + 1] != '\0' && str[i + 1] == 'E')
		return (0);
	else if (str[i] == 'E' && str[i + 1] != '\0' && str[i + 1] == 'A')
		return (0);
	else if (str[i] == 'F')
		return (0);
	else if (str[i] == 'C')
		return (0);
	return (1);
}

void	ft_init_texture(char *str, t_game *game)
{
	int	i;
	int	k;

	i = 0;
	while (str[i] && is_white_space(str[i]) == 1)
		i++;
	k = i;
	while (str[i] && is_white_space(str[i]) == 0)
		i++;
	while (str[i] && is_white_space(str[i]) == 1)
		i++;
	if (str[k] == 'N' && str[k + 1] != '\0' && str[k + 1] == 'O')
		game->north->pathfile = ft_strdup_start(str, i);
	else if (str[k] == 'S' && str[k + 1] != '\0' && str[k + 1] == 'O')
		game->south->pathfile = ft_strdup_start(str, i);
	else if (str[k] == 'W' && str[k + 1] != '\0' && str[k + 1] == 'E')
		game->west->pathfile = ft_strdup_start(str, i);
	else if (str[k] == 'E' && str[k + 1] != '\0' && str[k + 1] == 'A')
		game->east->pathfile = ft_strdup_start(str, i);
	else if (str[k] == 'F')
		game->floor->rgb_line = ft_recover_rgb(str, i);
	else if (str[k] == 'C')
		game->ceiling->rgb_line = ft_recover_rgb(str, i);
}

int	check_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (is_white_space(str[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_if_texture(t_game *game, char **split)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (split[i])
	{
		if (k == 6)
			break ;
		if (is_texture(split[i]) == 0)
		{
			ft_init_texture(split[i], game);
			k++;
		}
		else if (check_line(split[i]) == 1)
			return (return_error_texture(-1, split,
					"Error\nNot only texture before map\n"));
		i++;
	}
	if (k < 6)
		return (return_error_texture(-1, split, "Error\nTexture missing\n"));
	return (i);
}

int	ft_init_game_texture(t_game *game, char **split)
{
	int	i;

	i = ft_check_if_texture(game, split);
	if (i == -1)
		return (1);
	if (!game->floor->rgb_line || !game->ceiling->rgb_line
		|| check_texture(game) == 1)
	{
		ft_free_tab(split);
		return (1);
	}
	ft_valid_rgb(game->floor);
	ft_valid_rgb(game->ceiling);
	while (split[i] && ft_strchr(split[i], '1') == NULL)
		i++;
	if (init_map(game, split, i) == 1)
	{
		ft_free_tab(split);
		return (1);
	}
	ft_free_tab(split);
	return (0);
}
