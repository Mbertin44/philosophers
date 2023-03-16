/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:32:26 by mbertin           #+#    #+#             */
/*   Updated: 2023/03/16 15:10:04 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	check_param_value(t_vault *data)
{
	if (data->nbr_philo > 200 || data->nbr_philo < 1)
		data->error = 2;
	if (data->time_die < 1 || data->time_eat < 1 || data->time_sleep < 1
		|| (data->argc == 6 && data->nbr_time_eat < 1))
		data->error = 1;
}

void	print_status(t_philo *philo, int msg)
{
	t_vault	*data;

	data = philo->data;
	pthread_mutex_lock(&philo->data->print_mutex);
	if (msg == FORK)
		printf("%ld %d has taken a fork\n", get_actual_time(data), philo->id);
	else if (msg == EAT)
	{
		printf("%ld %d has taken a fork\n", get_actual_time(data), philo->id);
		printf("%ld %d is eating\n", get_actual_time(philo->data), philo->id);
	}
	else if (msg == SLEEP)
		printf("%ld %d is sleeping\n", get_actual_time(philo->data), philo->id);
	else if (msg == THINK)
		printf("%ld %d is thinking\n", get_actual_time(philo->data), philo->id);
	else if (msg == DIED)
		printf("%ld %d died\n", get_actual_time(philo->data), philo->id);
	pthread_mutex_unlock(&philo->data->print_mutex);
}

bool	error_management(t_vault *data)
{
	if (data->error == 1)
		printf("Wrong parameters\n");
	else if (data->error == 2)
		printf("Wrong amount of philosophers\n");
	else if (data->error == 3)
		printf("Fail to create the philos thread\n");
	else if (data->error == 4)
		printf("Fail to join the threads\n");
	if (data->error != 0)
		return (false);
	return (true);
}

bool	join_thread(t_vault *data)
{
	int	i;

	i = -1;
	while (++i < data->nbr_philo)
	{
		if (pthread_join(data->philo[i].thread, NULL) != 0)
		{
			data->error = 4;
			return (false);
		}
	}
	return (true);
}
