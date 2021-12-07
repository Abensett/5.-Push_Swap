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

t_list	*ft_fillstack(int ac, char **list)
{
	t_list	*stack;
	int		i;

	i = 1;
	stack = NULL;
	if (ac == 1)
	{
		ft_error();
		exit(42);
	}
	while (i < ac)
		ft_lstadd_back(&stack, ft_lstnew((void *) ft_atol(list[i++])));
	return (stack);
}

int	main(int ac, char **av)
{

	t_list	*stack_a;

	stack_a = ft_fillstack(ac, av);

/* 	printf("\n A: \n");
	ft_lst_int_print(*stack_a);
	printf("\n\n");    */

	if (ac < 2 || ft_checkdigit(ac, av) ||
	 ft_checkduplint(*stack_a) || ft_check_max_int(*stack_a))
		ft_error();

	if(!ft_lst_int_check_order(*stack_a))	
		ft_sort(&stack_a);
  /*  	printf("\n A:%d \n",ft_lst_int_check_order(*stack_a)); 
	ft_lst_int_print(*stack_a);   
 	printf("\n");    */
 
}
