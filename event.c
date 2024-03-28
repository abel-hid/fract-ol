/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:23:38 by abel-hid          #+#    #+#             */
/*   Updated: 2023/03/07 18:12:39 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

double	map(double x, double out_min, double out_max)
{
	return ((x - 0) * (out_max - out_min) / (800 - 0) + out_min);
}

int	keyboard_event(int keycode, t_data *fractol)
{
	ft_keycode_julia(keycode, fractol);
	ft_keycode_julia_2(keycode, fractol);
	if (keycode == 12)
	{
		fractol->color += 1;
		if (fractol->color == 6)
		fractol->color = 1;
		ft_map(fractol);
	}
	if (keycode == 53)
	{
		mlx_destroy_image(fractol->mlx, fractol->img);
		mlx_destroy_window(fractol->mlx, fractol->mlx_win);
		exit(1);
	}
	return (EXIT_SUCCESS);
}

int	ft_keycode_julia(int keycode, t_data *fractol)
{
	if (keycode == 13)
	{
		fractol->ci += 0.1;
		fractol->cr += 0.1;
		ft_map(fractol);
	}
	if (keycode == 14)
	{
		fractol->ci -= 0.1;
		fractol->cr -= 0.1;
		ft_map(fractol);
	}
	if (keycode == 15)
	{
		fractol->ci += 0.1;
		ft_map(fractol);
	}
	if (keycode == 17)
	{
		fractol->ci -= 0.1;
		ft_map(fractol);
	}
	return (0);
}

int	ft_keycode_julia_2(int keycode, t_data *fractol)
{
	if (keycode == 16)
	{
		fractol->cr += 0.1;
		ft_map(fractol);
	}
	if (keycode == 32)
	{
		fractol->cr -= 0.1;
		ft_map(fractol);
	}
	return (0);
}
