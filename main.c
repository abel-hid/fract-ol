/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 22:32:12 by abel-hid          #+#    #+#             */
/*   Updated: 2023/01/31 22:32:15 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

int	check_parsing(int ac, char **av, t_data *fractol)
{
	if (ac != 1)
	{
		if ((ft_strcmp(av[1], "julia")) == 0)
		{
			fractol->check = 1;
			return (1);
		}
		if ((ft_strcmp(av[1], "mandelbrot") == 0))
		{
			fractol->check = 2;
			return (2);
		}
		if ((ft_strncmp(av[1], "mandelbrot", ft_strlen(av[1]))) != 0
			|| (ft_strncmp(av[1], "julia", ft_strlen(av[1]))) != 0)
		{
			ft_error();
		}
	}
	return (0);
}

void	parse_argv(int ac, char *av[], t_data *fractol)
{
	if (ac != 1)
	{
		fractol->x_min = -2;
		fractol->x_max = 2;
		fractol->y_min = -2;
		fractol->y_max = 2;
		fractol->color = 1;
		if (check_parsing(ac, av, fractol) == 1)
		{
			julia(fractol);
			ft_parse_julia(ac, av, fractol);
		}
		if (check_parsing(ac, av, fractol) == 2)
		{
			mandelbrot(fractol);
			mlx_mouse_hook(fractol->mlx_win, mouse_hook, fractol);
			mlx_key_hook(fractol->mlx_win, keyboard_event, fractol);
		}
		if ((check_parsing(ac, av, fractol) == 2 && ac != 2))
			exit(1);
	}
}

void	ft_parse_julia(int ac, char **av, t_data *fractol)
{
	int	i;

	i = 0;
	if (ac == 6 || (ft_strncmp(av[1], "julia", 6)))
	{
		if ((ft_strncmp(av[2], "-cx", 3)) || (ft_strncmp(av[4], "-cy", 3)))
			ft_error();
		while (av[i])
		{
			if (!(ft_strncmp(av[i], "-cx", 3))
				&& !(ft_strncmp(av[i + 1], "-cy", 3)))
				exit(1);
			if (!(ft_strncmp(av[i], "-cx", 3)))
			fractol->cr = ft_atof(av[i + 1]);
			if (!(ft_strncmp(av[i], "-cy", 3)))
			fractol->ci = ft_atof(av[i + 1]);
			i++;
		}
		julia(fractol);
		mlx_key_hook(fractol->mlx_win, keyboard_event, fractol);
		mlx_mouse_hook(fractol->mlx_win, mouse_hook, fractol);
	}
	else
		ft_error();
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
		parse_argv(ac, av, &image);
		mlx_put_image_to_window(image.mlx, image.mlx_win, image.img, 0, 0);
		mlx_loop(image.mlx);
	}
	else
		ft_error();
}
