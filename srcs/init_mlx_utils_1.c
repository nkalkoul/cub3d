/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_utils_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 23:30:00 by assistant         #+#    #+#             */
/*   Updated: 2025/11/06 17:56:57 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	load_east_west(t_alldata *d)
{
	int	wimg;
	int	himg;

	d->mlx.e = mlx_xpm_file_to_image(d->mlx.init, d->params.ea, &wimg, &himg);
	if (!d->mlx.e || wimg != 64 || himg != 64)
		ft_free_and_exit(d, "initialisation img east error verifie chem file");
	d->mlx.e_addr = mlx_get_data_addr(d->mlx.e, &d->mlx.e_bpp,
			&d->mlx.e_line_len, &d->mlx.e_endian);
	d->mlx.e_w = wimg;
	d->mlx.e_h = himg;
	d->mlx.w = mlx_xpm_file_to_image(d->mlx.init, d->params.we, &wimg, &himg);
	if (!d->mlx.w || wimg != 64 || himg != 64)
		ft_free_and_exit(d, "initialisation img west error verifie chem file");
	d->mlx.w_addr = mlx_get_data_addr(d->mlx.w, &d->mlx.w_bpp,
			&d->mlx.w_line_len, &d->mlx.w_endian);
	d->mlx.w_w = wimg;
	d->mlx.w_h = himg;
}

static void	load_south_north(t_alldata *d)
{
	int	wimg;
	int	himg;

	d->mlx.s = mlx_xpm_file_to_image(d->mlx.init, d->params.so, &wimg, &himg);
	if (!d->mlx.s || wimg != 64 || himg != 64)
		ft_free_and_exit(d, "initialisation img sud error, verifie chem file");
	d->mlx.s_addr = mlx_get_data_addr(d->mlx.s, &d->mlx.s_bpp,
			&d->mlx.s_line_len, &d->mlx.s_endian);
	d->mlx.s_w = wimg;
	d->mlx.s_h = himg;
	d->mlx.n = mlx_xpm_file_to_image(d->mlx.init, d->params.no, &wimg, &himg);
	if (!d->mlx.n || wimg != 64 || himg != 64)
		ft_free_and_exit(d, "initialisation img nord error, verifie chem file");
	d->mlx.n_addr = mlx_get_data_addr(d->mlx.n, &d->mlx.n_bpp,
			&d->mlx.n_line_len, &d->mlx.n_endian);
	d->mlx.n_w = wimg;
	d->mlx.n_h = himg;
}

void	ft_init_image(t_alldata *d)
{
	load_east_west(d);
	load_south_north(d);
}

int	ft_key_press(int keycode, t_alldata *data)
{
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
	return (0);
}

int	ft_key_release(int keycode, t_alldata *data)
{
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
	return (0);
}
