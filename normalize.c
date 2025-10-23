/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slatrech <slatrech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 13:36:20 by slatrech          #+#    #+#             */
/*   Updated: 2025/04/10 11:54:05 by slatrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	fill_values_array(t_pile *head, int *values)
{
	t_pile	*current;
	int		i;

	current = head;
	i = 0;
	while (current != NULL)
	{
		values[i] = current->valeur;
		i++;
		current = current->next;
	}
}

static void	sort_values_array(int *values, int size)
{
	int	i;
	int	j;
	int	temp_value;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (values[i] > values[j])
			{
				temp_value = values[i];
				values[i] = values[j];
				values[j] = temp_value;
			}
			j++;
		}
		i++;
	}
}

static void	replace_values_with_indices(t_pile *head, int *values, int size)
{
	t_pile	*current;
	int		j;

	current = head;
	while (current != NULL)
	{
		j = 0;
		while (j < size)
		{
			if (current->valeur == values[j])
			{
				current->valeur = j;
				break ;
			}
			j++;
		}
		current = current->next;
	}
}

void	normalize(t_pile *head)
{
	int		size;
	int		*values;
	t_pile	*current;

	size = 0;
	current = head;
	while (current != NULL)
	{
		size++;
		current = current->next;
	}
	values = malloc(size * sizeof(int));
	if (!values)
		return ;
	fill_values_array(head, values);
	sort_values_array(values, size);
	replace_values_with_indices(head, values, size);
	free(values);
}
