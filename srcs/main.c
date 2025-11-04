/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 20:59:59 by nkalkoul          #+#    #+#             */
/*   Updated: 2025/11/04 16:42:41 by nsmail           ###   ########.fr       */
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
	data.ray = ft_calloc(1, sizeof(t_raycasting));
	// int i = 0;
	// while (data.copy[i])
	// {
	// 	printf("%s\n", data.copy[i]);
	// 	i++;
	// }
	if (!data.ray)
		ft_free_and_exit(&data, "malloc failed for ray");
	init_raycasting(&data);
	ft_start_mlx(&data);
	if (!exec_general(&data))
		ft_free_and_exit(&data, NULL);
	ft_free_and_exit(&data, NULL);
}
