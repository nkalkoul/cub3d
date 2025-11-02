/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_fill_param.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nassuto <nassuto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 07:40:23 by nkalkoul          #+#    #+#             */
/*   Updated: 2025/11/02 03:26:31 by nassuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// check bidon pour la forme 0,0,0 sans espace ni rien

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
	str += mini_len(str, ',') + 1;
	data->params.ceiling.g = ft_atoi(str);
	str += mini_len(str, ',') + 1;
	data->params.ceiling.b = ft_atoi(str);
	data->params.ceiling.final_color = get_color(data->params.ceiling);
}

void	ft_fill_floor(char *str, t_alldata *data)
{
	data->params.floor.r = ft_atoi(str);
	str += mini_len(str, ',') + 1;
	data->params.floor.g = ft_atoi(str);
	str += mini_len(str, ',') + 1;
	data->params.floor.b = ft_atoi(str);
	data->params.floor.final_color = get_color(data->params.floor);
}
