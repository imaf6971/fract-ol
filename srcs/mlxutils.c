/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxutils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erayl <erayl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 15:15:37 by erayl             #+#    #+#             */
/*   Updated: 2021/11/20 16:51:53 by erayl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fr.h"

static inline
void	*get_addr_by_coord(const t_mlxdata *data, const t_coord *coord)
{
	return (data->data_addr + (coord->y * data->line_length + \
	coord->x * (data->bits_per_pixel / 8)));
}

void	ft_img_pixel_put(const t_mlxdata *data, const t_coord *coord, int color)
{
	if (coord->x >= 0 && coord->x < 799 && coord->y >= 0 && coord->y < 599)
	{
		*(unsigned int *)get_addr_by_coord(data, coord) = color;
	}
}

void	img_fill_black(const t_mlxdata *img)
{
	t_coord	coord;

	coord.y = 600;
	while (coord.y--)
	{
		coord.x = 800;
		while (coord.x--)
		{
			ft_img_pixel_put(img, &coord, 0x0);
		}
	}
}
