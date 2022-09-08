/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ll_max_plus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 12:53:40 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/07 13:17:50 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_ll_max_plus(t_process *tmp, char **str, char ***str_split, int i)
{
	char	*ll_max_plus;

	ll_max_plus = "+9223372036854775807";
	while (i < (int)ft_strlen(ll_max_plus))
	{
		if ((*str_split)[0][i] > ll_max_plus[i])
			ft_error_exit(tmp, &(*str), &(*str_split), 1);
		i++;
	}
	ft_return_exit(&(*str), &(*str_split));
}
