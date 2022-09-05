/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_cmd_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 14:59:51 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/04 18:56:29 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_run_cmd_3(t_process *tmp, t_in_out *tmp2, int i)
{
	while (tmp->next)
	{
		tmp = tmp->next;
		tmp2 = tmp->inout;
		if (tmp2)
		{
			while (tmp2)
			{
				if (tmp2 && tmp2->type == 3)
				{
					i++;
					while (tmp2 && tmp2->type == 3)
						tmp2 = tmp2->next;
				}
				if (tmp2 && tmp2->type != 3)
				{
					i++;
					tmp2 = tmp2->next;
				}
			}
		}
		else if (tmp)
			i++;
	}
	return (i);
}
