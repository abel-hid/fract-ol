/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:04:33 by abel-hid          #+#    #+#             */
/*   Updated: 2023/03/08 18:12:39 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_check(char *str, int i)
{
	int	n;

	n = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			n *= -1;
		i++;
	}
	return (n);
}

double	ft_handler(char *str, int i)
{
	double	result;
	double	divider;

	result = 0.0;
	divider = 10.0;
	if (!*str)
		ft_error();
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10.0) + str[i] - 48;
		i++;
	}
	if (str[i] == '.')
	{
		i++;
		while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
		{
			result += (str[i] - 48) / divider;
			divider *= 10.0;
			i++;
		}
	}
	return (result);
}

int	is_valid(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-')
			i++;
		if (str[i] == 46)
		{
			j++;
			i++;
		}
		if (j == 2 || str[0] == 46 || str[0] == '\0')
			ft_error();
		if (str[i] >= 58 || str[i] <= 47)
			return (1);
		i++;
	}
	return (0);
}

double	ft_atof(char *str)
{
	int		i;
	int		n;
	double	result;

	i = 0;
	if (is_valid(str))
		ft_error();
	n = ft_check(str, i);
	if (str[i] == '-' || str[i] == '+')
		i++;
	result = ft_handler(str, i);
	return (result * n);
}
