/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opacity.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-batz <lde-batz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 15:56:03 by lde-batz          #+#    #+#             */
/*   Updated: 2019/01/19 16:45:53 by lde-batz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_opacity_up(void *param)
{
	t_graph	*win;

	win = param;
	if (win->key.opacity > 0)
	{
		win->key.opacity -= 5;
		ft_print_map(win);
	}
}

void	ft_opacity_down(void *param)
{
	t_graph	*win;

	win = param;
	if (win->key.opacity < 255)
	{
		win->key.opacity += 5;
		ft_print_map(win);
	}
}
