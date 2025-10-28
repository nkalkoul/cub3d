/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkalkoul <nkalkoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:54:16 by nkalkoul          #+#    #+#             */
/*   Updated: 2025/10/27 22:41:51 by nkalkoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;

	if (start >= ft_strlen(s))
	{
		new = malloc(1);
		if (new == NULL)
			return (NULL);
		new[0] = '\0';
		return (new);
	}
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	new = malloc(sizeof(char) * len + 1);
	if (new == NULL)
		return (NULL);
	new = (char *)ft_memcpy(new, (s + start), len);
	*(new + len) = '\0';
	return (new);
}
