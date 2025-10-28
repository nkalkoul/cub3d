/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkalkoul <nkalkoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 01:29:28 by nas91             #+#    #+#             */
/*   Updated: 2025/10/27 22:41:51 by nkalkoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>

char	*before_line(char *line)
{
	size_t	i;
	char	*new;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		i++;
	new = malloc(sizeof(char) * (i + 1));
	if (new == NULL)
		return (free(line), NULL);
	fts_strlcpy(new, line, i + 1);
	return (free(line), new);
}

char	*after_line(char *save, char *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i] && line[i] != '\n')
		i++;
	while (line[i])
		save[j++] = line[++i];
	save[j] = '\0';
	return (save);
}

char	*ft_gnl(int fd, char *buffer, char *save, char *line)
{
	int	bf;

	bf = 1;
	while (bf > 0 && !fts_strchr(line, '\n'))
	{
		bf = read(fd, buffer, BUFFER_SIZE);
		if (bf == -1)
		{
			save[0] = 0;
			return (free(buffer), free(line), NULL);
		}
		buffer[bf] = '\0';
		line = ft_re_strjoin(line, buffer);
		if (line == NULL)
			return (free(buffer), free(line), NULL);
	}
	after_line(save, line);
	line = before_line(line);
	if (line == NULL || line[0] == '\0')
		return (free(buffer), free(line), NULL);
	return (free(buffer), line);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	save[BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = fts_substr(save, 0, fts_strlen(save));
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer || !line)
		return (free(buffer), free(line), NULL);
	return (ft_gnl(fd, buffer, save, line));
}

// int	main(void)
// {
// 	int fd = open("ey.txt", O_RDONLY);
// 	char	*str;

// 	str = get_next_line(fd);
// 	while (str)
// 	{
// 		printf(".%s", str);
// 		free(str);
// 		str = get_next_line(fd);
// 	}
// 	free(str);
// 	return 0;
// }
