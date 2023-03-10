/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 09:35:01 by momo              #+#    #+#             */
/*   Updated: 2023/03/10 12:15:18 by mbertin          ###   ########.fr       */
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
	if (join_thread(&data) == false)
		return (1);
	return (0);
}
