/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slatrech <slatrech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 13:17:24 by slatrech          #+#    #+#             */
/*   Updated: 2025/04/10 11:58:13 by slatrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse_rotate(t_pile **p)
{
	t_pile	*prev;
	t_pile	*last;

	if (!p || !*p || !(*p)->next)
		return ;
	prev = NULL;
	last = *p;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *p;
	*p = last;
}
