/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawfractal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erayl <erayl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:29:34 by erayl             #+#    #+#             */
/*   Updated: 2021/11/20 18:37:34 by erayl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fr.h"

int	get_color(int i)
{
	int	color;
	int	mask;
	int	shift;

	color = 0b011011100001100101101000;
	mask = 0b000000000000010101110111;
	shift = i / 13;
	return (color | (mask << shift));
}

void	ft_drawjuliatoimg(const t_mlxdata *data,
const t_complex c, const t_position pos)
{
	t_complex	z;
	t_coord		coord;
	int			i;

	coord.y = 0;
	while (coord.y < HEIGHT)
	{
		coord.x = 0;
		while (coord.x < WIDTH)
		{
			complex_from_coordinates(&z, coord, pos);
			i = get_iterations(data->max_iter, &z, &c);
			ft_img_pixel_put(data, &coord, get_color(i));
			coord.x++;
		}
		coord.y++;
	}	
}

static inline
void	get_z0(t_complex *z)
{
	z->im = 0;
	z->re = 0;
}

void	ft_drawmandelbrottoimg(const t_mlxdata *data, t_position pos)
{
	t_complex	c;
	t_complex	z;
	t_coord		coord;
	int			i;

	coord.y = 0;
	while (coord.y < HEIGHT)
	{
		coord.x = 0;
		while (coord.x < WIDTH)
		{
			complex_from_coordinates(&c, coord, pos);
			get_z0(&z);
			i = get_iterations(data->max_iter, &z, &c);
			ft_img_pixel_put(data, &coord, get_color(i));
			coord.x++;
		}
		coord.y++;
	}
}
