/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 12:15:31 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/07 13:21:26 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_check_exit(t_process *tmp, char **str, char ***str_split, int i)
{
	(*str) = ft_strdup((*str_split)[1]);
	ft_free_split((*str_split));
	(*str_split) = ft_split((*str), ' ');
	if ((*str_split)[1])
		ft_error_exit(tmp, &(*str), &(*str_split), 1);
	while ((*str_split)[1])
	{
		if (!((i == 0 && ((((*str_split)[0][i] == '-' \
			|| (*str_split)[0][i] == '+') && (*str_split)[0][1])
			|| ((*str_split)[0][i] - 48 >= 0 && (*str_split)[0][i] - 48 <= 9)))
			|| (i != 0 && (*str_split)[0][i] - 48 >= 0
			&& (*str_split)[0][i] - 48 <= 9)))
			ft_error_exit(tmp, &(*str), &(*str_split), 1);
		i++;
	}
}
