/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-batz <lde-batz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 18:04:15 by lde-batz          #+#    #+#             */
/*   Updated: 2019/01/19 16:47:46 by lde-batz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_init_key(t_key *key)
{
	key->home = 0;
	key->z = 1;
	key->zoom = 0;
	key->verti = 0;
	key->horiz = 0;
	key->clic = 0;
	key->axono = 2;
	key->color = 0;
	key->opacity = 0;
}

void	ft_init_key_fct2(t_graph *win)
{
	win->key_fct[12].fct = &ft_altitude_up;
	win->key_fct[12].ok = 1;
	win->key_fct[13].fct = &ft_move_w;
	win->key_fct[13].ok = 1;
	win->key_fct[14].fct = &ft_altitude_down;
	win->key_fct[14].ok = 1;
	win->key_fct[53].fct = &ft_esc;
	win->key_fct[53].ok = 1;
}

void	ft_init_key_fct(t_graph *win)
{
	int i;

	i = -1;
	while (++i < 273)
	{
		win->key_fct[i].ok = 0;
		win->key_fct[i].fct = NULL;
	}
	win->key_fct[0].fct = &ft_move_a;
	win->key_fct[0].ok = 1;
	win->key_fct[1].fct = &ft_move_s;
	win->key_fct[1].ok = 1;
	win->key_fct[2].fct = &ft_move_d;
	win->key_fct[2].ok = 1;
	win->key_fct[3].fct = &ft_focus;
	win->key_fct[3].ok = 1;
	win->key_fct[7].fct = &ft_opacity_down;
	win->key_fct[7].ok = 1;
	win->key_fct[8].fct = &ft_opacity_up;
	win->key_fct[8].ok = 1;
	ft_init_key_fct2(win);
}

int		ft_press_key(int touch, void *param)
{
	t_graph	*win;

	win = param;
	if (win->key.home == 1)
	{
		if (win->key_fct[touch].ok)
			win->key_fct[touch].fct(win);
	}
	else if (win->key.home == 0)
	{
		if (touch == 53)
		{
			mlx_destroy_window(win->mlx, win->win);
			exit(0);
		}
		mlx_clear_window(win->mlx, win->win);
		ft_print_map(win);
		win->key.home = 1;
	}
	else if (touch == 53)
		win->key_fct[touch].fct(win);
	return (0);
}
