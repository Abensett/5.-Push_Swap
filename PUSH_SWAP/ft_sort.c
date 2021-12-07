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

void	ft_easy_sorting(t_list **stack)
{
	long	n1 = (long )(*stack)->content;
	long	n2 = (long )(*stack)->next->content;
	long	n3 = (long )(*stack)->next->next->content;

	if (n1 == ft_stack_min(**stack) && n2 == ft_stack_max(**stack))
	{
		ft_cmd("sa", stack, 0, 1);
		ft_cmd("ra", stack, 0, 1);
	}
	else if (n1 == ft_stack_max(**stack) && n2 == ft_stack_min(**stack))
		ft_cmd("ra", stack, 0, 1);
	else if (n1 == ft_stack_max(**stack) && n3 == ft_stack_min(**stack))
	{
		ft_cmd("ra", stack, 0, 1);
		ft_cmd("sa", stack, 0, 1);
	}
	else if (n2 == ft_stack_min(**stack) && n3 == ft_stack_max(**stack))
		ft_cmd("sa", stack, 0, 1);
	else if (n2 == ft_stack_max(**stack) && n3 == ft_stack_min(**stack))
		ft_cmd("rra", stack, 0, 1);
}

void	ft_push(t_list **stack_a, t_list **stack_b)
{
	long	*tab;

	if (!*stack_b)
	{
		ft_cmd("pb", stack_a, stack_b, 1);
		return;
	}
	if (!((*stack_b)->next))
	{
		ft_cmd("pb", stack_a, stack_b, 1);
		return;
	}
/* 	
	printf("\n after sort %d: \n", ft_stack_max_place(**stack_b)); */
	if ((long)(*stack_a)->content < ft_stack_min(**stack_b)
	|| (long)(*stack_a)->content > ft_stack_max(**stack_b))
	{
		ft_top(stack_b, ft_stack_max_place(**stack_b), 'b');
		ft_cmd("pb", stack_a, stack_b, 1);
		return;
	}
	tab = ft_sorted_tab(**stack_b);
	while ((long)(*stack_a)->content > *tab)
	{
		tab++;
	}
	tab--;
 /* 	printf("\n after s: %d \n, ", ft_scan_first(**stack_b, *tab, *tab)); */
	ft_top(stack_b, ft_scan_first(**stack_b, *tab, *tab) , 'b');
	ft_cmd("pb", stack_a, stack_b, 1); 
/*   	printf("\n after sort B: \n");
	ft_lst_int_print(**stack_b);
	printf("\n");   */

}

int 	*ft_hunks(int len, int size)
{
	int	*tab;
	int i;
	int j;

	tab = malloc ((size + 1) * sizeof(int));
	if (!tab)
		ft_error();
	i = 1;
	j = len / size;
	tab[0] = 0;
	while (i < size)
	{
		tab[i++] = j;
		j += len / size;
	}
	tab[size] = len - 1;
	return (tab);
}
void	ft_strong_sorting(t_list **s, t_list **stack_b)
{
	long	*tab;
	int		i;
	int		*hunk;

	i = 1;
	hunk = ft_hunks(ft_lstsize(*s), 11);
	tab = ft_sorted_tab(**s);
/*  	ft_putendl_fd("\n the whole hunk",1);
	ft_tab_int_print(hunk, 11);
	ft_putendl_fd("",1);
	ft_putendl_fd("\n",1);    */
	while (i < 12)
	{
/* 		ft_tab_long_print(tab, 100); */
 /* 	  	printf("\n my current tab:%ld-%ld \n",tab[hunk[i - 1]],tab[hunk[i]]);
 		printf("\n my current hunk:%d-%d ",hunk[i - 1], hunk[i] );
		printf("\n first:%d ",ft_scan_first(**s,tab[hunk[i - 1]], tab[hunk[i]]));	
		printf("\n last=%d: \n",ft_scan_last(**s,tab[hunk[i - 1]], tab[hunk[i]]));   */ 
		while (ft_scan_exist(**s, tab[hunk[i - 1]], tab[hunk[i]]))
		{	
			if (!(((*s)->next)))
				break;
			if (ft_scan_first(**s,tab[hunk[i - 1]], tab[hunk[i]]) 
			< ft_lstsize(*s) - ft_scan_last(**s, tab[hunk[i - 1]], tab[hunk[i]]))
				ft_top(s, ft_scan_first(**s,tab[hunk[i - 1]], tab[hunk[i]]), 'a');
			else
				ft_top(s, ft_scan_last(**s,tab[hunk[i - 1]], tab[hunk[i]]), 'a');
		
			ft_push(s, stack_b);
  /* 		 	printf("\n after push B: \n");
			ft_lst_int_print(**stack_b);
			ft_putendl_fd("\n",1);   */
 		
		 
		}
/*		printf("\n");
		printf("\n i=%d:",i);	
		printf("\n my current hunk:%d-%d ",hunk[i - 1], hunk[i] );
		printf("\n my current tab:%ld-%ld \n",tab[hunk[i - 1]],tab[hunk[i]] );
		*/

		i++;
	}
	ft_push(s, stack_b);
/* 	ft_putendl_fd("\n",1);
	ft_tab_long_print(tab, 100);
	ft_putendl_fd("wtf",1);
	ft_putendl_fd("\n",1);  */
}

void	ft_sort(t_list **stack)
{
	t_list	*stack_b;

	stack_b = 0;
	if (ft_lstsize(*stack) == 2)
		ft_cmd("sa", stack, 0, 1);
	else if (ft_lstsize(*stack) == 3)
		ft_easy_sorting(stack);
	else if (ft_lstsize(*stack) == 5)
	{
		ft_top(stack, ft_stack_min_place(**stack), 'a');
		ft_cmd("pb", stack, &stack_b, 1);
		ft_top(stack, ft_stack_min_place(**stack), 'a');
		ft_cmd("pb", stack, &stack_b, 1);
		ft_easy_sorting(stack);
	}
	else
	{
/* 		ft_top(stack, ft_stack_min_place(**stack), 'a');
		ft_cmd("pb", &stack_b, stack, 1); */

		ft_strong_sorting(stack, &stack_b);
		
/* 		printf("\n after sort B: \n");
		ft_lst_int_print(*stack_b);
		printf("\n");   */
/* 		printf("\n max B:%ld \n", ft_stack_max(*stack_b));
		ft_lst_int_print(*stack_b);
		printf("\n");    */
	}
	while (stack_b)
	{
			ft_top(&stack_b, ft_stack_max_place( *stack_b), 'b');
			ft_cmd("pa", &stack_b, stack, 1);
	}

}
