/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 13:27:31 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/08 18:24:21 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdlib.h>
# include "minishell.h"
# include "../libft/libft.h"

typedef struct s_data
{
	int				status;
	int				*fd;
	int				c_n;
	int				j;
	char			**p_env;
	char			**p_paths;
	char			***p_ag;
	char			*line;
	int				fork_status;
	int				n_cmd;
	int				*file;
	char			set[4];
	int				exit;
	struct s_in_out	*inout;
	pid_t			*pid1;
}t_data;

#endif
