/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slatrech <slatrech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:04:04 by slatrech          #+#    #+#             */
/*   Updated: 2025/04/10 14:18:12 by slatrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"

void	sa(t_pile **p1)
{
	ft_printf("sa\n");
	swap(p1);
}

void	ra(t_pile **p1)
{
	ft_printf("ra\n");
	rotate(p1);
}

void	rra(t_pile **p1)
{
	ft_printf("rra\n");
	reverse_rotate(p1);
}
