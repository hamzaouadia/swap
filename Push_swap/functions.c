/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouadia <mouadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 21:14:04 by mouadia           #+#    #+#             */
/*   Updated: 2024/02/25 12:30:21 by mouadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
* ft_putstr: this function prints a string
* @str: string
* Return: Void
*/
void	ft_putstr(const char *str)
{
	while (*str)
		write(1, &*str++, 1);
	write(1, "\n", 1);
}

/*
* push:	it pushes data from source to destination
* @source: source stack.
* @destination: destination stack.
* Return: void.
*/
void	push(t_stack **source, t_stack **destination, const char *inst)
{
	t_stack	*temp;

	if (*source == NULL)
		return ;
	temp = *source;
	*source = (*source)->next;
	temp->next = *destination;
	*destination = temp;
	ft_putstr(inst);
}
/*
*
*/

void	rotate_first_two(t_stack **head, const char *inst)
{
	t_stack	*temp;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	temp = *head;
	*head = (*head)->next;
	temp->next = (*head)->next;
	(*head)->next = temp;
	ft_putstr(inst);
}
