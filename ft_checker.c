/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 21:12:25 by abensett          #+#    #+#             */
/*   Updated: 2021/12/14 21:44:14 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	ps_error(void)
{
	ft_putendl_fd("Error", 2);
	return (1);
}

static int	parse(char *str, t_list **stack_1, t_list **stack_2)
{
	int	len;
	int	(*f)(const char *, const char *, size_t);

	len = ft_strlen(str);
	if (len < 3 || len > 4)
		return (ps_error());
	str[len - 1] = 0;
	len = ft_strlen(str);
	f = &ft_strncmp;
	if ((len == 3 && !f(str, "rra", 3)) || (len == 2 && (!f(str, "sa", 2)
				|| !f(str, "ra", 2))))
		ft_cmd(str, stack_1, 0, -1);
	else if ((len == 3 && !f(str, "rrb", 3)) || (len == 2 && (!f(str, "sb", 2)
				|| !f(str, "rb", 2))))
		ft_cmd(str, stack_2, 0, -1);
	else if ((len == 3 && !f(str, "rrr", 3)) || (len == 2 && (!f(str, "ss", 2)
				|| !f(str, "pb", 2) || !f(str, "rr", 2))))
		ft_cmd(str, stack_1, stack_2, -1);
	else if (!f(str, "pa", 2))
		ft_cmd(str, stack_2, stack_1, -1);
	else
		return (ps_error());
	return (0);
}

static void	sort_check(t_list **stack_a)
{
	char		*cmd;
	t_list		*stack_b;
	static char	*str;

	stack_b = 0;
	while (1)
	{
		cmd = get_next_line(&str);
		if (!cmd || !ft_strlen(cmd))
		{
			free(cmd);
			break ;
		}
		if (parse(cmd, stack_a, &stack_b))
		{
			free(str);
			free(cmd);
			return ;
		}
		free(cmd);
	}
	if (ft_lst_int_check_order(**stack_a) && !ft_lstsize(stack_b))
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
}

int	main(int ac, char **av)
{
	t_list	*stack;

	if (ac > 1)
	{
		stack = ft_fillstack(ac, av);
		if (ft_checkdigit(ac, av) || ft_checkduplint(*stack)
			|| ft_check_max_int(*stack))
			ft_error();
		sort_check(&stack);
	}
	return (0);
}
