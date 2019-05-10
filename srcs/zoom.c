/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-batz <lde-batz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 18:31:44 by lde-batz          #+#    #+#             */
/*   Updated: 2019/01/19 16:05:19 by lde-batz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_zoom_up(void *param, int x, int y)
{
	t_graph	*win;

	x = 0;
	y = 0;
	win = param;
	if (win->key.zoom < 6)
	{
		(win->key.zoom)++;
		ft_print_map(win);
	}
}

void	ft_zoom_down(void *param, int x, int y)
{
	t_graph	*win;

	x = 0;
	y = 0;
	win = param;
	if (win->key.zoom > -6)
	{
		(win->key.zoom)--;
		ft_print_map(win);
	}
}
