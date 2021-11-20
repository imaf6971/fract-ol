/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erayl <erayl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 16:22:11 by erayl             #+#    #+#             */
/*   Updated: 2021/11/20 17:33:29 by erayl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fr.h"

void	checkmlx(t_mlxdata *data, int mode)
{
	if (mode == CHECK_MLX_PTR)
	{
		if (data->mlx_ptr == NULL)
			exit(1);
	}
	else if (mode == CHECK_WIN_PTR)
	{
		if (data->win_ptr == NULL)
			exit(1);
	}
	else if (mode == CHECK_IMG_PTR)
	{
		if (data->img_ptr == NULL)
		{
			if (data->win_ptr != NULL && data->mlx_ptr != NULL)
			{
				mlx_destroy_window(data->mlx_ptr, data->win_ptr);
				exit(1);
			}
		}
	}
}

void	get_fr_type(t_mlxdata *data, char fr, t_complex c)
{
	data->fr_type = fr;
	data->c = c;
}

double	ft_atod(const char *a)
{
	double	d;
	double	c;
	int		cd;
	double	sign;

	sign = 1;
	if (*a == '+' || *a == '-')
	{
		if (*a == '-')
			sign = -1;
		a++;
	}
	d = (double) ft_atoi(a);
	c = 0.0;
	while (ft_isdigit(*a) && *a != '\0')
		a++;
	cd = 0;
	if (*a == '.')
	{
		a++;
		while (ft_isdigit(a[cd]) && a[cd] != '\0')
			cd++;
	}
	c = ft_atoi(a) * pow(0.1, cd);
	return (sign * (d + c));
}

t_complex	get_complex_for_julia(const char *re, const char *im)
{
	t_complex	comp;

	comp.re = ft_atod(re);
	comp.im = ft_atod(im);
	printf("%f\n%f\n", comp.re, comp.im);
	return (comp);
}
