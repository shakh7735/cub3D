/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakhge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:09:54 by eshakhge          #+#    #+#             */
/*   Updated: 2022/09/21 16:09:56 by eshakhge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_vector(t_int_xy *vector, double angle)
{
	if ((angle < 90 && angle >= 0) || (angle < 360 && angle > 270))
		vector->x = 1;
	else
		vector->x = -1;
	if (angle < 180 && angle > 0)
		vector->y = -1;
	else
		vector->y = 1;
}

void	init_wall(t_ray_cast *wall)
{
	if (wall->ray_angle >= 360)
		wall->ray_angle -= 360;
	else if (wall->ray_angle < 0)
		wall->ray_angle += 360;
	wall->ray.x = player.x;
	wall->ray.y = player.y;
	init_vector(&wall->vector, wall->ray_angle);
	wall->map.x = player.x / Size;
	wall->map.y = player.y / Size;
	wall->wall_id = -1;
}

void	print_line(t_ray_cast wall)
{
	int	i;
	int	side;
	int	t;

	if (wall.wall_id == 1 || wall.wall_id == 3)
		side = (int)wall.ray.x % Size;
	else
		side = (int)wall.ray.y % Size;
	wall.h = temp.scr_y / (sqrt(pow((player.x - wall.ray.x), 2) + \
			pow((player.y - wall.ray.y), 2)) * \
			cos (M_PI * fabs(wall.ray_angle - player.view) / 180) / Size);
	t = 0;
	wall.y = 0;
	if (wall.h > temp.scr_y)
		t = (wall.h - temp.scr_y) / 2;
	else
		wall.y = (temp.scr_y - wall.h) / 2;
	i = -1;
	while (++i < wall.h && i < temp.scr_y)
	{
		wall.color = pixel_color(temp.image[wall.wall_id],
				(double)temp.image[wall.wall_id].size_l / Size * side,
				(i + t) * temp.image[wall.wall_id].size_w / wall.h);
		my_mlx_pixel_put(wall.x, wall.y + i, wall.color);
	}
}

void	ray_cast(void)
{
	t_ray_cast	wall;
	t_sprite	*sprite;

	sprite = NULL;
	wall.ray_angle = player.view + Ray / 2;
	wall.step_angle = (double)Ray / temp.scr_x;
	wall.x = -1;
	while (++wall.x <= temp.scr_x)
	{
		init_wall(&wall);
		while (map.maps[wall.map.y][wall.map.x] != '1')
		{
			culc_delta(&wall);
			culc_ray(&wall);
			if (map.maps[wall.map.y][wall.map.x] == 'C')
				sprite = add_begin_sprite(&sprite, wall);
		}
		print_line(wall);
		wall.ray_angle -= wall.step_angle;
	}
	make_sprites(&sprite);
}
