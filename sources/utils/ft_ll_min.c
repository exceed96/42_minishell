/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ll_min.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 12:46:14 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/07 13:18:11 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_ll_min(t_process *tmp, char **str, char ***str_split, int i)
{
	char	*ll_min;

	ll_min = "-9223372036854775808";
	while (i < (int)ft_strlen(ll_min))
	{
		if ((*str_split)[0][i] > ll_min[i])
			ft_error_exit(tmp, &(*str), &(*str_split), 1);
		i++;
	}
	ft_return_exit(&(*str), &(*str_split));
}
