/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_tres.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nassuto <nassuto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 03:15:53 by nassuto           #+#    #+#             */
/*   Updated: 2025/11/03 05:58:20 by nassuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	get_color(t_color c)
{
	return (0xFF000000 | (c.b << 16) | (c.g << 8) | c.r);
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
