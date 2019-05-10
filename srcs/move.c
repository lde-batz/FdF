/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-batz <lde-batz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 18:11:16 by lde-batz          #+#    #+#             */
/*   Updated: 2019/01/18 18:20:53 by lde-batz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_move_w(void *param)
{
	t_graph	*win;

	win = param;
	(win->key.verti)--;
	ft_print_map(win);
}

void	ft_move_a(void *param)
{
	t_graph	*win;

	win = param;
	(win->key.horiz)--;
	ft_print_map(win);
}

void	ft_move_s(void *param)
{
	t_graph	*win;

	win = param;
	(win->key.verti)++;
	ft_print_map(win);
}

void	ft_move_d(void *param)
{
	t_graph	*win;

	win = param;
	(win->key.horiz)++;
	ft_print_map(win);
}
