/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorvisi <ecorvisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:12:44 by ecorvisi          #+#    #+#             */
/*   Updated: 2023/09/11 18:23:55 by ecorvisi         ###   ########.fr       */
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



t_game	*ft_init_game(char *str)
{
	t_game	*game;
	char	**split;
	int		i;
	int		k;


	game = malloc(sizeof(t_game));
	game->texture = malloc(sizeof(t_texture));
	split = recover_file(str);
	if (!split)
		return (NULL);
	i = 0;
	k = 0;
	while(split[i])
	{
		if (k == 6)
			break ;
		if (is_texture(split[i]) == 0)
		{
			printf("texture = %s", split[i]);
			k++;
		}
		i++;
	}
	if (k < 6)
	{
		printf("error\n");	//msg d'erreur
		ft_free_tab(split);
		free(game->texture);
		free(game);
		return (NULL);
	}
	return (game);
}