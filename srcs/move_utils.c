/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 22:53:11 by nsmail            #+#    #+#             */
/*   Updated: 2025/11/05 23:28:40 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	rotate_left(t_alldata *data)
{
	double	rotspeed;
	double	olddirx;
	double	oldplanex;

	rotspeed = 0.05;
	olddirx = data->ray.dirX;
	data->ray.dirX = data->ray.dirX * cos(rotspeed) - data->ray.dirY
		* sin(rotspeed);
	data->ray.dirY = olddirx * sin(rotspeed) + data->ray.dirY * cos(rotspeed);
	oldplanex = data->ray.planeX;
	data->ray.planeX = data->ray.planeX * cos(rotspeed) - data->ray.planeY
		* sin(rotspeed);
	data->ray.planeY = oldplanex * sin(rotspeed) + data->ray.planeY
		* cos(rotspeed);
}
