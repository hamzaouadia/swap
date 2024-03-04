/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouadia <mouadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 12:38:28 by mouadia           #+#    #+#             */
/*   Updated: 2024/03/02 00:26:56 by mouadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	the_else_condition(t_stack **a, t_stack **b, t_var *var)
{
	while ((*b)->nbr != var->big)
	{
		if ((*b)->nbr == var->sec_big)
		{
			push(b, a, "pa");
			var->sec = 1;
		}
		else
			reverse_rotate_linked_list(b, "rrb");
	}
}

void	b_to_a_conditions(t_stack **a, t_stack **b, t_var *var)
{
	if (var->index < ft_lstsize(*b) / 2)
	{
		while ((*b)->nbr != var->big)
		{
			if ((*b)->nbr == var->sec_big)
			{
				push(b, a, "pa");
				var->sec = 1;
			}
			else
				rotate_linked_list(b, "rb");
		}
	}
	else
		the_else_condition(a, b, var);
}

void	b_to_a(t_stack **a, t_stack **b, t_var *var)
{
	while (*b)
	{
		var->big = var->sorted_array[var->size - 1 - var->j];
		var->sec_big = var->sorted_array[var->size - 2 - var->j];
		var->index = ft_big_index(*b, var->big);
		b_to_a_conditions(a, b, var);
		push(b, a, "pa");
		if (var->sec == 1)
		{
			rotate_first_two(a, "sa");
			var->sec = 0;
			var->j++;
		}
		var->j++;
	}
}

void	a_to_b(t_stack **a, t_stack **b, t_var *var)
{
	
	while (*a)
	{
		var->index = ft_get_index(*a, var->sorted_array, var->start,
				var->range + var->start);
		if (var->index >= ft_lstsize(*a) / 2)
		{
			while (++var->index <= ft_lstsize(*a))
				reverse_rotate_linked_list(a, "rra");
		}
		else
		{
			while (--var->index >= 0)
				rotate_linked_list(a, "ra");
		}
		push(a, b, "pb");
		if (ft_lstsize(*b) >= var->range + var->start)
		{				
			var->start += var->range;
		}
	}
}


int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	t_var	var;

	if (ac == 1)
		return (0);
	a = push_swap_init(ac, av);
	var.size = ft_lstsize(a);
	if (var.size <= 3 && !ft_check_sort(a))
		sort_three_int(&a);
	else if (var.size <= 5 && !ft_check_sort(a))
		sort_five_int(&a, &b, var.size);
	else if (var.size > 5 && !ft_check_sort(a))
		sort_more_than_five(&a, &b, &var);
	ft_print_stack(a);
}
