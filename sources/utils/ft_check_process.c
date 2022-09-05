/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 15:06:13 by sangyeki          #+#    #+#             */
/*   Updated: 2022/08/31 15:07:21 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_check_process(t_process *process)
{
	t_process	*tmp;

	tmp = process;
	while (tmp)
	{
		if (tmp->inout)
		{
			if (tmp->inout->file && tmp->inout->file[0] == '\0')
				return (0);
			if (!tmp->inout->file)
				return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}
