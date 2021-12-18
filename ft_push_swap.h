/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 21:18:56 by abensett          #+#    #+#             */
/*   Updated: 2021/12/07 11:41:49 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# define BUFFER_SIZE 10

/*ERRORS in ft_errorshandler.c*/
void	ft_error(void);
int		ft_checkdigit(int ac, char **av);
int		ft_checkduplint(t_list stack);
int		ft_check_max_int(t_list stack);

/*ft_ps_utils.c*/
long	ft_stack_min(t_list stack);
long	ft_stack_max(t_list stack);
int		ft_stack_min_place(t_list stack);
t_list	*ft_fillstack(int ac, char **list);
/*bring the number at index nb at top, c = 'a' or 'b' depending the stack*/
void	ft_top(t_list **stack, int nb, char c);

/*ft_ps_commands.c*/
void	ft_s(t_list **stack1, t_list **stack2);
void	ft_p(t_list **stack1, t_list **stack2);
void	ft_r(t_list **stack1, t_list **stack2);
void	ft_rr(t_list **stack1, t_list **stack2);
void	ft_cmd(char *cmd, t_list **stack_1, t_list **stack_2, int x);

/*ft_sort_utils.c*/
int		ft_find_place(t_list *stack, int nb);
int		ft_find_place_maxmin(t_list *stack, int nb);
void	ft_find_min(t_list *stack_a, t_list *stack_b, int *a, int *b);
void	ft_rr_same(t_list **stack_a, t_list **stack_b, int a, int b);
void	ft_rr_diff(t_list **stack_a, t_list **stack_b, int a, int b);

/*ft_sort.c*/
void	ft_easy_sorting(t_list **stack_a);
void	ft_strong_sort(t_list **stack_a);
void	ft_sort(t_list **stack_a);

/*ft_push_swap.c*/
int		main(int ac, char **av);

/*bonus */
char	*ft_get_next_line(char **str);

#endif
