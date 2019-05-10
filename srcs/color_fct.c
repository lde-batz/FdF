/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_fct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-batz <lde-batz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 11:11:20 by lde-batz          #+#    #+#             */
/*   Updated: 2019/01/19 11:24:30 by lde-batz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_cpy_color(t_color *cpy, t_color *c)
{
	cpy->r = c->r;
	cpy->g = c->g;
	cpy->b = c->b;
}

void	ft_color_earth2(t_color *color, int z, t_map *m)
{
	if (z > 0)
	{
		color->r = 0;
		color->g = 255 - (153 * z / (m->z / 2));
		color->b = 0;
	}
	else if (-z <= m->z / 2)
	{
		z = -z;
		color->r = 51 - (51 * z / (m->z / 2));
		color->g = 153 - (153 * z / (m->z / 2));
		color->b = 255;
	}
	else
	{
		z = -z - (m->z / 2);
		color->r = 0;
		color->g = 0;
		color->b = 255 - (153 * z / (m->z / 2));
	}
}

void	ft_color_earth(t_color *color, int z, t_map *m)
{
	if (m->z == 0)
	{
		color->r = 51;
		color->g = 153;
		color->b = 255;
	}
	else if (z >= m->z * 0.8)
	{
		color->r = 255;
		color->g = 255;
		color->b = 255;
	}
	else if (z >= m->z / 2)
	{
		z = z - (m->z / 2);
		color->g = 102 - (77 * z / (m->z * 0.8 - (m->z / 2)));
		color->r = color->g * 2;
		color->b = 0;
	}
	else
		ft_color_earth2(color, z, m);
}

void	ft_color_degraded(t_color *color, int z, t_map *m)
{
	if (m->z == 0)
	{
		color->r = 255;
		color->g = 0;
		color->b = 0;
	}
	else if (z > 0)
	{
		color->r = 255;
		color->g = 255 * z / m->z;
		color->b = 255 * z / m->z;
	}
	else
	{
		z = -z;
		color->g = 0;
		color->b = 0;
		color->r = 255 - (255 * z / m->z);
	}
}

void	ft_choice_color(t_segment *s, t_link *l, t_key *k, t_map *m)
{
	if (k->color == 0)
	{
		ft_cpy_color(&(s->c), &(l->c1));
		ft_cpy_color(&(s->c1), &(l->c1));
		ft_cpy_color(&(s->c2), &(l->c2));
	}
	if (k->color == 1)
	{
		ft_color_earth(&(s->c), l->z1, m);
		ft_cpy_color(&(s->c1), &(s->c));
		ft_color_earth(&(s->c2), l->z2, m);
	}
	if (k->color == 2)
	{
		ft_color_degraded(&(s->c), l->z1, m);
		ft_cpy_color(&(s->c1), &(s->c));
		ft_color_degraded(&(s->c2), l->z2, m);
	}
}
