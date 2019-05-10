/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segment_1st_half.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-batz <lde-batz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 17:07:56 by lde-batz          #+#    #+#             */
/*   Updated: 2019/01/19 15:52:48 by lde-batz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_1st_octant(t_segment *s, t_img *img, short opacity)
{
	s->e = s->dx;
	s->dx *= 2;
	s->dy *= 2;
	s->length = s->x2 - s->x1;
	while (s->x1 != s->x2)
	{
		if (s->x1 >= 0 && s->x1 < WIN_W && s->y1 >= 0 && s->y1 < WIN_H)
		{
			(img->data)[(s->y1 * img->w) + (s->x1 * 4)] = s->c.b;
			(img->data)[(s->y1 * img->w) + (s->x1 * 4) + 1] = s->c.g;
			(img->data)[(s->y1 * img->w) + (s->x1 * 4) + 2] = s->c.r;
			(img->data)[(s->y1 * img->w) + (s->x1 * 4) + 3] = opacity;
		}
		ft_degraded_color(s, s->x2 - s->x1);
		(s->x1)++;
		if ((s->e -= s->dy) < 0)
		{
			(s->y1)++;
			s->e += s->dx;
		}
	}
}

void	ft_2nd_octant(t_segment *s, t_img *img, short opacity)
{
	s->e = s->dy;
	s->dx *= 2;
	s->dy *= 2;
	s->length = s->y2 - s->y1;
	while (s->y1 != s->y2)
	{
		if (s->x1 >= 0 && s->x1 < WIN_W && s->y1 >= 0 && s->y1 < WIN_H)
		{
			(img->data)[(s->y1 * img->w) + (s->x1 * 4)] = s->c.b;
			(img->data)[(s->y1 * img->w) + (s->x1 * 4) + 1] = s->c.g;
			(img->data)[(s->y1 * img->w) + (s->x1 * 4) + 2] = s->c.r;
			(img->data)[(s->y1 * img->w) + (s->x1 * 4) + 3] = opacity;
		}
		ft_degraded_color(s, s->y2 - s->y1);
		(s->y1)++;
		if ((s->e -= s->dx) < 0)
		{
			(s->x1)++;
			s->e += s->dy;
		}
	}
}

void	ft_8th_octant(t_segment *s, t_img *img, short opacity)
{
	s->e = s->dx;
	s->dx *= 2;
	s->dy *= 2;
	s->length = s->x2 - s->x1;
	while (s->x1 != s->x2)
	{
		if (s->x1 >= 0 && s->x1 < WIN_W && s->y1 >= 0 && s->y1 < WIN_H)
		{
			(img->data)[(s->y1 * img->w) + (s->x1 * 4)] = s->c.b;
			(img->data)[(s->y1 * img->w) + (s->x1 * 4) + 1] = s->c.g;
			(img->data)[(s->y1 * img->w) + (s->x1 * 4) + 2] = s->c.r;
			(img->data)[(s->y1 * img->w) + (s->x1 * 4) + 3] = opacity;
		}
		ft_degraded_color(s, s->x2 - s->x1);
		(s->x1)++;
		if ((s->e += s->dy) < 0)
		{
			(s->y1)--;
			s->e += s->dx;
		}
	}
}

void	ft_7th_octant(t_segment *s, t_img *img, short opacity)
{
	s->e = s->dy;
	s->dx *= 2;
	s->dy *= 2;
	s->length = s->y1 - s->y2;
	while (s->y1 != s->y2)
	{
		if (s->x1 >= 0 && s->x1 < WIN_W && s->y1 >= 0 && s->y1 < WIN_H)
		{
			(img->data)[(s->y1 * img->w) + (s->x1 * 4)] = s->c.b;
			(img->data)[(s->y1 * img->w) + (s->x1 * 4) + 1] = s->c.g;
			(img->data)[(s->y1 * img->w) + (s->x1 * 4) + 2] = s->c.r;
			(img->data)[(s->y1 * img->w) + (s->x1 * 4) + 3] = opacity;
		}
		ft_degraded_color(s, s->y1 - s->y2);
		(s->y1)--;
		if ((s->e += s->dx) > 0)
		{
			(s->x1)++;
			s->e += s->dy;
		}
	}
}

void	ft_1st_half(t_segment *s, t_img *img, short opacity)
{
	if ((s->dy = s->y2 - s->y1) != 0)
	{
		if (s->dy > 0)
		{
			if (s->dx >= s->dy)
				ft_1st_octant(s, img, opacity);
			else
				ft_2nd_octant(s, img, opacity);
		}
		else
		{
			if (s->dx >= -(s->dy))
				ft_8th_octant(s, img, opacity);
			else
				ft_7th_octant(s, img, opacity);
		}
	}
	else
		ft_segment_right(s, img, opacity);
}
