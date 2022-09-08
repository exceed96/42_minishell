/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_return_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:03:31 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/07 13:04:29 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_return_exit(char **str, char ***str_split)
{
	long long	ret_n;

	free(*str);
	ret_n = ft_atol((*str_split)[0]);
	ft_free_split((*str_split));
	exit (ret_n % 256);
}
