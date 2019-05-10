/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-batz <lde-batz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 16:07:37 by lde-batz          #+#    #+#             */
/*   Updated: 2019/01/19 16:31:26 by lde-batz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/srcs/libft.h"
# include "key.h"
# include "map.h"
# include <math.h>
# include <mlx.h>
# include <fcntl.h>

# define WIN_H 1316
# define WIN_W 2560

typedef struct	s_img
{
	void	*img_ptr;
	int		bpp;
	int		w;
	int		endian;
	char	*data;
}				t_img;

typedef struct	s_circle
{
	int	x0;
	int	y0;
	int	x;
	int	y;
}				t_circle;

typedef struct	s_graph
{
	void			*mlx;
	void			*win;
	t_line			*pts;
	t_map			map;
	t_link			*link;
	t_img			home;
	t_img			control;
	t_img			img;
	t_img			clic1;
	t_img			clic2;
	t_img			clic3;
	t_key			key;
	t_key_fct		key_fct[273];
	t_mouse_fct		mouse_fct[7][2][4];
	t_segment_fct	segment_fct[8];
}				t_graph;

void			ft_init_graph(char *argv, t_graph *win);
void			ft_init_map(t_graph *win);
int				ft_read_map(int fd, t_graph *win);
void			ft_init_link(t_graph *win);
void			ft_new_img(t_img *img, void *img_ptr, int w);
void			ft_clean_img(t_img *img);
void			ft_img_home(t_img *img);
void			ft_print_circle(int r, int x0, int y0, t_img *img);
void			ft_img_control(t_img *img);
void			ft_carre_up(t_img *img, int i);
void			ft_carre_down(t_img *img, int i);
void			ft_carre_left(t_img *img, int i);
void			ft_carre_right(t_img *img, int i);
void			ft_img_clic1(t_img *img);
void			ft_img_clic2(t_img *img);
void			ft_img_clic3(t_img *img);
void			ft_init_key_fct(t_graph *win);
void			ft_init_mouse_fct(t_graph *win);
void			ft_init_segment_fct(t_graph *win);
void			ft_print_clic2(t_graph *win);
void			ft_print_clic3(t_graph *win);
void			ft_proj1(int y, t_graph *win);
void			ft_print_map(t_graph *win);
void			ft_print_segment(t_segment *s, t_img *img, short opacity);
void			ft_1st_half(t_segment *s, t_img *img, short opacity);
void			ft_2nd_half(t_segment *s, t_img *img, short opacity);
void			ft_segment_up(t_segment *s, t_img *img, short opacity);
void			ft_segment_down(t_segment *s, t_img *img, short opacity);
void			ft_segment_left(t_segment *s, t_img *img, short opacity);
void			ft_segment_right(t_segment *s, t_img *img, short opacity);
void			ft_degraded_color(t_segment *s, int len);

#endif
