/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkalkoul <nkalkoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:15:10 by nkalkoul          #+#    #+#             */
/*   Updated: 2024/05/31 19:06:09 by nkalkoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*temp;

	i = 0;
	temp = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			temp = (char *)(s + i);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)s + i);
	return ((char *)temp);
}
