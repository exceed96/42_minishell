/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_structlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 15:25:18 by sangyeki          #+#    #+#             */
/*   Updated: 2022/08/31 15:26:10 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_structlen(t_process *process)
{
	t_process	*tmp;
	int			len;

	len = 0;
	tmp = process;
	while (tmp)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}
