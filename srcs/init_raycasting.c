/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_raycasting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 23:00:55 by nsmail            #+#    #+#             */
/*   Updated: 2025/11/05 23:01:03 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_raycasting_utils(t_alldata *data)
{
	if (data->dir == 'E')
	{
		data->ray.dirX = 0.0;
		data->ray.dirY = 1.0;
		data->ray.planeX = 0.66;
		data->ray.planeY = 0.0;
	}
	else if (data->dir == 'W')
	{
		data->ray.dirX = 0.0;
		data->ray.dirY = -1.0;
		data->ray.planeX = -0.66;
		data->ray.planeY = 0.0;
	}
}

void	init_raycasting(t_alldata *data)
{
	data->ray.posX = (double)data->px + 0.5;
	data->ray.posY = (double)data->py + 0.5;
	data->ray.moveSpeed = 5.0;
	data->ray.rotSpeed = 3.0;
	data->ray.time = 0.0;
	data->ray.oldTime = 0.0;
	data->ray.frameTime = 0.0;
	if (data->dir == 'N')
	{
		data->ray.dirX = -1.0;
		data->ray.dirY = 0.0;
		data->ray.planeX = 0.0;
		data->ray.planeY = 0.66;
	}
	else if (data->dir == 'S')
	{
		data->ray.dirX = 1.0;
		data->ray.dirY = 0.0;
		data->ray.planeX = 0.0;
		data->ray.planeY = -0.66;
	}
	else
		init_raycasting_utils(data);
}
