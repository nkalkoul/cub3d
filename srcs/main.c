/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkalkoul <nkalkoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 20:59:59 by nkalkoul          #+#    #+#             */
/*   Updated: 2025/10/30 03:07:18 by nkalkoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int ac, char **av)
{
	t_alldata	data;

	if (ac != 2)
		return (ft_printf(1, "Error\nYou must have only a map in args"), 1);
	ft_memset(&data, 0, sizeof(t_alldata));
	data.filename = av[1];
	if (!ft_start_parsing(&data))
		return (1);
	ft_parse_map(&data);
	ft_free_and_exit(&data, NULL);
}
