/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 17:48:30 by nsmail            #+#    #+#             */
/*   Updated: 2025/11/06 18:04:36 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	move_forward(t_alldata *data)
{
	double	movespeed;

	movespeed = 0.1;
	if (data->map[(int)(data->ray.posy)][(int)(data->ray.posx + data->ray.dirx
			* movespeed)] != '1')
		data->ray.posx += data->ray.dirx * movespeed;
	if (data->map[(int)(data->ray.posy + data->ray.diry
			* movespeed)][(int)(data->ray.posx)] != '1')
		data->ray.posy += data->ray.diry * movespeed;
}

void	move_backward(t_alldata *data)
{
	double	movespeed;

	movespeed = 0.1;
	if (data->map[(int)(data->ray.posy)][(int)(data->ray.posx - data->ray.dirx
			* movespeed)] != '1')
		data->ray.posx -= data->ray.dirx * movespeed;
	if (data->map[(int)(data->ray.posy - data->ray.diry
			* movespeed)][(int)(data->ray.posx)] != '1')
		data->ray.posy -= data->ray.diry * movespeed;
}

void	strafe_right(t_alldata *data)
{
	double	movespeed;
	double	perpx;
	double	perpy;

	movespeed = 0.08;
	perpx = -data->ray.diry;
	perpy = data->ray.dirx;
	if (data->map[(int)(data->ray.posy)][(int)(data->ray.posx + perpx
			* movespeed)] != '1')
		data->ray.posx += perpx * movespeed;
	if (data->map[(int)(data->ray.posy + perpy
			* movespeed)][(int)(data->ray.posx)] != '1')
		data->ray.posy += perpy * movespeed;
}

void	strafe_left(t_alldata *data)
{
	double	movespeed;
	double	perpx;
	double	perpy;

	movespeed = 0.08;
	perpx = -data->ray.diry;
	perpy = data->ray.dirx;
	if (data->map[(int)(data->ray.posy)][(int)(data->ray.posx - perpx
			* movespeed)] != '1')
		data->ray.posx -= perpx * movespeed;
	if (data->map[(int)(data->ray.posy - perpy
			* movespeed)][(int)(data->ray.posx)] != '1')
		data->ray.posy -= perpy * movespeed;
}

void	rotate_right(t_alldata *data)
{
	double	rot_speed;
	double	old_dir_x;
	double	old_plane_x;

	rot_speed = -0.05;
	old_dir_x = data->ray.dirx;
	data->ray.dirx = data->ray.dirx * cos(rot_speed) - data->ray.diry
		* sin(rot_speed);
	data->ray.diry = old_dir_x * sin(rot_speed) + data->ray.diry
		* cos(rot_speed);
	old_plane_x = data->ray.planex;
	data->ray.planex = data->ray.planex * cos(rot_speed) - data->ray.planey
		* sin(rot_speed);
	data->ray.planey = old_plane_x * sin(rot_speed) + data->ray.planey
		* cos(rot_speed);
}
