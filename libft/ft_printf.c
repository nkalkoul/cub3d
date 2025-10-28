/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkalkoul <nkalkoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 19:24:53 by nas91             #+#    #+#             */
/*   Updated: 2024/11/19 23:49:53 by nkalkoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_convert(int fd, va_list carg, char form)
{
	if (form == 'd' || form == 'i')
		return (ft_putintd(fd, carg));
	if (form == 'c')
		return (ft_putc(fd, carg));
	if (form == 's')
		return (ft_puts(fd, va_arg(carg, char *)));
	if (form == 'u')
		return (ft_putu(fd, va_arg(carg, unsigned int)));
	if (form == 'p')
		return (ft_putptr(fd, va_arg(carg, void *)));
	if (form == 'x' || form == 'X')
		return (ft_puthex(fd, va_arg(carg, unsigned int), form));
	if (form == '%')
	{
		ft_putchar_fd('%', fd);
		return (1);
	}
	return (0);
}

int	ft_printf(int fd, const char *str, ...)
{
	va_list	carg;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(carg, str);
	while (str[i])
	{
		if (str[i] == '%')
			count += ft_convert(fd, carg, str[++i]);
		else
		{
			ft_putchar_fd(str[i], fd);
			count++;
		}
		i++;
	}
	va_end(carg);
	return (count);
}
