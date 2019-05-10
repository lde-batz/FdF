/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-batz <lde-batz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 16:44:39 by lde-batz          #+#    #+#             */
/*   Updated: 2019/01/18 16:49:17 by lde-batz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_init_circle(t_circle *circle, int r, int x0, int y0)
{
	circle->x0 = x0;
	circle->y0 = y0;
	circle->x = 0;
	circle->y = r;
}

void	ft_circle_pixel(t_circle *c, t_img *i)
{
	int	rgb;

	rgb = -1;
	while (++rgb < 3)
	{
		(i->data)[((c->y + c->y0) * i->w) +
				((c->x + c->x0) * 4) + rgb] = (char)255;
		(i->data)[((c->x + c->y0) * i->w) +
				((c->y + c->x0) * 4) + rgb] = (char)255;
		(i->data)[((c->y + c->y0) * i->w) +
				((-(c->x) + c->x0) * 4) + rgb] = (char)255;
		(i->data)[((c->x + c->y0) * i->w) +
				((-(c->y) + c->x0) * 4) + rgb] = (char)255;
		(i->data)[((-(c->y) + c->y0) * i->w) +
				((c->x + c->x0) * 4) + rgb] = (char)255;
		(i->data)[((-(c->x) + c->y0) * i->w) +
				((c->y + c->x0) * 4) + rgb] = (char)255;
		(i->data)[((-(c->y) + c->y0) * i->w) +
				((-(c->x) + c->x0) * 4) + rgb] = (char)255;
		(i->data)[((-(c->x) + c->y0) * i->w) +
				((-(c->y) + c->x0) * 4) + rgb] = (char)255;
	}
}

void	ft_print_circle(int r, int x0, int y0, t_img *img)
{
	t_circle	circle;
	int			m;

	ft_init_circle(&circle, r, x0, y0);
	m = 5 - (4 * r);
	while (circle.x <= circle.y)
	{
		ft_circle_pixel(&circle, img);
		if (m > 0)
		{
			(circle.y)--;
			m -= 8 * circle.y;
		}
		(circle.x)++;
		m += (8 * circle.x) + 4;
	}
}
