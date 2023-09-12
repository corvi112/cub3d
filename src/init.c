/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorvisi <ecorvisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:12:44 by ecorvisi          #+#    #+#             */
/*   Updated: 2023/09/11 23:42:17 by ecorvisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static char	**ft_addtab(char	**tab, char *str)
{
	int		i;
	char	**dup_tab;

	dup_tab = ft_calloc(ft_strlen_tab(tab) + 2, sizeof(char **));
	i = 0;
	while (tab[i])
	{
		dup_tab[i] = ft_strdup(tab[i]);
		i++;
	}
	dup_tab[i] = ft_strdup(str);
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (dup_tab);
}

char	**recover_file(char *str)
{
	int		fd;
	char	**split;
	char	*buffer;

	fd = open(str, O_RDWR);
	if (fd == -1)
	{
		printf("error\n");	//msg d'erreur
		return (NULL);
	}
	buffer = get_next_line_cub(fd);
	split = ft_calloc(sizeof (char **), 1);
	while (buffer)
	{
		split = ft_addtab(split, buffer);
		free(buffer);
		buffer = get_next_line_cub(fd);
	}
	return (split);
}

t_game	*ft_init_game(char *str)
{
	t_game	*game;
	char	**split;

	game = malloc(sizeof(t_game));
	game->texture = malloc(sizeof(t_texture));
	game->texture->north = NULL;
	game->texture->south = NULL;
	game->texture->east = NULL;
	game->texture->west = NULL;
	game->texture->floor = NULL;
	game->texture->ceiling = NULL;
	game->map = NULL;
	split = recover_file(str);
	if (!split || ft_init_game_2(game, split) == 1)
	{
		ft_free_game(game);
		return (NULL);
	}
	return (game);
}
