/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clic1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-batz <lde-batz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 17:33:59 by lde-batz          #+#    #+#             */
/*   Updated: 2019/01/19 16:32:45 by lde-batz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_img_clic1b(t_img *img)
{
	int		x;
	int		y;
	short	gris;

	y = 69;
	gris = 180;
	while (++y < 75)
	{
		x = -1;
		while (++x < 140)
		{
			(img->data)[(y * img->w) + (x * 4)] = gris;
			(img->data)[(y * img->w) + (x * 4) + 1] = gris;
			(img->data)[(y * img->w) + (x * 4) + 2] = gris;
		}
	}
	x = -1;
	y = 115;
	while (++x < 140)
	{
		(img->data)[(y * img->w) + (x * 4)] = gris;
		(img->data)[(y * img->w) + (x * 4) + 1] = gris;
		(img->data)[(y * img->w) + (x * 4) + 2] = gris;
	}
}

void	ft_img_clic1(t_img *img)
{
	int		x;
	int		y;
	short	gris;

	gris = 255;
	y = -1;
	while (++y < 155)
	{
		x = -1;
		while (++x < 140)
		{
			(img->data)[(y * img->w) + (x * 4)] = gris;
			(img->data)[(y * img->w) + (x * 4) + 1] = gris;
			(img->data)[(y * img->w) + (x * 4) + 2] = gris;
			(img->data)[(y * img->w) + (x * 4) + 3] = 0;
		}
	}
	ft_img_clic1b(img);
}

void	ft_print_clic1(void *param, int x, int y)
{
	t_graph	*win;

	win = param;
	ft_print_map(win);
	win->key.clic = 1;
	if (x > WIN_W - 140)
		x -= 140;
	if (y > WIN_H - 155)
		y -= 155;
	win->key.clic1_x = x;
	win->key.clic1_y = y;
	mlx_put_image_to_window(win->mlx, win->win, win->clic1.img_ptr, x, y);
	mlx_string_put(win->mlx, win->win, x + 50, y + 25, 0xFF00000, "MENU");
	mlx_string_put(win->mlx, win->win, x + 10, y + 85, 0, "PROJECTION >");
	mlx_string_put(win->mlx, win->win, x + 10, y + 125, 0, "COLOR");
	mlx_string_put(win->mlx, win->win, x + 125, y + 125, 0, ">");
}

void	ft_proj1(int y, t_graph *win)
{
	if (y > win->key.clic1_y + 115)
	{
		ft_print_clic3(win);
		win->key.clic = 3;
	}
	else if (y > win->key.clic1_y + 75)
	{
		ft_print_clic2(win);
		win->key.clic = 2;
	}
}

void	ft_clic1(void *param, int x, int y)
{
	t_graph	*win;

	win = param;
	if (x > win->key.clic1_x && x < win->key.clic1_x
			+ 140 && y > win->key.clic1_y && y < win->key.clic1_y + 155)
		ft_proj1(y, win);
	else
	{
		win->key.clic = 0;
		ft_print_map(win);
	}
}
