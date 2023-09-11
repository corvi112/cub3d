/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorvisi <ecorvisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:54:00 by ecorvisi          #+#    #+#             */
/*   Updated: 2023/09/09 17:52:39 by ecorvisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef cub3D_H
# define cub3D_H

# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "get_next_line_cub.h"
# include "../libft/libft.h"

typedef struct	s_texture
{
	char	*floor;
	char	*ceiling;
	char	*north;
	char	*south;
	char	*west;
	char	*east;
}		t_texture;

typedef struct s_game
{
	char		**map;
	t_texture	*texture;
}		t_game;

void	ft_free_tab(char **str);
int		parsing(char *str);
t_game	*ft_init_game(char *str);

#endif
