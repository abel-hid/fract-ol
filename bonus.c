/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:24:10 by abel-hid          #+#    #+#             */
/*   Updated: 2024/03/28 21:35:35 by abel-hid         ###   ########.fr       */
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
		tricorn(param);
	mlx_put_image_to_window(param->mlx, param->mlx_win, param->img, 0, 0);
}

int	mouse_hook(int keycode, int x, int y, t_data *param)
{
	param->xposition = (param->x_min - param->x_max) / 800;
	param->yposition = (param->y_min - param->y_max) / 800;
	if (keycode == 4)
	{
		param->x_min += (x * param->xposition) * 0.2;
		param->x_max -= ((800 - x) * param->xposition) * 0.2;
		param->y_min += (y * param->yposition) * 0.2;
		param->y_max -= ((800 - y) * param->yposition) * 0.2;
		ft_map(param);
	}
	if (keycode == 5)
	{
		param->x_min -= (x * param->xposition) * 0.2;
		param->x_max += ((800 - x) * param->xposition) * 0.2;
		param->y_min -= (y * param->yposition) * 0.2;
		param->y_max += ((800 - y) * param->yposition) * 0.2;
		ft_map(param);
	}
	return (0);
}

int	check(int ac, char **av, t_data *fractol)
{
	(void)ac;
	if ((ft_strcmp(av[1], "tricorn")) == 0)
	{
		fractol->check = 1;
		return (1);
	}
	if ((ft_strncmp(av[1], "tricorn", ft_strlen(av[1]))) != 0)
	{
		ft_putstr("#### HINT ####\n");
		ft_putstr("./fractol tricorn");
		exit(1);
	}
	return (0);
}

void	parse(int ac, char *av[], t_data *fractol)
{
	if (ac == 2)
	{
		fractol->x_min = -2;
		fractol->x_max = 2;
		fractol->y_min = -2;
		fractol->y_max = 2;
		fractol->color = 1;
		if (check(ac, av, fractol) == 1)
		{
			tricorn(fractol);
			mlx_mouse_hook(fractol->mlx_win, mouse_hook, fractol);
			mlx_key_hook(fractol->mlx_win, keyboard_event, fractol);
		}
	}
	else
	{
		ft_putstr("#### HINT ####\n");
		ft_putstr("./fractol tricorn");
		exit(1);
	}
}

int	main(int ac, char *av[])
{
	t_data	image;
	

	if (ac != 1)
	{
		image.mlx = mlx_init();
		image.mlx_win = mlx_new_window(image.mlx, 800, 800, "fractol");
		image.img = mlx_new_image(image.mlx, 800, 800);
		image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel,
				&image.line_length, &image.endian);
		parse(ac, av, &image);
		mlx_put_image_to_window(image.mlx, image.mlx_win, image.img, 0, 0);
		mlx_loop(image.mlx);
	}
	else
	{
		ft_putstr("#### HINT ####\n");
		ft_putstr("./fractol tricorn");
		exit(1);
	}
}
