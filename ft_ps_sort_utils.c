/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 00:51:30 by abensett          #+#    #+#             */
/*   Updated: 2021/12/12 00:51:30 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	stack_idx_mid(t_list *stack, int num)
{
	int			current;
	int			next;
	int			ret;
	const int	size = ft_lstsize(stack);

	ret = 1;
	while (stack->next)
	{
		current = (long)(stack->content);
		next = (long)(stack->next->content);
		if (num > current && num < next)
			break ;
		++ret;
		stack = stack->next;
	}
	if (ret == size)
		ret = 0;
	else if (ret >= (size + 1) / 2)
		ret = -1 * (size - ret);
	return (ret);
}

int	stack_idx_minmax(t_list *stack, int num)
{
	int			ret;
	int			x;
	const int	size = ft_lstsize(stack);

	ret = 0;
	x = ft_stack_max(*stack);
	if (num <= ft_stack_min(*stack))
		x = ft_stack_min(*stack);
	else
		++ret;
	while (stack)
	{
		if ((long)(stack->content) == x)
			break ;
		++ret;
		stack = stack->next;
	}
	if (ret >= (size + 1) / 2)
		ret = -1 * (size - ret);
	return (ret);
}

void	ft_find_min(t_list *stack_a, t_list *stack_b, int *a, int *b)
{
	int			i;
	int			j;
	long		num;
	int			x;
	const int	size_b = ft_lstsize(stack_b);

	x = -1;
	while (stack_b && ++x >= 0)
	{
		num = (long)(stack_b->content);
		if (num < ft_stack_min(*stack_a) || num > ft_stack_max(*stack_a))
			i = stack_idx_minmax(stack_a, num);
		else
			i = stack_idx_mid(stack_a, num);
		j = x;
		if (x >= (size_b + 1) / 2)
			j = -1 * (size_b - x);
		if (x == 0 || ft_abs(*a) + ft_abs(*b) > ft_abs(i) + ft_abs(j))
		{
			*a = i;
			*b = j;
		}
		stack_b = stack_b->next;
	}
}

void	ft_rr_same(t_list **stack_a, t_list **stack_b, int a, int b)
{
	if (a >= 0 && b >= 0)
	{
		ft_cmd("rr", stack_a, stack_b, ft_min(ft_abs(a), ft_abs(b)));
		if (ft_abs(a) <= ft_abs(b))
			ft_cmd("rb", stack_b, 0, ft_abs(ft_abs(a) - ft_abs(b)));
		else
			ft_cmd("ra", stack_a, 0, ft_abs(ft_abs(a) - ft_abs(b)));
	}
	else
	{
		ft_cmd("rrr", stack_a, stack_b, ft_min(ft_abs(a), ft_abs(b)));
		if (ft_abs(a) <= ft_abs(b))
			ft_cmd("rrb", stack_b, 0, ft_abs(ft_abs(a) - ft_abs(b)));
		else
			ft_cmd("rra", stack_a, 0, ft_abs(ft_abs(a) - ft_abs(b)));
	}
}

void	ft_rr_diff(t_list **stack_a, t_list **stack_b, int a, int b)
{
	if (a >= 0 && b < 0)
	{
		ft_cmd("ra", stack_a, 0, a);
		ft_cmd("rrb", stack_b, 0, ft_abs(ft_min(a, b)));
	}
	else
	{
		ft_cmd("rb", stack_b, 0, b);
		ft_cmd("rra", stack_a, 0, ft_abs(ft_min(a, b)));
	}
}
