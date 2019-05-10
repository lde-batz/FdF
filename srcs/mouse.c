/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-batz <lde-batz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 18:30:50 by lde-batz          #+#    #+#             */
/*   Updated: 2019/01/19 11:32:05 by lde-batz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_init_mouse_fct3(t_graph *win)
{
	win->mouse_fct[0][0][1].ok = 1;
	win->mouse_fct[0][0][1].fct = &ft_clic1;
	win->mouse_fct[0][1][1].ok = 1;
	win->mouse_fct[0][1][1].fct = &ft_clic1;
	win->mouse_fct[0][0][2].ok = 1;
	win->mouse_fct[0][0][2].fct = &ft_clic2;
	win->mouse_fct[0][1][2].ok = 1;
	win->mouse_fct[0][1][2].fct = &ft_clic2;
	win->mouse_fct[0][0][3].ok = 1;
	win->mouse_fct[0][0][3].fct = &ft_clic3;
	win->mouse_fct[0][1][3].ok = 1;
	win->mouse_fct[0][1][3].fct = &ft_clic3;
}

void	ft_init_mouse_fct2(t_graph *win)
{
	int i;
	int j;

	i = -1;
	while (++i <= 3)
	{
		win->mouse_fct[3][0][i].ok = 1;
		win->mouse_fct[3][0][i].fct = &ft_zoom_up;
		win->mouse_fct[4][0][i].ok = 1;
		win->mouse_fct[4][0][i].fct = &ft_zoom_down;
	}
	i = -1;
	while (++i < 2)
	{
		j = -1;
		while (++j <= 3)
		{
			win->mouse_fct[1][i][j].ok = 1;
			win->mouse_fct[1][i][j].fct = &ft_print_clic1;
		}
	}
	ft_init_mouse_fct3(win);
}

void	ft_init_mouse_fct(t_graph *win)
{
	int i;
	int j;
	int	k;

	i = -1;
	while (++i < 7)
	{
		j = -1;
		while (++j < 2)
		{
			k = -1;
			while (++k <= 3)
			{
				win->mouse_fct[i][j][k].ok = 0;
				win->mouse_fct[i][j][k].fct = NULL;
			}
		}
	}
	ft_init_mouse_fct2(win);
}

int		ft_click_mouse(int button, int x, int y, void *param)
{
	t_graph *win;

	win = param;
	if (win->key.home > 0)
		if (win->mouse_fct[button - 1][win->key.home - 1][win->key.clic].ok)
			win->mouse_fct[button - 1][win->key.home - 1]
				[win->key.clic].fct(win, x, y);
	return (0);
}
