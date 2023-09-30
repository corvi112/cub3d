/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorvisi <ecorvisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 14:53:49 by ecorvisi          #+#    #+#             */
/*   Updated: 2023/09/27 19:30:11 by ecorvisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_forbidden_c(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if (is_allow(map[i][j]) == 1)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_map_playable(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (check_around_0(map, i, j) == 1)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_map(t_game *game)
{
	if (check_forbidden_c(game->map) == 1)
	{
		ft_putstr_fd("Error\nForbidden character\n", 2);
		return (1);
	}
	if (check_how_many(game->map) == 1)
	{
		ft_putstr_fd("Error\nToo many player\n", 2);
		return (1);
	}
	if (check_map_playable(game->map) == 1)
	{
		ft_putstr_fd("Error\nMap is not playable\n", 2);
		return (1);
	}
	return (0);
}

int	check_extention(char *str)
{
	int		i;
	int		j;
	char	*strr;

	j = 0;
	i = ft_strlen(str) - 1;
	strr = ft_calloc(ft_strlen(str) + 1, sizeof(char));
	while (i >= 0)
	{
		strr[j] = str[i];
		i--;
		j++;
	}
	if (ft_strncmp("buc.", strr, 4) != 0 || strr[4] == '.')
	{
		free(strr);
		return (1);
	}
	free(strr);
	return (0);
}

int	parsing(char *str)
{
	t_game	*game;

	
	if (check_extention(str) == 1)
	{
		ft_putstr_fd("Error\nThe file is not an extension '.cub'\n", 2);
		return (1);
	}
	if (check_filename(str) == 1)
	{
		ft_putstr_fd("Error\nThe file name is not allow\n", 2);
		return (1);
	}
	game = ft_init_game(str);
	if (!game)
		return (1);
	if (check_map(game) == 1)
		return (1);
	printf("texture NO = %s\ntexture SO = %s\ntexture EA = %s\ntexture WE = %s\n", game->north->pathfile, game->south->pathfile, game->east->pathfile, game->west->pathfile);
	printf("---------------\n|    FLOOR    |\n---------------\n\n	RED = %i\n	GREEN = %i\n	BLUE = %i\n---------------\n|   CEILING   |\n---------------\n\n	RED = %i\n	GREEN = %i\n	BLUE = %i\n",game->floor->red, game->floor->green, game->floor->blue, game->ceiling->red, game->ceiling->green, game->ceiling->blue);
	int i = 0;
	while(game->map[i])
	{
		printf("%s\n", game->map[i]);
		i++;
	}
	printf("\n");
	return (0);
}