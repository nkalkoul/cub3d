/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsingmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkalkoul <nkalkoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 21:22:50 by nkalkoul          #+#    #+#             */
/*   Updated: 2025/10/30 08:42:44 by nkalkoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_max_height(t_alldata *data)
{
	int		i;
	int		j;
	int		count;
	char	**map;

	map = data->map;
	i = 0;
	j = 0;
	count = 0;
	while (map[i])
	{
		if (count < ft_strlen(map[i]))
			count = ft_strlen(map[i]);
		i++;
	}
	data->max_height = i;
	data->max_width = count;
}

int	ft_checkstring(t_alldata *data, int i)
{
	if (data->map[i][0] == '\n')
		return (false);
	return (true);
}

int	ft_checkstring2(t_alldata *data, int i, char *start)
{
	int		o;
	char	**map;
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
				data->map[i][j] = 'P';
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

	i = 0;
	while (data->map[i])
	{
		printf("$%s$\n", data->map[i]);
		i++;
	}
	start = ft_strdup("NESW");
	i = 0;
	while (data->map[i])
	{
		if (!ft_checkstring(data, i) || !ft_checkstring2(data, i, start))
		{
			free(start);
			ft_free_and_exit(data, "wrong char in map");
		}
		i++;
	}
	free(start);
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
