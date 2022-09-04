/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_organize_inout.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 15:30:53 by sangyeki          #+#    #+#             */
/*   Updated: 2022/08/31 15:32:26 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_organize_inout(t_in_out *inout)
{
	int			i;
	t_in_out	*tmp;

	i = 0;
	tmp = inout;
	while (tmp)
	{
		if (i)
			i = 0;
		if (tmp->type == 3)
			tmp->read_prev = 1;
		i = 1;
		tmp = tmp->next;
	}
}
