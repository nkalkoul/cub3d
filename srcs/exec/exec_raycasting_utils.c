/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_raycasting_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 20:00:00 by assistant         #+#    #+#             */
/*   Updated: 2025/11/06 18:02:55 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_ray(t_alldata *data)
{
	data->ray.mapx = (int)data->ray.posx;
	data->ray.mapy = (int)data->ray.posy;
	if (data->ray.dirx == 0.0)
		data->ray.deltadistx = 1e30;
	else
		data->ray.deltadistx = fabs(1.0 / data->ray.dirx);
	if (data->ray.diry == 0.0)
		data->ray.deltadisty = 1e30;
	else
		data->ray.deltadisty = fabs(1.0 / data->ray.diry);
	data->ray.hit = 0;
	data->ray.side = 0;
	data->ray.stepx = 0;
	data->ray.stepy = 0;
	data->ray.sidedistx = 0.0;
	data->ray.sidedisty = 0.0;
	data->ray.perpwalldist = 0.0;
}

void	calc_step_and_sidedist(t_raycasting *ray)
{
	if (ray->dirx < 0)
	{
		ray->stepx = -1;
		ray->sidedistx = (ray->posx - ray->mapx) * ray->deltadistx;
	}
	else
	{
		ray->stepx = 1;
		ray->sidedistx = (ray->mapx + 1.0 - ray->posx) * ray->deltadistx;
	}
	if (ray->diry < 0)
	{
		ray->stepy = -1;
		ray->sidedisty = (ray->posy - ray->mapy) * ray->deltadisty;
	}
	else
	{
		ray->stepy = 1;
		ray->sidedisty = (ray->mapy + 1.0 - ray->posy) * ray->deltadisty;
	}
}

void	perform_dda(t_alldata *data)
{
	while (data->ray.hit == 0)
	{
		if (data->ray.sidedistx < data->ray.sidedisty)
		{
			data->ray.sidedistx += data->ray.deltadistx;
			data->ray.mapx += data->ray.stepx;
			data->ray.side = 0;
		}
		else
		{
			data->ray.sidedisty += data->ray.deltadisty;
			data->ray.mapy += data->ray.stepy;
			data->ray.side = 1;
		}
		if (data->map[data->ray.mapy][data->ray.mapx] == '1')
			data->ray.hit = 1;
	}
}

void	calculate_perp_wall_dist(t_alldata *data)
{
	if (data->ray.side == 0)
		data->ray.perpwalldist = (data->ray.sidedistx - data->ray.deltadistx);
	else
		data->ray.perpwalldist = (data->ray.sidedisty - data->ray.deltadisty);
}
