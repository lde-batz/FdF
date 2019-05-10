/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segment_fct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-batz <lde-batz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 10:54:17 by lde-batz          #+#    #+#             */
/*   Updated: 2019/01/19 11:07:10 by lde-batz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_s_elevation(t_segment *s, t_link *l, t_key *k, t_map *m)
{
	int			x0;
	int			y0;

	x0 = (WIN_W / 2) - (((m->w / 2) * 32 * pow(2, k->zoom)));
	y0 = (WIN_H / 2);
	s->x1 = x0 + (l->x1 * 32 * pow(2, k->zoom)) + (k->horiz * 16);
	s->y1 = y0 - (l->z1 * pow(2, k->z) * pow(2, k->zoom)) + (k->verti * 16);
	s->x2 = x0 + (l->x2 * 32 * pow(2, k->zoom)) + (k->horiz * 16);
	s->y2 = y0 - (l->z2 * pow(2, k->z) * pow(2, k->zoom)) + (k->verti * 16);
	s->dx = 0;
	s->dy = 0;
	s->e = 0;
	ft_choice_color(s, l, k, m);
}

void	ft_s_plan(t_segment *s, t_link *l, t_key *k, t_map *m)
{
	int			x0;
	int			y0;

	x0 = (WIN_W / 2) - ((m->w / 2) * 32 * pow(2, k->zoom));
	y0 = (WIN_H / 2) - ((m->h / 2) * 32 * pow(2, k->zoom));
	s->x1 = x0 + (l->x1 * 32 * pow(2, k->zoom)) + (k->horiz * 16);
	s->y1 = y0 + (l->y1 * 32 * pow(2, k->zoom)) + (k->verti * 16);
	s->x2 = x0 + (l->x2 * 32 * pow(2, k->zoom)) + (k->horiz * 16);
	s->y2 = y0 + (l->y2 * 32 * pow(2, k->zoom)) + (k->verti * 16);
	s->dx = 0;
	s->dy = 0;
	s->e = 0;
	ft_choice_color(s, l, k, m);
}

void	ft_s_iso(t_segment *s, t_link *l, t_key *k, t_map *m)
{
	int			x0;
	int			y0;

	x0 = (WIN_W / 2) - ((((m->h + m->w) * 28 * pow(2, k->zoom)) / 2)
		- (m->h * 28 * pow(2, k->zoom)));
	y0 = (WIN_H / 2) - (((m->h + m->w - 2) * 16 * pow(2, k->zoom)) / 2);
	s->x1 = x0 + ((l->x1 - l->y1) * 28 * pow(2, k->zoom)) + (k->horiz * 28);
	s->y1 = y0 + ((l->x1 + l->y1) * 16 * pow(2, k->zoom)) -
			(l->z1 * pow(2, k->z) * pow(2, k->zoom)) + (k->verti * 16);
	s->x2 = x0 + ((l->x2 - l->y2) * 28 * pow(2, k->zoom)) + (k->horiz * 28);
	s->y2 = y0 + ((l->x2 + l->y2) * 16 * pow(2, k->zoom)) -
			(l->z2 * pow(2, k->z) * pow(2, k->zoom)) + (k->verti * 16);
	s->dx = 0;
	s->dy = 0;
	s->e = 0;
	ft_choice_color(s, l, k, m);
}

void	ft_s_di(t_segment *s, t_link *l, t_key *k, t_map *m)
{
	int			x0;
	int			y0;

	x0 = (WIN_W / 2) - ((((m->h + m->w) * 32 * pow(2, k->zoom)) / 2)
		- (m->h * 32 * pow(2, k->zoom)));
	y0 = (WIN_H / 2) - (((m->h + m->w - 2) * 16 * pow(2, k->zoom)) / 2);
	s->x1 = x0 + ((l->x1 - l->y1) * 32 * pow(2, k->zoom)) + (k->horiz * 32);
	s->y1 = y0 + ((l->x1 + l->y1) * 16 * pow(2, k->zoom)) -
			(l->z1 * pow(2, k->z) * pow(2, k->zoom)) + (k->verti * 16);
	s->x2 = x0 + ((l->x2 - l->y2) * 32 * pow(2, k->zoom)) + (k->horiz * 32);
	s->y2 = y0 + ((l->x2 + l->y2) * 16 * pow(2, k->zoom)) -
			(l->z2 * pow(2, k->z) * pow(2, k->zoom)) + (k->verti * 16);
	s->dx = 0;
	s->dy = 0;
	s->e = 0;
	ft_choice_color(s, l, k, m);
}

void	ft_init_segment_fct(t_graph *win)
{
	win->segment_fct[0].ok = 1;
	win->segment_fct[0].fct = &ft_s_elevation;
	win->segment_fct[1].ok = 1;
	win->segment_fct[1].fct = &ft_s_plan;
	win->segment_fct[2].ok = 1;
	win->segment_fct[2].fct = &ft_s_iso;
	win->segment_fct[3].ok = 1;
	win->segment_fct[3].fct = &ft_s_di;
	win->segment_fct[4].ok = 1;
	win->segment_fct[4].fct = &ft_s_tri;
	win->segment_fct[5].ok = 1;
	win->segment_fct[5].fct = &ft_s_military;
	win->segment_fct[6].ok = 1;
	win->segment_fct[6].fct = &ft_s_cavalier;
	win->segment_fct[7].ok = 1;
	win->segment_fct[7].fct = &ft_s_top_down;
}
