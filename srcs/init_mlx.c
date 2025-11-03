/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nassuto <nassuto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 18:55:54 by nkalkoul          #+#    #+#             */
/*   Updated: 2025/11/03 06:27:06 by nassuto          ###   ########.fr       */
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
	ft_init_image(data);
}
