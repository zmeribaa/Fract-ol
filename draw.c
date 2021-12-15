/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmeribaa <zmeribaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 05:40:37 by zmeribaa          #+#    #+#             */
/*   Updated: 2021/12/15 16:10:28 by zmeribaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	draw(t_data img, int x, int y, int color)
{
	if (y < W_HEIGHT && x < W_WIDTH)
		img.addr[y * W_WIDTH + x] = color;
}
