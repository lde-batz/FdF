/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   home.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-batz <lde-batz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 16:40:49 by lde-batz          #+#    #+#             */
/*   Updated: 2019/01/18 16:54:40 by lde-batz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_shading_white(t_img *img)
{
	int		i;
	int		x;
	int		y;
	short	c;

	i = -1;
	while (++i < 2)
	{
		y = i * (WIN_H - 226);
		if ((i != (c = 0) + 1))
			c = 226;
		while (y <= 225 + (i * (WIN_H - 226)))
		{
			x = 0;
			while (x < WIN_W)
			{
				(img->data)[(y * img->w) + (x * 4)] = c;
				(img->data)[(y * img->w) + (x * 4) + 1] = c;
				(img->data)[(y * img->w) + (x++ * 4) + 2] = (char)226;
			}
			y++;
			if (c++ && i == 0)
				c -= 2;
		}
	}
}

void	ft_img_home(t_img *img)
{
	int		i;
	int		x;
	int		y;
	short	c;

	i = -1;
	while (++i < 2)
	{
		y = 226 + ((WIN_H - (226 * 3) + 1) * i);
		if ((i != (c = 0) + 1))
			c = 225;
		while (!(x = 0) && y <= 450 + ((WIN_H - (226 * 3) + 1) * i))
		{
			while (x < WIN_W)
			{
				(img->data)[(y * img->w) + (x * 4)] = 0;
				(img->data)[(y * img->w) + (x * 4) + 1] = 0;
				(img->data)[(y * img->w) + (x++ * 4) + 2] = c;
			}
			if (++y && c++ && i == 0)
				c -= 2;
		}
	}
	ft_shading_white(img);
	ft_print_circle(200, WIN_W / 2, WIN_H / 2, img);
}
