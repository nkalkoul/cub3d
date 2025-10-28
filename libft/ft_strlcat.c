/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkalkoul <nkalkoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 17:25:42 by nkalkoul          #+#    #+#             */
/*   Updated: 2024/05/28 19:39:33 by nkalkoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t fd)
{
	size_t	szed;
	size_t	i;

	szed = ft_strlen(dest);
	i = 0;
	if (fd <= szed)
		return (ft_strlen(src) + fd);
	while (src[i] && (szed + i) < (fd - 1))
	{
		dest[szed + i] = src[i];
		i++;
	}
	dest[szed + i] = 0;
	return (ft_strlen(src) + szed);
}
