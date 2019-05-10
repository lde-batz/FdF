/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-batz <lde-batz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 18:17:20 by lde-batz          #+#    #+#             */
/*   Updated: 2019/01/19 16:50:46 by lde-batz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		ft_print_control(t_graph *win)
{
	mlx_put_image_to_window(win->mlx, win->win, win->control.img_ptr, 0, 0);
	mlx_string_put(win->mlx, win->win, 75, 20, 0xFFFFFF, "  W");
	mlx_string_put(win->mlx, win->win, 10, 30, 0xFFFFFF, "MOVE:");
	mlx_string_put(win->mlx, win->win, 75, 40, 0xFFFFFF, "A S D");
	mlx_string_put(win->mlx, win->win, 10, 70, 0xFFFFFF, "SCROLL TO ZOOM");
	mlx_string_put(win->mlx, win->win, 10, 100, 0xFFFFFF, "ALTITUDE + : Q");
	mlx_string_put(win->mlx, win->win, 10, 130, 0xFFFFFF, "ALTITUDE - : E");
	mlx_string_put(win->mlx, win->win, 10, 160, 0xFFFFFF, "OPACITY + : C");
	mlx_string_put(win->mlx, win->win, 10, 190, 0xFFFFFF, "OPACITY - : X");
	mlx_string_put(win->mlx, win->win, 10, 220, 0xFFFFFF, "FOCUS : F");
}

void		ft_print_map(t_graph *win)
{
	t_segment	s;
	t_link		*l;

	l = win->link;
	mlx_clear_window(win->mlx, win->win);
	ft_clean_img(&(win->img));
	while (l)
	{
		win->segment_fct[win->key.axono].fct(&s, l, &(win->key), &(win->map));
		if (win->key.home == 0 && win->key.zoom > -6)
		{
			if (!(s.x1 >= 0 && s.x1 < WIN_W && s.y1 >= 0 && s.y1 < WIN_H &&
					s.x2 >= 0 && s.x2 < WIN_W && s.y2 >= 0 && s.y2 < WIN_H))
			{
				ft_zoom_down(win, 0, 0);
				return ;
			}
		}
		ft_print_segment(&s, &(win->img), win->key.opacity);
		l = l->next;
	}
	mlx_put_image_to_window(win->mlx, win->win, win->img.img_ptr, 0, 0);
	ft_print_control(win);
}
