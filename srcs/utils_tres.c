/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_tres.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkalkoul <nkalkoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 03:15:53 by nassuto           #+#    #+#             */
/*   Updated: 2025/11/02 19:17:20 by nkalkoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	get_color(t_color c)
{
	return (0xFF000000 | (c.b << 16) | (c.g << 8) | c.r);
}

char	*ft_skip(char *str, char c)
{
	int	i;

	i = 0;
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
