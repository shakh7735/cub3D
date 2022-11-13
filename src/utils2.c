/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakhge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 18:15:24 by eshakhge          #+#    #+#             */
/*   Updated: 2022/09/21 18:15:26 by eshakhge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	get_rgb(char *line)
{
	int		*rgb;
	int		i;
	char	**arg;

	arg = ft_split(line, ',');
	if (!arg || !arg[0])
		put_error("not valid rgb args");
	i = -1;
	rgb = malloc(sizeof(int) * 3);
	while (arg[++i] && i < 3)
		rgb[i] = get_num(arg[i]);
	if (arg[i])
		put_error("not valid rgb args count");
	free_mtx(arg);
	i = rgb[0] * 256 * 256 + rgb[1] * 256 + rgb[2];
	free(rgb);
	return (i);
}

void	my_mlx_pixel_put(int x, int y, int color)
{
	char	*dst;

	dst = data.addr + (y * data.line_length + x * (data.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	pixel_color(t_image image, int x, int y)
{
	char			*dst;

	dst = image.addr + (y * image.line_length + x * (image.bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

void	check_grad(double *grad)
{
	if (*grad > 360)
		*grad -= 360;
	else if (*grad < 0)
		*grad += 360;
}

void	check_angle_spr(double *angle)
{
	if (*angle > 90)
		*angle -= 180;
	else if (*angle < -90)
		*angle += 180;
	else
		return ;
	check_angle_spr(angle);
}
