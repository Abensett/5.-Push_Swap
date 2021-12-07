/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 22:29:51 by abensett          #+#    #+#             */
/*   Updated: 2021/11/11 22:29:51 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

long	*ft_sorted_tab(t_list list)
{
	t_list	*tmp ;
	long	*tab;
	int		i;

	i = 0;
	tab = malloc(ft_lstsize(&list) * sizeof(long));
	tmp = &list;
	while (tmp)
	{
		tab[i++] = (long)(tmp->content);
		tmp = tmp->next;
	}
	ft_tab_long_sort(tab, i);
	return (tab);
}

int		ft_scan_exist(t_list stack, long min, long max)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = &stack;
	while (tmp)
	{
		if (min <= (long)tmp->content && (long)tmp->content <= max)
			return (1);
		tmp = tmp->next;
	}
	return(0);
}

int		ft_scan_first(t_list stack, long min, long max)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = &stack;
	while (tmp)
	{
		if (min <= (long)tmp->content && (long)tmp->content <= max)
		{
			return (i);
		}
		i++;
		tmp = tmp->next;
	}
}
int		ft_scan_last(t_list stack, long min, long max)
{
	int 	i;
	int		isaved;
	t_list	*tmp;

	i = 0;
	tmp = &stack;
	while (tmp)
	{
		if (min <= (long)tmp->content && (long)tmp->content <= max)
			isaved = i;
		i++;
		tmp = tmp->next;
	}
	return (isaved);
}

void 	ft_top (t_list **stack, int index, char c)
{
	int i;

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



