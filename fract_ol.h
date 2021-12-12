/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmeribaa <zmeribaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 21:58:44 by zmeribaa          #+#    #+#             */
/*   Updated: 2021/12/12 15:03:00 by zmeribaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# define W_width 1000
# define W_height 1000
# define max 600
# define Menu "- Mandelbrot\n- Julia [1,2,3,4]\n- Sinkingship"
#include <mlx.h>
#include <math.h>
#include <stdlib.h>
#include<stdio.h>
#include "keys.h"

typedef struct	s_data {
	void	*img;
	int		*addr;
	double	zoom;
	void	*mlx;
	void	*mlx_win;
	int		x;
	int 	y;
	double	a;
	double	b;
	int		type;
	int		julia;
}				t_data;

void	draw(t_data img, int x, int y, int color);
int 	zoom(int keycode, int x, int y, t_data *img);
void	fra9tol(t_data *img);
t_data	mosa3ada(int zid);
float	*julia_affect(int type);
int		keys(int keycode, t_data *img);
int	mo7a9i9(int ac, char **av, t_data *img);

#endif