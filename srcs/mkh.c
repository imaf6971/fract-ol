/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mkh.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erayl <erayl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:51:10 by erayl             #+#    #+#             */
/*   Updated: 2021/11/20 18:06:40 by erayl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fr.h"

int	keyhook(int keycode, t_mlxdata *data)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_image(data->mlx_ptr, data->img_ptr);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		exit(0);
	}
	if (keycode == KEY_INCITER)
	{
		data->max_iter += 20;
		ft_fractol(getdata(), zoom_adjust(-1, 0, 0));
	}
	else if (keycode == KEY_DECITER)
	{
		data->max_iter -= 20;
		ft_fractol(getdata(), zoom_adjust(-1, 0, 0));
	}
	else if (keycode == KEY_ARRLEFT)
		ft_fractol(data, zoom_adjust(1, -20, 0));
	else if (keycode == KEY_ARRRIGHT)
		ft_fractol(data, zoom_adjust(1, 20, 0));
	else if (keycode == KEY_ARRUP)
		ft_fractol(getdata(), zoom_adjust(1, 0, 20));
	else if (keycode == KEY_ARRDOWN)
		ft_fractol(getdata(), zoom_adjust(1, 0, -20));
	return (0);
}

int	mh(int mk, int x, int y, void *data)
{
	if (mk == MKEY_LEFT || mk == MKEY_ZOOM_IN)
		ft_fractol(data, zoom_adjust(ZOOMIN, x, y));
	else if (mk == MKEY_RIGHT || mk == MKEY_ZOOM_OUT)
		ft_fractol(data, zoom_adjust(ZOOMOUT, x, y));
	return (0);
}
