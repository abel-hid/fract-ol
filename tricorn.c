/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:23:59 by abel-hid          #+#    #+#             */
/*   Updated: 2023/03/07 17:24:04 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "fractol.h"

void	init(t_data *data)
{
	data->zi = 0.0;
	data->zr = 0.0;
	data->iteration = 0;
	data->max_iteration = 80;
	data->cr = map(data->x, data->x_min, data->x_max);
	data->ci = map(data->y, data->y_min, data->y_max);
}

void	tricorn(t_data *data)
{
	data->y = -1;
	while (++data->y < 800)
	{
		data->x = -1;
		while (++data->x < 800)
		{
			init(data);
			while (((data->zr * data->zr) + (data->zi * data->zi)) <= 4
				&& data->iteration < data->max_iteration)
			{
				data->xtemp = ((data->zr * data->zr) - (data->zi * data->zi))
					+ data->cr;
				data->zi = (-2 * data->zr * data->zi) + data->ci;
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
