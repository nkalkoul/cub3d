/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_general.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:53:21 by nsmail            #+#    #+#             */
/*   Updated: 2025/11/03 19:34:19 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	exec_general(t_alldata *data)
{
	int			x;
	t_vector	ray;

	x = 0;
	while (x < WIDTH)
	{
		ray = calc_ray_direction(data, x);
		data->ray->dirX = ray.x;
		data->ray->dirY = ray.y;
		init_ray(data);
        calc_step_and_sidedist(data->ray);
		x++;
	}
	return (1);
}

t_vector	calc_ray_direction(t_alldata *data, int x)
{
	double		cameraX;
	t_vector	ray;

	cameraX = 2.0 * x / (double)(WIDTH)-1.0;
	ray.x = data->ray->origDirX + data->ray->planeX * cameraX;
	ray.y = data->ray->origDirY + data->ray->planeY * cameraX;
	return (ray);
}

void	init_ray(t_alldata *data)
{
	data->ray->posX = data->px + 0.5;
	data->ray->posY = data->py + 0.5;
	data->ray->mapX = (int)data->ray->posX;
	data->ray->mapY = (int)data->ray->posY;
	data->ray->deltaDistX = (data->ray->dirX == 0) ? 1e30 : fabs(1
			/ data->ray->dirX);
	data->ray->deltaDistY = (data->ray->dirY == 0) ? 1e30 : fabs(1
			/ data->ray->dirY);
	data->ray->hit = 0;
	data->ray->side = 0;
	data->ray->stepX = 0;
	data->ray->stepY = 0;
	data->ray->sideDistX = 0;
	data->ray->sideDistY = 0;
	data->ray->perpWallDist = 0;
}

void calc_step_and_sidedist(t_raycasting *ray)
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

void	init_raycasting(t_alldata *data)
{
	data->ray->posX = 22;
	data->ray->posY = 12;
	data->ray->dirX = data->ray->origDirX = -1;
	data->ray->dirY = data->ray->origDirY = 0;
	data->ray->planeX = 0;
	data->ray->planeY = 0.66;
	data->ray->time = 0;
	data->ray->oldTime = 0;
}
