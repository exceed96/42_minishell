/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 14:17:11 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/03 14:19:29 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_free(t_process **process)
{
	t_process	*tmp;

	while ((*process))
	{
		tmp = (*process)->next;
		if ((*process)->cmd)
			free((*process)->cmd);
		if ((*process)->cmd_arg)
			free((*process)->cmd_arg);
		if ((*process)->type)
			free((*process)->type);
		if ((*process)->inout)
			ft_free_inout(&(*process)->inout);
		free(*process);
		(*process) = tmp;
	}
}
