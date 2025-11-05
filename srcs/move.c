/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 17:48:30 by nsmail            #+#    #+#             */
/*   Updated: 2025/11/05 22:59:03 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	move_forward(t_alldata *data)
{
	double	movespeed;

	movespeed = 0.1;
	if (data->map[(int)(data->ray.posY)][(int)(data->ray.posX + data->ray.dirX
			* movespeed)] != '1')
		data->ray.posX += data->ray.dirX * movespeed;
	if (data->map[(int)(data->ray.posY + data->ray.dirY
			* movespeed)][(int)(data->ray.posX)] != '1')
		data->ray.posY += data->ray.dirY * movespeed;
}

void	move_backward(t_alldata *data)
{
	double	movespeed;

	movespeed = 0.1;
	if (data->map[(int)(data->ray.posY)][(int)(data->ray.posX - data->ray.dirX
			* movespeed)] != '1')
		data->ray.posX -= data->ray.dirX * movespeed;
	if (data->map[(int)(data->ray.posY - data->ray.dirY
			* movespeed)][(int)(data->ray.posX)] != '1')
		data->ray.posY -= data->ray.dirY * movespeed;
}

void	strafe_right(t_alldata *data)
{
	double	movespeed;
	double	perpx;
	double	perpy;

	movespeed = 0.08;
	perpx = -data->ray.dirY;
	perpy = data->ray.dirX;
	if (data->map[(int)(data->ray.posY)][(int)(data->ray.posX + perpx
			* movespeed)] != '1')
		data->ray.posX += perpx * movespeed;
	if (data->map[(int)(data->ray.posY + perpy
			* movespeed)][(int)(data->ray.posX)] != '1')
		data->ray.posY += perpy * movespeed;
}

void	strafe_left(t_alldata *data)
{
	double	movespeed;
	double	perpx;
	double	perpy;

	movespeed = 0.08;
	perpx = -data->ray.dirY;
	perpy = data->ray.dirX;
	if (data->map[(int)(data->ray.posY)][(int)(data->ray.posX - perpx
			* movespeed)] != '1')
		data->ray.posX -= perpx * movespeed;
	if (data->map[(int)(data->ray.posY - perpy
			* movespeed)][(int)(data->ray.posX)] != '1')
		data->ray.posY -= perpy * movespeed;
}

void	rotate_right(t_alldata *data)
{
	double	rot_speed;
	double	old_dir_x;
	double	old_plane_x;

	rot_speed = -0.05;
	old_dir_x = data->ray.dirX;
	data->ray.dirX = data->ray.dirX * cos(rot_speed) - data->ray.dirY
		* sin(rot_speed);
	data->ray.dirY = old_dir_x * sin(rot_speed) + data->ray.dirY
		* cos(rot_speed);
	old_plane_x = data->ray.planeX;
	data->ray.planeX = data->ray.planeX * cos(rot_speed) - data->ray.planeY
		* sin(rot_speed);
	data->ray.planeY = old_plane_x * sin(rot_speed) + data->ray.planeY
		* cos(rot_speed);
}
