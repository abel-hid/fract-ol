/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 22:32:00 by abel-hid          #+#    #+#             */
/*   Updated: 2024/03/28 21:42:42 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_all_julia(t_data *data)
{
	data->zi = map(data->y, data->y_min, data->y_max);
	data->zr = map(data->x, data->x_min, data->x_max);
	data->iteration = 0;
	data->max_iteration = 100;
}

void	julia(t_data *data)
{
	data->y = -1;
	while (++data->y < 800)
	{
		data->x = -1;
		while (++data->x < 800)
		{
			init_all_julia(data);
			while (((data->zr * data->zr) + (data->zi * data->zi)) <= 4
				&& data->iteration < data->max_iteration)
			{
				data->xtemp = ((data->zr * data->zr) - (data->zi * data->zi))
					+ data->cr;
				data->zi = (2 * data->zr * data->zi) + data->ci;
				data->zr = data->xtemp;
				data->iteration++;
			}
			if (data->iteration == data->max_iteration)
				my_mlx_pixel_put(data, data->x, data->y, ft_color(data));
			else
				my_mlx_pixel_put(data, data->x, data->y, ft_color(data)
					* (int)&data->iteration);
		}
	}
}
