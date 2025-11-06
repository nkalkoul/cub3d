/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 22:53:11 by nsmail            #+#    #+#             */
/*   Updated: 2025/11/06 18:04:55 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	rotate_left(t_alldata *data)
{
	double	rotspeed;
	double	olddirx;
	double	oldplanex;

	rotspeed = 0.05;
	olddirx = data->ray.dirx;
	data->ray.dirx = data->ray.dirx * cos(rotspeed) - data->ray.diry
		* sin(rotspeed);
	data->ray.diry = olddirx * sin(rotspeed) + data->ray.diry * cos(rotspeed);
	oldplanex = data->ray.planex;
	data->ray.planex = data->ray.planex * cos(rotspeed) - data->ray.planey
		* sin(rotspeed);
	data->ray.planey = oldplanex * sin(rotspeed) + data->ray.planey
		* cos(rotspeed);
}
