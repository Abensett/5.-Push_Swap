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

#include "ft_push_swap.h"

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

int		ft_stack_min_place(t_list stack)
{
	t_list	*tmp;
	long	min;
	int		num = 0;
	int		i = 0;

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

int		ft_stack_max_place(t_list stack)
{
	t_list	*tmp;
	long	max;
	int		num = 0;
	int		i = 0;

	tmp = &stack;
	max = (long)tmp->content;
	while (tmp)
	{
		if (max < (long)tmp->content)
		{
			max = (long)tmp->content;
			i = num;
		}
		num++;
		tmp = tmp->next;
	}
	return (i);
}
