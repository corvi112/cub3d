/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorvisi <ecorvisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:54:00 by ecorvisi          #+#    #+#             */
/*   Updated: 2023/09/11 23:38:08 by ecorvisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "get_next_line_cub.h"
# include "../libft/libft.h"

typedef struct s_texture
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
int		is_white_space(char c);
char	*ft_strdup_start(char *str, int start);
char	**ft_strdup_tab_start(char **tab, int start);
int		ft_init_game_2(t_game *game, char **split);
void	ft_free_game(t_game *game);

#endif
