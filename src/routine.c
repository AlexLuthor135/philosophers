/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alappas <alappas@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:37:54 by alappas           #+#    #+#             */
/*   Updated: 2023/12/14 18:44:29 by alappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*routine(void *arg)

{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		ft_usleep(philo->params->tte * 0.9 + 1);
	while (philo->params->over != 1)
	{
		ft_eat(philo);
		if (philo->params->over == 1)
			return (NULL);
		print_state(philo, 3);
		ft_usleep(philo->params->tts);
		print_state(philo, 4);
	}
	return (NULL);
}

void	ft_eat(t_philo *philo)

{
	pthread_mutex_lock(philo->forkl);
	print_state(philo, 1);
	pthread_mutex_lock(philo->forkr);
	print_state(philo, 1);
	philo->meal = time_now();
	philo->iter++;
	if (philo->iter == philo->params->tme)
		philo->params->tme_over++;
	print_state(philo, 2);
	ft_usleep(philo->params->tte);
	pthread_mutex_unlock(philo->forkl);
	pthread_mutex_unlock(philo->forkr);
}

int	check_state(t_philo *philo)

{
	long int	timenow;
	int			i;

	i = 0;
	timenow = time_now() - philo->meal;
	if ((timenow >= philo->params->ttd)
		|| (philo->params->tme > 0
			&& philo->params->tme_over == philo->params->num_p))
	{
		if (timenow >= philo->params->ttd)
			print_state(philo, 5);
		philo->params->over = 1;
		pthread_mutex_unlock(philo->forkl);
		pthread_mutex_unlock(philo->forkr);
		pthread_mutex_unlock(philo->params->print);
		return (1);
	}
	return (0);
}

void	join_thread(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->params->num_p)
	{
		pthread_join(philo[i].thread, (void *)&philo[i]);
		i++;
	}
}

void	print_state(t_philo *philo, int i)

{
	pthread_mutex_lock(philo->params->print);
	if (philo->params->over == 1)
	{
		pthread_mutex_unlock(philo->params->print);
		return ;
	}
	if (i == 1)
		printf("%llu %d has taken a fork\n",
			time_now() - philo->start, philo->id);
	if (i == 2)
		printf("%llu %d is eating\n", time_now() - philo->start, philo->id);
	if (i == 3)
		printf("%llu %d is sleeping\n", time_now() - philo->start, philo->id);
	if (i == 4)
		printf("%llu %d is thinking\n", time_now() - philo->start, philo->id);
	if (i == 5)
		printf("%lld %d died\n", time_now() - philo->start, philo->id);
	pthread_mutex_unlock(philo->params->print);
}
