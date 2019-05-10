/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segment_straight.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-batz <lde-batz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 17:13:29 by lde-batz          #+#    #+#             */
/*   Updated: 2019/01/19 15:54:21 by lde-batz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_segment_up(t_segment *s, t_img *img, short opacity)
{
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
	}
}

void	ft_segment_down(t_segment *s, t_img *img, short opacity)
{
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
	}
}

void	ft_segment_left(t_segment *s, t_img *img, short opacity)
{
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
	}
}

void	ft_segment_right(t_segment *s, t_img *img, short opacity)
{
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
	}
}
