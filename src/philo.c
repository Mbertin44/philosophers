/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 09:35:01 by momo              #+#    #+#             */
/*   Updated: 2023/03/09 11:06:36 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char const *argv[])
{
	t_vault	data;

	init_data(&data, argc, (char **)argv);
	if (parsing(&data) == false)
		return (1);
	usleep(1000000);
	printf("%ld ms\n", get_actual_time(&data));
	return (0);
}
