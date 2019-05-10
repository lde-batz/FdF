/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-batz <lde-batz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 18:11:07 by lde-batz          #+#    #+#             */
/*   Updated: 2019/01/19 11:25:21 by lde-batz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

typedef struct	s_map
{
	int	h;
	int	w;
	int	z;
}				t_map;

typedef struct	s_color
{
	short	r;
	short	g;
	short	b;
}				t_color;

typedef struct	s_read
{
	int		i;
	int		x;
	char	*line;
	char	**pt_line;
}				t_read;

typedef struct	s_point
{
	int				x;
	int				y;
	int				z;
	t_color			color;
}				t_point;

typedef struct	s_line
{
	int				len;
	t_point			*line;
	struct s_line	*next;
}				t_line;

typedef struct	s_link
{
	int				x1;
	int				y1;
	int				z1;
	int				x2;
	int				y2;
	int				z2;
	t_color			c1;
	t_color			c2;
	struct s_link	*next;
}				t_link;

typedef struct	s_segment
{
	int		x1;
	int		y1;
	int		x2;
	int		y2;
	int		dx;
	int		dy;
	int		e;
	int		length;
	t_color c;
	t_color c1;
	t_color c2;
}				t_segment;

typedef struct	s_segment_fct
{
	int		ok;
	void	(*fct)(t_segment *s, t_link *, t_key *, t_map *);
}				t_segment_fct;

void			ft_new_color(char *color, t_point *pt);
void			ft_s_tri(t_segment *s, t_link *l, t_key *k, t_map *m);
void			ft_s_military(t_segment *s, t_link *l, t_key *k, t_map *m);
void			ft_s_cavalier(t_segment *s, t_link *l, t_key *k, t_map *m);
void			ft_s_top_down(t_segment *s, t_link *l, t_key *k, t_map *m);
void			ft_choice_color(t_segment *s, t_link *l, t_key *k, t_map *m);

#endif
