/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_stop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 09:54:07 by mbertin           #+#    #+#             */
/*   Updated: 2023/03/23 13:50:35 by mbertin          ###   ########.fr       */
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
	pthread_mutex_init(&data->sleep_mutex, NULL);
	pthread_mutex_init(&data->food_mutex, NULL);
}

bool	init_philo(t_vault *data, int i, int j)
{
	while (++i < data->nbr_philo)
		pthread_mutex_init(&data->fork[i], NULL);
	i = -1;
	pthread_mutex_lock(&data->sleep_mutex);
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
			error_management(data);
			ft_dbl_ptr_free((void **)data->argv);
			return (false);
		}
		j++;
	}
	pthread_mutex_unlock(&data->sleep_mutex);
	return (true);
}

void	kill_them_all(t_vault *data)
{
	int	i;

	i = -1;
	while (++i < data->nbr_philo)
		pthread_mutex_destroy(&data->fork[i]);
	i = -1;
	while (++i < data->nbr_philo)
	{
		if (pthread_join(data->philo[i].thread, NULL) != 0)
			data->error = 4;
	}
	pthread_mutex_destroy(&data->print_mutex);
}

bool	lonely_init(t_vault *data)
{
	data->philo[0].id = 1;
	data->philo[0].full = FALSE;
	data->philo[0].nbr_time_ate = 0;
	data->philo[0].time_last_eat = 0;
	data->philo[0].data = data;
	if (pthread_create(&data->philo[0].thread, NULL,
			&lonely_routine, &data->philo[0]) != 0)
	{
		data->error = 3;
		ft_dbl_ptr_free((void **)data->argv);
		return (false);
	}
	return (true);
}

void	*lonely_routine(void *temp)
{
	t_philo	*philo;

	philo = (t_philo *)temp;
	print_status(philo, "has taken a fork");
	return (NULL);
}
