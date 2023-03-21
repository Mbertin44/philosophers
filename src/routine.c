/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 09:16:52 by mbertin           #+#    #+#             */
/*   Updated: 2023/03/21 08:53:05 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*routine(void *temp)
{
	t_philo	*philo;

	philo = (t_philo *)temp;
	if (philo->id % 2 == 0)
		usleep(100);
	while (1)
	{
		if (philo->data->death == FALSE)
			eating(philo);
		if (philo->data->death == FALSE && philo->data->nbr_philo > 1)
			sleeping(philo);
		if (philo->data->death == FALSE && philo->data->nbr_philo > 1)
			print_status(philo, THINK);
		if (philo->data->death == TRUE
			|| philo->data->nbr_philo_full == philo->data->nbr_philo
			|| philo->data->nbr_philo == 1)
			break ;
	}
	return (NULL);
}


void	eating(t_philo *philo)
{
	t_vault	*data;

	data = philo->data;
	pthread_mutex_lock(&data->fork[philo->id - 1]);
	print_status(philo, FORK);
	if (philo->data->nbr_philo > 1)
	{
		pthread_mutex_lock(&data->fork[philo->id % philo->data->nbr_philo]);
		print_status(philo, EAT);
		pthread_mutex_lock(&data->death_mutex);
		philo->time_last_eat = get_actual_time(data);
		pthread_mutex_unlock(&data->death_mutex);
		fixed_usleep(data->time_eat, philo);
		pthread_mutex_unlock(&data->fork[philo->id % philo->data->nbr_philo]);
		pthread_mutex_unlock(&data->fork[philo->id - 1]);
		if (philo->data->argc == 6)
		{
			pthread_mutex_lock(&data->death_mutex);
			philo->nbr_time_ate++;
			pthread_mutex_unlock(&data->death_mutex);
		}
	}
	else
		pthread_mutex_unlock(&data->fork[philo->id - 1]);
}

void	sleeping(t_philo *philo)
{
	print_status(philo, SLEEP);
	fixed_usleep(philo->data->time_sleep, philo);
}

/*
	Pour déterminer si mon philo est mort ou non je peux récupérer en
	milliseconde le temps que ca lui a pris pour manger. le calcul est :
	TEMPS ACTUEL - DERNIERE FOIS QU'IL A MANGE.
	Maintenant que j'ai le temps que ca lui a pris pour manger,	IF le temps pris
	pour manger est supérieur au temps pour mourir alors mon philo est mort.
*/
bool	philo_is_alive(t_vault *data, int i, long int actual_time)
{
	long int	time_to_eat;

	while (1)
	{
		if (data->death == TRUE)
			return (false);
		actual_time = get_actual_time(data);
		pthread_mutex_lock(&data->death_mutex);
		time_to_eat = actual_time - data->philo[i].time_last_eat;
		if (philo_is_full(data, i) == false)
			return (false);
		if (data->death == TRUE || time_to_eat > data->time_die)
		{
			data->death = TRUE;
			print_status(&data->philo[i], DIED);
			return (false);
		}
		pthread_mutex_unlock(&data->death_mutex);
		i++;
		if (i == data->nbr_philo)
			i = 0;
	}
	return (true);
}

bool	philo_is_full(t_vault *data, int i)
{
	if (data->argc == 6 && data->philo[i].nbr_time_ate
		>= data->nbr_time_eat && data->philo[i].full == FALSE)
	{
		data->philo[i].full = TRUE;
		data->nbr_philo_full++;
		if (data->nbr_philo_full == data->nbr_philo)
			return (false);
	}
	return (true);
}
