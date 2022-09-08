/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 12:21:13 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/07 13:20:24 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_error_exit(t_process *tmp, char **str, char ***str_split, int i)
{
	if (i)
		free(*str);
	ft_free_split(*str_split);
	if (!tmp->output_fd)
		printf("exit : numeric argument required\n");
	exit(255);
}
