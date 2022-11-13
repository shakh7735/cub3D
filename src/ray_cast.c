/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakhge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:47:02 by eshakhge          #+#    #+#             */
/*   Updated: 2022/09/21 17:47:05 by eshakhge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	culc_delta(t_ray_cast *wall)
{
	if (wall->vector.x == 1)
		wall->delta.x = Size - (wall->ray.x - (int)(wall->ray.x / Size) * Size);
	else if (wall->vector.x == -1)
		wall->delta.x = wall->ray.x - ((int)(wall->ray.x / Size) * Size);
	else
		wall->delta.x = INT_MAX;
	if (wall->vector.y == 1)
		wall->delta.y = Size - (wall->ray.y - (int)(wall->ray.y / Size) * Size);
	else if (wall->vector.y == -1)
		wall->delta.y = wall->ray.y - ((int)(wall->ray.y / Size) * Size);
	else
		wall->delta.y = INT_MAX;
	if (wall->delta.x == 0 && wall->vector.x)
		wall->delta.x = Size;
	if (wall->delta.y == 0 && wall->vector.y)
		wall->delta.y = Size;
}

void	culc_ray2(t_ray_cast *wall)
{
	wall->ray.y += wall->delta.y * wall->vector.y;
	wall->ray.x += wall->delta.x * wall->vector.x;
	wall->map.y += wall->vector.y;
	wall->map.x += wall->vector.x;
	if (wall->wall_id == -1 && map.maps[wall->map.y][wall->map.x] == '1')
	{
		if (wall->vector.x == 1)
			wall->wall_id = 0;
		else if (wall->vector.x == -1)
			wall->wall_id = 2;
	}
}

void	culc_ray_if1(t_ray_cast *wall)
{
	wall->ray.x += wall->delta.x * wall->vector.x;
	wall->ray.y += sqrt(pow(wall->lenght.x, 2) - pow(wall->delta.x, 2)) * \
				wall->vector.y;
	wall->map.x += wall->vector.x;
	if (wall->vector.x == 1)
		wall->wall_id = 0;
	else if (wall->vector.x == -1)
		wall->wall_id = 2;
}

void	culc_ray_if2(t_ray_cast *wall)
{
	wall->ray.y += wall->delta.y * wall->vector.y;
	wall->ray.x += sqrt(pow(wall->lenght.y, 2) - pow(wall->delta.y, 2)) * \
	wall->vector.x;
	wall->map.y += wall->vector.y;
	if (wall->vector.y == 1)
		wall->wall_id = 1;
	else if (wall->vector.y == -1)
		wall->wall_id = 3;
}

void	culc_ray(t_ray_cast *wall)
{
	wall->lenght.x = fabs(wall->delta.x / cos((M_PI * wall->ray_angle) / 180));
	wall->lenght.y = fabs(wall->delta.y / sin((M_PI * wall->ray_angle) / 180));
	if ((wall->lenght.x < wall->lenght.y && wall->lenght.x != 0) \
			|| wall->lenght.y == 0)
	{
		culc_ray_if1(wall);
	}
	else if ((wall->lenght.y < wall->lenght.x && wall->lenght.y != 0) \
			|| wall->lenght.x == 0)
	{
		culc_ray_if2(wall);
	}
	else
		culc_ray2(wall);
}
