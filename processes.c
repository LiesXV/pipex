/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhaim <ibenhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:33:37 by ibenhaim          #+#    #+#             */
/*   Updated: 2023/04/27 13:51:28 by ibenhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec(t_list *lst, char **env, t_data *args)
{
	execve(lst->path, lst->cmd, env);
	ft_putstr_fd("exec failed\n", 2);
	free_all(args);
	exit(1);
}

void	redir(t_list *lst, char **env, t_data *args)
{
	pid_t	pid;
	int		pipefd[2];

	if (pipe(pipefd) == -1)
	{
		free_all(args);
		exit(1);
	}
	pid = fork();
	if (pid == -1)
	{
		free_all(args);
		exit(1);
	}
	if (pid)
	{
		close(pipefd[1]);
		if (dup2(pipefd[0], STDIN_FILENO) == -1)
		{
			free_all(args);
			exit(1);
		}
		close(pipefd[0]);
	}
	else
	{
		close(pipefd[0]);
		if (dup2(pipefd[1], STDOUT_FILENO) == -1)
		{
			free_all(args);
			exit(1);
		}
		close(pipefd[1]);
		exec(lst, env, args);
	}
}
