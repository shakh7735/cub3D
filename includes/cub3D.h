/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakhge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:46:13 by eshakhge          #+#    #+#             */
/*   Updated: 2022/09/21 12:46:39 by eshakhge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libs/printf/ft_printf.h"
# include "./world.h"
# include "keycode.h"
# include <math.h>
# include <limits.h>
# include <stdio.h>

# if defined(linux) || defined(__linux)
#  include "../libs/minilibx_linux/mlx.h"
# else
#  include "../libs/minilibx_mms/mlx.h"
# endif

enum e_constant
{
	Size = 1000,
	Ray = 60,
	Speed = 15,
	SpriteAnimationSpeed = 8,
	Step = Size * Speed / 100
};

typedef struct s_image
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		size_l;
	int		size_w;
}			t_image;

typedef struct s_pos
{
	float	x;
	float	y;
}			t_pos;

typedef struct s_vector
{
	int	x;
	int	y;
}			t_vector;

struct	s_player
{
	float		x;
	float		y;
	t_vector	vec;
	double		view;
}		player;

typedef struct s_quad
{
	int			quad;
	int			tg;
	t_vector	dir;
	t_vector	k;
	t_vector	s;
}				t_quad;

typedef struct s_wall
{
	int		side_x;
	int		scr_x;
	int		x;
	int		y;
	int		h;
	int		side;
	double	r;
	double	angle;
	t_quad	quad;
	t_pos	vector[2];
	int		id[2];
}			t_wall;

struct	s_map
{
	char	**maps;
	int		coins;
	int		coll_coins;
	int		x;
	int		y;
	char	*png_no;
	char	*png_so;
	char	*png_we;
	char	*png_ea;
	int		collor_f;
	int		collor_c;
}			map;

struct	s_temp
{
	int		x;
	int		y;
	int		scr_x;
	int		scr_y;
	int		maxh;
	t_image	image[4];
	t_image	spr_image[6];
	char	*spr_file[7];
	char	*file;
	char	coin[19];
	char	coin_count;
}			temp;

struct	s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		mouse_hide;
	int		mouse_x_old;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		spr_id;
}			data;

//maps
void	get_map(char *filename);
t_quad	get_quardrant(double angle);
void	draw_circle(t_minimap m);
void	draw_line(t_minimap m);
void	check_map(void);
void	get_positions(void);
void	ckeck_map_flood(void);
void	check_line(char *line);

//images
void	get_img(int id);
void	make_minimap(void);
void	ray_cast(void);
void	culc_delta(t_ray_cast *wall);
void	culc_ray(t_ray_cast *wall);

//keys
int		key_hook(int keycode);
int		mouse_move(int x);
int		check_wall_distance(double angle, t_pos vector[2], int id[2], \
							t_quad quad);
int		key_view_left(void);
int		key_view_right(void);

//utils
void	put_error(char *str);
char	*ft_strjoin_free(char *s1, char const *s2);
void	get_size(void);
int		close_prog(void);
void	congrats(void);
int		check_null(void);
void	go_begin(void);
void	animation_count(void);
void	free_mtx(char **buff);
int		get_rgb(char *line);
void	my_mlx_pixel_put(int x, int y, int color);
int		pixel_color(t_image image, int x, int y);
void	check_grad(double *grad);
void	check_angle_spr(double *angle);
int		get_num(const char *str);
void	get_player_view(void);
int		mouse_pos(int button);
void	open_wall_image(void);
char	*my_ft_strjoin(char const *s1, char *s2);

#endif
