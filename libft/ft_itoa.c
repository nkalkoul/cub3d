/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkalkoul <nkalkoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 00:56:03 by nas91             #+#    #+#             */
/*   Updated: 2025/10/27 22:41:51 by nkalkoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_len(int n)
{
	int			cl;
	long int	tmp;

	cl = 1;
	tmp = n;
	if (n < 0)
	{
		cl = 2;
		tmp = -tmp;
	}
	while (tmp > 9)
	{
		tmp = tmp / 10;
		cl++;
	}
	return (cl);
}

char	*ft_dothei(char *new, int n, int i)
{
	if (n == -2147483648)
	{
		n = 147483648;
		new[0] = '-';
		new[1] = '2';
	}
	if (n < 0)
	{
		new[0] = '-';
		n = n * -1;
	}
	if (n > 9)
	{
		ft_dothei(new, n / 10, i - 1);
	}
	new[i] = n % 10 + '0';
	return (new);
}

char	*ft_itoa(int n)
{
	int		cl;
	char	*new;

	cl = ft_len(n);
	new = malloc(sizeof(char) * (cl + 1));
	if (new == NULL)
		return (NULL);
	ft_dothei(new, n, (cl - 1));
	new[cl] = '\0';
	return (new);
}
