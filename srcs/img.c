/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-batz <lde-batz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 15:44:17 by lde-batz          #+#    #+#             */
/*   Updated: 2019/01/19 16:31:16 by lde-batz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_new_img(t_img *img, void *img_ptr, int w)
{
	img->img_ptr = img_ptr;
	img->bpp = 4;
	img->w = w * 4;
}

void	ft_clean_img(t_img *img)
{
	int	i;

	i = 0;
	while (i < WIN_H * WIN_W * 4)
		(img->data)[i++] = 0;
}
