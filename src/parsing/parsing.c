/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorvisi <ecorvisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 14:53:49 by ecorvisi          #+#    #+#             */
/*   Updated: 2023/09/12 16:54:51 by ecorvisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
		printf("c'est une erreur\n");
		return (1);
	}
	game = ft_init_game(str);
	if (!game)
		return (1);
	printf("texture NO = %s\ntexture SO = %s\ntexture EA = %s\ntexture WE = %s\ntexture F = %s\ntexture C = %s\n", game->texture->north, game->texture->south, game->texture->east, game->texture->west, game->texture->floor, game->texture->ceiling);
	int i = 0;
	while(game->map[i])
	{
		printf("|%s|\n", game->map[i]);
		i++;
	}
	printf("\n");
	return (0);
}