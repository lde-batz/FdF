/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-batz <lde-batz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 18:00:06 by lde-batz          #+#    #+#             */
/*   Updated: 2019/01/19 16:06:18 by lde-batz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_H
# define KEY_H

typedef struct	s_key
{
	int		home;
	int		z;
	int		verti;
	int		horiz;
	int		zoom;
	int		proj;
	int		clic;
	int		clic1_x;
	int		clic1_y;
	int		clic2_x;
	int		clic2_y;
	int		clic3_x;
	int		clic3_y;
	int		axono;
	int		color;
	short	opacity;
}				t_key;

typedef struct	s_key_fct
{
	int		ok;
	void	(*fct)(void *);
}				t_key_fct;

typedef struct	s_mouse_fct
{
	int		ok;
	void	(*fct)(void *, int, int);
}				t_mouse_fct;

void			ft_init_key(t_key *key);
void			ft_move_w(void *param);
void			ft_move_a(void *param);
void			ft_move_s(void *param);
void			ft_move_d(void *param);
void			ft_altitude_up(void *param);
void			ft_altitude_down(void *param);
void			ft_opacity_up(void *param);
void			ft_opacity_down(void *param);
void			ft_focus(void *param);
void			ft_esc(void *param);
void			ft_zoom_up(void *param, int x, int y);
void			ft_zoom_down(void *param, int x, int y);
void			ft_print_clic1(void *param, int x, int y);
void			ft_clic1(void *param, int x, int y);
void			ft_clic2(void *param, int x, int y);
void			ft_clic3(void *param, int x, int y);
int				ft_press_key(int touch, void *param);
int				ft_click_mouse(int button, int x, int y, void *param);

#endif
