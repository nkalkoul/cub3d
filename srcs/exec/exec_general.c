/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_general.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:53:21 by nsmail            #+#    #+#             */
/*   Updated: 2025/11/04 21:33:19 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_background(t_alldata *data)
{
	int		total_pixels;
	t_color	ceiling_color;
	t_color	floor_color;
	int		i;

	total_pixels = WIDTH * HEIGHT;
	ceiling_color = data->params.ceiling;
	floor_color = data->params.floor;
	i = 0;
	while (i < total_pixels / 2)
	{
		ft_put_pixel(&data->mlx, i % WIDTH, i / WIDTH,
			ceiling_color.final_color);
		i++;
	}
	while (i < total_pixels)
	{
		ft_put_pixel(&data->mlx, i % WIDTH, i / WIDTH, floor_color.final_color);
		i++;
	}
}

int	exec_general(t_alldata *data)
{
	int			x;
	t_vector	ray;
	double		old_dir_x;
	double		old_dir_y;

	x = 0;
	draw_background(data);
	while (x < WIDTH)
	{
		ray = calc_ray_direction(data, x);
		old_dir_x = data->ray.dirX;
		old_dir_y = data->ray.dirY;
		data->ray.dirX = ray.x;
		data->ray.dirY = ray.y;
		init_ray(data);
		calc_step_and_sidedist(&data->ray);
		perform_dda(data);
		calculate_perp_wall_dist(data);
		render_column(data, x);
		data->ray.dirX = old_dir_x;
		data->ray.dirY = old_dir_y;
		x++;
	}
	return (1);
}

t_vector	calc_ray_direction(t_alldata *data, int x)
{
	double		camera_x;
	t_vector	ray;

	camera_x = 2.0 * (double)x / (double)WIDTH - 1.0;
	ray.x = data->ray.dirX + data->ray.planeX * camera_x;
	ray.y = data->ray.dirY + data->ray.planeY * camera_x;
	return (ray);
}

void	init_keyhooks(t_alldata *data)
{
	data->keyhooks.w = false;
	data->keyhooks.s = false;
	data->keyhooks.a = false;
	data->keyhooks.d = false;
	data->keyhooks.left = false;
	data->keyhooks.right = false;
}
