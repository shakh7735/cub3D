/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_open.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakhge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:57:36 by eshakhge          #+#    #+#             */
/*   Updated: 2022/09/21 16:57:38 by eshakhge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	check_image_open(void)
{
	int	fd;

	fd = open(map.png_no, O_RDONLY);
	if (fd == -1)
		put_error("Bad file discriptor of wall NO");
	close(fd);
	fd = open(map.png_ea, O_RDONLY);
	if (fd == -1)
		put_error("Bad file discriptor of wall EA");
	close(fd);
	fd = open(map.png_so, O_RDONLY);
	if (fd == -1)
		put_error("Bad file discriptor of wall SO");
	close(fd);
	fd = open(map.png_we, O_RDONLY);
	if (fd == -1)
		put_error("Bad file discriptor of wall WE");
	close(fd);
}

void	init_sprite_file(void)
{
	int	i;

	temp.spr_file[0] = ft_strdup("./png/mon1.xpm");
	temp.spr_file[1] = ft_strdup("./png/mon2.xpm");
	temp.spr_file[2] = ft_strdup("./png/mon3.xpm");
	temp.spr_file[3] = ft_strdup("./png/mon4.xpm");
	temp.spr_file[4] = ft_strdup("./png/mon5.xpm");
	temp.spr_file[5] = ft_strdup("./png/mon6.xpm");
	temp.spr_file[6] = NULL;
	i = -1;
	while (++i < 6)
	{
		temp.spr_image[i].img = mlx_xpm_file_to_image(data.mlx,
				temp.spr_file[i], &temp.spr_image[i].size_l,
				&temp.spr_image[i].size_w);
		temp.spr_image[i].addr = mlx_get_data_addr(temp.spr_image[i].img,
				&temp.spr_image[i].bits_per_pixel,
				&temp.spr_image[i].line_length, &temp.spr_image[i].endian);
	}
}

void	open_wall_image(void)
{
	check_image_open();
	temp.image[0].img = mlx_xpm_file_to_image(data.mlx, map.png_ea,
			&temp.image[0].size_l, &temp.image[0].size_w);
	temp.image[0].addr = mlx_get_data_addr(temp.image[0].img,
			&temp.image[0].bits_per_pixel, &temp.image[0].line_length,
			&temp.image[0].endian);
	temp.image[1].img = mlx_xpm_file_to_image(data.mlx, map.png_so,
			&temp.image[1].size_l, &temp.image[1].size_w);
	temp.image[1].addr = mlx_get_data_addr(temp.image[1].img,
			&temp.image[1].bits_per_pixel,
			&temp.image[1].line_length, &temp.image[1].endian);
	temp.image[2].img = mlx_xpm_file_to_image(data.mlx, map.png_we,
			&temp.image[2].size_l, &temp.image[2].size_w);
	temp.image[2].addr = mlx_get_data_addr(temp.image[2].img,
			&temp.image[2].bits_per_pixel,
			&temp.image[2].line_length, &temp.image[2].endian);
	temp.image[3].img = mlx_xpm_file_to_image(data.mlx, map.png_no,
			&temp.image[3].size_l, &temp.image[3].size_w);
	temp.image[3].addr = mlx_get_data_addr(temp.image[3].img,
			&temp.image[3].bits_per_pixel,
			&temp.image[3].line_length, &temp.image[3].endian);
	init_sprite_file();
}
