/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakhge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:54:11 by eshakhge          #+#    #+#             */
/*   Updated: 2022/09/21 17:54:12 by eshakhge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	searh_struct_spr(t_sprite **sprite, t_ray_cast wall)
{
	t_sprite	*node;

	node = *sprite;
	while (node)
	{
		if (node && node->wall.map.x == wall.map.x && \
			node->wall.map.y == wall.map.y)
		{
			node->end_x = wall.x;
			return (1);
		}
		node = node->next;
	}
	return (0);
}

t_sprite	*add_begin_sprite(t_sprite **sprite, t_ray_cast wall)
{
	t_sprite	*node;

	if (searh_struct_spr(sprite, wall))
		return (*sprite);
	node = malloc(sizeof(t_sprite));
	node->sprite.x = (wall.map.x) * Size + Size / 2;
	node->sprite.y = (wall.map.y) * Size + Size / 2;
	node->sprite_dist = sqrt(pow(node->sprite.x - player.x, 2) + \
		pow(node->sprite.y - player.y, 2));
	node->spr_size = (int)(temp.scr_y / 4 / (node->sprite_dist / Size));
	node->start_x = wall.x;
	node->angle = player.view + (180 / M_PI * atan((node->sprite.y - player.y) \
		/ (node->sprite.x - player.x)));
	check_angle_spr(&node->angle);
	if (node->angle < -(Ray / 2 + node->spr_size * wall.step_angle / 2) || \
		node->angle > (Ray / 2 + node->spr_size * wall.step_angle / 2))
	{
		free(node);
		return (*sprite);
	}
	node->wall = wall;
	node->next = *sprite;
	return (node);
}

void	print_sprite(t_sprite *sprite)
{
	t_ray_cast	wall;
	int			i;
	int			j;

	wall = sprite->wall;
	wall.x = (sprite->angle) / Ray * (temp.scr_x) + (temp.scr_x / 2 - \
		sprite->spr_size / 2);
	wall.y = (int)(temp.scr_y / 2 - sprite->spr_size / 2);
	i = -1;
	while (++i < sprite->spr_size && wall.x + i < sprite->end_x)
	{
		if (wall.x + i < sprite->start_x)
			continue ;
		j = -1;
		while (++j < sprite->spr_size && wall.y + j < temp.scr_y)
		{
			wall.color = pixel_color(temp.spr_image[data.spr_id],
					temp.spr_image[data.spr_id].size_l / sprite->spr_size * i,
					temp.spr_image[data.spr_id].size_w / sprite->spr_size * j);
			if (wall.y + j < 0 || wall.color == 4278190080)
				continue ;
			my_mlx_pixel_put(wall.x + i, wall.y + j, wall.color);
		}
	}
}

int	coins_collected(t_sprite *spr)
{
	int	dist;

	dist = Size / 1.6;
	if (fabs(spr->sprite.x - player.x) < dist && \
		fabs(spr->sprite.y - player.y) < dist)
	{
		map.maps[spr->wall.map.y][spr->wall.map.x] = '0';
		map.coins--;
		map.coll_coins++;
		return (1);
	}
	return (0);
}

void	make_sprites(t_sprite **sprite)
{
	t_sprite	*node;

	while (*sprite)
	{
		node = (*sprite)->next;
		if (!coins_collected(*sprite))
			print_sprite(*sprite);
		free(*sprite);
		*sprite = node;
	}
}
