/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:59:30 by nsmail            #+#    #+#             */
/*   Updated: 2025/11/04 21:33:19 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void ft_movement(t_alldata *data)
{
    if (data->keyhooks.w)
        move_forward(data);
    if (data->keyhooks.s)
        move_backward(data);
    /* swap strafe handlers to match observed key behaviour */
    if (data->keyhooks.a)
        strafe_right(data);
    if (data->keyhooks.d)
        strafe_left(data);
    if (data->keyhooks.left)
        rotate_left(data);
    if (data->keyhooks.right)
        rotate_right(data);
}

int render(t_alldata *data)
{
    //  si w == true alors on deplace le joueur vers l'avant
    //  si s == true alors on deplace le joueur vers l'arrière
    ft_movement(data);
    exec_general(data);
    mlx_put_image_to_window(data->mlx.init, data->mlx.wind, data->mlx.img, 0, 0);
    return (0);
}

void    init_direction(t_alldata *data)
{
    if (data->dir == 'N')
    {
        data->ray.dirX = 0;
        data->ray.dirY = -1;
        data->ray.planeX = 0.66;
        data->ray.planeY = 0;
    }
    else if (data->dir == 'S')
    {
        data->ray.dirX = 0;
        data->ray.dirY = 1;
        data->ray.planeX = -0.66;
        data->ray.planeY = 0;
    }
    else if (data->dir == 'E')
    {
        data->ray.dirX = 1;
        data->ray.dirY = 0;
        data->ray.planeX = 0;
        data->ray.planeY = 0.66;
    }
    else if (data->dir == 'W')
    {
        data->ray.dirX = -1;
        data->ray.dirY = 0;
        data->ray.planeX = 0;
        data->ray.planeY = -0.66;
    }
}
