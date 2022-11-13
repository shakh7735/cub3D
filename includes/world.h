/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakhge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:47:32 by eshakhge          #+#    #+#             */
/*   Updated: 2022/09/21 12:47:34 by eshakhge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_H
# define WORLD_H

typedef struct s_double_xy
{
	double	x;
	double	y;
}	t_double_xy;

typedef struct s_float_xy
{
	double	x;
	double	y;
}	t_float_xy;

typedef struct s_int_xy
{
	int	x;
	int	y;
}	t_int_xy;

typedef struct s_ray_cast
{
	t_double_xy		delta;
	t_float_xy		ray;
	t_double_xy		lenght;
	t_int_xy		map;
	t_int_xy		vector;
	double			ray_angle;
	double			step_angle;
	int				wall_id;
	int				x;
	int				y;
	int				h;
	unsigned int	color;

}					t_ray_cast;

typedef struct s_sprite
{
	t_double_xy		sprite;
	double			sprite_dist;
	double			angle;
	double			spr_size;
	int				start_x;
	int				end_x;
	t_ray_cast		wall;
	struct s_sprite	*next;
}				t_sprite;

typedef struct s_minimap
{
	int			min;
	int			size;
	int			collor;
	t_int_xy	count;
	t_double_xy	maps;
	t_double_xy	p;
	t_double_xy	step;
}				t_minimap;

t_sprite	*add_begin_sprite(t_sprite **sprite, t_ray_cast wall);
void		make_sprites(t_sprite **sprite);
void		init_vector(t_int_xy *vector, double angle);

#endif
