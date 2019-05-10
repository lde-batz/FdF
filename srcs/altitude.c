/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   altitude.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-batz <lde-batz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 18:12:58 by lde-batz          #+#    #+#             */
/*   Updated: 2019/01/18 18:26:40 by lde-batz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_altitude_up(void *param)
{
	t_graph	*win;

	win = param;
	if (win->key.z < 6)
	{
		(win->key.z)++;
		ft_print_map(win);
	}
}

void	ft_altitude_down(void *param)
{
	t_graph	*win;

	win = param;
	if (win->key.z > -6)
	{
		(win->key.z)--;
		ft_print_map(win);
	}
}
