/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakhge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:09:46 by eshakhge          #+#    #+#             */
/*   Updated: 2022/09/21 17:09:51 by eshakhge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	key_down(void)
{
	t_pos	vector[2];
	int		id[2];

	vector[0].x = 0;
	vector[0].y = 0;
	vector[1].x = 0;
	vector[1].y = 0;
	id[0] = 0;
	id[1] = 0;
	if (check_wall_distance(player.view + 180, vector, id,
			get_quardrant(player.view + 180)) > Size / 5 + Step)
	{
		player.y += Step * sin(player.view / 180 * M_PI);
		player.x -= Step * cos(player.view / 180 * M_PI);
		get_img(1);
		return (1);
	}
	return (0);
}

int	key_up(void)
{
	t_pos	vector[2];
	int		id[2];

	vector[0].x = 0;
	vector[0].y = 0;
	vector[1].x = 0;
	vector[1].y = 0;
	id[0] = 0;
	id[1] = 0;
	if (check_wall_distance(player.view, vector, id,
			get_quardrant(player.view)) > Size / 5 + Step)
	{
		player.y -= Step * sin(player.view / 180 * M_PI);
		player.x += Step * cos(player.view / 180 * M_PI);
		get_img(1);
		return (1);
	}
	return (0);
}

int	key_left(void)
{
	t_pos	vector[2];
	int		id[2];

	vector[0].x = 0;
	vector[0].y = 0;
	vector[1].x = 0;
	vector[1].y = 0;
	id[0] = 0;
	id[1] = 0;
	if (check_wall_distance(player.view + 90, vector, id,
			get_quardrant(player.view + 90)) > Size / 5 + Step)
	{
		player.x -= Step * sin(player.view / 180 * M_PI);
		player.y -= Step * cos(player.view / 180 * M_PI);
		get_img(1);
		return (1);
	}
	return (0);
}

int	key_right(void)
{
	t_pos	vector[2];
	int		id[2];

	vector[0].x = 0;
	vector[0].y = 0;
	vector[1].x = 0;
	vector[1].y = 0;
	id[0] = 0;
	id[1] = 0;
	if (check_wall_distance(player.view - 90, vector, id,
			get_quardrant(player.view - 90)) > Size / 5 + Step)
	{
		player.x += Step * sin(player.view / 180 * M_PI);
		player.y += Step * cos(player.view / 180 * M_PI);
		get_img(1);
		return (1);
	}
	return (0);
}

int	key_hook(int keycode)
{
	if ((keycode == KEY_LEFT || keycode == KEY_Q) && key_view_left())
		;
	else if ((keycode == KEY_DOWN || keycode == KEY_S) && key_down())
		;
	else if ((keycode == KEY_RIGHT || keycode == KEY_E) && key_view_right())
		;
	else if ((keycode == KEY_UP || keycode == KEY_W) && key_up())
		;
	else if (keycode == KEY_A && key_left())
		;
	else if (keycode == KEY_D && key_right())
		;
	else if (keycode == KEY_ESC)
		close_prog();
	return (0);
}
