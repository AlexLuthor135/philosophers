/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alappas <alappas@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:54:12 by alappas           #+#    #+#             */
/*   Updated: 2023/12/11 14:51:28 by alappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*result;

	i = 0;
	result = (char *)s;
	while (i < n)
	{
		result[i] = '\0';
		i++;
	}
	s = (void *)result;
}

uint64_t	time_now(void)
{
	uint64_t		milliseconds;
	struct timeval	tp;

	gettimeofday(&tp, NULL);
	milliseconds = tp.tv_sec * 1000;
	milliseconds += tp.tv_usec / 1000;
	return (milliseconds);
}

void	ft_usleep(long int time)
{
	long int	start_time;

	start_time = time_now();
	while ((time_now() - start_time) < (unsigned long long) time)
		usleep(150);
}

int	ft_atoi(const char *str)

{
	int	i;
	int	minus;
	int	result;

	i = 0;
	result = 0;
	minus = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		++i;
	if (str[i] == '-')
	{
		minus = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while ((str[i] >= 48 && str[i] <= 57) && str[i] != '\0')
	{
		result *= 10;
		result += str[i] - 48;
		++i;
	}
	return (result * minus);
}

void	*ft_calloc(size_t count, size_t size)

{
	size_t	i;
	char	*array;

	i = 0;
	array = malloc(count * size);
	if (count * size > SIZE_MAX)
		return (NULL);
	if (array == NULL)
		return (0);
	ft_bzero(array, size * count);
	return (array);
}
