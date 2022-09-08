/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ll_max.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 12:56:50 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/07 13:17:32 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_ll_max(t_process *tmp, char **str, char ***str_split, int i)
{
	char	*ll_max;

	ll_max = "9223372036854775807";
	while (i < (int)ft_strlen(ll_max))
	{
		if ((*str_split)[0][i] > ll_max[i])
			ft_error_exit(tmp, &(*str), &(*str_split), 1);
		i++;
	}
	ft_return_exit(&(*str), &(*str_split));
}
