/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 21:18:56 by abensett          #+#    #+#             */
/*   Updated: 2021/10/23 21:18:56 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "../libft/libft.h"
# include <unistd.h>
# include <limits.h>

/*errors in ft_errorshandler.c*/
void	ft_error(void);
int		ft_checkdigit(int ac, char **av);
int		ft_checkduplint(t_list stack);
int		ft_check_max_int(t_list stack);

/*ft_ps_utils.c*/
long	ft_stack_min(t_list stack);
long	ft_stack_max(t_list stack);
int		ft_stack_min_place(t_list stack);
int		ft_stack_max_place(t_list stack);

/*ft_ps_utils2.c*/
/* return a sorted tab (ascending order)*/
long	*ft_sorted_tab(t_list list);
/* check if there s a number between min and max in stack */
int		ft_scan_exist(t_list stack, long min, long max);
/* return the index of the first number found that belongs yo the hunk [min;max]*/
int		ft_scan_first(t_list stack, long min, long max);
/* return the index of the last number found that belongs yo the hunk [min;max]*/
int		ft_scan_last(t_list stack, long min, long max);

/*ft_ps_commands.c*/
void	ft_s(t_list **stack1, t_list **stack2);
void	ft_p(t_list **stack1, t_list **stack2);
void	ft_r(t_list **stack1, t_list **stack2);
void	ft_rr(t_list **stack1, t_list **stack2);
void	ft_cmd(char *cmd, t_list **stack_1, t_list **stack_2, int x);

/*ft_sort.c*/
void	ft_easy_sorting(t_list **stack_a);
int 	*ft_hunks(int len, int size);
void	ft_sort(t_list **stack);
void 	ft_top (t_list **stack, int nb, char c);


/*ft_push_swap.c*/
t_list	*ft_fillstack(int ac, char **list);
int		main(int ac, char **av);


#endif