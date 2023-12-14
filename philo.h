/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alappas <alappas@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:37:38 by alappas           #+#    #+#             */
/*   Updated: 2023/12/14 18:43:28 by alappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_data
{
	int				ttd;
	int				tte;
	int				tts;
	int				tme;
	int				over;
	int				num_p;
	int				tme_over;
	int				start;
	pthread_mutex_t	*print;
	pthread_mutex_t	*fork;
}				t_data;

typedef struct s_philo
{
	int				id;
	int				iter;
	long int		start;
	long int		meal;
	pthread_t		thread;
	pthread_mutex_t	*forkl;
	pthread_mutex_t	*forkr;
	t_data			*params;
}				t_philo;

int			check_input(char **argv);
int			ft_atoi(const char *str);
void		*ft_calloc(size_t count, size_t size);
t_data		*parse_data(char **argv);
uint64_t	time_now(void);
void		ft_usleep(long int time);
void		init_philo(t_data *data, t_philo *philo);
void		init_mutex(t_data *data, t_philo *philo);
void		init_thread(t_philo *philo);
void		*routine(void *arg);
void		ft_eat(t_philo *philo);
uint64_t	time_now(void);
void		join_thread(t_philo *philo);
void		free_data(t_philo *philo);
int			check_state(t_philo *philo);
void		print_state(t_philo *philo, int i);
void		main_cycle(t_philo *philo);
#endif