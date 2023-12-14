/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alappas <alappas@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:00:17 by alappas           #+#    #+#             */
/*   Updated: 2023/12/14 18:45:03 by alappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	init_philo(t_data *data, t_philo *philo)

{
	int	i;

	i = 0;
	while (i < data->num_p)
	{
		philo[i].id = i + 1;
		philo[i].forkl = &data->fork[i];
		if (philo[i].id == data->num_p)
			philo[i].forkr = &data->fork[0];
		else
			philo[i].forkr = &data->fork[i + 1];
		philo[i].params = data;
		i++;
	}
}

void	init_mutex(t_data *data, t_philo *philo)

{
	int	i;

	i = 0;
	while (i < philo->params->num_p)
	{
		pthread_mutex_init(philo[i].forkl, NULL);
		i++;
	}
	pthread_mutex_init(data->print, NULL);
}

void	init_thread(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->params->num_p)
	{
		pthread_create(&philo[i].thread, NULL, &routine, &philo[i]);
		philo[i].start = time_now();
		philo[i].meal = time_now();
		i++;
	}
}
