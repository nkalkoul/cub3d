/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsingmap_bis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkalkoul <nkalkoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 06:37:01 by nkalkoul          #+#    #+#             */
/*   Updated: 2025/10/31 20:29:06 by nkalkoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_floodfill(t_alldata *data, int x, int y)
{
	if (x > data->max_width + 1 || y > data->max_height + 1
		|| x < 0 || y < 0)
		return ;
	if (data->copy[y][x] == '1' || data->copy[y][x] == 'o')
		return ;
	if (data->copy[y][x] == 'P')
	{
		data->count += 1;
		return ;
	}
	data->copy[y][x] = 'o';
	ft_floodfill(data, x + 1, y);
	ft_floodfill(data, x - 1, y);
	ft_floodfill(data, x, y + 1);
	ft_floodfill(data, x, y - 1);
}

char	*ft_carre(char *dest, char *src)
{
	int	i;

	i = 1;
	while (src[i - 1] && dest[i] != '\0')
	{
		dest[i] = src[i - 1];
		i++;
	}
	return (dest);
}

void	ft_copymap(t_alldata *data)
{
	int	i;

	data->copy = malloc(sizeof(char *) * (data->max_height + 3));
	if (!data->copy)
		ft_free_and_exit(data, "malloc failed");
	i = -1;
	while (++i < data->max_height + 2)
	{
		data->copy[i] = malloc(sizeof(char) * (data->max_width + 3));
		if (!data->copy[i])
			ft_free_and_exit(data, "malloc failed");
		ft_memset(data->copy[i], ' ', data->max_width + 2);
		data->copy[i][data->max_width + 2] = '\0';
	}
	data->copy[i] = NULL;
	i = -1;
	while (++i < data->max_height)
		ft_carre(data->copy[i + 1], data->map[i]);
}

void	ft_affichemap(t_alldata *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		printf("@@%s@@\n", data->map[i]);
		i++;
	}
	i = 0;
	while (data->copy[i])
	{
		printf("$%s$\n", data->copy[i]);
		i++;
	}
}

void	ft_checkopen(t_alldata *data)
{
	int	i;

	i = 0;
	ft_copymap(data);
	ft_affichemap(data);
	ft_floodfill(data, 0, 0);
	i = 0;
	if (data->count != 0)
		ft_free_and_exit(data, "map is open");
}
