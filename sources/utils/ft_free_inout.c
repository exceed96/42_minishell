/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_inout.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 14:19:34 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/03 14:23:26 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_free_inout(t_in_out **inout)
{
	t_in_out	*tmp;
	t_in_out	*tmp2;

	tmp = *inout;
	while (tmp)
	{
		tmp2 = tmp->next;
		if (tmp->type == 3 && tmp->heredoc)
			free(tmp->heredoc);
		free(tmp->file);
		free(tmp);
		tmp = tmp2;
	}
	*inout = NULL;
}
