/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 18:55:54 by nkalkoul          #+#    #+#             */
/*   Updated: 2025/11/05 23:10:44 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_init_mlx(t_alldata *data)
{
	data->mlx.init = mlx_init();
	if (!data->mlx.init)
		ft_free_and_exit(data, "initialisation mlx error");
}

void	ft_create_window_and_image(t_alldata *d)
{
	d->mlx.wind = mlx_new_window(d->mlx.init, WIDTH, HEIGHT, "cub3D");
	if (!d->mlx.wind)
		ft_free_and_exit(d, "Error: failed window creation.");
	d->mlx.img = mlx_new_image(d->mlx.init, WIDTH, HEIGHT);
	if (!d->mlx.img)
		ft_free_and_exit(d, "Error: failed image creation.");
	d->mlx.addr = mlx_get_data_addr(d->mlx.img, &d->mlx.bits_per_pixel,
			&d->mlx.line_length, &d->mlx.endian);
}

void	ft_start_mlx(t_alldata *data)
{
	ft_init_mlx(data);
	ft_init_image(data);
	ft_create_window_and_image(data);
	mlx_hook(data->mlx.wind, KeyPress, KeyPressMask, &ft_key_press, data);
	mlx_hook(data->mlx.wind, KeyRelease, KeyReleaseMask, &ft_key_release, data);
	mlx_hook(data->mlx.wind, 17, 0, &ft_close, data);
	mlx_loop_hook(data->mlx.init, render, data);
	mlx_loop(data->mlx.init);
}
