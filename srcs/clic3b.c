/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clic3b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-batz <lde-batz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 17:58:05 by lde-batz          #+#    #+#             */
/*   Updated: 2019/01/18 18:37:48 by lde-batz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_proj_color(int x0, int y0, t_graph *win)
{
	int x;
	int	y;
	int i;

	i = -1;
	y = y0 + (win->key.color * 30);
	while (++i < 2)
	{
		x = x0 - 1;
		while (++x < x0 + 110)
			mlx_pixel_put(win->mlx, win->win, x, y, 0xff0000);
		y += 30;
	}
	x = x0;
	while (++i < 5)
	{
		y = y0 + (win->key.color * 30);
		while (++y < y0 + (win->key.color * 30) + 30)
			mlx_pixel_put(win->mlx, win->win, x, y, 0xff0000);
		x += 109;
	}
}

void	ft_print_clic3(t_graph *win)
{
	int	x;
	int	y;

	if ((x = win->key.clic1_x + 141) > WIN_W - 110)
		x -= 142 + 110;
	if ((y = win->key.clic1_y + 115) > WIN_H - 90)
		y -= 50;
	win->key.clic3_x = x;
	win->key.clic3_y = y;
	mlx_put_image_to_window(win->mlx, win->win, win->clic3.img_ptr, x, y);
	mlx_string_put(win->mlx, win->win, x + 10, y + 5, 0, "ORIGINAL");
	mlx_string_put(win->mlx, win->win, x + 10, y + 35, 0, "EARTH");
	mlx_string_put(win->mlx, win->win, x + 10, y + 65, 0, "GRADATION");
	ft_proj_color(x, y, win);
}

void	ft_proj3(int y, t_graph *win)
{
	int	i;
	int	j;

	i = 0;
	j = win->key.clic3_y + 30;
	while (j <= win->key.clic3_y + 90)
	{
		if (y < j)
		{
			win->key.color = i;
			j = win->key.clic3_y + 91;
		}
		j += 30;
		i++;
	}
	win->key.clic = 0;
	ft_print_map(win);
}

void	ft_clic3(void *param, int x, int y)
{
	t_graph	*win;

	win = param;
	if (x > win->key.clic3_x && x < win->key.clic3_x + 110
			&& y > win->key.clic3_y && y < win->key.clic3_y + 90)
		ft_proj3(y, win);
	else if (x > win->key.clic1_x && x < win->key.clic1_x
			+ 140 && y > win->key.clic1_y && y < win->key.clic1_y + 155)
	{
		ft_print_map(win);
		ft_print_clic1(win, win->key.clic1_x, win->key.clic1_y);
		ft_proj1(y, win);
	}
	else
	{
		win->key.clic = 0;
		ft_print_map(win);
	}
}
