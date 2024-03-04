/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouadia <mouadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 21:02:41 by mouadia           #+#    #+#             */
/*   Updated: 2024/03/02 00:38:09 by mouadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct	s_var
{
	int		size;
	int		index;
	int		*sorted_array;
	int		chunks;
	int		range;
	int		sec;
	int		start;
	int		j;
	int		big;
	int		sec_big;

} 	t_var;

typedef struct	push_swap
{
	int					nbr;
	struct push_swap	*next;
}	t_stack;


void	ft_exit(const char *msg, const char *type);

void	rotate_first_two(t_stack **head, const char *inst);
void	ss(t_stack **stackA, t_stack **stackB);
void	push(t_stack **source, t_stack **destination, const char *inst);
void	rotate_linked_list(t_stack **head, const char *inst);
void	rr(t_stack **stackA, t_stack **stackB);
void	reverse_rotate_linked_list(t_stack **head, const char *inst);
void	rrr(t_stack **stackA, t_stack **stackB);
void	ft_putstr(const char *str);
int		ft_lstsize(t_stack *lst);
int		ft_get_pos(t_stack *a, int nbr);
int		ft_big_index(t_stack *b, int big);
int		ft_get_index(t_stack *a, int *array, int start, int end);
int		*sort_stack_in_array(t_stack *a, int size);
void	sort_five_int(t_stack **a, t_stack **b, int size);
void	sort_three_int(t_stack **a);
void	ft_print_stack(t_stack *stack);
int		smallest_node(t_stack *cpy);
int		ft_check_sort(t_stack *cpy);
t_stack	*push_swap_init(int ac, char **av);
char	*ft_strchr(const char *s, int c);
void	ft_adv_atoi(char *str, t_stack **a);
int		ft_atoi(char *str);
int		ft_isdigit(int c);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack	*ft_lstnew(int nbr);
void	ft_exit(const char *msg, const char *type);
int		ft_lstsize(t_stack *lst);

/*main function*/
void	the_else_condition(t_stack **a, t_stack **b, t_var *var);
void	b_to_a_conditions(t_stack **a, t_stack **b, t_var *var);
void	b_to_a(t_stack **a, t_stack **b, t_var *var);
void	a_to_b(t_stack **a, t_stack **b, t_var *var);
/*sort_algo functions*/
void	sort_three_int(t_stack **a);
void    sort_five_int(t_stack **a, t_stack **b, int size);
void	sort_more_than_five(t_stack **a, t_stack **b, t_var *var);


#endif