/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-batz <lde-batz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 14:17:16 by lde-batz          #+#    #+#             */
/*   Updated: 2019/01/19 16:49:17 by lde-batz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_init_graph2(t_graph *win)
{
	ft_new_img(&(win->control), mlx_new_image(win->mlx, 160, 250), 160);
	win->control.data = mlx_get_data_addr(win->control.img_ptr,
			&(win->control.bpp), &(win->control.w), &(win->control.endian));
	ft_img_control(&(win->control));
	ft_new_img(&(win->clic1), mlx_new_image(win->mlx, 140, 155), 140);
	win->clic1.data = mlx_get_data_addr(win->clic1.img_ptr,
			&(win->clic1.bpp), &(win->clic1.w), &(win->clic1.endian));
	ft_img_clic1(&(win->clic1));
	ft_new_img(&(win->clic2), mlx_new_image(win->mlx, 110, 240), 110);
	win->clic2.data = mlx_get_data_addr(win->clic2.img_ptr,
			&(win->clic2.bpp), &(win->clic2.w), &(win->clic2.endian));
	ft_img_clic2(&(win->clic2));
	ft_new_img(&(win->clic3), mlx_new_image(win->mlx, 110, 90), 110);
	win->clic3.data = mlx_get_data_addr(win->clic3.img_ptr,
			&(win->clic3.bpp), &(win->clic3.w), &(win->clic3.endian));
	ft_img_clic3(&(win->clic3));
	ft_init_key(&(win->key));
	ft_init_key_fct(win);
	ft_init_mouse_fct(win);
	ft_init_segment_fct(win);
}

void	ft_init_graph(char *argv, t_graph *win)
{
	int	fd;

	ft_init_map(win);
	if ((fd = open(argv, O_RDONLY)) < 0)
	{
		ft_putendl("usage : no file found");
		exit(EXIT_FAILURE);
	}
	if (!(ft_read_map(fd, win)))
	{
		ft_putendl("usage : invalid map");
		exit(EXIT_FAILURE);
	}
	ft_init_link(win);
	win->mlx = mlx_init();
	win->win = mlx_new_window(win->mlx, WIN_W, WIN_H, "FDF");
	ft_new_img(&(win->home), mlx_new_image(win->mlx, WIN_W, WIN_H), WIN_W);
	win->home.data = mlx_get_data_addr(win->home.img_ptr, &(win->home.bpp),
			&(win->home.w), &(win->home.endian));
	ft_img_home(&(win->home));
	ft_new_img(&(win->img), mlx_new_image(win->mlx, WIN_W, WIN_H), WIN_W);
	win->img.data = mlx_get_data_addr(win->img.img_ptr, &(win->img.bpp),
			&(win->img.w), &(win->img.endian));
	ft_init_graph2(win);
}
