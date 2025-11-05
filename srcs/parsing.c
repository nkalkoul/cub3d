/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nassuto <nassuto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 21:06:12 by nkalkoul          #+#    #+#             */
/*   Updated: 2025/11/05 13:52:35 by nassuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

//verif le nom du fichier et demarrer le pars

int	ft_start_parsing(t_alldata *data)
{
	char	*cmp;

	if (ft_strlen(data->filename) < 4)
		return (ft_printf(2,
				"Error\nfile map must be in form <map>.cub\n"), false);
	cmp = ft_strrchr(data->filename, '.');
	if (!cmp || ft_strcmp(cmp, ".cub"))
		return (ft_printf(2,
				"Error\nfile map must be in form <map>.cub\n"), false);
	if (!ft_fill_data(data))
		return (false);
	return (true);
}

//deuxieme etape du pars ouvrir le file et lancer la suite

int	ft_fill_data(t_alldata *data)
{
	data->fd = open(data->filename, O_RDONLY | __O_DIRECTORY);
	if (data->fd >= 0)
		return (close(data->fd), ft_printf
			(2, "Error\nverifie the filename for the map\n"), false);
	data->fd = open(data->filename, O_RDONLY);
	if (data->fd == -1)
		return (perror("Error"), false);
	if (!ft_file_content(data))
		return (ft_printf(1, "Error malloc"), false);
	ft_parse_content(data);
	return (true);
}

//pour placer le contenue du fichier dans une string

int	ft_file_content(t_alldata *data)
{
	char	*line;
	char	*content;

	content = ft_strdup("");
	if (!content)
		return (close(data->fd), false);
	line = get_next_line(data->fd);
	while (line)
	{
		content = ft_re_strjoin(content, line);
		if (!content)
			return (close(data->fd), free(line), false);
		free(line);
		line = get_next_line(data->fd);
	}
	close(data->fd);
	data->filecontent = content;
	return (true);
}

// skip les \n et gerer le parsing/remplissage de data.param et copier la map
void	putmap(t_alldata *data, char *str)
{
	int		i;
	int		c;

	i = 0;
	c = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			c++;
		i++;
	}
	i = 0;
	data->map = malloc(sizeof(char *) * (c + 2));
	if (!data->map)
		ft_free_and_exit(data, "Malloc failed");
	ft_memset(data->map, 0, c + 1);
	while (i <= c)
	{
		if (str[0] == '\n')
			ft_free_and_exit(data, "empty line in map");
		data->map[i] = ft_substr(str, 0, mini_len(str, '\n'));
		str += mini_len(str, '\n') + 1;
		i++;
	}
	data->map[i] = 0;
}

void	ft_parse_content(t_alldata *data)
{
	int		i;
	char	*str;

	i = 0;
	str = data->filecontent;
	while (str && i < 6)
	{
		str = ft_skipbigtree(str);
		if (str)
			ft_attribute_params(str, data);
		else
			ft_free_and_exit(data, "We need all params for continue..");
		while (str && *str != '\n')
			str++;
		i++;
	}
	str = ft_skip(str, '\n');
	putmap(data, str);
	if (!data->map)
		ft_free_and_exit(data, "map error copy");
}
