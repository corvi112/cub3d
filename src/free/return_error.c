/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorvisi <ecorvisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 16:21:31 by ecorvisi          #+#    #+#             */
/*   Updated: 2023/10/19 14:04:44 by ecorvisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	return_error_texture(int error, char **tab, char *msg)
{
	ft_putstr_fd(msg, 2);
	if (tab != NULL)
		ft_free_tab(tab);
	return (error);
}
