/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 09:16:52 by mbertin           #+#    #+#             */
/*   Updated: 2023/03/16 15:52:10 by mbertin          ###   ########.fr       */
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
		eating(philo);
		if (philo->data->death == FALSE)
			sleeping(philo);
		if (philo->data->death == FALSE)
			print_status(philo, THINK);
		else
			break ;
	}
	return (NULL);
}

/*
	Pour déterminer si mon philo est mort ou non je peux récupérer en
	milliseconde le temps que ca lui a pris pour manger. le calcul est :
	TEMPS ACTUEL - DERNIERE FOIS QU'IL A MANGE.
	Maintenant que j'ai le temps que ca lui a pris pour manger,	IF le temps pris
	pour manger est supérieur au temps pour mourir alors mon philo est mort.
*/
// bool	philo_is_alive(t_philo *philo)
// {
// 	long int	actual_time;
// 	long int	time_to_eat;

// 	if (philo->data->death == TRUE)
// 		return (false);
// 	actual_time = get_actual_time(philo->data);
// 	time_to_eat = actual_time - philo->time_last_eat;
// 	if (philo->data->death == TRUE || time_to_eat > philo->data->time_die)
// 	{
// 		philo->data->death = TRUE;
// 		print_status(philo, DIED);
// 		return (false);
// 	}
// 	return (true);
// }

bool	philo_is_alive(t_vault *data)
{
	long int	actual_time;
	long int	time_to_eat;
	int			i;

	i = 0;
	while (1)
	{
		if (data->death == TRUE)
			return (false);
		actual_time = get_actual_time(data);
		time_to_eat = actual_time - data->philo[i].time_last_eat;
		if (data->death == TRUE || time_to_eat > data->time_die)
		{
			data->death = TRUE;
			print_status(&data->philo[i], DIED);
			return (false);
		}
		if (i == data->nbr_philo)
			i = 0;
	}
	return (true);
}

void	eating(t_philo *philo)
{
	t_vault	*data;

	data = philo->data;
	pthread_mutex_lock(&data->fork[philo->id - 1]);
	print_status(philo, FORK);
	pthread_mutex_lock(&data->fork[philo->id % philo->data->nbr_philo]);
	print_status(philo, EAT);
	fixed_usleep(data->time_eat, philo);
	pthread_mutex_unlock(&data->fork[philo->id % philo->data->nbr_philo]);
	pthread_mutex_unlock(&data->fork[philo->id - 1]);
	philo->time_last_eat = get_actual_time(data);
	if (philo->data->argc == 6)
		philo->nbr_time_ate++;
	// if (fixed_usleep(data->time_eat, philo) == DEAD)
	// {
	// 	print_status(philo, DIED);
	// 	return ;
	// }
}

void	sleeping(t_philo *philo)
{
	print_status(philo, SLEEP);
	fixed_usleep(philo->data->time_sleep, philo);
}
