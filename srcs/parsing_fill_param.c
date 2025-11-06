/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_fill_param.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 07:40:23 by nkalkoul          #+#    #+#             */
/*   Updated: 2025/11/06 18:24:07 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_check_formatc(char *str, t_alldata *data)
{
	int	len;
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		if (str[i] != ',' && !ft_isdigit(str[i]))
			ft_free_and_exit(data, "You have to use <,> and numbers only");
		i++;
	}
	i = 0;
	while (i < 2)
	{
		len = mini_len(str, ',');
		if (len > 3 || len < 1)
			ft_free_and_exit(data, "You have to use <,> for format r,g,b");
		str += len + 1;
		i++;
	}
}

// remplissage bidon atoi simple

void	ft_fill_ceiling(char *str, t_alldata *data)
{
	data->params.ceiling.r = ft_atoi(str);
	if (data->params.ceiling.r < 0 || data->params.ceiling.r > 255)
		ft_free_and_exit(data, "Ceiling color value out of range (0-255)");
	str += mini_len(str, ',') + 1;
	data->params.ceiling.g = ft_atoi(str);
	if (data->params.ceiling.g < 0 || data->params.ceiling.g > 255)
		ft_free_and_exit(data, "Ceiling color value out of range (0-255)");
	str += mini_len(str, ',') + 1;
	data->params.ceiling.b = ft_atoi(str);
	if (data->params.ceiling.b < 0 || data->params.ceiling.b > 255)
		ft_free_and_exit(data, "Ceiling color value out of range (0-255)");
	data->params.ceiling.final_color = get_color(data->params.ceiling);
}

void	ft_fill_floor(char *str, t_alldata *data)
{
	data->params.floor.r = ft_atoi(str);
	if (data->params.floor.r < 0 || data->params.floor.r > 255)
		ft_free_and_exit(data, "Floor color value out of range (0-255)");
	str += mini_len(str, ',') + 1;
	data->params.floor.g = ft_atoi(str);
	if (data->params.floor.g < 0 || data->params.floor.g > 255)
		ft_free_and_exit(data, "Floor color value out of range (0-255)");
	str += mini_len(str, ',') + 1;
	data->params.floor.b = ft_atoi(str);
	if (data->params.floor.b < 0 || data->params.floor.b > 255)
		ft_free_and_exit(data, "Floor color value out of range (0-255)");
	data->params.floor.final_color = get_color(data->params.floor);
}
