/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_raycasting_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 20:00:00 by assistant         #+#    #+#             */
/*   Updated: 2025/11/04 21:34:53 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_ray(t_alldata *data)
{
	data->ray.mapX = (int)data->ray.posX;
	data->ray.mapY = (int)data->ray.posY;
	if (data->ray.dirX == 0.0)
		data->ray.deltaDistX = 1e30;
	else
		data->ray.deltaDistX = fabs(1.0 / data->ray.dirX);
	if (data->ray.dirY == 0.0)
		data->ray.deltaDistY = 1e30;
	else
		data->ray.deltaDistY = fabs(1.0 / data->ray.dirY);
	data->ray.hit = 0;
	data->ray.side = 0;
	data->ray.stepX = 0;
	data->ray.stepY = 0;
	data->ray.sideDistX = 0.0;
	data->ray.sideDistY = 0.0;
	data->ray.perpWallDist = 0.0;
}

void	calc_step_and_sidedist(t_raycasting *ray)
{
	if (ray->dirX < 0)
	{
		ray->stepX = -1;
		ray->sideDistX = (ray->posX - ray->mapX) * ray->deltaDistX;
	}
	else
	{
		ray->stepX = 1;
		ray->sideDistX = (ray->mapX + 1.0 - ray->posX) * ray->deltaDistX;
	}
	if (ray->dirY < 0)
	{
		ray->stepY = -1;
		ray->sideDistY = (ray->posY - ray->mapY) * ray->deltaDistY;
	}
	else
	{
		ray->stepY = 1;
		ray->sideDistY = (ray->mapY + 1.0 - ray->posY) * ray->deltaDistY;
	}
}

void	perform_dda(t_alldata *data)
{
	while (data->ray.hit == 0)
	{
		if (data->ray.sideDistX < data->ray.sideDistY)
		{
			data->ray.sideDistX += data->ray.deltaDistX;
			data->ray.mapX += data->ray.stepX;
			data->ray.side = 0;
		}
		else
		{
			data->ray.sideDistY += data->ray.deltaDistY;
			data->ray.mapY += data->ray.stepY;
			data->ray.side = 1;
		}
		if (data->map[data->ray.mapY][data->ray.mapX] == '1')
			data->ray.hit = 1;
	}
}

void	calculate_perp_wall_dist(t_alldata *data)
{
	if (data->ray.side == 0)
		data->ray.perpWallDist = (data->ray.sideDistX - data->ray.deltaDistX);
	else
		data->ray.perpWallDist = (data->ray.sideDistY - data->ray.deltaDistY);
}
