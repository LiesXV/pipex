/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhaim <ibenhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:33:37 by ibenhaim          #+#    #+#             */
/*   Updated: 2023/03/30 14:59:30 by ibenhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec(t_list *lst, char **env)
{
	
	if (execve(lst->path, lst->cmd, env) == -1)
	{
		ft_printf("first exec failed\n");
		exit (0);
	}
}

void	redir(t_list *lst, char **env)
{
	pid_t	pid;
	int		pipefd[2];

	pipe(pipefd);
	pid = fork();
	if (pid)
	{
		//close(pipefd[0]);
		close(pipefd[1]);
		if (dup2(pipefd[0], STDIN_FILENO) == -1)
			exit(1);
		close(pipefd[0]);
	}
	else
	{
		close(pipefd[0]);
		if (dup2(pipefd[1], STDOUT_FILENO) == -1)
			exit (1);
		close(pipefd[1]);
		exec(lst, env);
		exit(1);
	}
}
