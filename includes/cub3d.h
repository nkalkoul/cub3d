/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 21:03:39 by nkalkoul          #+#    #+#             */
/*   Updated: 2025/11/05 23:31:59 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <sys/time.h>
# include <math.h>
# include <stdbool.h>

# define HEIGHT 1080
# define WIDTH 1920
typedef struct s_mlx
{
	void			*init;
	void			*wind;
	//
	void			*n;
	void			*s;
	void			*e;
	void			*w;

	/* cached texture image data (addr/bpp/line_length/endian + size) */
	char			*n_addr;
	int			n_bpp;
	int			n_line_len;
	int			n_endian;
	int			n_w;
	int			n_h;

	char			*s_addr;
	int			s_bpp;
	int			s_line_len;
	int			s_endian;
	int			s_w;
	int			s_h;

	char			*e_addr;
	int			e_bpp;
	int			e_line_len;
	int			e_endian;
	int			e_w;
	int			e_h;

	char			*w_addr;
	int			w_bpp;
	int			w_line_len;
	int			w_endian;
	int			w_w;
	int			w_h;
	//
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_mlx;

typedef struct s_keyhooks
{
	bool			w;
	bool			s;
	bool			a;
	bool			d;
	bool			left;
	bool			right;
}					t_keyhooks;

typedef struct s_color
{
	int				r;
	int				g;
	int				b;
	int				final_color;
}					t_color;

typedef struct s_params
{
	char			*no;
	// les chemin vers les images en fct de leur direction(mur nor mur sud etc)
	char			*so;
	char			*ea;
	char			*we;
	t_color			floor;
	t_color			ceiling;
}					t_params;

typedef struct s_raycasting
{
	// position of the player
	double			posX;
	double			posY;
	double			dirX;
	double			dirY;
	double			origDirX;
	double			origDirY;
	double			planeX;
	double			planeY;
	// time
	double			time;
	double			oldTime;
	double			frameTime;
	// movement speed
	double			moveSpeed;
	double			rotSpeed;
	// raycasting variables
	int				mapX;
	int				mapY;
	double			sideDistX;
	double			sideDistY;
	double			deltaDistX;
	double			deltaDistY;
	double			perpWallDist;
	int				stepX;
	int				stepY;
	int				hit;
	int				side;
}					t_raycasting;

typedef struct s_vector
{
	double			x;
	double			y;
}					t_vector;

typedef struct s_alldata
{
	int				fd;
	char			*filename;
	char			*filecontent;
	char			**map;
	char			**copy;
	int py;   // position y du joueur (map[y][x])
	int px;   // position x du joueur
	char dir; // N S E ou W
	int				count;
	int				max_height;
	int				max_width;
	t_mlx			mlx;
	t_keyhooks		keyhooks;
	t_params params; // parametre (couleur r,g,b et image)
	t_raycasting	ray;
}					t_alldata;

// -------------PARSING------------------

int					ft_start_parsing(t_alldata *data);
int					ft_fill_data(t_alldata *data);
int					ft_file_content(t_alldata *data);
void				ft_parse_content(t_alldata *data);
void				ft_attribute_params(char *str, t_alldata *data);
void				ft_fill_color(char *str, t_alldata *data);
void				ft_fill_ceiling(char *str, t_alldata *data);
void				ft_fill_floor(char *str, t_alldata *data);
void				ft_check_formatc(char *str, t_alldata *data);
void				ft_parse_map(t_alldata *data);
void				ft_checkopen(t_alldata *data);

//---------------UTILS--------------------

int					is_color_param(char *str);
int					is_texturefile_param(char *str);
int					whatisthedir(char *str);
char				*ft_skip(char *str, char c);
char				*ft_skipbigtree(char *str);
void				ft_free_and_exit(t_alldata *data, char *str);
int					mini_comp(char *str, char a, char b);
int					mini_len(char *str, char c);
int					is_validcara(char c);
int					get_color(t_color c);

//--------------MLX & EXEC-----------------

void				ft_init_mlx(t_alldata *data);
void				ft_init_image(t_alldata *d);
void				ft_create_window_and_image(t_alldata *d);
void				ft_put_pixel(t_mlx *mlx, int x, int y, int color);
void				ft_start_mlx(t_alldata *data);
int					exec_general(t_alldata *data);
void				init_raycasting(t_alldata *data);
void				init_ray(t_alldata *data);
void				calc_step_and_sidedist(t_raycasting *ray);
void				perform_dda(t_alldata *data);
int					render(t_alldata *data);
t_vector			calc_ray_direction(t_alldata *data, int x);
void				calc_step_and_sidedist(t_raycasting *ray);
void				perform_dda(t_alldata *data);
void				calculate_perp_wall_dist(t_alldata *data);
void				render_column(t_alldata *data, int x);
void				update_player(t_alldata *data);
int 				get_time(void);
int				ft_close(t_alldata *data);
void				init_keyhooks(t_alldata *data);
int			ft_key_press(int keycode, t_alldata *data);
int			ft_key_release(int keycode, t_alldata *data);

typedef struct s_bounds
{
	int	line_height;
	int	draw_start;
	int	draw_end;
}
t_bounds;

typedef struct s_tex_info
{
	char	*addr;
	int	bpp;
	int	line_len;
	int	w;
	int	h;
	int	tex_x;
	double	step;
	double	tex_pos;
}
t_tex_info;

t_tex_info	get_tex_meta(t_alldata *data, char wall_side);
t_bounds	calc_bounds(t_alldata *data);
char		choose_wall_side_local(t_alldata *data);
void		compute_tex_x(t_alldata *data, t_tex_info *t);
void		draw_textured_column(t_alldata *data, int x, t_bounds *b,
 						 t_tex_info *t);

// --------------MOVEMENT-----------------
void				ft_move(t_alldata *data);
void				move_forward(t_alldata *data);
void				move_backward(t_alldata *data);
void				strafe_left(t_alldata *data);
void				strafe_right(t_alldata *data);
void				rotate_left(t_alldata *data);
void				rotate_right(t_alldata *data);
void				init_direction(t_alldata *data);

#endif
