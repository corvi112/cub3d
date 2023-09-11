/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorvisi <ecorvisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:44:55 by ecorvisi          #+#    #+#             */
/*   Updated: 2023/09/08 14:55:40 by ecorvisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("error\n");
		return (1);
	}
	if (parsing(argv[1]) == 1)
		return (1);
	//check extansion de l'arg
	printf("%s\n", argv[1]);
	return (0);
}