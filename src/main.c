/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorvisi <ecorvisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:44:55 by ecorvisi          #+#    #+#             */
/*   Updated: 2023/09/19 14:41:10 by ecorvisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	if (parsing(argv[1]) == 1)
		return (1);
	return (0);
}