/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakhge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:49:42 by eshakhge          #+#    #+#             */
/*   Updated: 2022/09/21 13:49:45 by eshakhge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	check_arg(int argc, char **argv)
{
	if (argc != 2)
		put_error("Not correct input");
	if (ft_strcmp(argv[1] + ft_strlen(argv[1]) - 4, ".cub"))
		put_error("The map is not in \".cub\" format");
}

int	render_next_frame(void)
{
	static int	i;

	if (!(++i % SpriteAnimationSpeed) && (++data.spr_id > 5))
		data.spr_id = 0;
	get_img(1);
	return (0);
}

int	event(void)
{
	printf("OK\n");
	return (0);
}

void	cub3d(void)
{
	printf("Ok\n");
	data.mlx = mlx_init();
	data.spr_id = 0;
	open_wall_image();
	mlx_get_screen_size(data.mlx, &temp.scr_x, &temp.scr_y);
	temp.scr_x /= 1.3;
	temp.scr_y /= 1.3;
	temp.maxh = temp.scr_y * Size;
	data.win = mlx_new_window(data.mlx, temp.scr_x, temp.scr_y, "Super_cub3D");
	get_img(0);
	mlx_do_key_autorepeaton(data.mlx);
	mlx_hook(data.win, 2, 1L << 0, key_hook, &data);
	mlx_hook(data.win, 6, 0L, mouse_move, &data);
	mlx_hook(data.win, 17, 0L, close_prog, &data);
	mlx_mouse_hook(data.win, mouse_pos, &data);
	mlx_loop_hook(data.mlx, render_next_frame, &data);
	mlx_loop(data.mlx);
}

int	main(int argc, char **argv)
{
	check_arg(argc, argv);
	temp.file = argv[1];
	get_map(temp.file);
	player.vec.y = 1;
	player.vec.x = 1;
	cub3d();
	return (0);
}
