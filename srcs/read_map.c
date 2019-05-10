/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-batz <lde-batz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 14:34:16 by lde-batz          #+#    #+#             */
/*   Updated: 2019/01/18 15:34:13 by lde-batz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_new_pt(int x, int y, char *pt_info, t_point *pt)
{
	int		i;
	char	**z_color;

	z_color = ft_strsplit(pt_info, ',');
	pt->x = x;
	pt->y = y;
	pt->z = ft_atoi(z_color[0]);
	ft_new_color(z_color[1], pt);
	i = 0;
	while (z_color[i])
		free(z_color[i++]);
	free(z_color);
}

t_line	*ft_init_new_line(t_graph *win, t_read *r)
{
	t_line	*new;
	t_line	*last;

	if (!(new = (t_line*)malloc(sizeof(t_line))))
	{
		ft_putendl("error : a new line don't malloc");
		exit(EXIT_FAILURE);
	}
	last = win->pts;
	new->len = r->i;
	if (!(new->line = (t_point*)malloc(sizeof(t_point) * r->i)))
	{
		ft_putendl("error : new->line don't malloc");
		exit(EXIT_FAILURE);
	}
	new->next = NULL;
	if (win->pts)
	{
		while (last->next)
			last = last->next;
		last->next = new;
	}
	return (new);
}

void	ft_read_map2(t_read *r, t_graph *win)
{
	t_line	*new;

	r->x = 0;
	r->i = 0;
	r->pt_line = ft_strsplit(r->line, ' ');
	while ((r->pt_line)[r->i])
		(r->i)++;
	if ((r->line)[0] == '\0')
	{
		ft_putendl("usage : invalid map");
		exit(EXIT_FAILURE);
	}
	new = ft_init_new_line(win, r);
	if (!(win->pts))
		win->pts = new;
	while ((r->pt_line)[r->x])
	{
		ft_new_pt(r->x, win->map.h, (r->pt_line)[r->x], &(new->line[r->x]));
		if (win->map.z < abs(new->line[r->x].z))
			win->map.z = abs(new->line[r->x].z);
		free((r->pt_line)[(r->x)++]);
	}
	(win->map.h)++;
}

int		ft_read_map(int fd, t_graph *win)
{
	int		i;
	t_read	r;

	win->pts = NULL;
	while (get_next_line(fd, &(r.line)) && !(i = 0))
	{
		while (ft_isxdigit(((r.line)[i])) || (r.line)[i] == ' ' ||
				((r.line)[i] >= '+' && (r.line)[i] <= '-'))
			i++;
		if ((r.line)[i] != '\0')
			return (0);
		ft_read_map2(&r, win);
		free(r.pt_line);
		free(r.line);
		if (win->map.w < r.x)
			win->map.w = r.x;
	}
	free(r.line);
	close(fd);
	return (1);
}
