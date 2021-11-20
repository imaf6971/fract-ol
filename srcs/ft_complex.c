/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erayl <erayl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:50:14 by erayl             #+#    #+#             */
/*   Updated: 2021/11/20 17:59:02 by erayl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fr.h"

t_complex	ft_complexinit(double real, double imaginary)
{
	t_complex	complex;

	complex.re = real;
	complex.im = imaginary;
	return (complex);
}

static inline
int	isnt_z_in_set(const t_complex *z)
{
	return ((z->re * z->re + z->im * z->im) > 4);
}

static inline
void	fractal_formula(t_complex *z, const t_complex *c)
{
	double	tmp_re;

	tmp_re = z->re;
	z->re = z->re * z->re - z->im * z->im + c->re;
	z->im = 2 * tmp_re * z->im + c->im;
}

int	get_iterations(const int max_iter, t_complex *z, const t_complex *c)
{
	int	i;

	i = 0;
	while (i < max_iter)
	{
		fractal_formula(z, c);
		if (isnt_z_in_set(z))
			break ;
		i++;
	}
	return (i);
}

void	complex_from_coordinates(t_complex *num, t_coord coord, t_position pos)
{
	num->re = coord.x / pos.zoom + pos.move_x;
	num->im = coord.y / pos.zoom - pos.move_y;
}
