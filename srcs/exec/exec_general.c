/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_general.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:53:21 by nsmail            #+#    #+#             */
/*   Updated: 2025/11/03 16:30:50 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	exec_general(t_alldata *data)
{
	(void)data;
	return (1);
}

void	init_raycasting(t_alldata *data)
{
	data->ray->posX = 22;
	data->ray->posY = 12;
	data->ray->dirX = -1;
	data->ray->dirY = 0;
	data->ray->planeX = 0;
	data->ray->planeY = 0.66;
	data->ray->time = 0;
	data->ray->oldTime = 0;
}
