/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slatrech <slatrech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 11:22:40 by slatrech          #+#    #+#             */
/*   Updated: 2025/04/10 16:27:47 by slatrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"

int	find_smallest_value(t_pile *tmp, int min_val)
{
	int	i;
	int	min_pos;

	min_pos = 0;
	i = 0;
	while (tmp)
	{
		if (tmp->valeur < min_val)
		{
			min_val = tmp->valeur;
			min_pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (min_pos);
}

void	push_everything_in_p1(t_pile **p2, t_pile **p1)
{
	int	value;

	while (*p2)
	{
		ft_printf("pa\n");
		value = pop(p2);
		push(p1, value);
	}
}

int	is_valid_argument(char **argv, int argskip)
{
	int	i;
	int	j;

	i = argskip;
	while (argv[i])
	{
		j = 0;
		if (argv[i][j] == '-' || argv[i][j] == '+')
			j++;
		if (argv[i][j] == '\0')
			return (1);
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	str_counter(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
