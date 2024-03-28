/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:40:30 by abel-hid          #+#    #+#             */
/*   Updated: 2023/03/07 18:40:32 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_map(t_data *param)
{
	mlx_clear_window(param->mlx, param->mlx_win);
	mlx_destroy_image(param->mlx, param->img);
	param->img = mlx_new_image(param->mlx, 800, 800);
	param->addr = mlx_get_data_addr(param->img, &param->bits_per_pixel,
			&param->line_length, &param->endian);
	if (param->check == 1)
		julia(param);
	if (param->check == 2)
		mandelbrot(param);
	mlx_put_image_to_window(param->mlx, param->mlx_win, param->img, 0, 0);
}
