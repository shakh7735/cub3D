/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Util_Mac.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakhge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 18:05:46 by eshakhge          #+#    #+#             */
/*   Updated: 2022/09/21 18:05:48 by eshakhge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	mouse_move(int x)
{
	if (data.mouse_hide)
	{
		if (x != temp.scr_x / 2)
			player.view += (temp.scr_x / 2 - x) / 4;
		if (player.view >= 360)
			player.view -= 360;
		else if (player.view < 0)
			player.view += 360;
		if (player.view > 0 && player.view < 180)
			player.vec.y = -1;
		else
		player.vec.y = 1;
		if (player.view > 90 && player.view < 270)
			player.vec.x = -1;
		else
		player.vec.x = 1;
		mlx_mouse_move(data.win, temp.scr_x / 2, temp.scr_y / 2);
	}
	return (0);
}

int	mouse_pos(int button)
{
	static int	id;

	if (button == 1 && button != id)
	{
		id = button;
		mlx_mouse_hide();
		data.mouse_hide = 1;
		mlx_mouse_move(data.win, temp.scr_x / 2, temp.scr_y / 2);
	}
	if (button == 2 && button != id)
	{
		id = button;
		mlx_mouse_show();
		data.mouse_hide = 0;
	}
	return (0);
}
