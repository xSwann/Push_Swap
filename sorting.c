/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slatrech <slatrech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:31:55 by slatrech          #+#    #+#             */
/*   Updated: 2025/04/10 14:15:35 by slatrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"

void	actions(int nb, t_pile **p1, t_pile **p2)
{
	t_pile	*head;
	int		value;

	head = *p1;
	if (((head->valeur >> nb) & 1) == 0)
	{
		value = pop(p1);
		ft_printf("pb\n");
		push(p2, value);
	}
	else
	{
		ft_printf("ra\n");
		rotate(p1);
	}
}

void	bit_sorting(t_pile **p1, t_pile **p2, int size, int max_bits)
{
	int		nb;
	int		count;

	nb = 0;
	while (nb < max_bits)
	{
		count = 0;
		while (count < size)
		{
			actions(nb, p1, p2);
			count++;
		}
		push_everything_in_p1(p2, p1);
		nb++;
	}
}

void	tree_number_sorting(t_pile **p1)
{
	if ((*p1)->valeur < (*p1)->next->valeur
		&& (*p1)->valeur < (*p1)->next->next->valeur)
	{
		rra(p1);
		sa(p1);
	}
	else if ((*p1)->valeur > (*p1)->next->valeur
		&& (*p1)->next->valeur < (*p1)->next->next->valeur
		&& (*p1)->valeur < (*p1)->next->next->valeur)
		sa(p1);
	else if ((*p1)->valeur > (*p1)->next->valeur
		&& (*p1)->next->valeur > (*p1)->next->next->valeur)
	{
		sa(p1);
		rra(p1);
	}
	else if ((*p1)->valeur < (*p1)->next->valeur
		&& (*p1)->next->valeur > (*p1)->next->next->valeur)
		rra(p1);
	else
		ra(p1);
}

void	five_mover(int min_pos, int taille, t_pile **p1)
{
	int	i;

	i = 0;
	if (min_pos <= taille / 2)
	{
		i = 0;
		while (i < min_pos)
		{
			ra(p1);
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < taille - min_pos)
		{
			rra(p1);
			i++;
		}
	}
}

void	five_number_sorting(t_pile **p1, t_pile **p2, int nb)
{
	int		taille;
	int		j;
	t_pile	*tmp;
	int		value;

	j = 0;
	while (j < nb)
	{
		taille = 0;
		tmp = *p1;
		while (tmp)
		{
			taille++;
			tmp = tmp->next;
		}
		tmp = *p1;
		five_mover(find_smallest_value(tmp, (*p1)->valeur), taille, p1);
		ft_printf("pb\n");
		value = pop(p1);
		push(p2, value);
		j++;
	}
	if (is_sorted(*p1) == 1)
		tree_number_sorting(p1);
	push_everything_in_p1(p2, p1);
}
