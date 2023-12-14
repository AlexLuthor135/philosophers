/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alappas <alappas@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:37:11 by alappas           #+#    #+#             */
/*   Updated: 2023/12/13 23:13:04 by alappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	free_data(t_philo *philo)

{
	int	i;

	i = 0;
	while (i < philo->params->num_p)
	{
		pthread_mutex_destroy(philo->forkl);
		i++;
	}
	pthread_mutex_destroy(philo->params->print);
	free(philo->params->fork);
	free(philo->params->print);
	free(philo->params);
	free(philo);
}
