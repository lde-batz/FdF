/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segment.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-batz <lde-batz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 17:02:16 by lde-batz          #+#    #+#             */
/*   Updated: 2019/01/19 16:46:45 by lde-batz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_degraded_color(t_segment *s, int len)
{
	if (s->length > 255)
	{
		if (s->c1.r - s->c2.r != 0)
			if (len % (abs(s->length / (s->c1.r - s->c2.r)) + 1) == 0)
				((s->c1.r - s->c2.r) > 0) ? (s->c.r)-- : (s->c.r)++;
		if (s->c1.g - s->c2.g != 0)
			if (len % (abs(s->length / (s->c1.g - s->c2.g)) + 1) == 0)
				((s->c1.g - s->c2.g) > 0) ? (s->c.g)-- : (s->c.g)++;
		if (s->c1.b - s->c2.b != 0)
			if (len % (abs(s->length / (s->c1.b - s->c2.b)) + 1) == 0)
				((s->c1.b - s->c2.b) > 0) ? (s->c.b)-- : (s->c.b)++;
	}
	else
	{
		s->c.r -= (s->c1.r - s->c2.r) / s->length;
		if (len == abs((s->c1.r - s->c2.r) % s->length))
			((s->c1.r - s->c2.r) > 0) ? (s->c.r)-- : (s->c.r)++;
		s->c.g -= (s->c1.g - s->c2.g) / s->length;
		if (len == abs((s->c1.g - s->c2.g) % s->length))
			((s->c1.g - s->c2.g) > 0) ? (s->c.g)-- : (s->c.g)++;
		s->c.b -= (s->c1.b - s->c2.b) / s->length;
		if (len == abs((s->c1.b - s->c2.b) % s->length))
			((s->c1.b - s->c2.b) > 0) ? (s->c.b)-- : (s->c.b)++;
	}
}

void	ft_print_segment(t_segment *s, t_img *img, short opacity)
{
	if ((s->dx = s->x2 - s->x1) != 0)
	{
		if (s->dx > 0)
			ft_1st_half(s, img, opacity);
		else
			ft_2nd_half(s, img, opacity);
	}
	else
	{
		if ((s->dy = s->y2 - s->y1) != 0)
		{
			if (s->dy > 0)
				ft_segment_up(s, img, opacity);
			else
			{
				ft_segment_down(s, img, opacity);
			}
		}
	}
}
