/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 01:57:58 by nkalkoul          #+#    #+#             */
/*   Updated: 2025/11/03 16:31:02 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	freeptr(void *ptr)
{
	if (ptr)
		free(ptr);
}

void	ft_destroy_mlx(t_mlx *mlx)
{
	if (mlx->e)
		mlx_destroy_image(mlx->init, mlx->e);
	if (mlx->n)
		mlx_destroy_image(mlx->init, mlx->n);
	if (mlx->s)
		mlx_destroy_image(mlx->init, mlx->s);
	if (mlx->w)
		mlx_destroy_image(mlx->init, mlx->w);
	if (mlx->wind)
		mlx_destroy_window(mlx->init, mlx->wind);
	if (mlx->init)
		mlx_destroy_display(mlx->init);
}

void	ft_free_and_exit(t_alldata *data, char *str)
{
	if (str)
		ft_printf(1, "Error\n%s\n", str);
	freeptr(data->filecontent);
	freeptr(data->params.ea);
	freeptr(data->params.no);
	freeptr(data->params.so);
	freeptr(data->params.we);
	ft_destroy_mlx(&data->mlx);
	/* mlx.init must not be free()d directly; mlx_destroy_display already handled cleanup */
	(void)data; /* keep signature consistent if data used only for cleanup */
	freeptr(data->ray);
	free_double(data->map);
	free_double(data->copy);
	exit(1);
}
