/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-batz <lde-batz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 14:08:44 by lde-batz          #+#    #+#             */
/*   Updated: 2019/01/19 11:31:59 by lde-batz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	t_graph	win;

	if (argc != 2)
	{
		ft_putendl("usage : fillit input_file");
		exit(EXIT_FAILURE);
	}
	ft_init_graph(argv[1], &win);
	mlx_put_image_to_window(win.mlx, win.win, win.home.img_ptr, 0, 0);
	mlx_string_put(win.mlx, win.win, 1225, 647, 16777215, "PRESS A KEY");
	mlx_hook(win.win, 2, 0, ft_press_key, &win);
	mlx_hook(win.win, 4, 0, ft_click_mouse, &win);
	mlx_loop(win.mlx);
	return (0);
}
