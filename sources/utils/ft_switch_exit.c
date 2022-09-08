/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_switch_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 12:34:55 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/07 13:18:56 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_switch_exit(t_process *tmp, char **str, char ***str_split)
{
	char	*ll_max;
	char	*ll_max_plus;

	ll_max = "9223372036854775807";
	ll_max_plus = "+9223372036854775807";
	if ((((*str_split)[0][0] == '-' || (*str_split)[0][0] == '+')
		&& ft_strlen((*str_split)[0]) == ft_strlen(ll_max_plus))
		|| (ft_strlen((*str_split)[0]) == ft_strlen(ll_max)))
	{
		if ((*str_split)[0][0] == '-')
			ft_ll_min(tmp, &(*str), &(*str_split), 1);
		else if ((*str_split)[0][0] == '+')
			ft_ll_max_plus(tmp, &(*str), &(*str_split), 1);
		else
			ft_ll_max(tmp, &(*str), &(*str_split), 1);
	}
	else if ((((*str_split)[0][0] == '-' || (*str_split)[0][0] == '+')
			&& ft_strlen((*str_split)[0]) < ft_strlen(ll_max_plus))
			|| (ft_strlen((*str_split)[0]) < ft_strlen(ll_max)))
		ft_return_exit(&(*str), &(*str_split));
	else
		ft_error_exit(tmp, &(*str), &(*str_split), 1);
}
