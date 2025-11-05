/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_render_helpers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 22:40:00 by assistant         #+#    #+#             */
/*   Updated: 2025/11/05 22:38:11 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_tex_info	get_tex_meta(t_alldata *data, char wall_side)
{
	if (wall_side == 'N')
		return ((t_tex_info){data->mlx.n_addr, data->mlx.n_bpp,
			data->mlx.n_line_len, data->mlx.n_w, data->mlx.n_h, 0, 0.0, 0.0});
	if (wall_side == 'S')
		return ((t_tex_info){data->mlx.s_addr, data->mlx.s_bpp,
			data->mlx.s_line_len, data->mlx.s_w, data->mlx.s_h, 0, 0.0, 0.0});
	if (wall_side == 'E')
		return ((t_tex_info){data->mlx.e_addr, data->mlx.e_bpp,
			data->mlx.e_line_len, data->mlx.e_w, data->mlx.e_h, 0, 0.0, 0.0});
	if (wall_side == 'W')
		return ((t_tex_info){data->mlx.w_addr, data->mlx.w_bpp,
			data->mlx.w_line_len, data->mlx.w_w, data->mlx.w_h, 0, 0.0, 0.0});
	return ((t_tex_info){NULL, 0, 0, 0, 0, 0, 0.0, 0.0});
}

t_bounds	calc_bounds(t_alldata *data)
{
	t_bounds	b;

	if (data->ray.perpWallDist <= 0.0 || !isfinite(data->ray.perpWallDist))
		data->ray.perpWallDist = 1e-6;
	b.line_height = (int)(HEIGHT / data->ray.perpWallDist);
	b.draw_start = -b.line_height / 2 + HEIGHT / 2;
	if (b.draw_start < 0)
		b.draw_start = 0;
	b.draw_end = b.line_height / 2 + HEIGHT / 2;
	if (b.draw_end >= HEIGHT)
		b.draw_end = HEIGHT - 1;
	return (b);
}

char	choose_wall_side_local(t_alldata *data)
{
	if (data->ray.side == 0)
	{
		if (data->ray.stepX > 0)
			return ('W');
		return ('E');
	}
	if (data->ray.stepY > 0)
		return ('N');
	return ('S');
}

void	compute_tex_x(t_alldata *data, t_tex_info *t)
{
	double	wall_x;

	if (data->ray.side == 0)
		wall_x = data->ray.posY + data->ray.perpWallDist * data->ray.dirY;
	else
		wall_x = data->ray.posX + data->ray.perpWallDist * data->ray.dirX;
	wall_x -= floor(wall_x);
	t->tex_x = (int)(wall_x * (double)t->w);
	if (data->ray.side == 0 && data->ray.dirX > 0)
		t->tex_x = t->w - t->tex_x - 1;
	if (data->ray.side == 1 && data->ray.dirY < 0)
		t->tex_x = t->w - t->tex_x - 1;
}

void	draw_textured_column(t_alldata *data, int x, t_bounds *b, t_tex_info *t)
{
	int				tex_y;
	unsigned int	tex_color;
	char			*addr;
	int				i;

	t->step = 1.0 * t->h / (double)b->line_height;
	t->tex_pos = (b->draw_start - HEIGHT / 2 + b->line_height / 2) * t->step;
	i = b->draw_start;
	addr = t->addr;
	while (i <= b->draw_end)
	{
		tex_y = (int)t->tex_pos;
		if (tex_y < 0)
			tex_y = 0;
		if (tex_y >= t->h)
			tex_y = t->h - 1;
		t->tex_pos += t->step;
		tex_color = *(unsigned int *)(addr + tex_y * t->line_len + t->tex_x
				* (t->bpp / 8));
		if (data->ray.side == 1)
			tex_color = (tex_color >> 1) & 0x7F7F7F;
		ft_put_pixel(&data->mlx, x, i, (int)tex_color);
		i++;
	}
}
