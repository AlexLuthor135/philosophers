/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alappas <alappas@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:51:05 by alappas           #+#    #+#             */
/*   Updated: 2023/12/14 05:40:06 by alappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

t_data	*parse_data(char **argv)

{
	t_data	*data;

	data = ft_calloc(sizeof(t_data), 1);
	if (!data)
		return (NULL);
	data->print = malloc(sizeof(pthread_mutex_t));
	if (!data->print)
		return (NULL);
	data->fork = malloc(sizeof(pthread_mutex_t) * ft_atoi(argv[1]));
	if (!data->fork)
		return (0);
	data->num_p = ft_atoi(argv[1]);
	data->ttd = ft_atoi(argv[2]);
	data->tte = ft_atoi(argv[3]);
	data->tts = ft_atoi(argv[4]);
	if (argv[5])
		data->tme = ft_atoi(argv[5]);
	return (data);
}
