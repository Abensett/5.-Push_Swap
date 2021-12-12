/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 18:12:01 by abensett          #+#    #+#             */
/*   Updated: 2021/10/22 18:12:01 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	main(int ac, char **av)
{
	t_list	*stack_a;

	if (ac == 1)
		return (0);
	stack_a = ft_fillstack(ac, av);
	if (ft_checkdigit(ac, av)
		|| ft_checkduplint(*stack_a) || ft_check_max_int(*stack_a))
		ft_error();
	if (!ft_lst_int_check_order(*stack_a))
		ft_sort(&stack_a);
	return (0);
}
