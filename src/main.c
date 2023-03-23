/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 09:35:01 by momo              #+#    #+#             */
/*   Updated: 2023/03/23 11:10:27 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/*
	number_of_philosophers
	time_to_die
	time_to_eat
	time_to_sleep
	number_of_times_each_philosopher_must_eat
*/

int	main(int argc, char const *argv[])
{
	t_vault	data;
	t_philo	philo;

	init_data(&data, &philo, argc, (char **)argv);
	if (parsing(&data) == false)
		return (1);
	if (data.nbr_philo == 1)
	{
		if (lonely_init(&data) == false)
			return (1);
	}
	else
	{
		if (init_philo(&data, -1, 1) == false)
			return (1);
	}
	if (philo_is_alive(&data, 0, 0) != true)
	{
		kill_them_all(&data);
		return (0);
	}
}
