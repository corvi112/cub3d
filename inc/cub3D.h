/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorvisi <ecorvisi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:54:00 by ecorvisi          #+#    #+#             */
/*   Updated: 2023/10/02 17:39:30 by acomet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include "get_next_line_cub.h"
# include "../libft/libft.h"
/* lib de mlx */
# include "../MLX42/include/MLX42/MLX42.h"
# include "../MLX42/include/MLX42/MLX42_Int.h"

# define PI 3.1415926535
// # define WIDTH 5120
// # define HEIGHT 2880
# define WIDTH 1024
# define HEIGHT 512
# define YELLOW 0xffff00ff
# define WHITE 0xffffffff
# define BLACK 0x000000ff
# define RED 0xff0000ff
# define GREEN 0x00ff00ff
# define PLAYER_SIZE 2
# define PLAYER_RAY_SIZE 10
# define SPEED 4
# define SQUARE 64
# define FOV 45
# define RAY_STEP_DEGREE 1

typedef struct s_ray
{
	float	dir_x;
	float	dir_y;
	float	step_length_x;
	float	step_length_y;
	float	length_x;
	float	length_y;
	float	length_final;
	int		step_x;
	int		step_y;
	int		map_check_x;
	int		map_check_y;
	int		end;
}		t_ray;

typedef struct s_coor
{
	int	x1;
	int	y1;
	int	x2;
	int	y2;
}		t_coor;

typedef struct s_mlx
{
	mlx_t		*mlx;
	mlx_image_t	*mini_map;
}		t_mlx;

typedef struct s_player
{
	float	px;
	float	py;
	float	pdx;
	float	pdy;
	float	pa;
	int		*x_max;
	int		y_max;
}		t_player;

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
	// void		*mlx;
	void		*win;
	char		**map;
	t_player	*player;
	t_mlx		*mlx;
	t_rgb		*floor;
	t_rgb		*ceiling;
	t_texture	*north;
	t_texture	*south;
	t_texture	*west;
	t_texture	*east;
}		t_game;

void	ft_free_tab(char **str);
t_game	*parsing(char *str);
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

/*	execution 66	*/
int			execution(t_game *game);

/*	hook	*/
void		cub_hook(void *param);

	/*	draw	*/
int			draw_cub(t_game	*game);

	/*	player	*/
t_player	*init_player(t_game *game);
void		draw_player(t_game *game, t_player *player);

		/*	player directions	*/
int			player_directions(t_game *game, t_mlx *mlx, t_player *player);

		/*	player view angle	*/
int			player_view_angle(t_mlx *mlx, t_player *player);

	/*	draw map	*/
void		draw_map(t_game *game);

	/*	draw square	*/
void		draw_square_grid(t_mlx *mlx, int x, int y, uint32_t color);

	/*	draw rubikscube	*/
void		draw_rubikscube(t_game *game, t_player *player);

	/*	draw rays	*/
void		draw_rays(t_game *game, t_player *player, t_ray *ray);

	/*	draw line	*/
void		draw_line(mlx_image_t *img, t_coor coor, uint32_t color);

	/*	utils	*/
int			movement_x_possible(char **map, t_player *player, t_coor coor);

#endif
