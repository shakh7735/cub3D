/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_minimap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakhge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:31:15 by eshakhge          #+#    #+#             */
/*   Updated: 2022/09/21 16:31:17 by eshakhge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	check_map_wall(t_minimap m, int n)
{
	if (map.maps[(int)(m.maps.y / m.step.x)][(int)(m.maps.x / m.step.x)] == '1')
		my_mlx_pixel_put(m.min + m.size / 2 + n * m.count.y,
			m.min + m.size / 2 + m.count.x, m.collor);
	else if (map.maps[(int)(m.maps.y / m.step.x)]
		[(int)(m.maps.x / m.step.x)] == 'C')
		my_mlx_pixel_put(m.min + m.size / 2 + n * m.count.y,
			m.min + m.size / 2 + m.count.x, m.collor + 50000);
}

void	draw_walls_loop(t_minimap m)
{
	while (++m.count.y < m.step.y)
	{
		m.maps.x = m.p.x + m.count.y + m.step.x / 2;
		m.maps.y = m.p.y + m.count.x + m.step.x / 4;
		if (m.maps.x >= 0 && m.maps.y >= 0 && m.maps.x / m.step.x <= map.x && \
			m.maps.y / m.step.x < map.y)
			check_map_wall(m, 1);
		m.maps.x = m.p.x - m.count.y + m.step.x / 2;
		m.maps.y = m.p.y + m.count.x + m.step.x / 4;
		if (m.maps.x >= 0 && m.maps.y >= 0 && m.maps.x / m.step.x <= map.x && \
			m.maps.y / m.step.x < map.y)
			check_map_wall(m, -1);
	}
}

void	draw_walls(t_minimap m)
{
	m.step.x = m.size / 13;
	m.p.x = (int)player.x / Size * m.step.x;
	m.p.y = (int)player.y / Size * m.step.x;
	m.count.x = -m.size / 2;
	while (++m.count.x < m.size / 2)
	{
		m.step.y = sqrt(pow(m.size / 2, 2) - pow(m.count.x, 2));
		m.count.y = -1;
		draw_walls_loop(m);
	}
}

void	make_minimap(void)
{
	t_minimap	m_map;

	m_map.min = temp.scr_x / pow(2, 6);
	m_map.size = temp.scr_x / pow(2, 3);
	m_map.collor = get_rgb("0,0,0");
	draw_circle(m_map);
	m_map.collor = get_rgb("200,200,200");
	draw_walls(m_map);
	m_map.collor = get_rgb("255,0,0");
	draw_line(m_map);
}
