/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-batz <lde-batz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 16:55:50 by lde-batz          #+#    #+#             */
/*   Updated: 2019/01/19 16:51:42 by lde-batz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_init_color_red(t_color *color)
{
	color->r = 255;
	color->g = 0;
	color->b = 0;
}

void	ft_limit_control(t_img *img, int i)
{
	t_segment	s;

	if (i == 0)
	{
		s.x1 = 159;
		s.y1 = 0;
		s.x2 = 159;
		s.y2 = 249;
	}
	else
	{
		s.x1 = 0;
		s.y1 = 249;
		s.x2 = 159;
		s.y2 = 249;
	}
	s.dx = 0;
	s.dy = 0;
	s.e = 0;
	ft_init_color_red(&(s.c));
	ft_init_color_red(&(s.c1));
	ft_init_color_red(&(s.c2));
	ft_print_segment(&s, img, 0);
}

void	ft_img_control(t_img *img)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (i < 2)
			ft_limit_control(img, i);
		ft_carre_up(img, i);
		ft_carre_right(img, i);
		if (i < 3)
			ft_carre_down(img, i);
		ft_carre_left(img, i);
	}
}
