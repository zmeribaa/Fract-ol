/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmeribaa <zmeribaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 21:58:48 by zmeribaa          #+#    #+#             */
/*   Updated: 2021/12/12 15:38:19 by zmeribaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	keys(int keycode, t_data *img)
{
	if (keycode  == K_ESCAPE)
		exit(0);
	if (keycode == K_A || keycode == K_LEFT)
		img->a -= 0.05 *img->zoom;
	if (keycode == K_D || keycode == K_RIGHT)
		img->a += 0.05 *img->zoom;
	// if (keycode == K_W || keycode == K_UP)
	// 	img-
	return(0);
}

int zoom(int keycode, int x, int y, t_data *img)
{
	x = x + 1 - 1;
	y = y + 1 - 1;
	if (keycode == M_S_I || keycode == M_S_O)
	{
		if (keycode == M_S_I)
			img->zoom -= 0.1 * img->zoom;
		else
			img->zoom += 0.1 * img->zoom;
		mlx_clear_window(img->mlx, img->mlx_win);
		fra9tol(img);
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	}
	return (0);
}

float	*julia_affect(int type)
{
	float	*c;
	
	c = (float *)malloc(sizeof(float) * 2);
	if (type == 1)
	{
		c[0] = -0.4;
		c[1] = 0.6;
	}
	if (type == 2)
	{
		c[0] = 0.285;
		c[1] = 0;
	}
	if (type == 3)
	{
		c[0] = -0.835;
		c[1] =  - 0.2321; 
	}
	if (type == 4)
	{
		c[0] = -0.8;
		c[1] = 0.156;
	}
	return (c);
}