/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 20:30:00 by assistant         #+#    #+#             */
/*   Updated: 2025/11/04 20:30:00 by assistant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	get_tex_meta(t_alldata *data, char wall_side, char **addr, int *bpp,
		int *line_len, int *w, int *h)
{
	if (wall_side == 'N')
	{
		*addr = data->mlx.n_addr;
		*bpp = data->mlx.n_bpp;
		*line_len = data->mlx.n_line_len;
		*w = data->mlx.n_w;
		*h = data->mlx.n_h;
	}
	else if (wall_side == 'S')
	{
		*addr = data->mlx.s_addr;
		*bpp = data->mlx.s_bpp;
		*line_len = data->mlx.s_line_len;
		*w = data->mlx.s_w;
		*h = data->mlx.s_h;
	}
	else if (wall_side == 'E')
	{
		*addr = data->mlx.e_addr;
		*bpp = data->mlx.e_bpp;
		*line_len = data->mlx.e_line_len;
		*w = data->mlx.e_w;
		*h = data->mlx.e_h;
	}
	else if (wall_side == 'W')
	{
		*addr = data->mlx.w_addr;
		*bpp = data->mlx.w_bpp;
		*line_len = data->mlx.w_line_len;
		*w = data->mlx.w_w;
		*h = data->mlx.w_h;
	}
	else
	{
		*addr = NULL;
		*bpp = 0;
		*line_len = 0;
		*w = 0;
		*h = 0;
	}
}

void	render_column(t_alldata *data, int x)
{
	int		line_height;
	int		draw_start;
	int		draw_end;
	char	wall_side;
	char	*tex_addr;
	int		tex_bpp;
	int		tex_line_len;
	int		tex_w;
	int		tex_h;
	int		i;
		double wall_x;
		double step_tex;
		double tex_pos;
		int tex_x;
		int tex_y;
		unsigned int tex_color;

	if (data->ray.perpWallDist <= 0.0 || !isfinite(data->ray.perpWallDist))
		data->ray.perpWallDist = 1e-6;
	line_height = (int)(HEIGHT / data->ray.perpWallDist);
	draw_start = -line_height / 2 + HEIGHT / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = line_height / 2 + HEIGHT / 2;
	if (draw_end >= HEIGHT)
		draw_end = HEIGHT - 1;
	if (data->ray.side == 0)
	{
		if (data->ray.stepX > 0)
			wall_side = 'W';
		else
			wall_side = 'E';
	}
	else
	{
		if (data->ray.stepY > 0)
			wall_side = 'N';
		else
			wall_side = 'S';
	}
	get_tex_meta(data, wall_side, &tex_addr, &tex_bpp, &tex_line_len, &tex_w,
		&tex_h);
	if (tex_addr && tex_w > 0 && tex_h > 0)
	{
		if (data->ray.side == 0)
			wall_x = data->ray.posY + data->ray.perpWallDist * data->ray.dirY;
		else
			wall_x = data->ray.posX + data->ray.perpWallDist * data->ray.dirX;
		wall_x -= floor(wall_x);
		tex_x = (int)(wall_x * (double)tex_w);
		if (data->ray.side == 0 && data->ray.dirX > 0)
			tex_x = tex_w - tex_x - 1;
		if (data->ray.side == 1 && data->ray.dirY < 0)
			tex_x = tex_w - tex_x - 1;
		step_tex = 1.0 * tex_h / (double)line_height;
		tex_pos = (draw_start - HEIGHT / 2 + line_height / 2) * step_tex;
		i = draw_start;
		while (i <= draw_end)
		{
			tex_y = (int)tex_pos;
			if (tex_y < 0)
				tex_y = 0;
			if (tex_y >= tex_h)
				tex_y = tex_h - 1;
			tex_pos += step_tex;
			tex_color = *(unsigned int *)(tex_addr + tex_y * tex_line_len
					+ tex_x * (tex_bpp / 8));
			if (data->ray.side == 1)
				tex_color = (tex_color >> 1) & 0x7F7F7F;
			ft_put_pixel(&data->mlx, x, i, (int)tex_color);
			i++;
		}
	}
}
