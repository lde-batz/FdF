/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_fct.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-batz <lde-batz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 15:02:51 by lde-batz          #+#    #+#             */
/*   Updated: 2019/01/19 15:07:09 by lde-batz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_focus(void *param)
{
	t_graph	*win;

	win = param;
	win->key.verti = 0;
	win->key.horiz = 0;
	ft_print_map(win);
}

void	ft_esc(void *param)
{
	t_graph	*win;

	win = param;
	mlx_put_image_to_window(win->mlx, win->win, win->home.img_ptr, 0, 0);
	mlx_string_put(win->mlx, win->win, 1225, 647, 16777215, "PRESS A KEY");
	ft_init_key(&(win->key));
	win->key.home = 0;
}
