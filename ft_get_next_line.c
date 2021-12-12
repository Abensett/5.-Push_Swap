/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensett <abensett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 17:04:50 by abensett          #+#    #+#             */
/*   Updated: 2021/12/12 21:59:47 by abensett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	gnl_read(char *buf, char **str)
{
	int		i;
	char	*tmp;

	if (!*str || !ft_strchr(*str, '\n'))
	{
		i = read(0, buf, BUFFER_SIZE);
		while (i > 0)
		{
			buf[i] = 0;
			if (!*str)
				*str = ft_strdup(buf);
			else
			{
				tmp = *str;
				*str = ft_strjoin(*str, buf);
				free(tmp);
			}
			if (ft_strchr(buf, '\n'))
				break ;
			i = read(0, buf, BUFFER_SIZE);
		}
	}
	free(buf);
}

static char	*gnl_process(char **str)
{
	int		i;
	int		j;
	char	*ret;
	char	*tmp;

	if (!*str)
		return (0);
	if (!ft_strchr(*str, '\n'))
	{
		ret = ft_strdup(*str);
		free(*str);
		*str = 0;
		return (ret);
	}
	i = ft_strlen(*str);
	j = ft_strlen(ft_strchr(*str, '\n'));
	ret = ft_substr(*str, 0, i - j + 1);
	tmp = *str;
	*str = ft_substr(ft_strchr(*str, '\n'), 1, j - 1);
	free(tmp);
	return (ret);
}

char	*get_next_line(char **str)
{
	char	*buff;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	gnl_read(buff, str);
	return (gnl_process(str));
}
