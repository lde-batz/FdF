/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carre.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-batz <lde-batz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 17:20:06 by lde-batz          #+#    #+#             */
/*   Updated: 2019/01/19 15:55:03 by lde-batz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_init_color_white(t_color *color)
{
	color->r = 255;
	color->g = 255;
	color->b = 255;
}

void	ft_carre_up(t_img *img, int i)
{
	t_segment	s;

	if (i < 3)
	{
		s.x1 = 70 + (i * 20);
		s.y1 = 40;
		s.x2 = 90 + (i * 20);
		s.y2 = 40;
	}
	else
	{
		s.x1 = 90;
		s.y1 = 20;
		s.x2 = 110;
		s.y2 = 20;
	}
	s.dx = 0;
	s.dy = 0;
	s.e = 0;
	ft_init_color_white(&(s.c));
	ft_init_color_white(&(s.c1));
	ft_init_color_white(&(s.c2));
	ft_print_segment(&s, img, 0);
}

void	ft_carre_right(t_img *img, int i)
{
	t_segment	s;

	if (i < 3)
	{
		s.x1 = 90 + (i * 20);
		s.y1 = 40;
		s.x2 = 90 + (i * 20);
		s.y2 = 60;
	}
	else
	{
		s.x1 = 110;
		s.y1 = 20;
		s.x2 = 110;
		s.y2 = 40;
	}
	s.dx = 0;
	s.dy = 0;
	s.e = 0;
	ft_init_color_white(&(s.c));
	ft_init_color_white(&(s.c1));
	ft_init_color_white(&(s.c2));
	ft_print_segment(&s, img, 0);
}

void	ft_carre_down(t_img *img, int i)
{
	t_segment	s;

	s.x1 = 90 + (i * 20);
	s.y1 = 60;
	s.x2 = 70 + (i * 20);
	s.y2 = 60;
	s.dx = 0;
	s.dy = 0;
	s.e = 0;
	ft_init_color_white(&(s.c));
	ft_init_color_white(&(s.c1));
	ft_init_color_white(&(s.c2));
	ft_print_segment(&s, img, 0);
}

void	ft_carre_left(t_img *img, int i)
{
	t_segment	s;

	if (i < 3)
	{
		s.x1 = 70 + (i * 20);
		s.y1 = 60;
		s.x2 = 70 + (i * 20);
		s.y2 = 40;
	}
	else
	{
		s.x1 = 90;
		s.y1 = 40;
		s.x2 = 90;
		s.y2 = 20;
	}
	s.dx = 0;
	s.dy = 0;
	s.e = 0;
	ft_init_color_white(&(s.c));
	ft_init_color_white(&(s.c1));
	ft_init_color_white(&(s.c2));
	ft_print_segment(&s, img, 0);
}
