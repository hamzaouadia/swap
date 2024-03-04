/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouadia <mouadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 00:27:01 by mouadia           #+#    #+#             */
/*   Updated: 2024/03/02 00:42:52 by mouadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_int(t_stack **a)
{
	if (ft_check_sort(*a))
		return ;
	if ((*a)->nbr > (*a)->next->nbr)
	{
		rotate_first_two(a ,"sa");
		if (!ft_check_sort(*a))
			reverse_rotate_linked_list(a ,"rra");
		if (!ft_check_sort(*a))
			rotate_first_two(a ,"sa");
	}
	else if ((*a)->nbr < (*a)->next->nbr)
	{
		reverse_rotate_linked_list(a ,"rra");
		if (!ft_check_sort(*a))
			rotate_first_two(a ,"sa");
	}
}

void sort_five_int(t_stack **a, t_stack **b, int size)
{
	while (ft_lstsize(*a) > 3)
	{
		if (smallest_node(*a) == 0)
			push(a, b, "pb");
		else if (smallest_node(*a) >= 3)
			reverse_rotate_linked_list(a, "rra");
		else if (smallest_node(*a) < 3)
			rotate_linked_list(a, "ra");
	}
	sort_three_int(a);
	push(b, a, "pa");
	if (size != ft_lstsize(*a))
		push(b, a, "pa");
	if ((*a)->nbr > (*a)->next->nbr)
		rotate_first_two(a, "ra");
}

void	sort_more_than_five(t_stack **a, t_stack **b, t_var *var)
{
	var->size = ft_lstsize(*a);
	var->sorted_array = sort_stack_in_array(*a, var->size);
	var->sec = 0;
	var->start = 0;
	var->j = 0;
	if (var->size <= 100)
		var->chunks = 6;
	else
		var->chunks = 11;
	var->range = var->size / var->chunks;
	a_to_b(a, b, var);
	b_to_a(a, b, var);
	free(var->sorted_array);
}
