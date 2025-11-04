/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 18:55:54 by nkalkoul          #+#    #+#             */
/*   Updated: 2025/11/04 21:33:19 by nsmail           ###   ########.fr       */
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
	/* cache east texture data */
	d->mlx.e_addr = mlx_get_data_addr(d->mlx.e, &d->mlx.e_bpp,
			&d->mlx.e_line_len, &d->mlx.e_endian);
	d->mlx.e_w = wimg;
	d->mlx.e_h = himg;
	d->mlx.w = mlx_xpm_file_to_image(d->mlx.init, d->params.we, &wimg, &himg);
	if (!d->mlx.w || wimg != 64 || himg != 64)
		ft_free_and_exit(d, "initialisation img west error verifie chem file");
	/* cache west texture data */
	d->mlx.w_addr = mlx_get_data_addr(d->mlx.w, &d->mlx.w_bpp,
			&d->mlx.w_line_len, &d->mlx.w_endian);
	d->mlx.w_w = wimg;
	d->mlx.w_h = himg;
	d->mlx.s = mlx_xpm_file_to_image(d->mlx.init, d->params.so, &wimg, &himg);
	if (!d->mlx.s || wimg != 64 || himg != 64)
		ft_free_and_exit(d, "initialisation img sud error, verifie chem file");
	/* cache south texture data */
	d->mlx.s_addr = mlx_get_data_addr(d->mlx.s, &d->mlx.s_bpp,
			&d->mlx.s_line_len, &d->mlx.s_endian);
	d->mlx.s_w = wimg;
	d->mlx.s_h = himg;
	d->mlx.n = mlx_xpm_file_to_image(d->mlx.init, d->params.no, &wimg, &himg);
	if (!d->mlx.n || wimg != 64 || himg != 64)
		ft_free_and_exit(d, "initialisation img nord error, verifie chem file");
	/* cache north texture data */
	d->mlx.n_addr = mlx_get_data_addr(d->mlx.n, &d->mlx.n_bpp,
			&d->mlx.n_line_len, &d->mlx.n_endian);
	d->mlx.n_w = wimg;
	d->mlx.n_h = himg;
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

void	ft_key_press(int keycode, t_alldata *data)
{
	printf("[KEY_PRESS] keycode=%d\n", keycode);
	if (keycode == XK_Escape)
		ft_close(data);
	if (keycode == XK_w)
		data->keyhooks.w = true;
	if (keycode == XK_s)
		data->keyhooks.s = true;
	if (keycode == XK_a || keycode == XK_q)
		data->keyhooks.a = true;
	if (keycode == XK_d)
		data->keyhooks.d = true;
	if (keycode == XK_Left)
		data->keyhooks.left = true;
	if (keycode == XK_Right)
		data->keyhooks.right = true;
}

void ft_key_release(int keycode, t_alldata *data)
{
	printf("[KEY_RELEASE] keycode=%d\n", keycode);
	if (keycode == XK_w)
		data->keyhooks.w = false;
	if (keycode == XK_s)
		data->keyhooks.s = false;
	if (keycode == XK_a || keycode == XK_q)
		data->keyhooks.a = false;
	if (keycode == XK_d)
		data->keyhooks.d = false;
	if (keycode == XK_Left)
		data->keyhooks.left = false;
	if (keycode == XK_Right)
		data->keyhooks.right = false;
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
