/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorvisi <ecorvisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:30:07 by ecorvisi          #+#    #+#             */
/*   Updated: 2023/09/11 23:41:18 by ecorvisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_free_tab(char **str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	ft_free_game(t_game *game)
{
	if (game->map != NULL)
		ft_free_tab(game->map);
	if (game->texture->north)
		free(game->texture->north);
	if (game->texture->south)
		free(game->texture->south);
	if (game->texture->east)
		free(game->texture->east);
	if (game->texture->west)
		free(game->texture->west);
	if (game->texture->floor)
		free(game->texture->floor);
	if (game->texture->ceiling)
		free(game->texture->ceiling);
	free(game->texture);
	free(game);
}
