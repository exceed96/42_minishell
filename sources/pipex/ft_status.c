/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_status.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 19:47:19 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/03 19:48:22 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_status(t_data *data)
{
	if (WIFEXITED(data->status))
		return (WEXITSTATUS(data->status));
	else if (WIFSIGNALED(data->status))
		return (WTERMSIG(data->status));
	return (data->status);
}
