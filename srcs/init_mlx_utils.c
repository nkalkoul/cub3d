/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:59:30 by nsmail            #+#    #+#             */
/*   Updated: 2025/11/03 16:07:19 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int render(t_alldata *data)
{
    exec_general(data);
    mlx_put_image_to_window(data->mlx.init, data->mlx.wind, data->mlx.img, 0, 0);
    return (0);
}
