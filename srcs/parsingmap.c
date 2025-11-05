/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsingmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nassuto <nassuto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 21:22:50 by nkalkoul          #+#    #+#             */
/*   Updated: 2025/11/05 14:11:27 by nassuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_max_height(t_alldata *data)
{
	int		i;
	int		count;
	char	**map;

	map = data->map;
	i = 0;
	count = 0;
	while (map[i])
	{
		if (count < (int)ft_strlen(map[i]))
			count = (int)ft_strlen(map[i]);
		i++;
	}
	data->max_height = i;
	data->max_width = count;
}

int	ft_checkstring(t_alldata *data, int i, char *start)
{
	int		j;

	if (data->map[i][0] == '\n')
		return (false);
	j = 0;
	while (data->map[i][j])
	{
		if (!ft_strchr(start, data->map[i][j]))
			return (false);
		j++;
	}
	return (true);
}

int	ft_checkstring2(t_alldata *data, int i, char *start)
{
	int		o;
	int		j;

	j = 0;
	while (data->map[i][j])
	{
		o = 0;
		while (start[o])
		{
			if (start[o] == data->map[i][j])
			{
				data->count++;
				data->dir = start[o];
				data->map[i][j] = '0';
				data->px = j;
				data->py = i;
			}
			o++;
		}
		j++;
	}
	return (true);
}

void	ft_check_cara(t_alldata *data)
{
	int		i;
	char	*start;
	char	*pars;

	i = 0;
	pars = ft_strdup("10 NESW");
	start = ft_strdup("NESW");
	if (!pars || !start)
		return (ft_free_and_exit(data, "Malloc error"));
	i = 0;
	while (data->map[i])
	{
		if (!ft_checkstring(data, i, pars) || !ft_checkstring2(data, i, start))
		{
			free(start);
			free(pars);
			ft_free_and_exit(data, "wrong char in map");
		}
		i++;
	}
	free(start);
	free(pars);
	if (data->count != 1)
		ft_free_and_exit(data, "Wrong player number, its must be one");
	data->count = 0;
}

void	ft_parse_map(t_alldata *data)
{
	ft_check_cara(data);
	ft_max_height(data);
	ft_checkopen(data);
}
