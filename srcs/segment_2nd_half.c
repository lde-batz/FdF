/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segment_2nd_half.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-batz <lde-batz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 17:11:11 by lde-batz          #+#    #+#             */
/*   Updated: 2019/01/19 15:53:47 by lde-batz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_4th_octant(t_segment *s, t_img *img, short opacity)
{
	s->e = s->dx;
	s->dx *= 2;
	s->dy *= 2;
	s->length = s->x1 - s->x2;
	while (s->x1 != s->x2)
	{
		if (s->x1 >= 0 && s->x1 < WIN_W && s->y1 >= 0 && s->y1 < WIN_H)
		{
			(img->data)[(s->y1 * img->w) + (s->x1 * 4)] = s->c.b;
			(img->data)[(s->y1 * img->w) + (s->x1 * 4) + 1] = s->c.g;
			(img->data)[(s->y1 * img->w) + (s->x1 * 4) + 2] = s->c.r;
			(img->data)[(s->y1 * img->w) + (s->x1 * 4) + 3] = opacity;
		}
		ft_degraded_color(s, s->x1 - s->x2);
		(s->x1)--;
		if ((s->e += s->dy) >= 0)
		{
			(s->y1)++;
			s->e += s->dx;
		}
	}
}

void	ft_3rd_octant(t_segment *s, t_img *img, short opacity)
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
		if ((s->e += s->dx) <= 0)
		{
			(s->x1)--;
			s->e += s->dy;
		}
	}
}

void	ft_5th_octant(t_segment *s, t_img *img, short opacity)
{
	s->e = s->dx;
	s->dx *= 2;
	s->dy *= 2;
	s->length = s->x1 - s->x2;
	while (s->x1 != s->x2)
	{
		if (s->x1 >= 0 && s->x1 < WIN_W && s->y1 >= 0 && s->y1 < WIN_H)
		{
			(img->data)[(s->y1 * img->w) + (s->x1 * 4)] = s->c.b;
			(img->data)[(s->y1 * img->w) + (s->x1 * 4) + 1] = s->c.g;
			(img->data)[(s->y1 * img->w) + (s->x1 * 4) + 2] = s->c.r;
			(img->data)[(s->y1 * img->w) + (s->x1 * 4) + 3] = opacity;
		}
		ft_degraded_color(s, s->x1 - s->x2);
		(s->x1)--;
		if ((s->e -= s->dy) >= 0)
		{
			(s->y1)--;
			s->e += s->dx;
		}
	}
}

void	ft_6th_octant(t_segment *s, t_img *img, short opacity)
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
		if ((s->e -= s->dx) >= 0)
		{
			(s->x1)--;
			s->e += s->dy;
		}
	}
}

void	ft_2nd_half(t_segment *s, t_img *img, short opacity)
{
	if ((s->dy = s->y2 - s->y1) != 0)
	{
		if (s->dy > 0)
		{
			if (-(s->dx) >= s->dy)
				ft_4th_octant(s, img, opacity);
			else
				ft_3rd_octant(s, img, opacity);
		}
		else
		{
			if (s->dx <= s->dy)
				ft_5th_octant(s, img, opacity);
			else
				ft_6th_octant(s, img, opacity);
		}
	}
	else
		ft_segment_left(s, img, opacity);
}
