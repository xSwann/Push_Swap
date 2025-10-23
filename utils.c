/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slatrech <slatrech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 13:17:48 by slatrech          #+#    #+#             */
/*   Updated: 2025/04/11 11:12:54 by slatrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"

long	ft_atoi(const char *str)
{
	int		i;
	long	nbr;
	int		signe;

	i = 0;
	nbr = 0;
	signe = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		signe *= -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	if (nbr * signe > 2147483647 || nbr * signe < -2147483648)
		return (2147483648);
	return (nbr * signe);
}

int	pop(t_pile **p)
{
	t_pile	*tmp;
	int		value;

	if (!*p)
		return (-1);
	tmp = *p;
	value = tmp->valeur;
	*p = (*p)->next;
	free(tmp);
	return (value);
}

int	bit_checker(t_pile *p, int nb)
{
	while (p)
	{
		if (((p->valeur >> nb) & 1) == 0)
			return (1);
		p = p->next;
	}
	return (0);
}

int	is_sorted(t_pile *p1)
{
	t_pile	*head;

	head = p1;
	while (p1 -> next)
	{
		if (p1 -> valeur > p1 -> next -> valeur)
			return (1);
		p1 = p1 -> next;
	}
	p1 = head;
	return (0);
}

int	is_duplicate(t_pile *p)
{
	t_pile	*tmp;
	t_pile	*current;

	current = p;
	while (current)
	{
		tmp = current->next;
		while (tmp)
		{
			if (current->valeur == tmp->valeur)
			{
				ft_printf("Error\n");
				return (1);
			}
			tmp = tmp->next;
		}
		current = current->next;
	}
	return (0);
}
