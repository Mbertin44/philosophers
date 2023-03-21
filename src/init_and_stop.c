/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_stop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 09:54:07 by mbertin           #+#    #+#             */
/*   Updated: 2023/03/20 14:35:34 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	init_data(t_vault *data, t_philo *philo, int argc, char **argv)
{
	data->argc = argc;
	data->argv = ft_dbl_ptr_copy(argv);
	data->error = 0;
	data->time_die = 0;
	data->time_eat = 0;
	data->time_sleep = 0;
	data->nbr_time_eat = 0;
	data->nbr_philo_full = 0;
	philo->data = data;
	data->death = FALSE;
	get_start_time(data);
	pthread_mutex_init(&data->print_mutex, NULL);
	pthread_mutex_init(&data->death_mutex, NULL);
	pthread_mutex_init(&data->time_mutex, NULL);
}

bool	init_philo(t_vault *data)
{
	int	i;
	int	j;

	i = -1;
	j = 1;
	while (++i < data->nbr_philo)
	{
		data->philo[i].id = j;
		data->philo[i].full = FALSE;
		data->philo[i].nbr_time_ate = 0;
		data->philo[i].time_last_eat = 0;
		data->philo[i].data = data;
		if (pthread_create(&data->philo[i].thread, NULL,
				&routine, &data->philo[i]) != 0)
		{
			data->error = 3;
			return (false);
		}
		pthread_mutex_init(&data->fork[i], NULL);
		j++;
	}
	return (true);
}

void	kill_them_all(t_vault *data)
{
	int	i;

	i = -1;
	pthread_mutex_unlock(&data->death_mutex);
	while (++i < data->nbr_philo)
	{
		if (pthread_join(data->philo[i].thread, NULL) != 0)
			data->error = 4;
		pthread_mutex_destroy(&data->fork[i]);
	}
	pthread_mutex_destroy(&data->print_mutex);
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

