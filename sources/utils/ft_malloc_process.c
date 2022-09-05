/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_process.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 17:14:20 by sangyeki          #+#    #+#             */
/*   Updated: 2022/08/27 17:16:58 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_malloc_process(t_process **process)
{
	t_process	*new;

	new = malloc(sizeof(t_process));
	if (!new)
		return ;
	new->next = NULL;
	new->inout = NULL;
	new->cmd = NULL;
	new->cmd_arg = NULL;
	new->input_fd = 0;
	new->output_fd = 0;
	new->type = NULL;
	if (*process)
		(*process)->next = new;
	else
		(*process) = new;
}
