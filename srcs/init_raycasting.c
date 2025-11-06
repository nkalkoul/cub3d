/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_raycasting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 23:00:55 by nsmail            #+#    #+#             */
/*   Updated: 2025/11/06 18:01:36 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_raycasting_utils(t_alldata *data)
{
	if (data->dir == 'E')
	{
		data->ray.dirx = 0.0;
		data->ray.diry = 1.0;
		data->ray.planex = 0.66;
		data->ray.planey = 0.0;
	}
	else if (data->dir == 'W')
	{
		data->ray.dirx = 0.0;
		data->ray.diry = -1.0;
		data->ray.planex = -0.66;
		data->ray.planey = 0.0;
	}
}

void	init_raycasting(t_alldata *data)
{
	data->ray.posx = (double)data->px + 0.5;
	data->ray.posy = (double)data->py + 0.5;
	data->ray.movespeed = 5.0;
	data->ray.rotspeed = 3.0;
	data->ray.time = 0.0;
	data->ray.oldtime = 0.0;
	data->ray.frametime = 0.0;
	if (data->dir == 'N')
	{
		data->ray.dirx = -1.0;
		data->ray.diry = 0.0;
		data->ray.planex = 0.0;
		data->ray.planey = 0.66;
	}
	else if (data->dir == 'S')
	{
		data->ray.dirx = 1.0;
		data->ray.diry = 0.0;
		data->ray.planex = 0.0;
		data->ray.planey = -0.66;
	}
	else
		init_raycasting_utils(data);
}
