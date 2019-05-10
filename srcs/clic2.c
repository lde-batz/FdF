/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clic2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-batz <lde-batz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 17:52:40 by lde-batz          #+#    #+#             */
/*   Updated: 2019/01/19 16:33:13 by lde-batz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_img_clic2b(t_img *img)
{
	int		x;
	int		y;
	short	gris;

	y = 31;
	gris = 180;
	while (y < 215)
	{
		x = -1;
		while (++x < 110)
		{
			(img->data)[(y * img->w) + (x * 4)] = gris;
			(img->data)[(y * img->w) + (x * 4) + 1] = gris;
			(img->data)[(y * img->w) + (x * 4) + 2] = gris;
			(img->data)[(y * img->w) + (x * 4) + 3] = 0;
		}
		y += 30;
	}
}

void	ft_img_clic2(t_img *img)
{
	int		x;
	int		y;
	short	gris;

	gris = 220;
	y = -1;
	while (++y < 240)
	{
		x = -1;
		while (++x < 110)
		{
			(img->data)[(y * img->w) + (x * 4)] = gris;
			(img->data)[(y * img->w) + (x * 4) + 1] = gris;
			(img->data)[(y * img->w) + (x * 4) + 2] = gris;
			(img->data)[(y * img->w) + (x * 4) + 3] = 0;
		}
	}
	ft_img_clic2b(img);
}
