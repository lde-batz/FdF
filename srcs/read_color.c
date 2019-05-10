/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-batz <lde-batz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 15:45:57 by lde-batz          #+#    #+#             */
/*   Updated: 2019/01/17 10:01:52 by lde-batz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_color_deci(int color, t_point *pt)
{
	pt->color.r = color / (256 * 256);
	color = color % (256 * 256);
	pt->color.g = color / 256;
	color = color % 256;
	pt->color.b = color;
}

void	ft_new_color(char *color, t_point *pt)
{
	if (color)
	{
		if (color[0] == '0' && color[1] == 'x')
			ft_color_deci(ft_atoi_base(color + 2, "0123456789abcdef"), pt);
		else
			ft_color_deci(atoi(color), pt);
	}
	else
	{
		pt->color.r = 255;
		pt->color.g = 255;
		pt->color.b = 255;
	}
}
