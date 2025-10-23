/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slatrech <slatrech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 13:17:15 by slatrech          #+#    #+#             */
/*   Updated: 2025/04/10 11:59:24 by slatrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate(t_pile **p)
{
	t_pile	*first;
	t_pile	*last;

	if (!p || !*p || !(*p)->next)
		return ;
	first = *p;
	last = *p;
	while (last->next)
		last = last->next;
	*p = first->next;
	first->next = NULL;
	last->next = first;
}
