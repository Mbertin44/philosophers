/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:32:26 by mbertin           #+#    #+#             */
/*   Updated: 2023/03/21 08:53:21 by mbertin          ###   ########.fr       */
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
	if (philo->data->death == FALSE && msg == FORK)
		printf("%ld %d has taken a fork\n", get_actual_time(data), philo->id);
	else if (philo->data->death == FALSE && msg == EAT)
	{
		printf("%ld %d has taken a fork\n", get_actual_time(data), philo->id);
		printf("%ld %d is eating\n", get_actual_time(philo->data), philo->id);
	}
	else if (philo->data->death == FALSE && msg == SLEEP)
		printf("%ld %d is sleeping\n", get_actual_time(philo->data), philo->id);
	else if (philo->data->death == FALSE && msg == THINK)
		printf("%ld %d is thinking\n", get_actual_time(philo->data), philo->id);
	else if (philo->data->death == TRUE && msg == DIED)
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

/*
	Si je fais seulement un usleep de la durée du paramètre time_to_sleep,
	il est possible que un des mes philos meurt PENDANT le usleep. Pour
	corriger ce problème j'effectue plusieurs petit usleep dans une boucle
	infini et je vérifie l'état de mes philos entre chaque rappel de la boucle.
*/
void	fixed_usleep(int time_to_sleep, t_philo *philo)
{
	int	start_sleep;
	int	sleeping_time;

	start_sleep = get_actual_time(philo->data);
	while (1)
	{
		sleeping_time = get_actual_time(philo->data) - start_sleep;
		if (sleeping_time >= philo->data->time_die)
		{
			pthread_mutex_lock(&philo->data->death_mutex);
			philo->data->death = TRUE;
			pthread_mutex_unlock(&philo->data->death_mutex);
			return ;
		}
		if (sleeping_time >= time_to_sleep)
			return ;
		usleep(10);
	}
}
