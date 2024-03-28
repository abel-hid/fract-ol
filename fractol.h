/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 22:31:52 by abel-hid          #+#    #+#             */
/*   Updated: 2024/03/28 21:45:10 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <unistd.h>

typedef struct s_data 
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	double	xtemp;
	double	zr;
	double	ci;
	double	cr;
	double	zi;
	double	y;
	double	x;
	int		iteration;
	int		max_iteration;
	int		check;
	double	xposition;
	double	yposition;
	double	y_max;
	double	y_min;
	double	x_max;
	double	x_min;
	int		color;
}			t_data;

double	map(double x, double out_min, double out_max);
void	mandelbrot(t_data *data);
void	init_all(t_data *data);
void	init_all_julia(t_data *data);
void	julia(t_data *data);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	parse_argv(int ac, char *av[], t_data *fractol);
int		keyboard_event(int keycode, t_data *fractol);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		event(int keycode, t_data *fractol);
void	ft_parse_julia(int ac, char **av, t_data *fractol);
size_t	ft_strlen(const char *s);
int		ft_strcmp(char *s1, char *s2);
void	ft_putstr(char *str);
void	ft_map(t_data *param);
int		ft_color(t_data *fractol);
void	tricorn(t_data *data);
void	init(t_data *data);
void	parse(int ac, char *av[], t_data *fractol);
int		check(int ac, char **av, t_data *fractol);
int		ft_keycode_julia(int keycode, t_data *fractol);
int		ft_keycode_julia_2(int keycode, t_data *fractol);
double	ft_atof(char *str);
void	ft_error(void);
int		ft_isfloat(float num);

#endif
