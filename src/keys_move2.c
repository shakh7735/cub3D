/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_move2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakhge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:28:17 by eshakhge          #+#    #+#             */
/*   Updated: 2022/09/21 17:28:18 by eshakhge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_wall_distance(double angle, t_pos vector[2], int id[2], t_quad quad)
{
	double	r[2];

	vector[0].x = (int)player.x + quad.dir.x * id[0] * Size + \
		quad.s.x * Size - ((int)player.x % Size);
	vector[0].y = (int)player.y + (player.x - vector[0].x) * \
		tan(angle / 180 * M_PI);
	r[0] = sqrt(pow(player.x - vector[0].x, 2) + pow(player.y - \
			vector[0].y, 2));
	vector[1].y = (int)player.y + quad.dir.y * id[1] * Size + \
		quad.s.y * Size - ((int)player.y % Size);
	vector[1].x = (int)player.x + (player.y - vector[1].y) / \
		tan(angle / 180 * M_PI);
	r[1] = sqrt(pow(player.x - vector[1].x, 2) + pow(player.y - \
			vector[1].y, 2));
	if (r[0] < r[1])
	{
		if (++id[0] && map.maps[(int)((int)vector[0].y / Size)]
			[(int)((int)vector[0].x / Size) - (quad.s.x ^ 1)] == '1')
			return (r[0]);
	}
	else if (++id[1] && map.maps[(int)((int)vector[1].y / Size) - \
		(quad.s.y ^ 1)][(int)((int)vector[1].x / Size)] == '1')
		return (r[1]);
	return (check_wall_distance(angle, vector, id, quad));
}

int	key_view_left(void)
{
	player.view += Speed / 3;
	check_grad(&player.view);
	get_img(1);
	return (1);
}

int	key_view_right(void)
{
	player.view -= Speed / 3;
	check_grad(&player.view);
	get_img(1);
	return (1);
}
