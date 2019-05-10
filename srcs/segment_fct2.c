/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segment_fct2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-batz <lde-batz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 10:55:55 by lde-batz          #+#    #+#             */
/*   Updated: 2019/01/19 11:06:49 by lde-batz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_s_tri(t_segment *s, t_link *l, t_key *k, t_map *m)
{
	int			x0;
	int			y0;

	x0 = (WIN_W / 2) + (((m->h - 1) / 2) * 20 * pow(2, k->zoom))
		- (((m->w - 1) / 2) * 11 * pow(2, k->zoom));
	y0 = (WIN_H / 2) - (((m->h - 1) / 2) * 5 * pow(2, k->zoom))
		- (((m->w - 1) / 2) * 9 * pow(2, k->zoom));
	s->x1 = x0 + (l->x1 * 11 * pow(2, k->zoom))
		- (l->y1 * 20 * pow(2, k->zoom)) + (k->horiz * 15);
	s->y1 = y0 + (l->y1 * 5 * pow(2, k->zoom)) + (l->x1 * 9 * pow(2,
		k->zoom)) - (l->z1 * pow(2, k->z) * pow(2, k->zoom)) + (k->verti * 7);
	s->x2 = x0 + (l->x2 * 11 * pow(2, k->zoom))
		- (l->y2 * 20 * pow(2, k->zoom)) + (k->horiz * 15);
	s->y2 = y0 + (l->y2 * 5 * pow(2, k->zoom)) + (l->x2 * 9 * pow(2,
		k->zoom)) - (l->z2 * pow(2, k->z) * pow(2, k->zoom)) + (k->verti * 7);
	s->dx = 0;
	s->dy = 0;
	s->e = 0;
	ft_choice_color(s, l, k, m);
}

void	ft_s_military(t_segment *s, t_link *l, t_key *k, t_map *m)
{
	int			x0;
	int			y0;

	x0 = (WIN_W / 2) - ((((m->h + m->w) * 16 * pow(2, k->zoom)) / 2)
		- (m->h * 16 * pow(2, k->zoom)));
	y0 = (WIN_H / 2) - (((m->h + m->w - 2) * 16 * pow(2, k->zoom)) / 2);
	s->x1 = x0 + ((l->x1 - l->y1) * 16 * pow(2, k->zoom)) + (k->horiz * 16);
	s->y1 = y0 + ((l->x1 + l->y1) * 16 * pow(2, k->zoom)) -
			(l->z1 * pow(2, k->z) * pow(2, k->zoom)) + (k->verti * 16);
	s->x2 = x0 + ((l->x2 - l->y2) * 16 * pow(2, k->zoom)) + (k->horiz * 16);
	s->y2 = y0 + ((l->x2 + l->y2) * 16 * pow(2, k->zoom)) -
			(l->z2 * pow(2, k->z) * pow(2, k->zoom)) + (k->verti * 16);
	s->dx = 0;
	s->dy = 0;
	s->e = 0;
	ft_choice_color(s, l, k, m);
}

void	ft_s_cavalier(t_segment *s, t_link *l, t_key *k, t_map *m)
{
	int			x0;
	int			y0;

	x0 = (WIN_W / 2) + (((m->h - 1) / 2) * 16 * pow(2, k->zoom))
		- (((m->w - 1) / 2) * 24 * pow(2, k->zoom));
	y0 = (WIN_H / 2) - (((m->h - 1) / 2) * 16 * pow(2, k->zoom));
	s->x1 = x0 + (l->x1 * 24 * pow(2, k->zoom))
		- (l->y1 * 16 * pow(2, k->zoom)) + (k->horiz * 24);
	s->y1 = y0 + (l->y1 * 16 * pow(2, k->zoom)) -
			(l->z1 * pow(2, k->z) * pow(2, k->zoom)) + (k->verti * 16);
	s->x2 = x0 + (l->x2 * 24 * pow(2, k->zoom))
		- (l->y2 * 16 * pow(2, k->zoom)) + (k->horiz * 24);
	s->y2 = y0 + (l->y2 * 16 * pow(2, k->zoom)) -
			(l->z2 * pow(2, k->z) * pow(2, k->zoom)) + (k->verti * 16);
	s->dx = 0;
	s->dy = 0;
	s->e = 0;
	ft_choice_color(s, l, k, m);
}

void	ft_s_top_down(t_segment *s, t_link *l, t_key *k, t_map *m)
{
	int			x0;
	int			y0;

	x0 = (WIN_W / 2) - ((m->w / 2) * 32 * pow(2, k->zoom));
	y0 = (WIN_H / 2) - ((m->h / 2) * 32 * pow(2, k->zoom));
	s->x1 = x0 + (l->x1 * 32 * pow(2, k->zoom)) + (k->horiz * 16);
	s->y1 = y0 + (l->y1 * 32 * pow(2, k->zoom)) - (l->z1 * pow(2, k->z))
		+ (k->verti * 16);
	s->x2 = x0 + (l->x2 * 32 * pow(2, k->zoom)) + (k->horiz * 16);
	s->y2 = y0 + (l->y2 * 32 * pow(2, k->zoom)) - (l->z2 * pow(2, k->z))
		+ (k->verti * 16);
	s->dx = 0;
	s->dy = 0;
	s->e = 0;
	ft_choice_color(s, l, k, m);
}
