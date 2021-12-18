/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 23:01:39 by abensett          #+#    #+#             */
/*   Updated: 2021/10/22 23:01:39 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

long	ft_stack_min(t_list stack)
{
	t_list	*tmp;
	long	min;
	long	num;

	tmp = &stack;
	min = (long)tmp->content;
	while (tmp)
	{
		num = (long)tmp->content;
		if (min > num)
			min = num;
		tmp = tmp->next;
	}
	return (min);
}

long	ft_stack_max(t_list stack)
{
	t_list	*tmp;
	long	max;
	long	num;

	tmp = &stack;
	max = (long)tmp->content;
	while (tmp)
	{
		num = (long)tmp->content;
		if (max < num)
			max = num;
		tmp = tmp->next;
	}
	return (max);
}

int	ft_stack_min_place(t_list stack)
{
	t_list	*tmp;
	long	min;
	int		num;
	int		i;

	num = 0;
	i = 0;
	tmp = &stack;
	min = (long)tmp->content;
	while (tmp)
	{
		if (min > (long)tmp->content)
		{
			min = (long)tmp->content;
			i = num;
		}
		num++;
		tmp = tmp->next;
	}
	return (i);
}

t_list	*ft_fillstack(int ac, char **list)
{
	t_list	*stack;
	int		i;

	i = 1;
	stack = NULL;
	if (ac == 1)
		ft_error();
	while (i < ac)
		ft_lstadd_back(&stack, ft_lstnew((void *) ft_atol(list[i++])));
	return (stack);
}

void	ft_top(t_list **stack, int index, char c)
{
	int	i;

	i = 0;
	if (index > ft_lstsize(*stack) / 2)
		i = ft_lstsize(*stack) - index;
	else
		i = index;
	while (i--)
	{
		if (c == 'a')
		{
			if (index > ft_lstsize(*stack) / 2)
				ft_cmd("rra", stack, 0, 1);
			else
				ft_cmd("ra", stack, 0, 1);
		}
		else
		{
			if (index > ft_lstsize(*stack) / 2)
				ft_cmd("rrb", stack, 0, 1);
			else
				ft_cmd("rb", stack, 0, 1);
		}
	}
}
