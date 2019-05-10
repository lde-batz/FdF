/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clic2b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-batz <lde-batz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 17:48:55 by lde-batz          #+#    #+#             */
/*   Updated: 2019/01/18 18:37:14 by lde-batz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_proj_axono(int x0, int y0, t_graph *win)
{
	int x;
	int	y;
	int i;

	if (win->key.axono >= 0)
	{
		i = -1;
		y = y0 + (win->key.axono * 30);
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
			y = y0 + (win->key.axono * 30);
			while (++y < y0 + (win->key.axono * 30) + 30)
				mlx_pixel_put(win->mlx, win->win, x, y, 0xff0000);
			x += 109;
		}
	}
}

void	ft_print_clic2(t_graph *win)
{
	int	x;
	int	y;

	if ((x = win->key.clic1_x + 141) > WIN_W - 110)
		x -= 142 + 110;
	if ((y = win->key.clic1_y + 75) > WIN_H - 240)
		y -= 200;
	win->key.clic2_x = x;
	win->key.clic2_y = y;
	mlx_put_image_to_window(win->mlx, win->win, win->clic2.img_ptr, x, y);
	mlx_string_put(win->mlx, win->win, x + 10, y + 5, 0, "ELEVATION");
	mlx_string_put(win->mlx, win->win, x + 10, y + 35, 0, "PLAN");
	mlx_string_put(win->mlx, win->win, x + 10, y + 65, 0, "ISOMETRIC");
	mlx_string_put(win->mlx, win->win, x + 10, y + 95, 0, "DIMETRIC");
	mlx_string_put(win->mlx, win->win, x + 10, y + 125, 0, "TRIMETRIC");
	mlx_string_put(win->mlx, win->win, x + 10, y + 155, 0, "MILITARY");
	mlx_string_put(win->mlx, win->win, x + 10, y + 185, 0, "CAVALIER");
	mlx_string_put(win->mlx, win->win, x + 10, y + 215, 0, "TOP-DOWN");
	ft_proj_axono(x, y, win);
}

void	ft_proj2(int y, t_graph *win)
{
	int	i;
	int	j;

	i = 0;
	j = win->key.clic2_y + 30;
	while (j <= win->key.clic2_y + 240)
	{
		if (y < j)
		{
			win->key.axono = i;
			j = win->key.clic2_y + 241;
		}
		j += 30;
		i++;
	}
	win->key.home = 1;
	win->key.clic = 0;
	ft_print_map(win);
}

void	ft_clic2(void *param, int x, int y)
{
	t_graph	*win;

	win = param;
	if (x > win->key.clic2_x && x < win->key.clic2_x + 110
			&& y > win->key.clic2_y && y < win->key.clic2_y + 240)
		ft_proj2(y, win);
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
