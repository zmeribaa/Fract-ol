/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fra9tol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmeribaa <zmeribaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 21:53:14 by zmeribaa          #+#    #+#             */
/*   Updated: 2021/12/15 04:48:50 by zmeribaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	draw(t_data img, int x, int y, int color)
{
	if (y < W_height && x < W_width)
		img.addr[y * W_width + x] = color;
}

int	mandel_brot(float x_axis, float y_axis)
{
	int iteration;
	float x;
	float y;
	float x_new;
	float y_new;

	iteration = 0;
	x = 0;
	y = 0;
	x_new = (x * x) - (y * y) + x_axis;
	y_new = (2 * x * y) + y_axis;		
    while (x*x+y*y < 4 && iteration < max) 
	{
    	iteration++;
		x = x_new;
		y = y_new;
		x_new = (x * x) - (y * y) + x_axis;
		y_new = (2 * x * y) + y_axis;
    }
        if (iteration == max) 
			return (0x000000 * 10);
        else 
			return (0xCCCCCC + iteration * exp(10));		
}

int	julia(float x_axis, float y_axis, float *c)
{
	int iteration;
	float x;
	float y;
	float x_new;
	float y_new;

	iteration = 0;
	x = x_axis;
	y = y_axis;
    while (x*x+y*y < 4 && iteration < max) 
	{
		x_new = (x * x) - (y * y) + c[0];
		y_new = (2 * x * y) + c[1];
    	iteration++;
		x = x_new;
		y = y_new;
    }
    if (iteration == max) 
		return (0x000000 * 10);
    else 
		return (0xCCCCCC + iteration * exp(10));	
}

int	sinking_ship(float x_axis, float y_axis)
{
	int iteration;
	float x;
	float y;
	float x_new;
	float y_new;

	iteration = 0;
	x = 0;
	y = 0;
	x_new = (x * x) - (y * y) + x_axis;
	y_new = (2 * x * y) + y_axis;		
    while (x*x+y*y < 4 && iteration < max) 
	{
    	iteration++;
		x = x_new;
		y = y_new;
		x_new = (x * x) - (y * y) + x_axis;
		y_new = fabs((2 * x * y)) + y_axis;
    }
    if (iteration == max) 
		return (0x000000 * 10);
   	else 
		return (0xCCCCCC + iteration * exp(10));
}

void	fra9tol(t_data *img)
{
	int	i;
	int	j;
	float	x;
	float	y;
	float	*c;

	i = 0;
	c = julia_affect(img->julia);
	while(i < W_width)
	{
		j = 0;
		while(j < W_height)
		{
			x = (((float)i * img->zoom) / W_width)
				- (img->zoom / 2) + img->a;
			y = (((float)j * img->zoom) / W_height)
				- (img->zoom / 2) + img->b;
			if (img->type == 2)
				draw(*img, i, j, mandel_brot(x,y));
			if (img->type == 1)
				draw(*img, i, j, julia(x,y,c));
			if (img->type == 3)
				draw(*img, i, j, sinking_ship(x,y));
			j++;
		}
		i++;
	}
	mlx_string_put(img->mlx,img->mlx_win,0xFFFFFF,450,450,"zmeribaa");
}

int main(int ac, char **av)
{
	int add;
	t_data	img;

	add = 0;
	img	= mosa3ada(add);
	if (!mo7a9i9(ac, av, &img))
		return (printf(Menu));
	mlx_hook(img.mlx_win, 2, (1L << 1), keys, &img);
	mlx_mouse_hook(img.mlx_win, zoom, &img);
	fra9tol(&img);
	mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
	mlx_string_put(img.mlx,img.mlx_win,890,950,0xFFFFFF,"zmeribaa");
	mlx_string_put(img.mlx,img.mlx_win,890,950,0xFFFFFF,"Movements: W,A,S,D or use arrows\n zoom with the mouse scroll\n");
	mlx_loop(img.mlx);
	return (1);
}