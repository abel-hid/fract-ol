/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:38:34 by abel-hid          #+#    #+#             */
/*   Updated: 2023/03/02 18:38:40 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_color(t_data *fractol)
{
	int	i;

	i = 0;
	if (fractol->color == 1)
		i = (0x00FDFFFC >> 4) * fractol->iteration ;
	if (fractol->color == 2)
		i = 0x00235789 * fractol->iteration;
	if (fractol->color == 3)
		i = 0x00C1292E * fractol->iteration;
	if (fractol->color == 4)
		i = 0x00F1D302 * fractol->iteration;
	if (fractol->color == 5)
		i = 0x00FFFFFF * fractol->iteration;
	if (fractol->color == 6)
		i = 0x00F96F5D * fractol->iteration;
	return (i);
}
