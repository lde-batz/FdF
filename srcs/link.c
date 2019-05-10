/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-batz <lde-batz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 12:39:37 by lde-batz          #+#    #+#             */
/*   Updated: 2019/01/18 15:41:01 by lde-batz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_new_link(t_point *p1, t_point *p2, t_graph *win)
{
	t_link *new;

	if (!(new = (t_link*)malloc(sizeof(t_link))))
	{
		ft_putendl("error : new->link don't malloc");
		exit(EXIT_FAILURE);
	}
	new->x1 = p1->x;
	new->y1 = p1->y;
	new->z1 = p1->z;
	new->x2 = p2->x;
	new->y2 = p2->y;
	new->z2 = p2->z;
	new->c1 = p1->color;
	new->c2 = p2->color;
	new->next = win->link;
	win->link = new;
}

void	ft_init_link(t_graph *win)
{
	int		i;
	t_line	*p1;
	t_line	*p2;

	win->link = NULL;
	p1 = win->pts;
	while (p1)
	{
		i = -1;
		p2 = p1->next;
		while (++i < p1->len)
		{
			if (i + 1 < p1->len)
				ft_new_link(&(p1->line[i]), &(p1->line[i + 1]), win);
			if (p2)
				if (i < p2->len)
					ft_new_link(&(p1->line[i]), &(p2->line[i]), win);
		}
		p1 = p2;
	}
}
