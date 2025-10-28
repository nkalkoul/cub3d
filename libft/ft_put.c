/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkalkoul <nkalkoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:23:48 by nkalkoul          #+#    #+#             */
/*   Updated: 2025/10/27 22:42:00 by nkalkoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putintd(int fd, va_list carg)
{
	int		count;
	char	*str;

	count = 0;
	str = ft_itoa(va_arg(carg, int));
	count = ft_strlen(str);
	ft_putstr_fd(str, fd);
	free(str);
	return (count);
}

int	ft_putc(int fd, va_list carg)
{
	ft_putchar_fd(va_arg(carg, int), fd);
	return (1);
}

int	ft_puts(int fd, char *str)
{
	int		count;

	if (!str)
		return (write(2, "(null)", 6));
	count = ft_strlen(str);
	ft_putstr_fd(str, fd);
	return (count);
}

int	ft_putu(int fd, unsigned int n)
{
	int	count;

	count = 0;
	if (n > 9)
		count += ft_putu(fd, n / 10);
	count++;
	ft_putchar_fd((n % 10) + '0', fd);
	return (count);
}
