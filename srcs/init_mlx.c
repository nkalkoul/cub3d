/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 18:55:54 by nkalkoul          #+#    #+#             */
/*   Updated: 2025/11/03 17:05:22 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_init_image(t_alldata *d)
{
	int	wimg;
	int	himg;

	d->mlx.e = mlx_xpm_file_to_image(d->mlx.init, d->params.ea, &wimg, &himg);
	if (!d->mlx.e || wimg != 64 || himg != 64)
		ft_free_and_exit(d, "initialisation img east error verifie chem file");
	d->mlx.w = mlx_xpm_file_to_image(d->mlx.init, d->params.we, &wimg, &himg);
	if (!d->mlx.w || wimg != 64 || himg != 64)
		ft_free_and_exit(d, "initialisation img west error verifie chem file");
	d->mlx.s = mlx_xpm_file_to_image(d->mlx.init, d->params.so, &wimg, &himg);
	if (!d->mlx.s || wimg != 64 || himg != 64)
		ft_free_and_exit(d, "initialisation img sud error, verifie chem file");
	d->mlx.n = mlx_xpm_file_to_image(d->mlx.init, d->params.no, &wimg, &himg);
	if (!d->mlx.n || wimg != 64 || himg != 64)
		ft_free_and_exit(d, "initialisation img nord error, verifie chem file");
}

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

void	ft_put_pixel(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_start_mlx(t_alldata *data)
{
	ft_init_mlx(data);
	ft_init_image(data);
	ft_create_window_and_image(data);
	mlx_loop_hook(data->mlx.init, render, data);
	mlx_loop(data->mlx.init);
}
