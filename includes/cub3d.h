/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkalkoul <nkalkoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 21:03:39 by nkalkoul          #+#    #+#             */
/*   Updated: 2025/11/02 19:14:37 by nkalkoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include <stdbool.h>
# include <X11/X.h>
# include <X11/keysym.h>

# define HEIGH 1200
# define WIDTH 900
typedef struct s_mlx
{
	void	*init;
	void	*n;
	void	*s;
	void	*e;
	void	*w;
	void	*wind;
}	t_mlx;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
	int	final_color;
}	t_color;

typedef struct s_params
{
	char	*no; // les chemin vers les images en fct de leur direction(mur nor mur sud etc)
	char	*so;
	char	*ea;
	char	*we;
	t_color	floor;
	t_color	ceiling;
}	t_params;

typedef struct s_alldata
{
	int			fd;
	char		*filename;
	char		*filecontent;
	char		**map;
	char		**copy;
	int			py;			//position y du joueur (map[y][x])
	int			px;			// position x du joueur
	char		dir;		// N S E ou W
	int			count;
	int			max_height;
	int			max_width;
	t_mlx		mlx;
	t_params	params;		// parametre (couleur r,g,b et image)
}	t_alldata;

// -------------PARSING------------------

int		ft_start_parsing(t_alldata *data);
int		ft_fill_data(t_alldata *data);
int		ft_file_content(t_alldata *data);
void	ft_parse_content(t_alldata *data);
void	ft_attribute_params(char *str, t_alldata *data);
void	ft_fill_color(char *str, t_alldata *data);
void	ft_fill_ceiling(char *str, t_alldata *data);
void	ft_fill_floor(char *str, t_alldata *data);
void	ft_check_formatc(char *str, t_alldata *data);
void	ft_parse_map(t_alldata *data);
void	ft_checkopen(t_alldata *data);


//---------------UTILS--------------------

int		is_color_param(char *str);
int		is_texturefile_param(char *str);
int		whatisthedir(char *str);
char	*ft_skip(char *str, char c);
char	*ft_skipbigtree(char *str);
void	ft_free_and_exit(t_alldata *data, char *str);
int		mini_comp(char *str, char a, char b);
int		mini_len(char *str, char c);
int		is_validcara(char c);
int		get_color(t_color c);

#endif
