/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 18:30:48 by abensett          #+#    #+#             */
/*   Updated: 2021/10/31 18:30:48 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_easy_sorting(t_list **stack_a)
{
	long	n1;
	long	n2;
	long	n3;

	n1 = (long )(*stack_a)->content;
	n2 = (long )(*stack_a)->next->content;
	n3 = (long )(*stack_a)->next->next->content;
	if (n1 == ft_stack_min(**stack_a) && n2 == ft_stack_max(**stack_a))
	{
		ft_cmd("sa", stack_a, 0, 1);
		ft_cmd("ra", stack_a, 0, 1);
	}
	else if (n1 == ft_stack_max(**stack_a) && n2 == ft_stack_min(**stack_a))
		ft_cmd("ra", stack_a, 0, 1);
	else if (n1 == ft_stack_max(**stack_a) && n3 == ft_stack_min(**stack_a))
	{
		ft_cmd("ra", stack_a, 0, 1);
		ft_cmd("sa", stack_a, 0, 1);
	}
	else if (n2 == ft_stack_min(**stack_a) && n3 == ft_stack_max(**stack_a))
		ft_cmd("sa", stack_a, 0, 1);
	else if (n2 == ft_stack_max(**stack_a) && n3 == ft_stack_min(**stack_a))
		ft_cmd("rra", stack_a, 0, 1);
}

void	ft_strong_sorting(t_list **stack_a)
{
	int		a;
	int		b;
	t_list	*stack_b;

	stack_b = 0;
	while (ft_lstsize(*stack_a) > 3)
		ft_cmd("pb", stack_a, &stack_b, 1);
	if (ft_lstsize(*stack_a) == 3)
		ft_easy_sorting(stack_a);
	while (ft_lstsize(stack_b))
	{
		a = 0;
		b = 0;
		ft_find_min(*stack_a, stack_b, &a, &b);
		if ((a >= 0 && b >= 0) || (a < 0 && b < 0))
			ft_rr_same(stack_a, &stack_b, a, b);
		else
			ft_rr_diff(stack_a, &stack_b, a, b);
		ft_cmd("pa", &stack_b, stack_a, 1);
	}
}

void	ft_sort(t_list **stack_a)
{
	if (ft_lstsize(*stack_a) == 2)
		ft_cmd("sa", stack_a, 0, 1);
	else if (ft_lstsize(*stack_a) == 3)
		ft_easy_sorting(stack_a);
	else
		ft_strong_sorting(stack_a);
	ft_top(stack_a, ft_stack_min_place(**stack_a), 'a');
}
