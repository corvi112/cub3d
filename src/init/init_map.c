/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorvisi <ecorvisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:37:53 by ecorvisi          #+#    #+#             */
/*   Updated: 2023/10/03 15:16:07 by ecorvisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_if_double_map(char **split, int i)
{
	int	j;
	int	boolean;

	j = i;
	boolean = 0;
	while (split[j])
	{
		if (ft_strchr(split[j], '1') == NULL)
			boolean = 1;
		if (boolean == 1 && ft_strchr(split[j], '1') != NULL)
			return (1);
		j++;
	}
	return (0);
}

int	init_map(t_game *game, char **split, int i)
{
	if (check_if_double_map(split, i) == 1)
	{
		ft_putstr_fd("Error\nDouble map detected\n", 2);
		return (1);
	}
	game->map = ft_strdup_tab_start(split, i);
	return (0);
}
