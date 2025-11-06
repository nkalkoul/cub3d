/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:59:30 by nsmail            #+#    #+#             */
/*   Updated: 2025/11/06 18:01:00 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_movement(t_alldata *data)
{
	if (data->keyhooks.w)
		move_forward(data);
	if (data->keyhooks.s)
		move_backward(data);
	if (data->keyhooks.a)
		strafe_right(data);
	if (data->keyhooks.d)
		strafe_left(data);
	if (data->keyhooks.left)
		rotate_left(data);
	if (data->keyhooks.right)
		rotate_right(data);
}

int	render(t_alldata *data)
{
	ft_movement(data);
	exec_general(data);
	mlx_put_image_to_window(data->mlx.init, data->mlx.wind, data->mlx.img, 0,
		0);
	return (0);
}

void	init_direction_norm(t_alldata *data)
{
	if (data->dir == 'E')
	{
		data->ray.dirx = 1;
		data->ray.diry = 0;
		data->ray.planex = 0;
		data->ray.planey = 0.66;
	}
	else if (data->dir == 'W')
	{
		data->ray.dirx = -1;
		data->ray.diry = 0;
		data->ray.planex = 0;
		data->ray.planey = -0.66;
	}
}

void	init_direction(t_alldata *data)
{
	if (data->dir == 'N')
	{
		data->ray.dirx = 0;
		data->ray.diry = -1;
		data->ray.planex = 0.66;
		data->ray.planey = 0;
	}
	else if (data->dir == 'S')
	{
		data->ray.dirx = 0;
		data->ray.diry = 1;
		data->ray.planex = -0.66;
		data->ray.planey = 0;
	}
	init_direction_norm(data);
}

void	ft_put_pixel(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
