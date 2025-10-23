/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slatrech <slatrech@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 13:17:42 by slatrech          #+#    #+#             */
/*   Updated: 2025/04/11 13:38:53 by slatrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"

void	print_list(t_pile *head)
{
	t_pile	*current;

	current = head;
	while (current != NULL)
	{
		ft_printf("%d ", current->valeur);
		current = current->next;
	}
	ft_printf("\n");
}

void	print_bits(unsigned char octet)
{
	int		i;
	char	bit;

	i = 7;
	while (i >= 0)
	{
		bit = ((octet >> i) & 1) + '0';
		write(1, &bit, 1);
		i--;
	}
}

void	sorting_handler(int argc, t_pile **p1, t_pile **p2, int max_bits)
{
	if (argc - 1 == 3)
		tree_number_sorting(p1);
	else if (argc - 1 == 5)
		five_number_sorting(p1, p2, 2);
	else if (argc - 1 == 4)
		five_number_sorting(p1, p2, 1);
	else
		bit_sorting(p1, p2, argc - 1, max_bits);
}

int	handle_input(int argc, char **argv, t_pile **p1, int argskip)
{
	int		i;
	long	value;

	i = argc - 1;
	if (is_valid_argument(argv, argskip) == 1)
	{
		ft_printf("Error\n");
		return (1);
	}
	while (i >= argskip)
	{
		value = ft_atoi(argv[i]);
		if (value == 2147483648)
		{
			ft_printf("Error\n");
			return (1);
		}
		push(p1, value);
		i--;
	}
	if (is_duplicate(*p1) == 1)
		return (1);
	if (is_sorted(*p1) == 0)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_pile	*p1;
	t_pile	*p2;
	int		argskip;

	if (argc == 1)
		return (0);
	init_variables(&p1, &p2, &argskip);
	if (argc == 2 && handle_single_arg(argv, &argv, &argc, &argskip))
		return (0);
	if (handle_input(argc, argv, &p1, argskip) == 1)
	{
		if (argskip == 0)
			free_split(argv);
		while (p1)
			pop(&p1);
		return (0);
	}
	if (argskip == 0)
		argc++;
	normalize_and_sort(argc, &p1, &p2);
	while (p1)
		pop(&p1);
	if (argskip == 0)
		free_split(argv);
	return (0);
}
