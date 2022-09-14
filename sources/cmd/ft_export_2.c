/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 12:01:36 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/14 12:05:08 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_data	*ft_export_2(t_data *data, char **str, int q[3])
{
	free(data->env[q[1]]);
	data->env[q[1]] = ft_strdup(str[q[0]++]);
	return (data);
}
