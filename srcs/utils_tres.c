/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_tres.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 03:15:53 by nassuto           #+#    #+#             */
/*   Updated: 2025/11/05 22:49:34 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	get_color(t_color c)
{
	return (((c.r & 0xFF) << 16) | ((c.g & 0xFF) << 8) | (c.b & 0xFF));
}

char	*ft_skip(char *str, char c)
{
	while (str && *str == c)
		str++;
	return (str);
}

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

int	mini_comp(char *str, char a, char b)
{
	if (str[0] == a && str[1] == b)
		return (true);
	return (false);
}

int	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}
