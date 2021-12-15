/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mosa3ada.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmeribaa <zmeribaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 21:53:38 by zmeribaa          #+#    #+#             */
/*   Updated: 2021/12/15 04:37:03 by zmeribaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

t_data	mosa3ada(int zid)
{
	t_data	img;

	img.zoom = 4;
	img.a = 0;
	img.b = 0;
	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, W_width, W_height, "Mandel Brot");
	img.img = mlx_new_image(img.mlx, W_width, W_height);
	img.addr = (int *)mlx_get_data_addr(img.img, &zid, &zid, &zid);
	return (img);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (ft_strlen(s1) != ft_strlen(s2))
		return (0);
	while (s1[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

int	mo7a9i9(int ac, char **av, t_data *img)
{
	if (ac != 2 && ac != 3)
		return (0);
	if (ft_strcmp(av[1], "Julia"))
	{
		if (ac != 3 || ft_strlen(av[2]) != 1
			|| av[2][0] >= '5' || av[2][0] <= '0')
			return (0);
		img->type = 1;
		img->julia = av[2][0] - 48;
	}
	else if (ft_strcmp(av[1], "Mandelbrot"))
	{
		if (ac != 2)
			return (0);
		img->type = 2;
	}
	else if (ft_strcmp(av[1], "Sinkingship"))
	{
		if (ac != 2)
			return (0);
		img->type = 3;
	}
	else
		return (0);
	return (1);
}
