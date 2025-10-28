/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkalkoul <nkalkoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 06:28:30 by nkalkoul          #+#    #+#             */
/*   Updated: 2025/10/28 15:08:44 by nkalkoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	is_color_param(char *str)
{
	if (str[0] == 'C' || str[0] == 'F')
		return (true);
	return (false);
}

int	whatisthedir(char *str)
{
	if (mini_comp(str, 'N', 'O'))
		return (1);
	else if (mini_comp(str, 'W', 'E'))
		return (2);
	else if (mini_comp(str, 'S', 'O'))
		return (3);
	else if (mini_comp(str, 'E', 'A'))
		return (4);
	return (false);
}

int	is_texturefile_param(char *str)
{
	if (mini_comp(str, 'N', 'O'))
		return (true);
	else if (mini_comp(str, 'W', 'E'))
		return (true);
	else if (mini_comp(str, 'S', 'O'))
		return (true);
	else if (mini_comp(str, 'E', 'A'))
		return (true);
	return (false);
}

int	mini_len(char *str, char c)
{
	int	i;

	i = 0;
	while (str && str[i] != c)
		i++;
	return (i);
}
