/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouadia <mouadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 20:57:26 by mouadia           #+#    #+#             */
/*   Updated: 2024/03/02 01:23:16 by mouadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	ft_lstsize(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

void ft_exit(const char* msg, const char *type)
{
	printf("%s%s\n",msg, type);
	exit(0);
}

t_stack	*ft_lstnew(int nbr)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (new_node == NULL)
		return (NULL);
	new_node->nbr = nbr;
	new_node->next = NULL;
	return (new_node);
}
void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*last_node;

	if (*lst == NULL)
		*lst = new;
	else
	{
		last_node = *lst;
		while (last_node->next != NULL)
		{
			if (last_node->nbr == new->nbr)
				ft_exit("err duplicat","");
			last_node = last_node->next;
		}
		if (last_node->nbr == new->nbr)
			ft_exit("err duplicat","");
		last_node->next = new;
	}
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

static int	white_space(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

void atoi_boucle(char *str, int *num)
{
	int	digit;

	while (*str)
	{
		if (!ft_isdigit(*str))
			ft_exit("error in ", str);
		*num *= 10;
		digit = (int)(*str - '0');
		if (digit < 0)
			digit = -digit;
		*num += digit;
		str++;
	}
}

int	ft_atoi(char *str)
{
	int	num;
	int	sign;

	num = 0;
	sign = 1;
	while (white_space(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	atoi_boucle(str, &num);
	return (num * sign);
}

void adv_atoi_cond(t_stack **a, char *str)
{
	int	num;
	int	sign;

	num = 0;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (!ft_isdigit(*str))
		ft_exit("adv_error in ", str);
	num = num * 10 + *str - '0';
	str++;
	if (*str == ' ' || *str == '\0')
	{
		ft_lstadd_back(a, ft_lstnew(num * sign));
		sign = 1;
		num = 0;
	}
}

void	ft_adv_atoi(char *str, t_stack **a)
{
	while (white_space(*str))
		str++;
	while (*str)
	{
		while (white_space(*str))
			str++;
		adv_atoi_cond(a, str);
	}
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	c1;

	i = 0;
	c1 = (char)c;
	while (s[i])
	{
		if (s[i] == c1)
			return ((char *)s + i);
		i++;
	}
	if (c1 == '\0')
		return ((char *)s + i);
	return (0);
}

t_stack  *push_swap_init (int ac, char **av)
{
	t_stack *a;

    int i = 1;
	while (i < ac)
	{
		if (ft_strchr(av[i], ' '))
			ft_adv_atoi(av[i], &a);
		else if (av[i][0] != '\0')
			ft_lstadd_back(&a, ft_lstnew(ft_atoi(av[i])));
		i++;
	}
    return a;
}

int ft_check_sort(t_stack *cpy)
{
	while(cpy->next)
	{
		if (cpy->nbr > cpy->next->nbr)
			return 0;
		cpy = cpy->next;
	}
	return 1;
}
int	smallest_node(t_stack *cpy)
{
	
    if (cpy == NULL) {
        return -1; 
    }

	int smallIndex = 0;
    int currentIndex = 1;
    int minValue = cpy->nbr;

    t_stack  *current = cpy->next;

    while (current != NULL) {
        if (current->nbr < minValue) {
            minValue = current->nbr;
			smallIndex = currentIndex;
        }
        current = current->next;
        currentIndex++;
    }
    return smallIndex;
}

void ft_print_stack(t_stack *stack)
{
	while (stack)
	{
		printf("%d ", stack->nbr);
		stack = stack->next;
	}
	printf("\n");
}

void sorting_array(int *array, int end)
{
	int i;
	int j;
	int save;

	i = 0;
	while (i < end)
	{
		j = i + 1;
		while (j < end)
		{
			if (array[i] > array[j])
			{
				save = array[i];
				array[i] = array[j];
				array[j] = save;
			}
			j++;
		}
		i++;
	}
}

int *sort_stack_in_array(t_stack *a, int size)
{
	int *array = malloc(sizeof(t_stack) * size);
	int i = 0;
	int end;
	
	if (!array)
		ft_exit("malloc failled", NULL);
	while (a)
	{
		array[i] = a->nbr;
		a = a->next;
		i++;
	}
	end = i;
	sorting_array(array, end);
	return array;
}

int ft_get_index(t_stack *a, int *array, int start, int end)
{
	int index = -1;
	int i;

	while (a)
	{
		i = start;
		index++;
		while (i < end)
		{
			if (array[i] == a->nbr)
				return index;
			i++;
		}
		a = a->next;
	}

	return index;
}

int ft_big_index(t_stack *b, int big)
{
	int index = 0;

	while (b)
	{
		if (b->nbr == big)
			break;
		index++;
		b = b->next;
	}
	return index;
}
