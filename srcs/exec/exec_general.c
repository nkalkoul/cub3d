/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_general.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:53:21 by nsmail            #+#    #+#             */
/*   Updated: 2025/11/04 16:58:56 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	exec_general(t_alldata *data)
{
	int			x;
	t_vector	ray;
	double		oldDirX;
	double		oldDirY;

	x = 0;
	init_raycasting(data);
	while (x < WIDTH)
	{
		ray = calc_ray_direction(data, x);
		oldDirX = data->ray->dirX;
		oldDirY = data->ray->dirY;
		data->ray->dirX = ray.x;
		data->ray->dirY = ray.y;
		init_ray(data);
		calc_step_and_sidedist(data->ray);
		perform_dda(data);
		calculate_perp_wall_dist(data);
		render_column(data, x);
		data->ray->dirX = oldDirX;
		data->ray->dirY = oldDirY;
		x++;
	}
	return (1);
}

t_vector	calc_ray_direction(t_alldata *data, int x)
{
	double		cameraX;
	t_vector	ray;

	cameraX = 2.0 * (double)x / (double)WIDTH - 1.0;
	/* use current (possibly rotated) direction */
	ray.x = data->ray->dirX + data->ray->planeX * cameraX;
	ray.y = data->ray->dirY + data->ray->planeY * cameraX;
	return (ray);
}

void	init_ray(t_alldata *data)
{
	data->ray->posX = data->px + 0.5;
	data->ray->posY = data->py + 0.5;
	data->ray->mapX = (int)data->ray->posX;
	data->ray->mapY = (int)data->ray->posY;
	data->ray->deltaDistX = (data->ray->dirX == 0.0) ? 1e30 : fabs(1.0
			/ data->ray->dirX);
	data->ray->deltaDistY = (data->ray->dirY == 0.0) ? 1e30 : fabs(1.0
			/ data->ray->dirY);
	data->ray->hit = 0;
	data->ray->side = 0;
	data->ray->stepX = 0;
	data->ray->stepY = 0;
	data->ray->sideDistX = 0.0;
	data->ray->sideDistY = 0.0;
	data->ray->perpWallDist = 0.0;
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
	while (data->ray->hit == 0)
	{
		if (data->ray->sideDistX < data->ray->sideDistY)
		{
			data->ray->sideDistX += data->ray->deltaDistX;
			data->ray->mapX += data->ray->stepX;
			data->ray->side = 0;
		}
		else
		{
			data->ray->sideDistY += data->ray->deltaDistY;
			data->ray->mapY += data->ray->stepY;
			data->ray->side = 1;
		}
		if (data->ray->mapY < 0 || data->ray->mapY >= data->max_height
			|| data->ray->mapX < 0 || data->ray->mapX >= data->max_width)
		{
			data->ray->hit = 1;
			break ;
		}
		if (data->map[data->ray->mapY][data->ray->mapX] == '1')
			data->ray->hit = 1;
	}
}

void	calculate_perp_wall_dist(t_alldata *data)
{
	if (data->ray->side == 0)
		data->ray->perpWallDist = (data->ray->sideDistX
				- data->ray->deltaDistX);
	else
		data->ray->perpWallDist = (data->ray->sideDistY
				- data->ray->deltaDistY);
	if (data->ray->perpWallDist <= 0.0 || !isfinite(data->ray->perpWallDist))
		data->ray->perpWallDist = 1e-6;
}

void	render_column(t_alldata *data, int x)
{
	int		lineHeight;
	int		drawStart;
	int		drawEnd;
	int		color;
	char	wallTexture;
	int		i;

	lineHeight = (int)(HEIGHT / data->ray->perpWallDist);
	drawStart = -lineHeight / 2 + HEIGHT / 2;
	if (drawStart < 0)
		drawStart = 0;
	drawEnd = lineHeight / 2 + HEIGHT / 2;
	if (drawEnd >= HEIGHT)
		drawEnd = HEIGHT - 1;
	/* bounds-check before accessing map */
	wallTexture = ' ';
	if (data->ray->mapY >= 0 && data->ray->mapY < data->max_height
		&& data->ray->mapX >= 0 && data->ray->mapX < data->max_width)
		wallTexture = data->map[data->ray->mapY][data->ray->mapX];
	switch (wallTexture)
	{
	case 'N':
		color = 0xFF0000; // Red for North wall
		break ;
	case 'S':
		color = 0x00FF00; // Green for South wall
		break ;
	case 'E':
		color = 0x0000FF; // Blue for East wall
		break ;
	case 'W':
		color = 0xFFFF00; // Yellow for West wall
		break ;
	default:
		color = 0xFFFFFF; // White as default
		break ;
	}
	if (data->ray->side == 1)
		color = color / 2; // Darken color for Y sides
	i = drawStart;
	while (i <= drawEnd)
	{
		ft_put_pixel(&data->mlx, x, i, color);
		i++;
	}
}

void update_player(t_alldata *data)
{
	double oldDirX, oldPlaneX;
	
	data->ray->oldTime = data->ray->time;
	data->ray->time = get_time();
	data->ray->frameTime = (data->ray->time - data->ray->oldTime) / 1000.0; // frameTime is the time this frame has taken, in seconds
	data->ray->moveSpeed = data->ray->frameTime * 5.0; // the constant value is in squares/second
	data->ray->rotSpeed = data->ray->frameTime * 3.0; // the constant value is in radians/second
}

void	init_raycasting(t_alldata *data)
{
	data->ray->posX = 22.0;
	data->ray->posY = 12.0;
	data->ray->dirX = -1.0;
	data->ray->dirY = 0.0;
	data->ray->origDirX = data->ray->dirX;
	data->ray->origDirY = data->ray->dirY;
	data->ray->planeX = 0.0;
	data->ray->planeY = 0.66;
	data->ray->time = 0.0;
	data->ray->oldTime = 0.0;
}
