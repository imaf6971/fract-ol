/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawbc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erayl <erayl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 18:20:02 by erayl             #+#    #+#             */
/*   Updated: 2021/11/20 18:47:23 by erayl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fr.h"

int	get_bc_iter(int max_iter, t_complex *z, t_complex *c)
{
	int		i;
	double	tmp;

	i = 0;
	while (i < max_iter)
	{
		tmp = (z->re * z->re - z->im * z->im) + c->re;
		z->im = fabs(2 * z->re * z->im) + c->im;
		z->re = tmp;
		if (isnt_z_in_set(z))
			break ;
		i++;
	}
	return (i);
}

void	draw_burning_crusade(const t_mlxdata *data, t_position pos)
{
	t_coord		coord;
	t_complex	z;
	t_complex	c;
	int			i;

	coord.y = 0;
	while (coord.y < HEIGHT)
	{
		coord.x = 0;
		while (coord.x < WIDTH)
		{
			complex_from_coordinates(&c, coord, pos);
			z.im = 0;
			z.re = 0;
			i = get_bc_iter(data->max_iter, &z, &c);
			ft_img_pixel_put(data, &coord, get_color(i));
			coord.x++;
		}
		coord.y++;
	}
}
