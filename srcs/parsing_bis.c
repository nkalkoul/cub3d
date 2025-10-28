/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkalkoul <nkalkoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 06:00:41 by nkalkoul          #+#    #+#             */
/*   Updated: 2025/10/28 11:14:37 by nkalkoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_fill_color(char *str, t_alldata *data)
{
	int		i;
	char	symbol;

	symbol = str[0];
	i = 0;
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
	if (symbol == 'C')
		ft_fill_ceiling(str, data);
	else
		ft_fill_floor(str, data);
}

void	ft_check_extension(char *str, t_alldata *data)
{
	char	*cmp;

	if (ft_strlen(str) < 4)
		ft_free_and_exit(data, "no good extension file .xpm");
	cmp = ft_strrchr(str, '.');
	if (!cmp || ft_strcmp(cmp, ".xpm"))
		ft_free_and_exit(data, "no good extension <file>.xpm");

}

void	ft_fill_xpmfile_param(char *str, t_alldata *data, int s)
{
	if (s == 1)
	{
		data->params.no = ft_substr(str, 0, mini_len(str, '\n'));
		ft_check_extension(data->params.no, data);
	}
	else if (s == 2)
	{
		data->params.we = ft_substr(str, 0, mini_len(str, '\n'));
		ft_check_extension(data->params.we, data);
	}
	else if (s == 3)
	{
		data->params.so = ft_substr(str, 0, mini_len(str, '\n'));
		ft_check_extension(data->params.so, data);
	}
	else if (s == 4)
	{
		data->params.ea = ft_substr(str, 0, mini_len(str, '\n'));
		ft_check_extension(data->params.ea, data);
	}
}

void	ft_check_xpm(char *str, t_alldata *data)
{
	int	symbol;
	int	i;

	i = 0;
	symbol = whatisthedir(str);
	if (!ft_isspace(str[2]))
		return (ft_free_and_exit(data, "Bad indentation in xpm file def"));
	str = &str[2];
	while (str && !ft_isprint(str[0]))
	{
		str = ft_skip(str, ' ');
		str = ft_skip(str, '\t');
	}
	while (str && str[i] != '\n')
	{
		if (!ft_isprint(str[i]))
			ft_free_and_exit(data, "no valid xpm files");
		i++;
	}
	ft_fill_xpmfile_param(str, data, symbol);
}

void	ft_attribute_params(char *str, t_alldata *data)
{
	if (is_color_param(str))
		ft_fill_color(str, data);
	else if (is_xpmfile_param(str))
		ft_check_xpm(str, data);
	else
		ft_free_and_exit(data, "We need definition of param for continue");
}
