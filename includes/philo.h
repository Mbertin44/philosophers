/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 19:18:06 by ewurstei          #+#    #+#             */
/*   Updated: 2023/03/23 14:10:54 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

					/***** DEFINES *****/
# define TRUE 0
# define FALSE 1
# define ALIVE 0
# define DEAD 1

					/***** STRUTURES *****/

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				nbr_time_ate;
	long			time_last_eat;
	int				full;
	struct s_vault	*data;
}	t_philo;

typedef struct s_vault
{
	int				argc;
	char			**argv;
	int				error;
	int				nbr_philo;
	int				nbr_philo_full;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				nbr_time_eat;
	int				status;
	int				death;
	long int		start_time_ms;
	long int		current_time_ms;
	pthread_mutex_t	fork[200];
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	death_mutex;
	pthread_mutex_t	time_mutex;
	pthread_mutex_t	sleep_mutex;
	pthread_mutex_t	food_mutex;
	struct timeval	start_time;
	struct timeval	current_time;
	t_philo			philo[200];
}	t_vault;

					/***** FONCTIONS *****/

/***** parsing.c *****/
bool		parsing(t_vault *data);
bool		check_argc(t_vault *data);
bool		check_param_is_digit(t_vault *data);
bool		check_param_len(t_vault *data);
void		check_param_value(t_vault *data);

/***** utils.c *****/
void		param_to_int(t_vault *data);
void		print_status(t_philo *philo, char *str);
void		print_dead(t_philo *philo);
bool		error_management(t_vault *data);
void		fixed_usleep(int time_to_sleep, t_philo *philo);

/***** init_and_stop.c *****/
void		init_data(t_vault *data, t_philo *philo, int argc, char **argv);
bool		init_philo(t_vault *data, int i, int j);
void		kill_them_all(t_vault *data);
bool		lonely_init(t_vault *data);
void		*lonely_routine(void *temp);

/***** get_time_and_check.c *****/
void		get_start_time(t_vault *data);
long int	get_actual_time(t_vault *data);
bool		check_dead(t_philo *philo);
bool		check_full(t_philo *philo);

/***** routine.c *****/
void		*routine(void *temp);
bool		philo_is_alive(t_vault *data, int i, long int actual_time);
void		eating(t_philo *philo);
void		sleeping(t_philo *philo);
bool		philo_is_full(t_vault *data, int i);

/***** libft_utils.c *****/
int			ft_isdigit(int c);
void		ft_dbl_ptr_free(void **ptr);
size_t		ft_strlen(const char *s);
int			ft_atoi(const char *str);
char		**ft_dbl_ptr_copy(char **source);

/***** libft_utils2.c *****/
void		*ft_calloc(size_t nbr, size_t size);
void		ft_bzero(void *s, size_t n);
int			ft_dbl_ptr_len(char **tab);
char		*ft_strdup(const char *s1);

#endif