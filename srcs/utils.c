/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkalkoul <nkalkoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 01:57:58 by nkalkoul          #+#    #+#             */
/*   Updated: 2025/10/28 11:39:18 by nkalkoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*ft_skipbigtree(char *str)
{
	while (str && (str[0] == '\n' || str[0] == '\t'))
	{
		str = ft_skip(str, '\n');
		str = ft_skip(str, '\t');
	}
	str = ft_skip(str, ' ');
	return (str);
}

char	*ft_skip(char *str, char c)
{
	int	i;

	i = 0;
	while (str && *str == c)
		str++;
	return (str);
}

int	mini_comp(char *str, char a, char b)
{
	if (str[0] == a && str[1] == b)
		return (true);
	return (false);
}

void	freeptr(void *ptr)
{
	if (ptr)
		free(ptr);
}

void	ft_free_and_exit(t_alldata *data, char *str)
{
	if (str)
		ft_printf(1, "Error\n%s\n", str);
	freeptr(data->filecontent);
	freeptr(data->params.ea);
	freeptr(data->params.no);
	freeptr(data->params.so);
	freeptr(data->params.we);
	free_double(data->map);
	exit(1);
}
