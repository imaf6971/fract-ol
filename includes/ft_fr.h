/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fr.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erayl <erayl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 16:46:21 by erayl             #+#    #+#             */
/*   Updated: 2021/11/20 17:59:31 by erayl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FR_H
# define FT_FR_H
# include <printf.h>
# include <stdlib.h>
# include <math.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"

# define WIDTH 800
# define HEIGHT 600
# define ZOOMIN 42
# define ZOOMOUT -42

# define MKEY_LEFT 1
# define MKEY_RIGHT 2
# define MKEY_ZOOM_IN 4
# define MKEY_ZOOM_OUT 5
# define KEY_ESC 53
# define KEY_INCITER 7
# define KEY_DECITER 6
# define KEY_ARRLEFT 123
# define KEY_ARRRIGHT 124
# define KEY_ARRUP 125
# define KEY_ARRDOWN 126

# define CHECK_MLX_PTR 0
# define CHECK_WIN_PTR 1
# define CHECK_IMG_PTR 2

typedef struct s_position {
	double	zoom;
	double	move_x;
	double	move_y;
}	t_position;

typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

typedef struct s_mlx_data {
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*data_addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	char		fr_type;
	int			max_iter;
	t_complex	c;
}	t_mlxdata;

typedef struct s_coord {
	int	x;
	int	y;
}	t_coord;

t_complex	get_complex_for_julia(const char *re, const char *im);
void		ft_drawmandelbrottoimg(const t_mlxdata *data, t_position pos);
void		ft_drawjuliatoimg(
				const t_mlxdata *data,
				const t_complex c, const t_position pos);
t_complex	ft_complexinit(double real, double imaginary);
int			get_iterations(
				const int max_iter, t_complex *z, const t_complex *c);
void		complex_from_coordinates(
				t_complex *num, t_coord coord, t_position pos);
t_mlxdata	*getdata(void);
void		ft_fractol(const t_mlxdata *data, const t_position pos);
t_position	zoom_adjust(const int zoom_strategy,
				const double moveX, const double moveY);
int			keyhook(int keycode, t_mlxdata *data);
int			mh(int mk, int x, int y, void *data);
void		get_fr_type(t_mlxdata *data, char fr, t_complex c);
void		checkmlx(t_mlxdata *data, int mode);
void		ft_img_pixel_put(const t_mlxdata *data,
				const t_coord *coord, int color);
void		img_fill_black(const t_mlxdata *img);
#endif