/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 14:25:58 by abensett          #+#    #+#             */
/*   Updated: 2021/12/18 14:25:58 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

int	ft_find_place(t_list *stack, int nb)
{
	int			current;
	int			next;
	int			place;
	const int	size = ft_lstsize(stack);

	place = 1;
	while (stack->next)
	{
		current = (long)(stack->content);
		next = (long)(stack->next->content);
		if (nb > current && nb < next)
			break ;
		++place;
		stack = stack->next;
	}
	if (place == size)
		place = 0;
	else if (place >= (size + 1) / 2)
		place = -1 * (size - place);
	return (place);
}

int	ft_find_place_maxmin(t_list *stack, int nb)
{
	int			place;
	int			x;
	const int	size = ft_lstsize(stack);

	place = 0;
	x = ft_stack_max(*stack);
	if (nb <= ft_stack_min(*stack))
		x = ft_stack_min(*stack);
	else
		++place;
	while (stack)
	{
		if ((long)(stack->content) == x)
			break ;
		++place;
		stack = stack->next;
	}
	if (place >= (size + 1) / 2)
		place = -1 * (size - place);
	return (place);
}

void	ft_find_min(t_list *stack_a, t_list *stack_b, int *a, int *b)
{
	int			i;
	int			j;
	long		nb;
	int			x;
	const int	len_b = ft_lstsize(stack_b);

	x = -1;
	while (stack_b && ++x >= 0)
	{
		nb = (long)(stack_b->content);
		if (nb < ft_stack_min(*stack_a) || nb > ft_stack_max(*stack_a))
			i = ft_find_place_maxmin(stack_a, nb);
		else
			i = ft_find_place(stack_a, nb);
		j = x;
		if (x >= (len_b + 1) / 2)
			j = -1 * (len_b - x);
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
