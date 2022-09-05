/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_cmd_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 14:54:28 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/02 18:25:47 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_run_cmd_2(t_process *tmp, t_in_out *tmp2, t_process *process)
{
	int	i;

	if (!tmp2 || (tmp2 && tmp2->type == 3))
		i = 1;
	else
		i = 0;
	while (tmp2)
	{
		if (tmp2 && tmp2->type != 3)
			i++;
		tmp2 = tmp2->next;
	}
	i = ft_run_cmd_3(tmp, tmp2, i);
	tmp = process;
	return (1);
}
