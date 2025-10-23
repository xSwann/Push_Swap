/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slatrech <slatrech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 13:17:21 by slatrech          #+#    #+#             */
/*   Updated: 2025/04/11 10:58:21 by slatrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_pile **p, int value)
{
	t_pile	*element;

	element = malloc(sizeof(t_pile));
	if (!element)
		exit(EXIT_FAILURE);
	element->valeur = value;
	element->next = *p;
	*p = element;
}
