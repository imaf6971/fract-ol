/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erayl <erayl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:55:48 by erayl             #+#    #+#             */
/*   Updated: 2021/11/20 18:52:02 by erayl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fr.h"

t_position	zoom_adjust(const int zoom_strategy,
	const double moveX, const double moveY)
{
	static t_position	pos = {200.0, -2.0, 1.5};

	pos.move_x += moveX / pos.zoom;
	pos.move_y -= moveY / pos.zoom;
	if (zoom_strategy == ZOOMIN)
	{
		pos.zoom *= 2;
		pos.move_x -= (WIDTH / 2) / pos.zoom;
		pos.move_y += (HEIGHT / 2) / pos.zoom;
	}	
	else if (zoom_strategy == ZOOMOUT)
	{
		pos.zoom /= 2;
		pos.move_x -= (WIDTH / 2) / pos.zoom;
		pos.move_y += (HEIGHT / 2) / pos.zoom;
	}
	return (pos);
}

t_mlxdata	*getdata(void)
{
	static t_mlxdata	data;

	return (&data);
}

void	ft_fractol(const t_mlxdata *data, const t_position pos)
{
	img_fill_black(data);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	if (data->fr_type == 'j')
		ft_drawjuliatoimg(data, data->c, pos);
	else if (data->fr_type == 'm')
		ft_drawmandelbrottoimg(data, pos);
	else if (data->fr_type == 'b')
		draw_burning_crusade(data, pos);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
}

void	ft_fractolmlx(char fr_type, t_complex c)
{
	t_mlxdata	*data;

	data = getdata();
	data->mlx_ptr = mlx_init();
	checkmlx(data, CHECK_MLX_PTR);
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "fract-ol");
	checkmlx(data, CHECK_WIN_PTR);
	data->img_ptr = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	checkmlx(data, CHECK_IMG_PTR);
	data->data_addr = mlx_get_data_addr(data->img_ptr, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	get_fr_type(data, fr_type, c);
	data->max_iter = 255;
	ft_fractol(data, zoom_adjust(1, 0, 0));
	mlx_key_hook(data->win_ptr, keyhook, data);
	mlx_mouse_hook(data->win_ptr, mh, data);
	mlx_loop(data->mlx_ptr);
}

int	main(int argc, char const *argv[])
{
	if (argc == 4 && ft_strncmp("Julia", argv[1], 5) == 0)
		ft_fractolmlx('j', get_complex_for_julia(argv[2], argv[3]));
	else if (argc == 2 && ft_strncmp("Mandelbrot", argv[1], 11) == 0)
		ft_fractolmlx('m', ft_complexinit(0, 0));
	else if (argc == 2 && ft_strncmp("Julia", argv[1], 5) == 0)
		ft_fractolmlx('j', ft_complexinit(-0.7, 0.27015));
	else if (argc == 2 && ft_strncmp("BC", argv[1], 5) == 0)
		ft_fractolmlx('b', ft_complexinit(0, 0));
	else
	{
		printf("Invalid arguments!\n");
		printf("Valid args:\n");
		printf("\tJulia [re] [im] (re and im is optional)\n");
		printf("\tMandelbrot\n");
		printf("\tBC\n");
	}
	return (0);
}
