/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slatrech <slatrech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 13:17:30 by slatrech          #+#    #+#             */
/*   Updated: 2025/04/10 12:00:28 by slatrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_pile **p)
{
	t_pile	*first;
	t_pile	*second;

	if (!p || !*p || !(*p)->next)
		return ;
	first = *p;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*p = second;
}
