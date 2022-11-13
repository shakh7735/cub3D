/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakhge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:46:30 by eshakhge          #+#    #+#             */
/*   Updated: 2022/09/21 17:46:32 by eshakhge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_quadrat(t_minimap m)
{
	int	i;
	int	size_x;
	int	size_y;

	size_x = m.size - m.size % map.x + 1;
	size_y = m.size - m.size % map.y + 1;
	i = 0;
	while (i <= size_x || i <= size_y)
	{
		if (i <= size_x)
		{
			my_mlx_pixel_put(m.min + i, m.min, m.collor);
			my_mlx_pixel_put(m.min + i, m.min + size_y, m.collor);
		}
		if (i <= size_y)
		{
			my_mlx_pixel_put(m.min, m.min + i, m.collor);
			my_mlx_pixel_put(m.min + size_x, m.min + i, m.collor);
		}
		i++;
	}
}

void	draw_circle(t_minimap m)
{
	int		i;
	int		j;
	int		r;
	double	row;

	r = m.size / 2;
	j = -1;
	while (++j <= r)
	{
		row = sqrt(pow(r, 2) - pow(j, 2));
		i = -1;
		while (++i <= row)
		{
			my_mlx_pixel_put(m.min + r + i, m.min + r - j, m.collor);
			my_mlx_pixel_put(m.min + r + i, m.min + r + j, m.collor);
			my_mlx_pixel_put(m.min + r - i, m.min + r - j, m.collor);
			my_mlx_pixel_put(m.min + r - i, m.min + r + j, m.collor);
		}
	}
}

void	draw_line(t_minimap m)
{
	int		j;
	double	angle;
	int		collor;

	angle = 1;
	while (angle < 360)
	{
		if (fabs(angle - player.view) < 8 * data.spr_id)
			collor = get_rgb("0,0,255");
		else
			collor = m.collor;
		m.step.x = cos(M_PI * angle / 180);
		m.step.y = sin(M_PI * angle / 180);
		j = -1;
		while (++j < m.min / 2)
			my_mlx_pixel_put(m.size / 2 + m.min + j * m.step.x, m.size / 2 + \
				m.min - j * m.step.y, collor);
		angle += (double)m.min / 360;
	}
}
