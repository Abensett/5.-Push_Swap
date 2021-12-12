/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 02:04:10 by abensett          #+#    #+#             */
/*   Updated: 2021/10/30 02:04:10 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/*SWAP F2:push the swap the first two elements of stack*/
void	ft_s(t_list **stack1, t_list **stack2)
{
	t_list	*tmp;

	if (ft_lstsize(*stack1) >= 2)
	{
		tmp = (*stack1)->next;
		(*stack1)->next = (*stack1)->next->next;
		ft_lstadd_front(stack1, tmp);
	}
	(void)(*stack2);
}

/*PUSH : the first element of stack1 onto stack2*/
void	ft_p(t_list **stack1, t_list **stack2)
{
	t_list	*tmp;

	if (ft_lstsize(*stack1))
	{
		tmp = (*stack1);
		(*stack1) = (*stack1)->next;
		ft_lstadd_front(stack2, tmp);
	}
	(void)(*stack2);
}

/*ROTATE :The first element becomes  the last one*/
void	ft_r(t_list **stack1, t_list **stack2)
{
	t_list	*tmp;

	if (ft_lstsize(*stack1) >= 2)
	{
		tmp = (*stack1);
		(*stack1) = (*stack1)->next;
		tmp->next = NULL;
		ft_lstadd_back(stack1, tmp);
	}
	(void)(*stack2);
}

/*REVERSE :The last element becomes the first one*/
void	ft_rr(t_list **stack1, t_list **stack2)
{
	t_list	*tmp;
	t_list	*last;

	if (ft_lstsize(*stack1) >= 2)
	{
		last = *stack1;
		while (last->next)
		{
			tmp = last;
			last = last->next;
		}
		tmp->next = NULL;
		ft_lstadd_front(stack1, last);
	}
	(void)(*stack2);
}

/*execute the cmds*/
void	ft_cmd(char *cmd, t_list **stack_1, t_list **stack_2, int times)
{
	const int	len = ft_strlen(cmd);
	void		(*f_cmd)(t_list **, t_list **);
	int			x;

	x = ft_abs(times);
	if (!ft_strncmp(cmd, "sa", len) || !ft_strncmp(cmd, "sb", len)
		|| !ft_strncmp(cmd, "ss", len))
		f_cmd = &ft_s;
	else if (!ft_strncmp(cmd, "pa", len) || !ft_strncmp(cmd, "pb", len))
		f_cmd = &ft_p;
	else if (!ft_strncmp(cmd, "ra", len) || !ft_strncmp(cmd, "rb", len)
		|| !ft_strncmp(cmd, "rr", len))
		f_cmd = &ft_r;
	else
		f_cmd = &ft_rr;
	while (x-- > 0)
	{
		if (f_cmd != ft_p && stack_2)
			f_cmd(stack_2, 0);
		f_cmd(stack_1, stack_2);
		if (times > 0)
			ft_putendl_fd(cmd, 1);
	}
}
