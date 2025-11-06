/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 22:47:14 by nsmail            #+#    #+#             */
/*   Updated: 2025/11/06 19:48:24 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_close(t_alldata *data)
{
	ft_free_and_exit(data, NULL);
	return (0);
}
void	fill_map(t_alldata *data, char *str, int c)
{
	int	i;

	i = 0;
while (i <= c)
	{
		if (str[0] == '\n')
		{
			data->map[i] = 0;
			ft_free_and_exit(data, "empty line in map");
		}
		data->map[i] = ft_substr(str, 0, mini_len(str, '\n'));
		str += mini_len(str, '\n') + 1;
		i++;
	}
	data->map[i] = 0;
}
