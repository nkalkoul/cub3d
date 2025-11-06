/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 06:00:41 by nkalkoul          #+#    #+#             */
/*   Updated: 2025/11/06 21:08:00 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

//debut du pars des couleur et lancer le remplissement de la struct color

void	ft_fill_color(char *str, t_alldata *data)
{
	char	symbol;

	symbol = str[0];
	if (!ft_isspace(str[1]))
		return (ft_free_and_exit(data, "Bad indentation in color def"));
	str = &str[1];
	while (str && !ft_isdigit(str[0]))
	{
		str = ft_skip(str, ' ');
		str = ft_skip(str, '\t');
	}
	if (!ft_isdigit(str[0]))
		ft_free_and_exit(data, "we need color format");
	if (mini_len(str, '\n') < 5 || mini_len(str, '\n') > 11)
		return (ft_free_and_exit(data,
				"Color format must be between 0,0,0 and 255,255,255"));
	ft_check_formatc(str, data);
	if (symbol == 'C' && !data->params.ceiling.r && !data->params.ceiling.g
		&& !data->params.ceiling.b)
		ft_fill_ceiling(str, data);
	else if (symbol == 'F' && !data->params.floor.r && !data->params.floor.g
		&& !data->params.floor.b)
		ft_fill_floor(str, data);
	else
		ft_free_and_exit(data, "Duplicate color definition");
}

//remplir la struct param des path des texture

void	ft_fill_texturefile_param(char *str, t_alldata *data, int s)
{
	if (s == 1 && !data->params.no)
		data->params.no = ft_substr(str, 0, mini_len(str, '\n'));
	else if (s == 2 && !data->params.we)
		data->params.we = ft_substr(str, 0, mini_len(str, '\n'));
	else if (s == 3 && !data->params.so)
		data->params.so = ft_substr(str, 0, mini_len(str, '\n'));
	else if (s == 4 && !data->params.ea)
		data->params.ea = ft_substr(str, 0, mini_len(str, '\n'));
	else
		ft_free_and_exit(data, "Duplicate texture file definition");
}

void	ft_check_texture(char *str, t_alldata *data)
{
	int	symbol;
	int	i;

	i = 0;
	symbol = whatisthedir(str);
	if (!ft_isspace(str[2]))
		return (ft_free_and_exit(data, "Bad indentation in texture file def"));
	str = &str[2];
	while (str && !ft_isprint(str[0]))
	{
		str = ft_skip(str, ' ');
		str = ft_skip(str, '\t');
	}
	while (str && str[i] != '\n')
	{
		if (!ft_isprint(str[i]))
			ft_free_and_exit(data, "no valid texture files");
		i++;
	}
	ft_fill_texturefile_param(str, data, symbol);
}

void	ft_attribute_params(char *str, t_alldata *data)
{
	if (is_color_param(str))
		ft_fill_color(str, data);
	else if (is_texturefile_param(str))
		ft_check_texture(str, data);
	else
		ft_free_and_exit(data, "We need definition of 6 param for continue");
}
