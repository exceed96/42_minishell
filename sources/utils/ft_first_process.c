/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 17:12:13 by sangyeki          #+#    #+#             */
/*   Updated: 2022/08/27 17:18:31 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_first_process(t_process **process, t_process **tmp, int i)
{
	if (!i)
	{
		(*tmp) = malloc(sizeof(t_process));
		if (!(*tmp))
			return ;
		ft_malloc_process(tmp);
		(*process) = (*tmp)->next;
		free((*tmp));
	}
	else
	{
		ft_malloc_process(process);
		(*process) = (*process)->next;
	}
	if (!i)
		(*tmp) = (*process);
}
