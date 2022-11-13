/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakhge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:58:11 by eshakhge          #+#    #+#             */
/*   Updated: 2022/09/21 16:58:13 by eshakhge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_quad	get_quardrant2(double angle, t_quad *quad)
{
	if (angle >= 180 && angle < 270)
	{
		quad->quad = 3;
		quad->tg = 1;
		quad->dir.x = -1;
		quad->dir.y = 1;
		quad->s.x = 0;
		quad->s.y = 1;
	}
	else
	{
		quad->quad = 1;
		quad->tg = -1;
		quad->dir.x = 1;
		quad->dir.y = 1;
		quad->s.x = 1;
		quad->s.y = 1;
	}
	return (*quad);
}

t_quad	get_quardrant(double angle)
{
	t_quad	quad;

	check_grad(&angle);
	if (angle >= 0 && angle < 90)
	{
		quad.quad = 1;
		quad.tg = 1;
		quad.dir.x = 1;
		quad.dir.y = -1;
		quad.s.x = 1;
		quad.s.y = 0;
	}
	else if (angle >= 90 && angle < 180)
	{
		quad.quad = 3;
		quad.tg = -1;
		quad.dir.x = -1;
		quad.dir.y = -1;
		quad.s.x = 0;
		quad.s.y = 0;
	}
	else
		return (get_quardrant2(angle, &quad));
	return (quad);
}

void	make_background(void)
{
	int		x;
	int		y;

	y = 0;
	while (y < temp.scr_y / 2)
	{
		x = -1;
		while (++x <= temp.scr_x)
			my_mlx_pixel_put(x, y, map.collor_c);
		y++;
	}
	while (y < temp.scr_y)
	{
		x = -1;
		while (++x <= temp.scr_x)
			my_mlx_pixel_put(x, y, map.collor_f);
		y++;
	}
}

void	put_parameters(void)
{
	char	*view;
	char	*x;
	char	*y;
	char	*total_c;
	char	*coins;

	view = my_ft_strjoin("view: ", ft_itoa((int)(player.view)));
	x = my_ft_strjoin("x: ", ft_itoa((int)(player.x / Size)));
	y = my_ft_strjoin("y: ", ft_itoa((int)(player.y / Size)));
	total_c = my_ft_strjoin("Total Coins: ", ft_itoa(map.coins));
	coins = my_ft_strjoin("Collected Coins: ", ft_itoa(map.coll_coins));
	mlx_string_put(data.mlx, data.win, 5, 15, 0xFF11111, view);
	mlx_string_put(data.mlx, data.win, 5, 30, 0xFF11111, x);
	mlx_string_put(data.mlx, data.win, 5, 45, 0xFF11111, y);
	mlx_string_put(data.mlx, data.win, 120, 15, 0xFF11111, total_c);
	mlx_string_put(data.mlx, data.win, 300, 15, 0xFF11111, coins);
	free(view);
	free(x);
	free(y);
	free(total_c);
	free(coins);
}

void	get_img(int id)
{
	if (id)
		mlx_destroy_image(data.mlx, data.img);
	data.img = mlx_new_image(data.mlx, temp.scr_x, temp.scr_y);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel,
			&data.line_length, &data.endian);
	make_background();
	ray_cast();
	make_minimap();
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	put_parameters();
	mlx_do_sync(data.mlx);
}
