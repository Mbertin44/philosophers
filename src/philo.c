/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 09:35:01 by momo              #+#    #+#             */
/*   Updated: 2023/03/16 15:42:02 by mbertin          ###   ########.fr       */
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
	init_philo(&data);
	if (philo_is_alive(&data) == false)
	{
		kill_them_all(&data);
		return (0);
	}
	// if (join_thread(&data) == false)
	// 	return (1);
}

void	kill_them_all(t_vault *data)
{
	int	i;

	i = -1;
	while (++i < data->nbr_philo)
	{
		if (pthread_join(data->philo[i].thread, NULL) != 0)
			data->error = 4;
		pthread_mutex_destroy(&data->fork[i]);
	}
	pthread_mutex_destroy(&data->print_mutex);
	exit (0);
}
