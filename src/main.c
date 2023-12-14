/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alappas <alappas@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:38:09 by alappas           #+#    #+#             */
/*   Updated: 2023/12/14 18:44:52 by alappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	main_cycle(t_philo *philo)

{
	int	i;

	while (philo->params->over != 1)
	{
		i = 0;
		while (i < philo->params->num_p)
		{
			check_state(&philo[i]);
			i++;
		}
	}
}

int	main(int argc, char **argv)

{
	t_data	*data;
	t_philo	*philo;

	if (((argc != 5 && argc != 6)) || check_input(argv))
	{
		printf("Wrong arguments\n");
		exit(0);
	}
	philo = ft_calloc((sizeof(t_philo) * ft_atoi(argv[1])), 1);
	data = parse_data(argv);
	init_philo(data, philo);
	init_mutex(data, philo);
	init_thread(philo);
	main_cycle(philo);
	join_thread(philo);
	if (data->over == 1)
		free_data(philo);
}
