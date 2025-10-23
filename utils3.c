/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slatrech <slatrech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:41:16 by slatrech          #+#    #+#             */
/*   Updated: 2025/04/11 13:39:32 by slatrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_variables(t_pile **p1, t_pile **p2, int *argskip)
{
	*p1 = NULL;
	*p2 = NULL;
	*argskip = 1;
}

int	handle_single_arg(char **argv, char ***numbers, int *size,
						int *argskip)
{
	int	i;

	i = 0;
	if (argv[1][0] == '\0')
		return (1);
	*numbers = ft_split(argv[1], ' ');
	while (i < *size)
	{
		if (!is_valid_number((*numbers)[i]))
		{
			free_split(*numbers);
			return (1);
		}
		i++;
	}
	*size = str_counter(*numbers);
	*argskip = 0;
	return (0);
}

int	count_max_bits(t_pile *p1)
{
	int		max_bits;

	max_bits = 0;
	while (p1)
	{
		while ((p1->valeur >> max_bits) != 0)
			max_bits++;
		p1 = p1->next;
	}
	return (max_bits);
}

void	normalize_and_sort(int argc, t_pile **p1, t_pile **p2)
{
	normalize(*p1);
	sorting_handler(argc, p1, p2, count_max_bits(*p1));
}

int	is_valid_number(char *str)
{
	int	i;

	if (!str || *str == '\0')
		return (0);
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
