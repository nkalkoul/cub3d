/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkalkoul <nkalkoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 21:03:39 by nkalkoul          #+#    #+#             */
/*   Updated: 2025/10/28 16:30:43 by nkalkoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include <stdbool.h>

typedef struct s_mlx
{
	void	*init;
}	t_mlx;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_params
{
	char	*no;
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
	t_mlx		mlx;
	t_params	params;

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

//---------------UTILS--------------------

int		is_color_param(char *str);
int		is_texturefile_param(char *str);
int		whatisthedir(char *str);
char	*ft_skip(char *str, char c);
char	*ft_skipbigtree(char *str);
void	ft_free_and_exit(t_alldata *data, char *str);
int		mini_comp(char *str, char a, char b);
int		mini_len(char *str, char c);

#endif
