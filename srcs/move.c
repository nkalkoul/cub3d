/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 17:48:30 by nsmail            #+#    #+#             */
/*   Updated: 2025/11/04 22:44:11 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void move_forward(t_alldata *data)
{
    double moveSpeed = 0.08; // adjust movement speed as needed
    if (data->map[(int)(data->ray.posY)][(int)(data->ray.posX + data->ray.dirX * moveSpeed)] != '1')
        data->ray.posX += data->ray.dirX * moveSpeed;
    if (data->map[(int)(data->ray.posY + data->ray.dirY * moveSpeed)][(int)(data->ray.posX)] != '1')
        data->ray.posY += data->ray.dirY * moveSpeed;
}

void move_backward(t_alldata *data)
{
    double moveSpeed = 0.08; // adjust movement speed as needed
    if (data->map[(int)(data->ray.posY)][(int)(data->ray.posX - data->ray.dirX * moveSpeed)] != '1')
        data->ray.posX -= data->ray.dirX * moveSpeed;
    if (data->map[(int)(data->ray.posY - data->ray.dirY * moveSpeed)][(int)(data->ray.posX)] != '1')
        data->ray.posY -= data->ray.dirY * moveSpeed;
}

void strafe_right(t_alldata *data)
{
    double moveSpeed = 0.08; // adjust movement speed as needed
    double perpX = -data->ray.dirY;
    double perpY = data->ray.dirX;
    if (data->map[(int)(data->ray.posY)][(int)(data->ray.posX + perpX * moveSpeed)] != '1')
        data->ray.posX += perpX * moveSpeed;
    if (data->map[(int)(data->ray.posY + perpY * moveSpeed)][(int)(data->ray.posX)] != '1')
        data->ray.posY += perpY * moveSpeed;
}

void strafe_left(t_alldata *data)
{
    double moveSpeed = 0.08; // adjust movement speed as needed
    double perpX = -data->ray.dirY;
    double perpY = data->ray.dirX;
    if (data->map[(int)(data->ray.posY)][(int)(data->ray.posX - perpX * moveSpeed)] != '1')
        data->ray.posX -= perpX * moveSpeed;
    if (data->map[(int)(data->ray.posY - perpY * moveSpeed)][(int)(data->ray.posX)] != '1')
        data->ray.posY -= perpY * moveSpeed;
}

void rotate_right(t_alldata *data)
{
    double rotSpeed = -0.03; // positive = left, negative = right
    double oldDirX = data->ray.dirX;
    data->ray.dirX = data->ray.dirX * cos(rotSpeed) - data->ray.dirY * sin(rotSpeed);
    data->ray.dirY = oldDirX * sin(rotSpeed) + data->ray.dirY * cos(rotSpeed);
    double oldPlaneX = data->ray.planeX;
    data->ray.planeX = data->ray.planeX * cos(rotSpeed) - data->ray.planeY * sin(rotSpeed);
    data->ray.planeY = oldPlaneX * sin(rotSpeed) + data->ray.planeY * cos(rotSpeed);
}

void rotate_left(t_alldata *data)
{
    double rotSpeed = 0.03; // positive = left, negative = right
    double oldDirX = data->ray.dirX;
    data->ray.dirX = data->ray.dirX * cos(rotSpeed) - data->ray.dirY * sin(rotSpeed);
    data->ray.dirY = oldDirX * sin(rotSpeed) + data->ray.dirY * cos(rotSpeed);
    double oldPlaneX = data->ray.planeX;
    data->ray.planeX = data->ray.planeX * cos(rotSpeed) - data->ray.planeY * sin(rotSpeed);
    data->ray.planeY = oldPlaneX * sin(rotSpeed) + data->ray.planeY * cos(rotSpeed);
}
