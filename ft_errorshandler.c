/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errorshandler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 22:06:21 by abensett          #+#    #+#             */
/*   Updated: 2021/10/22 22:06:21 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

int	ft_checkdigit(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		if (ft_strlen(av[i]) > 11)
			return (0);
		while (av[i][j])
		{
			if ((av[i][0] == '+' || av[i][0] == '-') && av[i][1])
				j++;
			else if (!(ft_isdigit(av[i][j++])))
				return (1);
		}
		i++;
	}
	return (0);
}

int	ft_checkduplint(t_list stack)
{
	t_list	*tmp;

	tmp = &stack;
	while (tmp)
	{
		if (ft_lst_int_occurence(stack, (long)tmp->content) > 1)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	ft_check_max_int(t_list stack)
{
	t_list	*tmp;

	tmp = &stack;
	while (tmp)
	{
		if ((long)tmp->content > INT_MAX || (long)tmp->content < INT_MIN)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
