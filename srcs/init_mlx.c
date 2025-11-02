/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkalkoul <nkalkoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 18:55:54 by nkalkoul          #+#    #+#             */
/*   Updated: 2025/11/02 19:15:26 by nkalkoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_init_mlx(t_alldata *data)
{
	data->mlx.init = mlx_init();
	if (!data->mlx.init)
		ft_free_and_exit(data, "initialisation mlx error");
}
