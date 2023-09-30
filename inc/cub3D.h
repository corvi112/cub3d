/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorvisi <ecorvisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:54:00 by ecorvisi          #+#    #+#             */
/*   Updated: 2023/09/30 17:42:11 by ecorvisi         ###   ########.fr       */
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

typedef struct s_rgb
{
	int		red;
	int		green;
	int		blue;
	char	*rgb_line;
}		t_rgb;

typedef struct s_texture
{
	char	*pathfile;
	void	*sprite;
}		t_texture;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		**map;
	t_rgb		*floor;
	t_rgb		*ceiling;
	t_texture	*north;
	t_texture	*south;
	t_texture	*west;
	t_texture	*east;
}		t_game;

void	ft_free_tab(char **str);
int		parsing(char *str);
t_game	*ft_init_game(char *str);
int		is_white_space(char c);
char	*ft_strdup_start(char *str, int start);
char	**ft_strdup_tab_start(char **tab, int start);
int		ft_init_game_texture(t_game *game, char **split);
void	ft_free_game(t_game *game);
int		is_allow(char c);
int		check_how_many(char **map);
int		check_around_0(char **map, int i, int j);
int		check_texture(t_game *game);
int		check_filename(char *str);
char	*ft_recover_rgb(char *str, int i);
char	*ft_strdup_cub(const char *s);
int		init_map(t_game *game, char **split, int i);
void	ft_valid_rgb(t_rgb *rgb);
int		return_error_texture(int error, char **tab, char *msg);



#endif
